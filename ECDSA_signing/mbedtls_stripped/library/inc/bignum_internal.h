/**
<<<<<<< HEAD
 * \file bignum_internal.h
 *
 * \brief Internal-only bignum public-key cryptosystem API.
 *
 * This file declares bignum-related functions that are to be used
 * only from within the Mbed TLS library itself.
 *
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */
#ifndef MBEDTLS_BIGNUM_INTERNAL_H
#define MBEDTLS_BIGNUM_INTERNAL_H

/**
 * \brief          Perform a modular exponentiation: X = A^E mod N
 *
 * \warning        This function is not constant time with respect to \p E (the exponent).
 *
 * \param X        The destination MPI. This must point to an initialized MPI.
 *                 This must not alias E or N.
 * \param A        The base of the exponentiation.
 *                 This must point to an initialized MPI.
 * \param E        The exponent MPI. This must point to an initialized MPI.
 * \param N        The base for the modular reduction. This must point to an
 *                 initialized MPI.
 * \param prec_RR  A helper MPI depending solely on \p N which can be used to
 *                 speed-up multiple modular exponentiations for the same value
 *                 of \p N. This may be \c NULL. If it is not \c NULL, it must
 *                 point to an initialized MPI. If it hasn't been used after
 *                 the call to mbedtls_mpi_init(), this function will compute
 *                 the helper value and store it in \p prec_RR for reuse on
 *                 subsequent calls to this function. Otherwise, the function
 *                 will assume that \p prec_RR holds the helper value set by a
 *                 previous call to mbedtls_mpi_exp_mod(), and reuse it.
 *
 * \return         \c 0 if successful.
 * \return         #MBEDTLS_ERR_MPI_ALLOC_FAILED if a memory allocation failed.
 * \return         #MBEDTLS_ERR_MPI_BAD_INPUT_DATA if \c N is negative or
 *                 even, or if \c E is negative.
 * \return         Another negative error code on different kinds of failures.
 *
 */
int mbedtls_mpi_exp_mod_unsafe(mbedtls_mpi *X, const mbedtls_mpi *A,
                               const mbedtls_mpi *E, const mbedtls_mpi *N,
                               mbedtls_mpi *prec_RR);

#endif /* bignum_internal.h */
=======
 *  Low level bignum functions
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */

#ifndef MBEDTLS_BIGNUM_INTERNAL_H
#define MBEDTLS_BIGNUM_INTERNAL_H

#include "mbedtls/bignum.h"

/**
 * \brief Calculate the square of the Montgomery constant. (Needed
 *        for conversion and operations in Montgomery form.)
 *
 * \param[out] X  A pointer to the result of the calculation of
 *                the square of the Montgomery constant:
 *                2^{2*n*biL} mod N.
 * \param[in]  N  Little-endian presentation of the modulus, which must be odd.
 *
 * \return        0 if successful.
 * \return        #MBEDTLS_ERR_MPI_ALLOC_FAILED if there is not enough space
 *                to store the value of Montgomery constant squared.
 * \return        #MBEDTLS_ERR_MPI_DIVISION_BY_ZERO if \p N modulus is zero.
 * \return        #MBEDTLS_ERR_MPI_NEGATIVE_VALUE if \p N modulus is negative.
 */
int mbedtls_mpi_get_mont_r2_unsafe(mbedtls_mpi *X,
                                   const mbedtls_mpi *N);

/**
 * \brief Calculate initialisation value for fast Montgomery modular
 *        multiplication
 *
 * \param[in] N  Little-endian presentation of the modulus. This must have
 *               at least one limb.
 *
 * \return       The initialisation value for fast Montgomery modular multiplication
 */
mbedtls_mpi_uint mbedtls_mpi_montmul_init(const mbedtls_mpi_uint *N);

/** Montgomery multiplication: A = A * B * R^-1 mod N  (HAC 14.36)
 *
 * \param[in,out]   A   One of the numbers to multiply.
 *                      It must have at least as many limbs as N
 *                      (A->n >= N->n), and any limbs beyond n are ignored.
 *                      On successful completion, A contains the result of
 *                      the multiplication A * B * R^-1 mod N where
 *                      R = (2^ciL)^n.
 * \param[in]       B   One of the numbers to multiply.
 *                      It must be nonzero and must not have more limbs than N
 *                      (B->n <= N->n).
 * \param[in]       N   The modulo. N must be odd.
 * \param           mm  The value calculated by
 *                      `mbedtls_mpi_montg_init(&mm, N)`.
 *                      This is -N^-1 mod 2^ciL.
 * \param[in,out]   T   A bignum for temporary storage.
 *                      It must be at least twice the limb size of N plus 2
 *                      (T->n >= 2 * (N->n + 1)).
 *                      Its initial content is unused and
 *                      its final content is indeterminate.
 *                      Note that unlike the usual convention in the library
 *                      for `const mbedtls_mpi*`, the content of T can change.
 */
void mbedtls_mpi_montmul(mbedtls_mpi *A,
                         const mbedtls_mpi *B,
                         const mbedtls_mpi *N,
                         mbedtls_mpi_uint mm,
                         const mbedtls_mpi *T);

#endif /* MBEDTLS_BIGNUM_INTERNAL_H */
>>>>>>> 92eb519ef88cdabe32536fc75c44a9f25f758ce7
