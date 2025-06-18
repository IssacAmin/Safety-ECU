/*
 * flags.c
 *
 *  Created on: Mar 5, 2025
 *      Author: Issac Amin
 */
#include <stdint.h>

const uint32_t flags_section[4096] __attribute__((section(".flags"))) = {
    0x00000000,  /*programming session*/
    0x00000000,  /*uds last security level*/
    0x00000000,  /*current app*/
    0x00000001,  /*flash bank A valid*/
    0x00000000,  /*flash bank A erased*/
    0x00000000,  /*flash bank B valid*/
    0x00000000,  /*flash bank B erased*/
    0x00000000,  /*flashing in progress*/
    0x00000000,   /*reset during flash*/
	0x5a5a5a5a   /*test flag*/
};

const uint32_t appALength __attribute__((section(".appAMetaData"))) = 0x14e80;
const uint16_t appACRC __attribute__((section(".appAMetaData"))) = 0x1149;
