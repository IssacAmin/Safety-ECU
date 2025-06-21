/*file : sign_verify.c*/

#include "sign_verify.h"

ecdsa_verifier_t ctx;

uint8_t signVerifier_init(const uint8_t *raw_pubkey, size_t raw_pubkey_len) 
{
    int ret;
    mbedtls_ecdsa_init(&ctx.ecdsa);
    mbedtls_sha256_init(&ctx.sha256);

    if ((ret = mbedtls_ecp_group_load(&ctx.ecdsa.grp, MBEDTLS_ECP_DP_SECP256R1)) != 0)
        return 0U;

    if ((ret = mbedtls_ecp_point_read_binary(&ctx.ecdsa.grp, &ctx.ecdsa.Q, raw_pubkey, raw_pubkey_len)) != 0)
        return 0U;

    mbedtls_sha256_starts(&ctx.sha256, 0);

    return 1U;
}

void signVerifier_updateHash(const uint8_t *chunk, size_t chunk_len) 
{
    mbedtls_sha256_update(&ctx.sha256, chunk, chunk_len);
}

uint8_t signVerifier_finalizeCheckSignature(const uint8_t *sig_der, size_t sig_len) 
{
    unsigned char hash[32];
    mbedtls_sha256_finish(&ctx.sha256, hash);
    return mbedtls_ecdsa_read_signature(&ctx.ecdsa, hash, sizeof(hash), sig_der, sig_len)? 0U: 1U;
}

void signVerifier_deInit() {
    mbedtls_ecdsa_free(&ctx.ecdsa);
    mbedtls_sha256_free(&ctx.sha256);
}