/*
 * crc.h
 *
 *  Created on: Mar 5, 2025
 *      Author: Issac Amin
 */

#ifndef CRC_H_
#define CRC_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Fls.h"
#include "flashbankConfig.h"

/*
 * #define CRC_POLY_xxxx
 *
 * The constants of the form CRC_POLY_xxxx define the polynomials for some well
 * known CRC calculations.
 */

#define		CRC_POLY_CCITT		0x1021



/*
 * Prototype list of global functions
 */

uint16_t		crc_ccitt_generic	( const unsigned char *input_str, size_t num_bytes, uint16_t start_value );
uint16_t		update_crc_ccitt	( uint16_t crc, unsigned char c);
bool memory_check(uint32_t start_address, uint32_t memory_length,uint16_t stored_crc , uint8_t app_sector_buffer[]);
#endif /* CRC_H_ */
