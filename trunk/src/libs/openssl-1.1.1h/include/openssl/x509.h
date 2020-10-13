/*
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 * Copyright (c) 2002, Oracle and/or its affiliates. All rights reserved
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_X509_H
# define HEADER_X509_H

# include <openssl/e_os2.h>
# include <openssl/ossl_typ.h>
# include <openssl/symhacks.h>
# include <openssl/buffer.h>
# include <openssl/evp.h>
# include <openssl/bio.h>
# include <openssl/asn1.h>
# include <openssl/safestack.h>
# include <openssl/ec.h>

# if OPENSSL_API_COMPAT < 0x10100000L
#  include <openssl/rsa.h>
#  include <openssl/dsa.h>
#  include <openssl/dh.h>
# endif

# include <openssl/sha.h>
# include <openssl/x509err.h>

#ifdef  __cplusplus
extern "C" {
#endif


/* Flags for X509_get_signature_info() */
/* Signature info is valid */
# define X509_SIG_INFO_VALID     0x1
/* Signature is suitable for TLS use */
# define X509_SIG_INFO_TLS       0x2

# define X509_FILETYPE_PEM       1
# define X509_FILETYPE_ASN1      2
# define X509_FILETYPE_DEFAULT   3

# define X509v3_KU_DIGITAL_SIGNATURE     0x0080
# define X509v3_KU_NON_REPUDIATION       0x0040
# define X509v3_KU_KEY_ENCIPHERMENT      0x0020
# define X509v3_KU_DATA_ENCIPHERMENT     0x0010
# define X509v3_KU_KEY_AGREEMENT         0x0008
# define X509v3_KU_KEY_CERT_SIGN         0x0004
# define X509v3_KU_CRL_SIGN              0x0002
# define X509v3_KU_ENCIPHER_ONLY         0x0001
# define X509v3_KU_DECIPHER_ONLY         0x8000
# define X509v3_KU_UNDEF                 0xffff

struct X509_algor_st {
    ASN1_OBJECT *algorithm;
    ASN1_TYPE *parameter;
} /* X509_ALGOR */ ;

typedef STACK_OF(X509_ALGOR) X509_ALGORS;

typedef struct X509_val_st {
    ASN1_TIME *notBefore;
    ASN1_TIME *notAfter;
} X509_VAL;

typedef struct X509_sig_st X509_SIG;

typedef struct X509_name_entry_st X509_NAME_ENTRY;

DEFINE_STACK_OF(X509_NAME_ENTRY)

DEFINE_STACK_OF(X509_NAME)

# define X509_EX_V_NETSCAPE_HACK         0x8000
# define X509_EX_V_INIT                  0x0001
typedef struct X509_extension_st X509_EXTENSION;

typedef STACK_OF(X509_EXTENSION) X509_EXTENSIONS;

DEFINE_STACK_OF(X509_EXTENSION)

typedef struct x509_attributes_st X509_ATTRIBUTE;

DEFINE_STACK_OF(X509_ATTRIBUTE)

typedef struct X509_req_info_st X509_REQ_INFO;

typedef struct X509_req_st X509_REQ;

typedef struct x509_cert_aux_st X509_CERT_AUX;

typedef struct x509_cinf_st X509_CINF;

DEFINE_STACK_OF(X509)

/* This is used for a table of trust checking functions */

typedef struct x509_trust_st {
    int trust;
    int flags;
    int (*check_trust) (struct x509_trust_st *, X509 *, int);
    char *name;
    int arg1;
    void *arg2;
} X509_TRUST;

DEFINE_STACK_OF(X509_TRUST)

/* standard trust ids */

# define X509_TRUST_DEFAULT      0 /* Only valid in purpose settings */

# define X509_TRUST_COMPAT       1
# define X509_TRUST_SSL_CLIENT   2
# define X509_TRUST_SSL_SERVER   3
# define X509_TRUST_EMAIL        4
# define X509_TRUST_OBJECT_SIGN  5
# define X509_TRUST_OCSP_SIGN    6
# define X509_TRUST_OCSP_REQUEST 7
# define X509_TRUST_TSA          8

/* Keep these up to date! */
# define X509_TRUST_MIN          1
# define X509_TRUST_MAX          8

/* trust_flags values */
# define X509_TRUST_DYNAMIC      (1U << 0)
# define X509_TRUST_DYNAMIC_NAME (1U << 1)
/* No compat trust if self-signed, preempts "DO_SS" */
# define X509_TRUST_NO_SS_COMPAT (1U << 2)
/* Compat trust if no explicit accepted trust EKUs */
# define X509_TRUST_DO_SS_COMPAT (1U << 3)
/* Accept "anyEKU" as a wildcard trust OID */
# define X509_TRUST_OK_ANY_EKU   (1U << 4)

/* check_trust return codes */

# define X509_TRUST_TRUSTED      1
# define X509_TRUST_REJECTED     2
# define X509_TRUST_UNTRUSTED    3

/* Flags for X509_print_ex() */

# define X509_FLAG_COMPAT                0
# define X509_FLAG_NO_HEADER             1L
# define X509_FLAG_NO_VERSION            (1L << 1)
# define X509_FLAG_NO_SERIAL             (1L << 2)
# define X509_FLAG_NO_SIGNAME            (1L << 3)
# define X509_FLAG_NO_ISSUER             (1L << 4)
# define X509_FLAG_NO_VALIDITY           (1L << 5)
# define X509_FLAG_NO_SUBJECT            (1L << 6)
# define X509_FLAG_NO_PUBKEY             (1L << 7)
# define X509_FLAG_NO_EXTENSIONS         (1L << 8)
# define X509_FLAG_NO_SIGDUMP            (1L << 9)
# define X509_FLAG_NO_AUX                (1L << 10)
# define X509_FLAG_NO_ATTRIBUTES         (1L << 11)
# define X509_FLAG_NO_IDS                (1L << 12)

/* Flags specific to X509_NAME_print_ex() */

/* The field separator information */

# define XN_FLAG_SEP_MASK        (0xf << 16)

# define XN_FLAG_COMPAT          0/* Traditional; use old X509_NAME_print */
# define XN_FLAG_SEP_COMMA_PLUS  (1 << 16)/* RFC2253 ,+ */
# define XN_FLAG_SEP_CPLUS_SPC   (2 << 16)/* ,+ spaced: more readable */
# define XN_FLAG_SEP_SPLUS_SPC   (3 << 16)/* ;+ spaced */
# define XN_FLAG_SEP_MULTILINE   (4 << 16)/* One line per field */

# define XN_FLAG_DN_REV          (1 << 20)/* Reverse DN order */

/* How the field name is shown */

# define XN_FLAG_FN_MASK         (0x3 << 21)

# define XN_FLAG_FN_SN           0/* Object short name */
# define XN_FLAG_FN_LN           (1 << 21)/* Object long name */
# define XN_FLAG_FN_OID          (2 << 21)/* Always use OIDs */
# define XN_FLAG_FN_NONE         (3 << 21)/* No field names */

# define XN_FLAG_SPC_EQ          (1 << 23)/* Put spaces round '=' */

/*
 * This determines if we dump fields we don't recognise: RFC2253 requires
 * this.
 */

# define XN_FLAG_DUMP_UNKNOWN_FIELDS (1 << 24)

# define XN_FLAG_FN_ALIGN        (1 << 25)/* Align field names to 20
                                           * characters */

/* Complete set of RFC2253 flags */

# define XN_FLAG_RFC2253 (ASN1_STRFLGS_RFC2253 | \
                        XN_FLAG_SEP_COMMA_PLUS | \
                        XN_FLAG_DN_REV | \
                        XN_FLAG_FN_SN | \
                        XN_FLAG_DUMP_UNKNOWN_FIELDS)

/* readable oneline form */

# define XN_FLAG_ONELINE (ASN1_STRFLGS_RFC2253 | \
                        ASN1_STRFLGS_ESC_QUOTE | \
                        XN_FLAG_SEP_CPLUS_SPC | \
                        XN_FLAG_SPC_EQ | \
                        XN_FLAG_FN_SN)

/* readable multiline form */

# define XN_FLAG_MULTILINE (ASN1_STRFLGS_ESC_CTRL | \
                        ASN1_STRFLGS_ESC_MSB | \
                        XN_FLAG_SEP_MULTILINE | \
                        XN_FLAG_SPC_EQ | \
                        XN_FLAG_FN_LN | \
                        XN_FLAG_FN_ALIGN)

DEFINE_STACK_OF(X509_REVOKED)

typedef struct X509_crl_info_st X509_CRL_INFO;

DEFINE_STACK_OF(X509_CRL)

typedef struct private_key_st {
    int version;
    /* The PKCS#8 data types */
    X509_ALGOR *enc_algor;
    ASN1_OCTET_STRING *enc_pkey; /* encrypted pub key */
    /* When decrypted, the following will not be NULL */
    EVP_PKEY *dec_pkey;
    /* used to encrypt and decrypt */
    int key_length;
    char *key_data;
    int key_free;               /* true if we should auto free key_data */
    /* expanded version of 'enc_algor' */
    EVP_CIPHER_INFO cipher;
} X509_PKEY;

typedef struct X509_info_st {
    X509 *x509;
    X509_CRL *crl;
    X509_PKEY *x_pkey;
    EVP_CIPHER_INFO enc_cipher;
    int enc_len;
    char *enc_data;
} X509_INFO;

DEFINE_STACK_OF(X509_INFO)

/*
 * The next 2 structures and their 8 routines are used to manipulate Netscape's
 * spki structures - useful if you are writing a CA web page
 */
typedef struct Netscape_spkac_st {
    X509_PUBKEY *pubkey;
    ASN1_IA5STRING *challenge;  /* challenge sent in atlas >= PR2 */
} NETSCAPE_SPKAC;

typedef struct Netscape_spki_st {
    NETSCAPE_SPKAC *spkac;      /* signed public key and challenge */
    X509_ALGOR sig_algor;
    ASN1_BIT_STRING *signature;
} NETSCAPE_SPKI;

/* Netscape certificate sequence structure */
typedef struct Netscape_certificate_sequence {
    ASN1_OBJECT *type;
    STACK_OF(X509) *certs;
} NETSCAPE_CERT_SEQUENCE;

/*- Unused (and iv length is wrong)
typedef struct CBCParameter_st
        {
        unsigned char iv[8];
        } CBC_PARAM;
*/

/* Password based encryption structure */

typedef struct PBEPARAM_st {
    ASN1_OCTET_STRING *salt;
    ASN1_INTEGER *iter;
} PBEPARAM;

/* Password based encryption V2 structures */

typedef struct PBE2PARAM_st {
    X509_ALGOR *keyfunc;
    X509_ALGOR *encryption;
} PBE2PARAM;

typedef struct PBKDF2PARAM_st {
/* Usually OCTET STRING but could be anything */
    ASN1_TYPE *salt;
    ASN1_INTEGER *iter;
    ASN1_INTEGER *keylength;
    X509_ALGOR *prf;
} PBKDF2PARAM;

#ifndef OPENSSL_NO_SCRYPT
typedef struct SCRYPT_PARAMS_st {
    ASN1_OCTET_STRING *salt;
    ASN1_INTEGER *costParameter;
    ASN1_INTEGER *blockSize;
    ASN1_INTEGER *parallelizationParameter;
    ASN1_INTEGER *keyLength;
} SCRYPT_PARAMS;
#endif

#ifdef  __cplusplus
}
#endif

# include <openssl/x509_vfy.h>
# include <openssl/pkcs7.h>

#ifdef  __cplusplus
extern "C" {
#endif

# define X509_EXT_PACK_UNKNOWN   1
# define X509_EXT_PACK_STRING    2

# define         X509_extract_key(x)     X509_get_pubkey(x)/*****/
# define         X509_REQ_extract_key(a) X509_REQ_get_pubkey(a)
# define         X509_name_cmp(a,b)      X509_NAME_cmp((a),(b))

void X509_CRL_set_default_method(const X509_CRL_METHOD *meth);
X509_CRL_METHOD *X509_CRL_METHOD_new(int (*crl_init) (X509_CRL *crl),
                                     int (*crl_free) (X509_CRL *crl),
                                     int (*crl_lookup) (X509_CRL *crl,
                                                        X509_REVOKED **ret,
                                                        ASN1_INTEGER *ser,
                                                        X509_NAME *issuer),
                                     int (*crl_verify) (X509_CRL *crl,
                                                        EVP_PKEY *pk));
void X509_CRL_METHOD_free(X509_CRL_METHOD *m);

void X509_CRL_set_meth_data(X509_CRL *crl, void *dat);
void *X509_CRL_get_meth_data(X509_CRL *crl);

const char *X509_verify_cert_error_string(long n);

int X509_verify(X509 *a, EVP_PKEY *r);

int X509_REQ_verify(X509_REQ *a, EVP_PKEY *r);
int X509_CRL_verify(X509_CRL *a, EVP_PKEY *r);
int NETSCAPE_SPKI_verify(NETSCAPE_SPKI *a, EVP_PKEY *r);

NETSCAPE_SPKI *NETSCAPE_SPKI_b64_decode(const char *str, int len);
char *NETSCAPE_SPKI_b64_encode(NETSCAPE_SPKI *x);
EVP_PKEY *NETSCAPE_SPKI_get_pubkey(NETSCAPE_SPKI *x);
int NETSCAPE_SPKI_set_pubkey(NETSCAPE_SPKI *x, EVP_PKEY *pkey);

int NETSCAPE_SPKI_print(BIO *out, NETSCAPE_SPKI *spki);

int X509_signature_dump(BIO *bp, const ASN1_STRING *sig, int indent);
int X509_signature_print(BIO *bp, const X509_ALGOR *alg,
                         const ASN1_STRING *sig);

int X509_sign(X509 *x, EVP_PKEY *pkey, const EVP_MD *md);
int X509_sign_ctx(X509 *x, EVP_MD_CTX *ctx);
# ifndef OPENSSL_NO_OCSP
int X509_http_nbio(OCSP_REQ_CTX *rctx, X509 **pcert);
# endif
int X509_REQ_sign(X509_REQ *x, EVP_PKEY *pkey, const EVP_MD *md);
int X509_REQ_sign_ctx(X509_REQ *x, EVP_MD_CTX *ctx);
int X509_CRL_sign(X509_CRL *x, EVP_PKEY *pkey, const EVP_MD *md);
int X509_CRL_sign_ctx(X509_CRL *x, EVP_MD_CTX *ctx);
# ifndef OPENSSL_NO_OCSP
int X509_CRL_http_nbio(OCSP_REQ_CTX *rctx, X509_CRL **pcrl);
# endif
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x, EVP_PKEY *pkey, const EVP_MD *md);

int X509_pubkey_digest(const X509 *data, const EVP_MD *type,
                       unsigned char *md, unsigned int *len);
int X509_digest(const X509 *data, const EVP_MD *type,
                unsigned char *md, unsigned int *len);
int X509_CRL_digest(const X509_CRL *data, const EVP_MD *type,
                    unsigned char *md, unsigned int *len);
int X509_REQ_digest(const X509_REQ *data, const EVP_MD *type,
                    unsigned char *md, unsigned int *len);
int X509_NAME_digest(const X509_NAME *data, const EVP_MD *type,
                     unsigned char *md, unsigned int *len);

# ifndef OPENSSL_NO_STDIO
X509 *d2i_X509_fp(FILE *fp, X509 **x509);
int i2d_X509_fp(FILE *fp, X509 *x509);
X509_CRL *d2i_X509_CRL_fp(FILE *fp, X509_CRL **crl);
int i2d_X509_CRL_fp(FILE *fp, X509_CRL *crl);
X509_REQ *d2i_X509_REQ_fp(FILE *fp, X509_REQ **req);
int i2d_X509_REQ_fp(FILE *fp, X509_REQ *req);
#  ifndef OPENSSL_NO_RSA
RSA *d2i_RSAPrivateKey_fp(FILE *fp, RSA **rsa);
int i2d_RSAPrivateKey_fp(FILE *fp, RSA *rsa);
RSA *d2i_RSAPublicKey_fp(FILE *fp, RSA **rsa);
int i2d_RSAPublicKey_fp(FILE *fp, RSA *rsa);
RSA *d2i_RSA_PUBKEY_fp(FILE *fp, RSA **rsa);
int i2d_RSA_PUBKEY_fp(FILE *fp, RSA *rsa);
#  endif
#  ifndef OPENSSL_NO_DSA
DSA *d2i_DSA_PUBKEY_fp(FILE *fp, DSA **dsa);
int i2d_DSA_PUBKEY_fp(FILE *fp, DSA *dsa);
DSA *d2i_DSAPrivateKey_fp(FILE *fp, DSA **dsa);
int i2d_DSAPrivateKey_fp(FILE *fp, DSA *dsa);
#  endif
#  ifndef OPENSSL_NO_EC
EC_KEY *d2i_EC_PUBKEY_fp(FILE *fp, EC_KEY **eckey);
int i2d_EC_PUBKEY_fp(FILE *fp, EC_KEY *eckey);
EC_KEY *d2i_ECPrivateKey_fp(FILE *fp, EC_KEY **eckey);
int i2d_ECPrivateKey_fp(FILE *fp, EC_KEY *eckey);
#  endif
X509_SIG *d2i_PKCS8_fp(FILE *fp, X509_SIG **p8);
int i2d_PKCS8_fp(FILE *fp, X509_SIG *p8);
PKCS8_PRIV_KEY_INFO *d2i_PKCS8_PRIV_KEY_INFO_fp(FILE *fp,
                                                PKCS8_PRIV_KEY_INFO **p8inf);
int i2d_PKCS8_PRIV_KEY_INFO_fp(FILE *fp, PKCS8_PRIV_KEY_INFO *p8inf);
int i2d_PKCS8PrivateKeyInfo_fp(FILE *fp, EVP_PKEY *key);
int i2d_PrivateKey_fp(FILE *fp, EVP_PKEY *pkey);
EVP_PKEY *d2i_PrivateKey_fp(FILE *fp, EVP_PKEY **a);
int i2d_PUBKEY_fp(FILE *fp, EVP_PKEY *pkey);
EVP_PKEY *d2i_PUBKEY_fp(FILE *fp, EVP_PKEY **a);
# endif

X509 *d2i_X509_bio(BIO *bp, X509 **x509);
int i2d_X509_bio(BIO *bp, X509 *x509);
X509_CRL *d2i_X509_CRL_bio(BIO *bp, X509_CRL **crl);
int i2d_X509_CRL_bio(BIO *bp, X509_CRL *crl);
X509_REQ *d2i_X509_REQ_bio(BIO *bp, X509_REQ **req);
int i2d_X509_REQ_bio(BIO *bp, X509_REQ *req);
#  ifndef OPENSSL_NO_RSA
RSA *d2i_RSAPrivateKey_bio(BIO *bp, RSA **rsa);
int i2d_RSAPrivateKey_bio(BIO *bp, RSA *rsa);
RSA *d2i_RSAPublicKey_bio(BIO *bp, RSA **rsa);
int i2d_RSAPublicKey_bio(BIO *bp, RSA *rsa);
RSA *d2i_RSA_PUBKEY_bio(BIO *bp, RSA **rsa);
int i2d_RSA_PUBKEY_bio(BIO *bp, RSA *rsa);
#  endif
#  ifndef OPENSSL_NO_DSA
DSA *d2i_DSA_PUBKEY_bio(BIO *bp, DSA **dsa);
int i2d_DSA_PUBKEY_bio(BIO *bp, DSA *dsa);
DSA *d2i_DSAPrivateKey_bio(BIO *bp, DSA **dsa);
int i2d_DSAPrivateKey_bio(BIO *bp, DSA *dsa);
#  endif
#  ifndef OPENSSL_NO_EC
EC_KEY *d2i_EC_PUBKEY_bio(BIO *bp, EC_KEY **eckey);
int i2d_EC_PUBKEY_bio(BIO *bp, EC_KEY *eckey);
EC_KEY *d2i_ECPrivateKey_bio(BIO *bp, EC_KEY **eckey);
int i2d_ECPrivateKey_bio(BIO *bp, EC_KEY *eckey);
#  endif
X509_SIG *d2i_PKCS8_bio(BIO *bp, X509_SIG **p8);
int i2d_PKCS8_bio(BIO *bp, X509_SIG *p8);
PKCS8_PRIV_KEY_INFO *d2i_PKCS8_PRIV_KEY_INFO_bio(BIO *bp,
                                                 PKCS8_PRIV_KEY_INFO **p8inf);
int i2d_PKCS8_PRIV_KEY_INFO_bio(BIO *bp, PKCS8_PRIV_KEY_INFO *p8inf);
int i2d_PKCS8PrivateKeyInfo_bio(BIO *bp, EVP_PKEY *key);
int i2d_PrivateKey_bio(BIO *bp, EVP_PKEY *pkey);
EVP_PKEY *d2i_PrivateKey_bio(BIO *bp, EVP_PKEY **a);
int i2d_PUBKEY_bio(BIO *bp, EVP_PKEY *pkey);
EVP_PKEY *d2i_PUBKEY_bio(BIO *bp, EVP_PKEY **a);

X509 *X509_dup(X509 *x509);
X509_ATTRIBUTE *X509_ATTRIBUTE_dup(X509_ATTRIBUTE *xa);
X509_EXTENSION *X509_EXTENSION_dup(X509_EXTENSION *ex);
X509_CRL *X509_CRL_dup(X509_CRL *crl);
X509_REVOKED *X509_REVOKED_dup(X509_REVOKED *rev);
X509_REQ *X509_REQ_dup(X509_REQ *req);
X509_ALGOR *X509_ALGOR_dup(X509_ALGOR *xn);
int X509_ALGOR_set0(X509_ALGOR *alg, ASN1_OBJECT *aobj, int ptype,
                    void *pval);
void X509_ALGOR_get0(const ASN1_OBJECT **paobj, int *pptype,
                     const void **ppval, const X509_ALGOR *algor);
void X509_ALGOR_set_md(X509_ALGOR *alg, const EVP_MD *md);
int X509_ALGOR_cmp(const X509_ALGOR *a, const X509_ALGOR *b);
int X509_ALGOR_copy(X509_ALGOR *dest, const X509_ALGOR *src);

X509_NAME *X509_NAME_dup(X509_NAME *xn);
X509_NAME_ENTRY *X509_NAME_ENTRY_dup(X509_NAME_ENTRY *ne);

int X509_cmp_time(const ASN1_TIME *s, time_t *t);
int X509_cmp_current_time(const ASN1_TIME *s);
ASN1_TIME *X509_time_adj(ASN1_TIME *s, long adj, time_t *t);
ASN1_TIME *X509_time_adj_ex(ASN1_TIME *s,
                            int offset_day, long offset_sec, time_t *t);
ASN1_TIME *X509_gmtime_adj(ASN1_TIME *s, long adj);

const char *X509_get_default_cert_area(void);
const char *X509_get_default_cert_dir(void);
const char *X509_get_default_cert_file(void);
const char *X509_get_default_cert_dir_env(void);
const char *X509_get_default_cert_file_env(void);
const char *X509_get_default_private_dir(void);

X509_REQ *X509_to_X509_REQ(X509 *x, EVP_PKEY *pkey, const EVP_MD *md);
X509 *X509_REQ_to_X509(X509_REQ *r, int days, EVP_PKEY *pkey);

DECLARE_ASN1_FUNCTIONS(X509_ALGOR)
DECLARE_ASN1_ENCODE_FUNCTIONS(X509_ALGORS, X509_ALGORS, X509_ALGORS)
DECLARE_ASN1_FUNCTIONS(X509_VAL)

DECLARE_ASN1_FUNCTIONS(X509_PUBKEY)

int X509_PUBKEY_set(X509_PUBKEY **x, EVP_PKEY *pkey);
EVP_PKEY *X509_PUBKEY_get0(X509_PUBKEY *key);
EVP_PKEY *X509_PUBKEY_get(X509_PUBKEY *key);
int X509_get_pubkey_parameters(EVP_PKEY *pkey, STACK_OF(X509) *chain);
long X509_get_pathlen(X509 *x);
int i2d_PUBKEY(EVP_PKEY *a, unsigned char **pp);
EVP_PKEY *d2i_PUBKEY(EVP_PKEY **a, const unsigned char **pp, long length);
# ifndef OPENSSL_NO_RSA
int i2d_RSA_PUBKEY(RSA *a, unsigned char **pp);
RSA *d2i_RSA_PUBKEY(RSA **a, const unsigned char **pp, long length);
# endif
# ifndef OPENSSL_NO_DSA
int i2d_DSA_PUBKEY(DSA *a, unsigned char **pp);
DSA *d2i_DSA_PUBKEY(DSA **a, const unsigned char **pp, long length);
# endif
# ifndef OPENSSL_NO_EC
int i2d_EC_PUBKEY(EC_KEY *a, unsigned char **pp);
EC_KEY *d2i_EC_PUBKEY(EC_KEY **a, const unsigned char **pp, long length);
# endif

DECLARE_ASN1_FUNCTIONS(X509_SIG)
void X509_SIG_get0(const X509_SIG *sig, const X509_ALGOR **palg,
                   const ASN1_OCTET_STRING **pdigest);
void X509_SIG_getm(X509_SIG *sig, X509_ALGOR **palg,
                   ASN1_OCTET_STRING **pdigest);

DECLARE_ASN1_FUNCTIONS(X509_REQ_INFO)
DECLARE_ASN1_FUNCTIONS(X509_REQ)

DECLARE_ASN1_FUNCTIONS(X509_ATTRIBUTE)
X509_ATTRIBUTE *X509_ATTRIBUTE_create(int nid, int atrtype, void *value);

DECLARE_ASN1_FUNCTIONS(X509_EXTENSION)
DECLARE_ASN1_ENCODE_FUNCTIONS(X509_EXTENSIONS, X509_EXTENSIONS, X509_EXTENSIONS)

DECLARE_ASN1_FUNCTIONS(X509_NAME_ENTRY)

DECLARE_ASN1_FUNCTIONS(X509_NAME)

int X509_NAME_set(X509_NAME **xn, X509_NAME *name);

DECLARE_ASN1_FUNCTIONS(X509_CINF)

DECLARE_ASN1_FUNCTIONS(X509)
DECLARE_ASN1_FUNCTIONS(X509_CERT_AUX)

#define X509_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_X509, l, p, newf, dupf, freef)
int X509_set_ex_data(X509 *r, int idx, void *arg);
void *X509_get_ex_data(X509 *r, int idx);
int i2d_X509_AUX(X509 *a, unsigned char **pp);
X509 *d2i_X509_AUX(X509 **a, const unsigned char **pp, long length);

int i2d_re_X509_tbs(X509 *x, unsigned char **pp);

int X509_SIG_INFO_get(const X509_SIG_INFO *siginf, int *mdnid, int *pknid,
                      int *secbits, uint32_t *flags);
void X509_SIG_INFO_set(X509_SIG_INFO *siginf, int mdnid, int pknid,
                       int secbits, uint32_t flags);

int X509_get_signature_info(X509 *x, int *mdnid, int *pknid, int *secbits,
                            uint32_t *flags);

void X509_get0_signature(const ASN1_BIT_STRING **psig,
                         const X509_ALGOR **palg, const X509 *x);
int X509_get_signature_nid(const X509 *x);

int X509_trusted(const X509 *x);
int X509_alias_set1(X509 *x, const unsigned char *name, int len);
int X509_keyid_set1(X509 *x, const unsigned char *id, int len);
unsigned char *X509_alias_get0(X509 *x, int *len);
unsigned char *X509_keyid_get0(X509 *x, int *len);
int (*X509_TRUST_set_default(int (*trust) (int, X509 *, int))) (int, X509 *,
                                                                int);
int X509_TRUST_set(int *t, int trust);
int X509_add1_trust_object(X509 *x, const ASN1_OBJECT *obj);
int X509_add1_reject_object(X509 *x, const ASN1_OBJECT *obj);
void X509_trust_clear(X509 *x);
void X509_reject_clear(X509 *x);

STACK_OF(ASN1_OBJECT) *X509_get0_trust_objects(X509 *x);
STACK_OF(ASN1_OBJECT) *X509_get0_reject_objects(X509 *x);

DECLARE_ASN1_FUNCTIONS(X509_REVOKED)
DECLARE_ASN1_FUNCTIONS(X509_CRL_INFO)
DECLARE_ASN1_FUNCTIONS(X509_CRL)

int X509_CRL_add0_revoked(X509_CRL *crl, X509_REVOKED *rev);
int X509_CRL_get0_by_serial(X509_CRL *crl,
                            X509_REVOKED **ret, ASN1_INTEGER *serial);
int X509_CRL_get0_by_cert(X509_CRL *crl, X509_REVOKED **ret, X509 *x);

X509_PKEY *X509_PKEY_new(void);
void X509_PKEY_free(X509_PKEY *a);

DECLARE_ASN1_FUNCTIONS(NETSCAPE_SPKI)
DECLARE_ASN1_FUNCTIONS(NETSCAPE_SPKAC)
DECLARE_ASN1_FUNCTIONS(NETSCAPE_CERT_SEQUENCE)

X509_INFO *X509_INFO_new(void);
void X509_INFO_free(X509_INFO *a);
char *X509_NAME_oneline(const X509_NAME *a, char *buf, int size);

int ASN1_verify(i2d_of_void *i2d, X509_ALGOR *algor1,
                ASN1_BIT_STRING *signature, char *data, EVP_PKEY *pkey);

int ASN1_digest(i2d_of_void *i2d, const EVP_MD *type, char *data,
                unsigned char *md, unsigned int *len);

int ASN1_sign(i2d_of_void *i2d, X509_ALGOR *algor1,
              X509_ALGOR *algor2, ASN1_BIT_STRING *signature,
              char *data, EVP_PKEY *pkey, const EVP_MD *type);

int ASN1_item_digest(const ASN1_ITEM *it, const EVP_MD *type, void *data,
                     unsigned char *md, unsigned int *len);

int ASN1_item_verify(const ASN1_ITEM *it, X509_ALGOR *algor1,
                     ASN1_BIT_STRING *signature, void *data, EVP_PKEY *pkey);

int ASN1_item_sign(const ASN1_ITEM *it, X509_ALGOR *algor1,
                   X509_ALGOR *algor2, ASN1_BIT_STRING *signature, void *data,
                   EVP_PKEY *pkey, const EVP_MD *type);
int ASN1_item_sign_ctx(const ASN1_ITEM *it, X509_ALGOR *algor1,
                       X509_ALGOR *algor2, ASN1_BIT_STRING *signature,
                       void *asn, EVP_MD_CTX *ctx);

long X509_get_version(const X509 *x);
int X509_set_version(X509 *x, long version);
int X509_set_serialNumber(X509 *x, ASN1_INTEGER *serial);
ASN1_INTEGER *X509_get_serialNumber(X509 *x);
const ASN1_INTEGER *X509_get0_serialNumber(const X509 *x);
int X509_set_issuer_name(X509 *x, X509_NAME *name);
X509_NAME *X509_get_issuer_name(const X509 *a);
int X509_set_subject_name(X509 *x, X509_NAME *name);
X509_NAME *X509_get_subject_name(const X509 *a);
const ASN1_TIME * X509_get0_notBefore(const X509 *x);
ASN1_TIME *X509_getm_notBefore(const X509 *x);
int X509_set1_notBefore(X509 *x, const ASN1_TIME *tm);
const ASN1_TIME *X509_get0_notAfter(const X509 *x);
ASN1_TIME *X509_getm_notAfter(const X509 *x);
int X509_set1_notAfter(X509 *x, const ASN1_TIME *tm);
int X509_set_pubkey(X509 *x, EVP_PKEY *pkey);
int X509_up_ref(X509 *x);
int X509_get_signature_type(const X509 *x);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define X509_get_notBefore X509_getm_notBefore
#  define X509_get_notAfter X509_getm_notAfter
#  define X509_set_notBefore X509_set1_notBefore
#  define X509_set_notAfter X509_set1_notAfter
#endif


/*
 * This one is only used so that a binary form can output, as in
 * i2d_X509_PUBKEY(X509_get_X509_PUBKEY(x), &buf)
 */
X509_PUBKEY *X509_get_X509_PUBKEY(const X509 *x);
const STACK_OF(X509_EXTENSION) *X509_get0_extensions(const X509 *x);
void X509_get0_uids(const X509 *x, const ASN1_BIT_STRING **piuid,
                    const ASN1_BIT_STRING **psuid);
const X509_ALGOR *X509_get0_tbs_sigalg(const X509 *x);

EVP_PKEY *X509_get0_pubkey(const X509 *x);
EVP_PKEY *X509_get_pubkey(X509 *x);
ASN1_BIT_STRING *X509_get0_pubkey_bitstr(const X509 *x);
int X509_certificate_type(const X509 *x, const EVP_PKEY *pubkey);

long X509_REQ_get_version(const X509_REQ *req);
int X509_REQ_set_version(X509_REQ *x, long version);
X509_NAME *X509_REQ_get_subject_name(const X509_REQ *req);
int X509_REQ_set_subject_name(X509_REQ *req, X509_NAME *name);
void X509_REQ_get0_signature(const X509_REQ *req, const ASN1_BIT_STRING **psig,
                             const X509_ALGOR **palg);
void X509_REQ_set0_signature(X509_REQ *req, ASN1_BIT_STRING *psig);
int X509_REQ_set1_signature_algo(X509_REQ *req, X509_ALGOR *palg);
int X509_REQ_get_signature_nid(const X509_REQ *req);
int i2d_re_X509_REQ_tbs(X509_REQ *req, unsigned char **pp);
int X509_REQ_set_pubkey(X509_REQ *x, EVP_PKEY *pkey);
EVP_PKEY *X509_REQ_get_pubkey(X509_REQ *req);
EVP_PKEY *X509_REQ_get0_pubkey(X509_REQ *req);
X509_PUBKEY *X509_REQ_get_X509_PUBKEY(X509_REQ *req);
int X509_REQ_extension_nid(int nid);
int *X509_REQ_get_extension_nids(void);
void X509_REQ_set_extension_nids(int *nids);
STACK_OF(X509_EXTENSION) *X509_REQ_get_extensions(X509_REQ *req);
int X509_REQ_add_extensions_nid(X509_REQ *req, STACK_OF(X509_EXTENSION) *exts,
                                int nid);
int X509_REQ_add_extensions(X509_REQ *req, STACK_OF(X509_EXTENSION) *exts);
int X509_REQ_get_attr_count(const X509_REQ *req);
int X509_REQ_get_attr_by_NID(const X509_REQ *req, int nid, int lastpos);
int X509_REQ_get_attr_by_OBJ(const X509_REQ *req, const ASN1_OBJECT *obj,
                             int lastpos);
X509_ATTRIBUTE *X509_REQ_get_attr(const X509_REQ *req, int loc);
X509_ATTRIBUTE *X509_REQ_delete_attr(X509_REQ *req, int loc);
int X509_REQ_add1_attr(X509_REQ *req, X509_ATTRIBUTE *attr);
int X509_REQ_add1_attr_by_OBJ(X509_REQ *req,
                              const ASN1_OBJECT *obj, int type,
                              const unsigned char *bytes, int len);
int X509_REQ_add1_attr_by_NID(X509_REQ *req,
                              int nid, int type,
                              const unsigned char *bytes, int len);
int X509_REQ_add1_attr_by_txt(X509_REQ *req,
                              const char *attrname, int type,
                              const unsigned char *bytes, int len);

int X509_CRL_set_version(X509_CRL *x, long version);
int X509_CRL_set_issuer_name(X509_CRL *x, X509_NAME *name);
int X509_CRL_set1_lastUpdate(X509_CRL *x, const ASN1_TIME *tm);
int X509_CRL_set1_nextUpdate(X509_CRL *x, const ASN1_TIME *tm);
int X509_CRL_sort(X509_CRL *crl);
int X509_CRL_up_ref(X509_CRL *crl);

# if OPENSSL_API_COMPAT < 0x10100000L
#  define X509_CRL_set_lastUpdate X509_CRL_set1_lastUpdate
#  define X509_CRL_set_nextUpdate X509_CRL_set1_nextUpdate
#endif

long X509_CRL_get_version(const X509_CRL *crl);
const ASN1_TIME *X509_CRL_get0_lastUpdate(const X509_CRL *crl);
const ASN1_TIME *X509_CRL_get0_nextUpdate(const X509_CRL *crl);
DEPRECATEDIN_1_1_0(ASN1_TIME *X509_CRL_get_lastUpdate(X509_CRL *crl))
DEPRECATEDIN_1_1_0(ASN1_TIME *X509_CRL_get_nextUpdate(X509_CRL *crl))
X509_NAME *X509_CRL_get_issuer(const X509_CRL *crl);
const STACK_OF(X509_EXTENSION) *X509_CRL_get0_extensions(const X509_CRL *crl);
STACK_OF(X509_REVOKED) *X509_CRL_get_REVOKED(X509_CRL *crl);
void X509_CRL_get0_signature(const X509_CRL *crl, const ASN1_BIT_STRING **psig,
                             const X509_ALGOR **palg);
int X509_CRL_get_signature_nid(const X509_CRL *crl);
int i2d_re_X509_CRL_tbs(X509_CRL *req, unsigned char **pp);

const ASN1_INTEGER *X509_REVOKED_get0_serialNumber(const X509_REVOKED *x);
int X509_REVOKED_set_serialNumber(X509_REVOKED *x, ASN1_INTEGER *serial);
const ASN1_TIME *X509_REVOKED_get0_revocationDate(const X509_REVOKED *x);
int X509_REVOKED_set_revocationDate(X509_REVOKED *r, ASN1_TIME *tm);
const STACK_OF(X509_EXTENSION) *
X509_REVOKED_get0_extensions(const X509_REVOKED *r);

X509_CRL *X509_CRL_diff(X509_CRL *base, X509_CRL *newer,
                        EVP_PKEY *skey, const EVP_MD *md, unsigned int flags);

int X509_REQ_check_private_key(X509_REQ *x509, EVP_PKEY *pkey);

int X509_check_private_key(const X509 *x509, const EVP_PKEY *pkey);
int X509_chain_check_suiteb(int *perror_depth,
                            X509 *x, STACK_OF(X509) *chain,
                            unsigned long flags);
int X509_CRL_check_suiteb(X509_CRL *crl, EVP_PKEY *pk, unsigned long flags);
STACK_OF(X509) *X509_chain_up_ref(STACK_OF(X509) *chain);

int X509_issuer_and_serial_cmp(const X509 *a, const X509 *b);
unsigned long X509_issuer_and_serial_hash(X509 *a);

int X509_issuer_name_cmp(const X509 *a, const X509 *b);
unsigned long X509_issuer_name_hash(X509 *a);

int X509_subject_name_cmp(const X509 *a, const X509 *b);
unsigned long X509_subject_name_hash(X509 *x);

# ifndef OPENSSL_NO_MD5
unsigned long X509_issuer_name_hash_old(X509 *a);
unsigned long X509_subject_name_hash_old(X509 *x);
# endif

int X509_cmp(const X509 *a, const X509 *b);
int X509_NAME_cmp(const X509_NAME *a, const X509_NAME *b);
unsigned long X509_NAME_hash(X509_NAME *x);
unsigned long X509_NAME_hash_old(X509_NAME *x);

int X509_CRL_cmp(const X509_CRL *a, const X509_CRL *b);
int X509_CRL_match(const X509_CRL *a, const X509_CRL *b);
int X509_aux_print(BIO *out, X509 *x, int indent);
# ifndef OPENSSL_NO_STDIO
int X509_print_ex_fp(FILE *bp, X509 *x, unsigned long nmflag,
                     unsigned long cflag);
int X509_print_fp(FILE *bp, X509 *x);
int X509_CRL_print_fp(FILE *bp, X509_CRL *x);
int X509_REQ_print_fp(FILE *bp, X509_REQ *req);
int X509_NAME_print_ex_fp(FILE *fp, const X509_NAME *nm, int indent,
                          unsigned long flags);
# endif

int X509_NAME_print(BIO *bp, const X509_NAME *name, int obase);
int X509_NAME_print_ex(BIO *out, const X509_NAME *nm, int indent,
                       unsigned long flags);
int X509_print_ex(BIO *bp, X509 *x, unsigned long nmflag,
                  unsigned long cflag);
int X509_print(BIO *bp, X509 *x);
int X509_ocspid_print(BIO *bp, X509 *x);
int X509_CRL_print_ex(BIO *out, X509_CRL *x, unsigned long nmflag);
int X509_CRL_print(BIO *bp, X509_CRL *x);
int X509_REQ_print_ex(BIO *bp, X509_REQ *x, unsigned long nmflag,
                      unsigned long cflag);
int X509_REQ_print(BIO *bp, X509_REQ *req);

int X509_NAME_entry_count(const X509_NAME *name);
int X509_NAME_get_text_by_NID(X509_NAME *name, int nid, char *buf, int len);
int X509_NAME_get_text_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj,
                              char *buf, int len);

/*
 * NOTE: you should be passing -1, not 0 as lastpos. The functions that use
 * lastpos, search after that position on.
 */
int X509_NAME_get_index_by_NID(X509_NAME *name, int nid, int lastpos);
int X509_NAME_get_index_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj,
                               int lastpos);
X509_NAME_ENTRY *X509_NAME_get_entry(const X509_NAME *name, int loc);
X509_NAME_ENTRY *X509_NAME_delete_entry(X509_NAME *name, int loc);
int X509_NAME_add_entry(X509_NAME *name, const X509_NAME_ENTRY *ne,
                        int loc, int set);
int X509_NAME_add_entry_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
int X509_NAME_add_entry_by_NID(X509_NAME *name, int nid, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
X509_NAME_ENTRY *X509_NAME_ENTRY_create_by_txt(X509_NAME_ENTRY **ne,
                                               const char *field, int type,
                                               const unsigned char *bytes,
                                               int len);
X509_NAME_ENTRY *X509_NAME_ENTRY_create_by_NID(X509_NAME_ENTRY **ne, int nid,
                                               int type,
                                               const unsigned char *bytes,
                                               int len);
int X509_NAME_add_entry_by_txt(X509_NAME *name, const char *field, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set);
X509_NAME_ENTRY *X509_NAME_ENTRY_create_by_OBJ(X509_NAME_ENTRY **ne,
                                               const ASN1_OBJECT *obj, int type,
                                               const unsigned char *bytes,
                                               int len);
int X509_NAME_ENTRY_set_object(X509_NAME_ENTRY *ne, const ASN1_OBJECT *obj);
int X509_NAME_ENTRY_set_data(X509_NAME_ENTRY *ne, int type,
                             const unsigned char *bytes, int len);
ASN1_OBJECT *X509_NAME_ENTRY_get_object(const X509_NAME_ENTRY *ne);
ASN1_STRING * X509_NAME_ENTRY_get_data(const X509_NAME_ENTRY *ne);
int X509_NAME_ENTRY_set(const X509_NAME_ENTRY *ne);

int X509_NAME_get0_der(X509_NAME *nm, const unsigned char **pder,
                       size_t *pderlen);

int X509v3_get_ext_count(const STACK_OF(X509_EXTENSION) *x);
int X509v3_get_ext_by_NID(const STACK_OF(X509_EXTENSION) *x,
                          int nid, int lastpos);
int X509v3_get_ext_by_OBJ(const STACK_OF(X509_EXTENSION) *x,
                          const ASN1_OBJECT *obj, int lastpos);
int X509v3_get_ext_by_critical(const STACK_OF(X509_EXTENSION) *x,
                               int crit, int lastpos);
X509_EXTENSION *X509v3_get_ext(const STACK_OF(X509_EXTENSION) *x, int loc);
X509_EXTENSION *X509v3_delete_ext(STACK_OF(X509_EXTENSION) *x, int loc);
STACK_OF(X509_EXTENSION) *X509v3_add_ext(STACK_OF(X509_EXTENSION) **x,
                                         X509_EXTENSION *ex, int loc);

int X509_get_ext_count(const X509 *x);
int X509_get_ext_by_NID(const X509 *x, int nid, int lastpos);
int X509_get_ext_by_OBJ(const X509 *x, const ASN1_OBJECT *obj, int lastpos);
int X509_get_ext_by_critical(const X509 *x, int crit, int lastpos);
X509_EXTENSION *X509_get_ext(const X509 *x, int loc);
X509_EXTENSION *X509_delete_ext(X509 *x, int loc);
int X509_add_ext(X509 *x, X509_EXTENSION *ex, int loc);
void *X509_get_ext_d2i(const X509 *x, int nid, int *crit, int *idx);
int X509_add1_ext_i2d(X509 *x, int nid, void *value, int crit,
                      unsigned long flags);

int X509_CRL_get_ext_count(const X509_CRL *x);
int X509_CRL_get_ext_by_NID(const X509_CRL *x, int nid, int lastpos);
int X509_CRL_get_ext_by_OBJ(const X509_CRL *x, const ASN1_OBJECT *obj,
                            int lastpos);
int X509_CRL_get_ext_by_critical(const X509_CRL *x, int crit, int lastpos);
X509_EXTENSION *X509_CRL_get_ext(const X509_CRL *x, int loc);
X509_EXTENSION *X509_CRL_delete_ext(X509_CRL *x, int loc);
int X509_CRL_add_ext(X509_CRL *x, X509_EXTENSION *ex, int loc);
void *X509_CRL_get_ext_d2i(const X509_CRL *x, int nid, int *crit, int *idx);
int X509_CRL_add1_ext_i2d(X509_CRL *x, int nid, void *value, int crit,
                          unsigned long flags);

int X509_REVOKED_get_ext_count(const X509_REVOKED *x);
int X509_REVOKED_get_ext_by_NID(const X509_REVOKED *x, int nid, int lastpos);
int X509_REVOKED_get_ext_by_OBJ(const X509_REVOKED *x, const ASN1_OBJECT *obj,
                                int lastpos);
int X509_REVOKED_get_ext_by_critical(const X509_REVOKED *x, int crit,
                                     int lastpos);
X509_EXTENSION *X509_REVOKED_get_ext(const X509_REVOKED *x, int loc);
X509_EXTENSION *X509_REVOKED_delete_ext(X509_REVOKED *x, int loc);
int X509_REVOKED_add_ext(X509_REVOKED *x, X509_EXTENSION *ex, int loc);
void *X509_REVOKED_get_ext_d2i(const X509_REVOKED *x, int nid, int *crit,
                               int *idx);
int X509_REVOKED_add1_ext_i2d(X509_REVOKED *x, int nid, void *value, int crit,
                              unsigned long flags);

X509_EXTENSION *X509_EXTENSION_create_by_NID(X509_EXTENSION **ex,
                                             int nid, int crit,
                                             ASN1_OCTET_STRING *data);
X509_EXTENSION *X509_EXTENSION_create_by_OBJ(X509_EXTENSION **ex,
                                             const ASN1_OBJECT *obj, int crit,
                                             ASN1_OCTET_STRING *data);
int X509_EXTENSION_set_object(X509_EXTENSION *ex, const ASN1_OBJECT *obj);
int X509_EXTENSION_set_critical(X509_EXTENSION *ex, int crit);
int X509_EXTENSION_set_data(X509_EXTENSION *ex, ASN1_OCTET_STRING *data);
ASN1_OBJECT *X509_EXTENSION_get_object(X509_EXTENSION *ex);
ASN1_OCTET_STRING *X509_EXTENSION_get_data(X509_EXTENSION *ne);
int X509_EXTENSION_get_critical(const X509_EXTENSION *ex);

int X509at_get_attr_count(const STACK_OF(X509_ATTRIBUTE) *x);
int X509at_get_attr_by_NID(const STACK_OF(X509_ATTRIBUTE) *x, int nid,
                           int lastpos);
int X509at_get_attr_by_OBJ(const STACK_OF(X509_ATTRIBUTE) *sk,
                           const ASN1_OBJECT *obj, int lastpos);
X509_ATTRIBUTE *X509at_get_attr(const STACK_OF(X509_ATTRIBUTE) *x, int loc);
X509_ATTRIBUTE *X509at_delete_attr(STACK_OF(X509_ATTRIBUTE) *x, int loc);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr(STACK_OF(X509_ATTRIBUTE) **x,
                                           X509_ATTRIBUTE *attr);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr_by_OBJ(STACK_OF(X509_ATTRIBUTE)
                                                  **x, const ASN1_OBJECT *obj,
                                                  int type,
                                                  const unsigned char *bytes,
                                                  int len);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr_by_NID(STACK_OF(X509_ATTRIBUTE)
                                                  **x, int nid, int type,
                                                  const unsigned char *bytes,
                                                  int len);
STACK_OF(X509_ATTRIBUTE) *X509at_add1_attr_by_txt(STACK_OF(X509_ATTRIBUTE)
                                                  **x, const char *attrname,
                                                  int type,
                                                  const unsigned char *bytes,
                                                  int len);
void *X509at_get0_data_by_OBJ(STACK_OF(X509_ATTRIBUTE) *x,
                              const ASN1_OBJECT *obj, int lastpos, int type);
X509_ATTRIBUTE *X509_ATTRIBUTE_create_by_NID(X509_ATTRIBUTE **attr, int nid,
                                             int atrtype, const void *data,
                                             int len);
X509_ATTRIBUTE *X509_ATTRIBUTE_create_by_OBJ(X509_ATTRIBUTE **attr,
                                             const ASN1_OBJECT *obj,
                                             int atrtype, const void *data,
                                             int len);
X509_ATTRIBUTE *X509_ATTRIBUTE_create_by_txt(X509_ATTRIBUTE **attr,
                                             const char *atrname, int type,
                                             const unsigned char *bytes,
                                             int len);
int X509_ATTRIBUTE_set1_object(X509_ATTRIBUTE *attr, const ASN1_OBJECT *obj);
int X509_ATTRIBUTE_set1_data(X509_ATTRIBUTE *attr, int attrtype,
                             const void *data, int len);
void *X509_ATTRIBUTE_get0_data(X509_ATTRIBUTE *attr, int idx, int atrtype,
                               void *data);
int X509_ATTRIBUTE_count(const X509_ATTRIBUTE *attr);
ASN1_OBJECT *X509_ATTRIBUTE_get0_object(X509_ATTRIBUTE *attr);
ASN1_TYPE *X509_ATTRIBUTE_get0_type(X509_ATTRIBUTE *attr, int idx);

int EVP_PKEY_get_attr_count(const EVP_PKEY *key);
int EVP_PKEY_get_attr_by_NID(const EVP_PKEY *key, int nid, int lastpos);
int EVP_PKEY_get_attr_by_OBJ(const EVP_PKEY *key, const ASN1_OBJECT *obj,
                             int lastpos);
X509_ATTRIBUTE *EVP_PKEY_get_attr(const EVP_PKEY *key, int loc);
X509_ATTRIBUTE *EVP_PKEY_delete_attr(EVP_PKEY *key, int loc);
int EVP_PKEY_add1_attr(EVP_PKEY *key, X509_ATTRIBUTE *attr);
int EVP_PKEY_add1_attr_by_OBJ(EVP_PKEY *key,
                              const ASN1_OBJECT *obj, int type,
                              const unsigned char *bytes, int len);
int EVP_PKEY_add1_attr_by_NID(EVP_PKEY *key,
                              int nid, int type,
                              const unsigned char *bytes, int len);
int EVP_PKEY_add1_attr_by_txt(EVP_PKEY *key,
                              const char *attrname, int type,
                              const unsigned char *bytes, int len);

int X509_verify_cert(X509_STORE_CTX *ctx);

/* lookup a cert from a X509 STACK */
X509 *X509_find_by_issuer_and_serial(STACK_OF(X509) *sk, X509_NAME *name,
                                     ASN1_INTEGER *serial);
X509 *X509_find_by_subject(STACK_OF(X509) *sk, X509_NAME *name);

DECLARE_ASN1_FUNCTIONS(PBEPARAM)
DECLARE_ASN1_FUNCTIONS(PBE2PARAM)
DECLARE_ASN1_FUNCTIONS(PBKDF2PARAM)
#ifndef OPENSSL_NO_SCRYPT
DECLARE_ASN1_FUNCTIONS(SCRYPT_PARAMS)
#endif

int PKCS5_pbe_set0_algor(X509_ALGOR *algor, int alg, int iter,
                         const unsigned char *salt, int saltlen);

X509_ALGOR *PKCS5_pbe_set(int alg, int iter,
                          const unsigned char *salt, int saltlen);
X509_ALGOR *PKCS5_pbe2_set(const EVP_CIPHER *cipher, int iter,
                           unsigned char *salt, int saltlen);
X509_ALGOR *PKCS5_pbe2_set_iv(const EVP_CIPHER *cipher, int iter,
                              unsigned char *salt, int saltlen,
                              unsigned char *aiv, int prf_nid);

#ifndef OPENSSL_NO_SCRYPT
X509_ALGOR *PKCS5_pbe2_set_scrypt(const EVP_CIPHER *cipher,
                                  const unsigned char *salt, int saltlen,
                                  unsigned char *aiv, uint64_t N, uint64_t r,
                                  uint64_t p);
#endif

X509_ALGOR *PKCS5_pbkdf2_set(int iter, unsigned char *salt, int saltlen,
                             int prf_nid, int keylen);

/* PKCS#8 utilities */

DECLARE_ASN1_FUNCTIONS(PKCS8_PRIV_KEY_INFO)

EVP_PKEY *EVP_PKCS82PKEY(const PKCS8_PRIV_KEY_INFO *p8);
PKCS8_PRIV_KEY_INFO *EVP_PKEY2PKCS8(EVP_PKEY *pkey);

int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv, ASN1_OBJECT *aobj,
                    int version, int ptype, void *pval,
                    unsigned char *penc, int penclen);
int PKCS8_pkey_get0(const ASN1_OBJECT **ppkalg,
                    const unsigned char **pk, int *ppklen,
                    const X509_ALGOR **pa, const PKCS8_PRIV_KEY_INFO *p8);

const STACK_OF(X509_ATTRIBUTE) *
PKCS8_pkey_get0_attrs(const PKCS8_PRIV_KEY_INFO *p8);
int PKCS8_pkey_add1_attr_by_NID(PKCS8_PRIV_KEY_INFO *p8, int nid, int type,
                                const unsigned char *bytes, int len);

int X509_PUBKEY_set0_param(X509_PUBKEY *pub, ASN1_OBJECT *aobj,
                           int ptype, void *pval,
                           unsigned char *penc, int penclen);
int X509_PUBKEY_get0_param(ASN1_OBJECT **ppkalg,
                           const unsigned char **pk, int *ppklen,
                           X509_ALGOR **pa, X509_PUBKEY *pub);

int X509_check_trust(X509 *x, int id, int flags);
int X509_TRUST_get_count(void);
X509_TRUST *X509_TRUST_get0(int idx);
int X509_TRUST_get_by_id(int id);
int X509_TRUST_add(int id, int flags, int (*ck) (X509_TRUST *, X509 *, int),
                   const char *name, int arg1, void *arg2);
void X509_TRUST_cleanup(void);
int X509_TRUST_get_flags(const X509_TRUST *xp);
char *X509_TRUST_get0_name(const X509_TRUST *xp);
int X509_TRUST_get_trust(const X509_TRUST *xp);

# ifdef  __cplusplus
}
# endif
#endif
