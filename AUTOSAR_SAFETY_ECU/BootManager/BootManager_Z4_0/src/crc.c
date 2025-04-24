/*
 * crc.c
 *
 *  Created on: Mar 5, 2025
 *      Author: Issac Amin
 */

#include "crc.h"

void flsWaitUntilJobDone(void);


static void             init_crcccitt_tab( void );

static bool             crc_tabccitt_init       = false;
static uint16_t         crc_tabccitt[256];


/*
 * uint16_t crc_ccitt_ffff( const unsigned char *input_str, size_t num_bytes );
 *
 * The function crc_ccitt_ffff() performs a one-pass calculation of the CCITT
 * CRC for a byte string that has been passed as a parameter. The initial value
 * 0xffff is used for the CRC.
 */



/*
 * static uint16_t crc_ccitt_generic( const unsigned char *input_str, size_t num_bytes, uint16_t start_value );
 *
 * The function crc_ccitt_generic() is a generic implementation of the CCITT
 * algorithm for a one-pass calculation of the CRC for a byte string. The
 * function accepts an initial start value for the crc.
 */

uint16_t crc_ccitt_generic( const unsigned char *input_str, size_t num_bytes, uint16_t start_value ) {

	uint16_t crc;
	const unsigned char *ptr;
	size_t a;

	if ( ! crc_tabccitt_init ) init_crcccitt_tab();

	crc = start_value;
	ptr = input_str;

	if ( ptr != NULL ) for (a=0; a<num_bytes; a++) {

		crc = (crc << 8) ^ crc_tabccitt[ ((crc >> 8) ^ (uint16_t) *ptr++) & 0x00FF ];
	}

	return crc;

}  /* crc_ccitt_generic */

/*
 * uint16_t update_crc_ccitt( uint16_t crc, unsigned char c );
 *
 * The function update_crc_ccitt() calculates a new CRC-CCITT value based on
 * the previous value of the CRC and the next byte of the data to be checked.
 */

uint16_t update_crc_ccitt( uint16_t crc, unsigned char c ) {

	if ( ! crc_tabccitt_init ) init_crcccitt_tab();

	return (crc << 8) ^ crc_tabccitt[ ((crc >> 8) ^ (uint16_t) c) & 0x00FF ];

}  /* update_crc_ccitt */

/*
 * static void init_crcccitt_tab( void );
 *
 * For optimal performance, the routine to calculate the CRC-CCITT uses a
 * lookup table with pre-compiled values that can be directly applied in the
 * XOR action. This table is created at the first call of the function by the
 * init_crcccitt_tab() routine.
 */

static void init_crcccitt_tab( void ) {

	uint16_t i;
	uint16_t j;
	uint16_t crc;
	uint16_t c;

	for (i=0; i<256; i++) {

		crc = 0;
		c   = i << 8;

		for (j=0; j<8; j++) {

			if ( (crc ^ c) & 0x8000 ) crc = ( crc << 1 ) ^ CRC_POLY_CCITT;
			else                      crc =   crc << 1;

			c = c << 1;
		}

		crc_tabccitt[i] = crc;
	}

	crc_tabccitt_init = true;

}  /* init_crcccitt_tab */



bool memory_check(uint32_t start_address, uint32_t memory_length, uint16_t stored_crc, uint8_t * app_sector_buffer){
	uint16_t computed_crc;
	Std_ReturnType fls_ret;

	if(memory_length <= SECTOR_SIZE)
	{
		fls_ret = Fls_Read(start_address, app_sector_buffer, memory_length);
		flsWaitUntilJobDone();

		computed_crc = crc_ccitt_generic( app_sector_buffer , memory_length, CRC_CCITT_START_VALUE);
	}
	else
	{
		uint8_t num_of_sectors = ceil((double)memory_length / SECTOR_SIZE);
		uint8_t i = 0;
		uint16_t crc_calculation_size = 0;
		/*
		 * Check if the memory_length is page_aligned and padded
		 */
		if(memory_length % PAGE_SIZE != 0)
			return false;


		for(i = 0; i < num_of_sectors;i++)
		{
			if(i == num_of_sectors - 1)
			{
				uint16_t final_read_size;
			    if(memory_length % SECTOR_SIZE != 0)
					final_read_size = memory_length  % SECTOR_SIZE;
			    else{
					 final_read_size = SECTOR_SIZE;
				}

				fls_ret = Fls_Read(start_address + (SECTOR_SIZE * i), app_sector_buffer, final_read_size);
				flsWaitUntilJobDone();

				crc_calculation_size = final_read_size;
			}
			else
			{
				fls_ret = Fls_Read(start_address + (SECTOR_SIZE * i), app_sector_buffer, SECTOR_SIZE);
				flsWaitUntilJobDone();

				crc_calculation_size = (SECTOR_SIZE);
			}
			if(i == 0)
			{
				computed_crc = crc_ccitt_generic(app_sector_buffer, SECTOR_SIZE, CRC_CCITT_START_VALUE);
				continue;
			}
			int j = 0;
			for(j = 0; j < crc_calculation_size;j++)
			{
				computed_crc = update_crc_ccitt(computed_crc, app_sector_buffer[j]);
			}
		}
	}

	if(stored_crc == computed_crc)
		return true;
	return false;
}
