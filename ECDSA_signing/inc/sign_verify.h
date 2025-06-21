#ifndef FBL_UPDATE_SIGNATURE_VERIFIER_H_
#define FBL_UPDATE_SIGNATURE_VERIFIER_H_

#include "mbedtls/ecdsa.h"
#include "mbedtls/ecp.h"
#include "mbedtls/sha256.h"
#include <stddef.h>
#include <stdint.h>

typedef struct {
    mbedtls_ecdsa_context ecdsa;
    mbedtls_sha256_context sha256;
} ecdsa_verifier_t;

uint8_t signVerifier_init(const uint8_t *raw_pubkey, size_t raw_pubkey_len); 
void signVerifier_updateHash(const uint8_t *chunk, size_t chunk_len);
uint8_t signVerifier_finalizeCheckSignature(const uint8_t *sig_der, size_t sig_len);
void signVerifier_deInit();

#endif