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
    0x00000001,  /*current app*/
    0x00000000,  /*flash bank A valid*/
    0x00000000,  /*flash bank A erased*/
    0x00000000,  /*flash bank B valid*/
    0x00000000,  /*flash bank B erased*/
    0x00000000,  /*flashing in progress*/
    0x00000000   /*reset during flash*/
};

const uint8_t appACRC[2] __attribute__((section(".appACRC"))) = {0xbd, 0xc5}; //TODO: correct the crc and add applength first
