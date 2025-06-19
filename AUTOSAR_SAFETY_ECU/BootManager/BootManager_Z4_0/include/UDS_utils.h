/*
 * UDS_utils.h
 *
 *  Created on: Mar 8, 2025
 *      Author: Issac Amin
 */

#ifndef UDS_UTILS_H_
#define UDS_UTILS_H_

#include "Fls.h"
#include "crc.h"
#include "flags.h"
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include "Mcu.h"

typedef enum {
	PRIMARY_APP = 0,
	SECONDARY_APP
} FlashBankType;
typedef enum{
	FLASH_OK,
	FLASH_BUSY,
	FLASH_STARTADDRESS_UNALIGNED,
	FLASH_DATALENGTH_CROSS_PAGE_BOUNDARY,
	PARAMETERS_INVALID,
	FLASH_FAILED,
	FLASH_BANK_VALID,
	FLASH_BANK_NOT_VALID,
}UDS_Utils_ReturnType;
UDS_Utils_ReturnType validate_flashbank(FlashBankType flashBankType,flags* flags);
UDS_Utils_ReturnType updateBootloader(flags* flags_instance);

#endif /* UDS_UTILS_H_ */
