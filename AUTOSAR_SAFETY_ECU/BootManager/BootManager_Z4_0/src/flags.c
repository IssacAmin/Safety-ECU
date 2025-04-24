/*
 * flags.c
 *
 *  Created on: Mar 5, 2025
 *      Author: Issac Amin
 */
#include <stdint.h>

const uint32_t flags_section[4096] __attribute__((section(".flags")));

const uint8_t appACRC[2] __attribute__((section(".appACRC"))) = {0xbd, 0xc5}; //TODO: correct the crc and add applength first
