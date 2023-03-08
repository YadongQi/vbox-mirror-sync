#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include <libtpms/tpm_library.h>
#include <libtpms/tpm_error.h>
#include <libtpms/tpm_memory.h>

static void dump_array(const char *h, const unsigned char *d, size_t dlen)
{
    size_t i;

    fprintf(stderr, "%s\n", h);
    for (i = 0; i < dlen; i++) {
        fprintf(stderr, "%02x ", d[i]);
        if ((i & 0xf) == 0xf)
            fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
}

int main(void)
{
    unsigned char *rbuffer = NULL;
    uint32_t rlength;
    uint32_t rtotal = 0;
    TPM_RESULT res;
    int ret = 1;
    unsigned char *perm = NULL;
    uint32_t permlen = 0;
    unsigned char *vol = NULL;
    uint32_t vollen = 0;
    unsigned char startup[] = {
        0x80, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00,
        0x01, 0x44, 0x00, 0x00
    };

    unsigned char tpm2_pcr_read[] = {
                0x80, 0x01,             // TPM_ST_NO_SESSIONS
                0x00, 0x00, 0x00, 0x26, // command size
                0x00, 0x00, 0x01, 0x7e, // TPM_CC_PCR_Read
                0x00, 0x00, 0x00, 0x04, // TPML_PCR_SELECTION
                0x00, 0x04,             // TPMI_ALG_HASH, SHA1=4
                0x03,                   // size of the select
                0x01, 0x00, 0x10,       // pcrSelect
                0x00, 0x0b,             // TPMI_ALG_HASH, SHA256=11
                0x03,                   // size of the select
                0x01, 0x00, 0x10,       // pcrSelect
                0x00, 0x0c,             // TPMI_ALG_HASH, SHA384=12
                0x03,                   // size of the select
                0x01, 0x00, 0x10,       // pcrSelect
                0x00, 0x0d,             // TPMI_ALG_HASH, SHA512=13
                0x03,                   // size of the select
                0x01, 0x00, 0x10        // pcrSelect
    };
    const unsigned char tpm2_pcr_read_exp_resp[] = {
        0x80, 0x01, 0x00, 0x00, 0x01, 0x86, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
        0x00, 0x04, 0x00, 0x04, 0x03, 0x01, 0x00, 0x10,
        0x00, 0x0b, 0x03, 0x01, 0x00, 0x10, 0x00, 0x0c,
        0x03, 0x01, 0x00, 0x10, 0x00, 0x0d, 0x03, 0x01,
        0x00, 0x10, 0x00, 0x00, 0x00, 0x08, 0x00, 0x14,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x30,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x30, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    };

    res = TPMLIB_ChooseTPMVersion(TPMLIB_TPM_VERSION_2);
    if (res) {
        fprintf(stderr, "TPMLIB_ChooseTPMVersion() failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_MainInit();
    if (res) {
        fprintf(stderr, "TPMLIB_MainInit() failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_Process(&rbuffer, &rlength, &rtotal, startup, sizeof(startup));
    if (res) {
        fprintf(stderr, "TPMLIB_Process(Startup) failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_Process(&rbuffer, &rlength, &rtotal,
                         tpm2_pcr_read, sizeof(tpm2_pcr_read));
    if (res) {
        fprintf(stderr, "TPMLIB_Process(TPM2_PCR_Read) failed: 0x%02x\n",
                res);
        goto exit;
    }

    if (rlength != sizeof(tpm2_pcr_read_exp_resp)) {
        fprintf(stderr, "Expected response is %zu bytes, but got %u.\n",
                sizeof(tpm2_pcr_read_exp_resp), rlength);
        goto exit;
    }

    if (memcmp(rbuffer, tpm2_pcr_read_exp_resp, rlength)) {
        fprintf(stderr, "Expected response is different than received one.\n");
        dump_array("actual:", rbuffer, rlength);
        dump_array("expected:", tpm2_pcr_read_exp_resp, sizeof(tpm2_pcr_read_exp_resp));
        goto exit;
    }

    /* Extend PCR 10 with string '1234' */
    unsigned char tpm2_pcr_extend[] = {
        0x80, 0x02, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00,
        0x01, 0x82, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00,
        0x00, 0x09, 0x40, 0x00, 0x00, 0x09, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
        0x0b, 0x31, 0x32, 0x33, 0x34, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00
    };

    res = TPMLIB_Process(&rbuffer, &rlength, &rtotal,
                         tpm2_pcr_extend, sizeof(tpm2_pcr_extend));
    if (res != TPM_SUCCESS) {
        fprintf(stderr,
                "TPMLIB_Process(TPM2_PCR_Extend) failed: 0x%02x\n", res);
        goto exit;
    }

    /* Read value of PCR 10 */
    unsigned char tpm2_pcr10_read[] = {
        0x80, 0x01, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
        0x01, 0x7e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0b,
        0x03, 0x00, 0x04, 0x00
    };

    res = TPMLIB_Process(&rbuffer, &rlength, &rtotal,
                         tpm2_pcr10_read, sizeof(tpm2_pcr10_read));
    if (res) {
        fprintf(stderr, "TPMLIB_Process(PCR10 Read) failed: 0x%02x\n", res);
        goto exit;
    }

    const unsigned char tpm2_pcr10_read_resp[] = {
        0x80, 0x01, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x0b, 0x03, 0x00, 0x04, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x1f, 0x7f,
        0xb1, 0x00, 0xe1, 0xb2, 0xd1, 0x95, 0x19, 0x4b,
        0x58, 0xe7, 0xc3, 0x09, 0xa5, 0x86, 0x30, 0x7c,
        0x34, 0x64, 0x19, 0xdc, 0xb2, 0xd5, 0x9f, 0x52,
        0x2b, 0xe7, 0xf0, 0x94, 0x51, 0x01
    };

    if (memcmp(tpm2_pcr10_read_resp, rbuffer, rlength)) {
        fprintf(stderr, "TPM2_PCRRead(PCR10) did not return expected result\n");
        dump_array("actual:", rbuffer, rlength);
        dump_array("expected:", tpm2_pcr10_read_resp, sizeof(tpm2_pcr10_read_resp));
        goto exit;
    }

    /* save permanent and volatile state */
    res = TPMLIB_GetState(TPMLIB_STATE_PERMANENT, &perm, &permlen);
    if (res) {
        fprintf(stderr, "TPMLIB_GetState(PERMANENT) failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_GetState(TPMLIB_STATE_VOLATILE, &vol, &vollen);
    if (res) {
        fprintf(stderr, "TPMLIB_GetState(VOLATILE) failed: 0x%02x\n", res);
        goto exit;
    }

    /* terminate and resume where we left off */
    TPMLIB_Terminate();

    res = TPMLIB_SetState(TPMLIB_STATE_PERMANENT, perm, permlen);
    if (res) {
        fprintf(stderr, "TPMLIB_SetState(PERMANENT) failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_SetState(TPMLIB_STATE_VOLATILE, vol, vollen);
    if (res) {
        fprintf(stderr, "TPMLIB_SetState(VOLATILE) failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_MainInit();
    if (res) {
        fprintf(stderr, "TPMLIB_MainInit() after SetState failed: 0x%02x\n", res);
        goto exit;
    }

    res = TPMLIB_Process(&rbuffer, &rlength, &rtotal,
                         tpm2_pcr10_read, sizeof(tpm2_pcr10_read));
    if (res) {
        fprintf(stderr,
                "TPMLIB_Process(PCR10 Read) after SetState failedL 0x%02x\n",
                res);
        goto exit;
    }

    if (memcmp(tpm2_pcr10_read_resp, rbuffer, rlength)) {
        fprintf(stderr,
                "TPM2_PCRRead(PCR10) after SetState did not return expected "
                "result\n");
        goto exit;
    }

    unsigned char tpm2_shutdown[] = {
         0x80, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00,
         0x01, 0x45, 0x00, 0x00
    };

    res = TPMLIB_Process(&rbuffer, &rlength, &rtotal,
                         tpm2_shutdown, sizeof(tpm2_shutdown));
    if (res) {
        fprintf(stderr,
                "TPMLIB_Process(Shutdown) after SetState failed: 0x%02x\n",
                res);
        goto exit;
    }

    unsigned char tpm2_shutdown_resp[] = {
         0x80, 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00,
         0x00, 0x00
    };

    if (memcmp(tpm2_shutdown_resp, rbuffer, rlength)) {
        fprintf(stderr,
                "TPM2_PCRRead(Shutdown) after SetState did not return expected "
                "result\n");
        goto exit;
    }

    ret = 0;

    fprintf(stdout, "OK\n");

exit:
    free(perm);
    free(vol);
    TPMLIB_Terminate();
    TPM_Free(rbuffer);

    return ret;
}
