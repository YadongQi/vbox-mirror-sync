/* $Id$ */
/** @file
 * VirtualBox Translator class.
 */

/*
 * Copyright (C) 2006-2020 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#include <iprt/asm.h>
#include <iprt/ctype.h>
#include <iprt/err.h>
#include <iprt/locale.h>
#include <iprt/once.h>
#include <iprt/path.h>
#include <iprt/string.h>
#include <iprt/thread.h>
#include <iprt/strcache.h>

#include "Global.h"
#include "VirtualBoxBase.h"
#include "QMTranslator.h"
#include "VirtualBoxTranslator.h"

#define TRANSLATOR_CACHE_SIZE 32

/** Init once for the critical section. */
static RTONCE               g_Once = RTONCE_INITIALIZER;
RTCRITSECTRW                VirtualBoxTranslator::s_instanceRwLock;
VirtualBoxTranslator       *VirtualBoxTranslator::s_pInstance = NULL;
static RTTLS                g_idxTls = NIL_RTTLS;

typedef std::pair<const char *, const char *> LastTranslation;

/**
 * @callback_method_impl{FNRTONCE}
 */
static DECLCALLBACK(int32_t) initLock(void *pvUser)
{
    RT_NOREF(pvUser);
    return VirtualBoxTranslator::initCritSect();
}


/**
 * @callback_method_impl{FNRTTLSDTOR, Destroys the cache during thread termination.}
 */
static DECLCALLBACK(void) freeThreadCache(void *pvValue) RT_NOTHROW_DEF
{
    if (pvValue != NULL)
    {
        LastTranslation *pCache = (LastTranslation *)pvValue;
        delete pCache;
    }
}


VirtualBoxTranslator::VirtualBoxTranslator()
    : util::RWLockHandle(VBoxLockingClass::LOCKCLASS_TRANSLATOR)
    , m_cInstanceRefs(0)
    , m_pTranslator(NULL)
    , m_hStrCache(NIL_RTSTRCACHE)
{
    RTTlsAllocEx(&g_idxTls, &freeThreadCache);
    int rc = RTStrCacheCreate(&m_hStrCache, "API Translation");
    m_rcCache = rc;
    if (RT_FAILURE(rc))
        m_hStrCache = NIL_RTSTRCACHE; /* (loadLanguage will fail) */
}


VirtualBoxTranslator::~VirtualBoxTranslator()
{
    if (g_idxTls != NIL_RTTLS)
    {
        void *pvTlsValue = NULL;
        int rc = RTTlsGetEx(g_idxTls, &pvTlsValue);
        if (RT_SUCCESS(rc))
        {
            freeThreadCache(pvTlsValue);
            RTTlsSet(g_idxTls, NULL);
        }
        RTTlsFree(g_idxTls);
        g_idxTls = NIL_RTTLS;
    }
    if (m_pTranslator)
    {
        delete m_pTranslator;
        m_pTranslator = NULL;
    }
    if (m_hStrCache != NIL_RTSTRCACHE)
    {
        RTStrCacheDestroy(m_hStrCache);
        m_hStrCache = NIL_RTSTRCACHE;
        m_rcCache = VERR_WRONG_ORDER;
    }
}


/**
 * Get or create a translator instance (singelton), referenced.
 *
 * The main reference is held by the main VBox singelton objects (VirtualBox,
 * VirtualBoxClient) tying it's lifetime to theirs.
 */
/* static */
VirtualBoxTranslator *VirtualBoxTranslator::instance()
{
    int rc = RTOnce(&g_Once, initLock, NULL);
    if (RT_SUCCESS(rc))
    {
        RTCritSectRwEnterShared(&s_instanceRwLock);
        VirtualBoxTranslator *pInstance = s_pInstance;
        if (RT_LIKELY(pInstance != NULL))
        {
            uint32_t cRefs = ASMAtomicIncU32(&pInstance->m_cInstanceRefs);
            Assert(cRefs > 1); Assert(cRefs < _8K); RT_NOREF(cRefs);
            RTCritSectRwLeaveShared(&s_instanceRwLock);
            return pInstance;
        }

        /* Maybe create the instance: */
        RTCritSectRwLeaveShared(&s_instanceRwLock);
        RTCritSectRwEnterExcl(&s_instanceRwLock);
        pInstance = s_pInstance;
        if (pInstance == NULL)
            s_pInstance = pInstance = new VirtualBoxTranslator();
        ASMAtomicIncU32(&pInstance->m_cInstanceRefs);
        RTCritSectRwLeaveExcl(&s_instanceRwLock);
        return pInstance;
    }
    return NULL;
}


/* static */
VirtualBoxTranslator *VirtualBoxTranslator::tryInstance()
{
    int rc = RTOnce(&g_Once, initLock, NULL);
    if (RT_SUCCESS(rc))
    {
        RTCritSectRwEnterShared(&s_instanceRwLock);
        VirtualBoxTranslator *pInstance = s_pInstance;
        if (RT_LIKELY(pInstance != NULL))
        {
            uint32_t cRefs = ASMAtomicIncU32(&pInstance->m_cInstanceRefs);
            Assert(cRefs > 1); Assert(cRefs < _8K); RT_NOREF(cRefs);
        }
        RTCritSectRwLeaveShared(&s_instanceRwLock);
        return pInstance;
    }
    return NULL;
}


/**
 * Release translator reference previous obtained via instance() or
 * i_instance().
 */
void VirtualBoxTranslator::release()
{
    RTCritSectRwEnterShared(&s_instanceRwLock);
    uint32_t cRefs = ASMAtomicDecU32(&m_cInstanceRefs);
    Assert(cRefs < _8K);
    if (RT_LIKELY(cRefs > 0))
        RTCritSectRwLeaveShared(&s_instanceRwLock);
    else
    {
        /* Looks like we've got the last reference. Must switch to exclusive
           mode for safe cleanup. */
        ASMAtomicIncU32(&m_cInstanceRefs);
        RTCritSectRwLeaveShared(&s_instanceRwLock);
        RTCritSectRwEnterExcl(&s_instanceRwLock);
        cRefs = ASMAtomicDecU32(&m_cInstanceRefs);
        Assert(cRefs < _8K);
        if (cRefs == 0)
        {
            s_pInstance = NULL;
            delete this;
        }
        RTCritSectRwLeaveExcl(&s_instanceRwLock);
    }
}


HRESULT VirtualBoxTranslator::loadLanguage(ComPtr<IVirtualBox> aVirtualBox)
{
    AssertReturn(aVirtualBox, E_INVALIDARG);

    ComPtr<ISystemProperties> pSystemProperties;
    HRESULT hrc = aVirtualBox->COMGETTER(SystemProperties)(pSystemProperties.asOutParam());
    if (SUCCEEDED(hrc))
    {
        com::Bstr bstrLocale;
        hrc = pSystemProperties->COMGETTER(LanguageId)(bstrLocale.asOutParam());
        if (SUCCEEDED(hrc))
        {
            int vrc = i_loadLanguage(com::Utf8Str(bstrLocale).c_str());
            if (RT_FAILURE(vrc))
                hrc = Global::vboxStatusCodeToCOM(vrc);
        }
    }
    return hrc;
}


int VirtualBoxTranslator::i_loadLanguage(const char *pszLang)
{
    int  rc = VINF_SUCCESS;
    char szLocale[256];
    if (pszLang == NULL || *pszLang == '\0')
    {
        rc = RTLocaleQueryNormalizedBaseLocaleName(szLocale, sizeof(szLocale));
        if (RT_SUCCESS(rc))
            pszLang = szLocale;
    }
    else
    {
        /* check the pszLang looks like language code, i.e. {ll} or {ll}_{CC} */
        size_t cbLang = strlen(pszLang);
        if (   !(cbLang == 1 && pszLang[0] == 'C')
            && !(cbLang == 2 && RT_C_IS_LOWER(pszLang[0]) && RT_C_IS_LOWER(pszLang[1]))
            && !(cbLang == 5 && RTLOCALE_IS_LANGUAGE2_UNDERSCORE_COUNTRY2(pszLang)))
            rc = VERR_INVALID_PARAMETER;
    }
    if (RT_SUCCESS(rc))
    {
        if (strcmp(pszLang, "C") != 0)
        {
            /* Construct the base filename for the translations: */
            char szNlsPath[RTPATH_MAX];
            rc = RTPathAppPrivateNoArch(szNlsPath, sizeof(szNlsPath));
            if (RT_SUCCESS(rc))
                rc = RTPathAppend(szNlsPath, sizeof(szNlsPath), "nls" RTPATH_SLASH_STR "VirtualBoxAPI_");
            if (RT_SUCCESS(rc))
            {
                size_t const cchNlsBase = strlen(szNlsPath);

                /* Try load language file on form 'VirtualBoxAPI_ll_CC.qm' if it exists
                   where 'll_CC' could for example be 'en_US' or 'de_CH': */
                ssize_t cchOkay = RTStrPrintf2(&szNlsPath[cchNlsBase], sizeof(szNlsPath) - cchNlsBase, "%s.qm", pszLang);
                if (cchOkay > 0)
                    rc = i_setLanguageFile(szNlsPath);
                else
                    rc = VERR_FILENAME_TOO_LONG;
                if (RT_FAILURE(rc))
                {
                    /* No luck, drop the country part, i.e. 'VirtualBoxAPI_de.qm' or 'VirtualBoxAPI_en.qm': */
                    const char *pszDash = strchr(pszLang, '_');
                    if (pszDash && pszDash != pszLang)
                    {
                        cchOkay = RTStrPrintf2(&szNlsPath[cchNlsBase], sizeof(szNlsPath) - cchNlsBase, "%.*s.qm",
                                               pszDash - pszLang, pszLang);
                        if (cchOkay > 0)
                            rc = i_setLanguageFile(szNlsPath);
                    }
                }
            }
        }
        else
        {
            /* No translator needed for 'C': */
            AutoWriteLock alock(this COMMA_LOCKVAL_SRC_POS);
            delete m_pTranslator;
            m_pTranslator = NULL;
        }
    }
    return rc;
}


int VirtualBoxTranslator::i_setLanguageFile(const char *aFileName)
{
    int rc = m_rcCache;
    if (m_hStrCache != NIL_RTSTRCACHE)
    {
        QMTranslator *pNewTranslator;
        try { pNewTranslator = new QMTranslator(); }
        catch (std::bad_alloc &) { pNewTranslator = NULL; }
        if (pNewTranslator)
        {
            rc = pNewTranslator->load(aFileName, m_hStrCache);
            if (RT_SUCCESS(rc))
            {
                AutoWriteLock alock(this COMMA_LOCKVAL_SRC_POS);

                if (m_pTranslator)
                    delete m_pTranslator;
                m_pTranslator     = pNewTranslator;
                m_strLangFileName = aFileName;
            }
            else
                delete pNewTranslator;
        }
        else
            rc = VERR_NO_MEMORY;
    }
    else
        Assert(RT_FAILURE_NP(rc));
    return rc;
}


com::Utf8Str VirtualBoxTranslator::i_languageFile()
{
    AutoReadLock alock(this COMMA_LOCKVAL_SRC_POS);
    return m_strLangFileName;
}


const char *VirtualBoxTranslator::translate(const char *aContext,
                                            const char *aSourceText,
                                            const char *aComment,
                                            const int   aNum)
{
    VirtualBoxTranslator *pCurrInstance = VirtualBoxTranslator::tryInstance();
    const char *pszTranslation = aSourceText;
    if (pCurrInstance != NULL)
    {
        pszTranslation = pCurrInstance->i_translate(aContext, aSourceText, aComment, aNum);
        pCurrInstance->release();
    }
    return pszTranslation;
}


static LastTranslation *getTlsEntry() RT_NOEXCEPT
{
    if (RT_LIKELY(g_idxTls != NIL_RTTLS))
    {
        LastTranslation *pEntry = (LastTranslation *)RTTlsGet(g_idxTls);
        if (pEntry != NULL)
            return pEntry; /* likely */

        /* Create a new entry. */
        try
        {
            pEntry = new LastTranslation();
            pEntry->first = pEntry->second = "";
            int rc = RTTlsSet(g_idxTls, pEntry);
            if (RT_SUCCESS(rc))
                return pEntry;
            delete pEntry;
        }
        catch (std::bad_alloc &)
        {
        }
    }
    return NULL;
}


const char *VirtualBoxTranslator::i_translate(const char *aContext,
                                              const char *aSourceText,
                                              const char *aComment,
                                              const int   aNum)
{
    AutoReadLock alock(this COMMA_LOCKVAL_SRC_POS);
    if (!m_pTranslator)
        return aSourceText;
    const char *pszTranslation = m_pTranslator->translate(aContext, aSourceText, aComment, aNum);
    alock.release();

    LastTranslation *pEntry = getTlsEntry();
    if (pEntry)
    {
        pEntry->first = pszTranslation;
        pEntry->second = aSourceText;
    }

    return pszTranslation;
}


const char *VirtualBoxTranslator::trSource(const char *aTranslation)
{
    const char *pszSource = aTranslation;
    VirtualBoxTranslator *pCurInstance = VirtualBoxTranslator::tryInstance(); /* paranoia */
    if (pCurInstance != NULL)
    {
        LastTranslation *pEntry = getTlsEntry();
        if (   pEntry != NULL
            && (   pEntry->first == aTranslation
                || strcmp(pEntry->first, aTranslation) == 0) )
            pszSource = pEntry->second;
        pCurInstance->release();
    }
    return pszSource;
}


int32_t VirtualBoxTranslator::initCritSect()
{
    return RTCritSectRwInit(&s_instanceRwLock);
}
/* vi: set tabstop=4 shiftwidth=4 expandtab: */