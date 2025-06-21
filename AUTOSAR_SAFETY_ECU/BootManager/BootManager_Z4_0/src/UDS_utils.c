/*
 * UDS_utils.c
 *
 *  Created on: Mar 8, 2025
 *      Author: Issac Amin
 */
#include "UDS_utils.h"

static uint8_t app_sector_buffer[SECTOR_SIZE]  __attribute__((section(".appSectorBuffer")));

void flsWaitUntilJobDone(void)
{
	Fls_MainFunction();
	while(Fls_GetJobResult() == MEMIF_JOB_PENDING)
	{
		Fls_MainFunction();
	}
}

UDS_Utils_ReturnType validate_flashbank(FlashBankType flashBankType,flags * flags_instance) 
{
	Std_ReturnType fls_ret;
	uint32_t currentFlashBankStartAddress = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1;
	bool valid_crc = false;
	meta_data meta_data_instance;

	switch(flashBankType)
	{
		case(PRIMARY_APP):
			if(flags_instance->current_app == 0)
			{
				currentFlashBankStartAddress = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1;
			}
			else
			{
				currentFlashBankStartAddress = FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1;
			}
			break;
		case(SECONDARY_APP):
			if(flags_instance->current_app == 0)
			{
				currentFlashBankStartAddress = FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1;
			}
			else
			{
				currentFlashBankStartAddress = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1;
			}
			break;
	}

	fls_ret = Fls_Read((currentFlashBankStartAddress + FLASHBANK_SIZE - QUAD_PAGE_SIZE),&meta_data_instance , QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	uint32_t app_length = meta_data_instance.app_length;
	uint16_t stored_crc = meta_data_instance.crc_ccitt;

	valid_crc = memory_check(currentFlashBankStartAddress, app_length, stored_crc, app_sector_buffer);
	if(valid_crc)
	{
		switch(currentFlashBankStartAddress)
		{
			case(FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1):
				flags_instance->flashbank_A_valid = 1U;
				break;
			case(FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1):
				flags_instance->flashbank_B_valid = 1U;
				break;
			default:
				return FLASH_FAILED; // Invalid flash bank address
		}
		return FLASH_BANK_VALID;
	}
	else
	{
		/* Invalidate the flash bank due to invalid CRC */
		switch(currentFlashBankStartAddress)
		{
			case(FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1):
				flags_instance->flashbank_A_valid = 0U;
				break;
			case(FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1):
				flags_instance->flashbank_B_valid = 0U;
				break;
			default:
				return FLASH_FAILED; // Invalid flash bank address
		}
		return FLASH_BANK_NOT_VALID;
	}

	return FLASH_BANK_NOT_VALID;
}

#ifdef BOOTLOADER_USE_BOOTLOADER_UPDATER
UDS_Utils_ReturnType updateBootloader(flags* flags_instance)
{
	uint32_t length = flags_instance-> bootloader_update_size;
	Std_ReturnType fls_ret;
	uint32_t newStartAddress;
	if(flags_instance->current_app == 0)
	{
		newStartAddress = FLASHBANK_B_BASE_ADDRESS;
	}
	else
	{
		newStartAddress = FLASHBANK_A_BASE_ADDRESS;
	}
	uint8_t num_of_sectors = ceil((double)length / SECTOR_SIZE);
	uint8_t i = 0;
	/*
		* Check if the memory_length is page_aligned and padded
	*/
	if(length % PAGE_SIZE != 0)
			return FLASH_DATALENGTH_CROSS_PAGE_BOUNDARY;

	for(;i<num_of_sectors;i++)
	{
		Fls_Read(newStartAddress + (SECTOR_SIZE * i),app_sector_buffer,SECTOR_SIZE);
		flsWaitUntilJobDone();

		Fls_Write(BOOTLOADER_LOGICAL_ADDRESS_SECTOR_1 + (SECTOR_SIZE * i),app_sector_buffer,SECTOR_SIZE);
		flsWaitUntilJobDone();
	}
	return FLASH_OK;
}
#endif