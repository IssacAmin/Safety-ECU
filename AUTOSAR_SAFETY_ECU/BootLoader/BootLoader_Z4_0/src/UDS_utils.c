/*
 * UDS_utils.c
 *
 *  Created on: Mar 8, 2025
 *      Author: Issac Amin
 */
#include "UDS_utils.h"

static flags flags_instance;
static uint32_t global_dst_address = 0, modifyFlashBankErasedFlagTrigger = 0;


UDS_Utils_ReturnType modify_flag(UDS_Utils_FLAG flag ,UDS_Utils_ModifyFlag input){
	Std_ReturnType fls_ret;

	//leah quad page
	fls_ret = Fls_Read((Fls_AddressType)FLAGS, (uint8_t *)&flags_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	switch(flag){
	case PROGRAMMING_SESSION:
		if(input == FLAG_TOGGLE)
			flags_instance.programming_session = !(flags_instance.programming_session);
		else{
			flags_instance.programming_session = (input == FLAG_SET)? 1 : 0;
		}
		break;
	case CURRENT_APP:
		if(input == FLAG_TOGGLE)
			flags_instance.current_app = !(flags_instance.current_app);
		else{
			flags_instance.current_app = (input == FLAG_SET)? 1 : 0;
		}
		break;
	case FLASHBANK_VALID:
		if(flags_instance.current_app == 0){
			if(input == FLAG_TOGGLE)
				flags_instance.flashbank_A_valid = !(flags_instance.flashbank_A_valid);
			else{
				flags_instance.flashbank_A_valid = (input == FLAG_SET)? 1 : 0;
			}
		}else{
			if(input == FLAG_TOGGLE)
				flags_instance.flashbank_B_valid = !(flags_instance.flashbank_B_valid);
			else{
				flags_instance.flashbank_B_valid = (input == FLAG_SET)? 1 : 0;
			}
		}
		break;
	case FLASHING_IN_PROGRESS:
		if(input == FLAG_TOGGLE)
			flags_instance.flashing_in_progress = !(flags_instance.flashing_in_progress);
		else{
			flags_instance.flashing_in_progress = (input == FLAG_SET)? 1 : 0;
		}
		break;
	case RESET_DURING_FLASH:
		if(input == FLAG_TOGGLE)
			flags_instance.reset_during_flash = !(flags_instance.reset_during_flash);
		else{
			flags_instance.reset_during_flash = (input == FLAG_SET)? 1 : 0;
		}
		break;
	case FLASHBANK_A_ERASED:
		if(input == FLAG_TOGGLE)
			flags_instance.flashbank_A_Erased = !(flags_instance.flashbank_A_Erased);
		else{
			flags_instance.flashbank_A_Erased = (input == FLAG_SET)? 1 : 0;
		}
		break;
	case FLASHBANK_B_ERASED:
		if(input == FLAG_TOGGLE)
			flags_instance.flashbank_B_Erased = !(flags_instance.flashbank_B_Erased);
		else{
			flags_instance.flashbank_B_Erased = (input == FLAG_SET)? 1 : 0;
		}
		break;
	default:
		break;
	}

	fls_ret = Fls_Erase(FLAGS, SECTOR_SIZE);
	flsWaitUntilJobDone();


	fls_ret = Fls_Write((Fls_AddressType)FLAGS , (uint8_t *)&flags_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	return FLASH_OK;
}


uint8_t read_flags(UDS_Utils_FLAG flag){

	Std_ReturnType fls_ret;

	switch(flag){
	case PROGRAMMING_SESSION:
		return flags_instance.programming_session;
	case CURRENT_APP:
		return flags_instance.current_app;
	case FLASHBANK_VALID:
		if(flags_instance.current_app == 0){
			return flags_instance.flashbank_A_valid;
		}else{
			return flags_instance.flashbank_B_valid;
		}
	case FLASHING_IN_PROGRESS:
		return flags_instance.flashing_in_progress;
	case RESET_DURING_FLASH:
		return flags_instance.reset_during_flash;
	case FLASHBANK_A_ERASED:
		return flags_instance.flashbank_A_Erased;	
	case FLASHBANK_B_ERASED:
		return flags_instance.flashbank_B_Erased;
	default:
		return -1; //TODO: return something
	}
}

UDS_Utils_ReturnType erase_flashbank(void){

	Std_ReturnType fls_ret;
	fls_ret = Fls_Read((Fls_AddressType)FLAGS, (uint8_t *)&flags_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	if(flags_instance.programming_session && flags_instance.flashing_in_progress)
	{
		if(flags_instance.current_app == 0)
		{
			if(!flags_instance.flashbank_B_Erased)
			{
				modifyFlashBankErasedFlagTrigger = 1;
				flags_instance.flashbank_B_valid = 0;
				flags_instance.flashbank_B_Erased = 1;
				fls_ret = Fls_Erase(FLAGS, SECTOR_SIZE);
				flsWaitUntilJobDone();
				fls_ret = Fls_Write((Fls_AddressType)FLAGS , (uint8_t *)&flags_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
				flsWaitUntilJobDone();
				fls_ret = Fls_Erase(FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1, FLASHBANK_SIZE);
				flsWaitUntilJobDone();
			}
			return FLASH_OK;
		}
		else
		{
			if(!flags_instance.flashbank_A_Erased)
			{
				modifyFlashBankErasedFlagTrigger = 1;
				flags_instance.flashbank_A_valid = 0;
				flags_instance.flashbank_A_Erased = 1;
				fls_ret = Fls_Erase(FLAGS, SECTOR_SIZE);
				flsWaitUntilJobDone();
				fls_ret = Fls_Write((Fls_AddressType)FLAGS , (uint8_t *)&flags_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
				flsWaitUntilJobDone();
				fls_ret = Fls_Erase(FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1, FLASHBANK_SIZE);
				flsWaitUntilJobDone();
			}
			return FLASH_OK;
		}
	}
	else
	{
		return FLASH_FAILED;
	}
}

UDS_Utils_ReturnType copy_segment(uint32_t start_address, uint32_t segment_length, uint32_t dst_address){
	/* Variable Initialization */
	Std_ReturnType fls_ret;
	uint8_t app_sector_buffer[SECTOR_SIZE + PAGE_SIZE];


	/*getting respective logical address for flash driver*/
	uint32_t entry_point, dst_point;
	uint8_t entry_point_alignment_shift = 0;
	uint8_t segment_length_correction = 0;

	if(!(flags_instance.programming_session && flags_instance.flashing_in_progress))
		return FLASH_FAILED;
	if(flags_instance.current_app == 0){
		entry_point = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1 + start_address;
		dst_point   = FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1 + dst_address;
	}else{
		entry_point = FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1 + start_address;
		dst_point   = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1 + dst_address;
	}

	/* check start address address alignment */
	if(entry_point % PAGE_SIZE != 0)
	{
		entry_point_alignment_shift = entry_point % PAGE_SIZE;
		segment_length_correction = PAGE_SIZE;
	}

	if(segment_length % QUAD_PAGE_SIZE != 0)
		return FLASH_DATALENGTH_CROSS_PAGE_BOUNDARY;


	if(segment_length < SECTOR_SIZE){

		fls_ret = Fls_Read(entry_point - entry_point_alignment_shift , app_sector_buffer, segment_length + segment_length_correction);
		flsWaitUntilJobDone();


		fls_ret = Fls_Write(dst_point , app_sector_buffer + entry_point_alignment_shift, segment_length);
		flsWaitUntilJobDone();

	}else{
		uint8_t num_of_sectors = ceil((double)segment_length  / SECTOR_SIZE );
		uint8_t i = 0;
		for(i = 0; i < num_of_sectors; i++)
		{
			if(i == (num_of_sectors - 1)){
				uint16_t final_read_size;
				if(segment_length % SECTOR_SIZE != 0)
					final_read_size = segment_length  % SECTOR_SIZE;
				else{
					final_read_size = SECTOR_SIZE;
				}

				fls_ret = Fls_Read((entry_point + i * SECTOR_SIZE) - entry_point_alignment_shift, app_sector_buffer , final_read_size + segment_length_correction);
				flsWaitUntilJobDone();


				fls_ret = Fls_Write(dst_point +(SECTOR_SIZE * i) , app_sector_buffer + entry_point_alignment_shift, final_read_size);
				flsWaitUntilJobDone();

			}else{

				fls_ret = Fls_Read((entry_point + i * SECTOR_SIZE) - entry_point_alignment_shift, app_sector_buffer , SECTOR_SIZE + segment_length_correction);
				flsWaitUntilJobDone();


				fls_ret = Fls_Write(dst_point +(SECTOR_SIZE * i) , app_sector_buffer + entry_point_alignment_shift, SECTOR_SIZE);
				flsWaitUntilJobDone();
			}
		}
	}
	return FLASH_OK;
}



UDS_Utils_ReturnType add_segment(uint32_t dst_address, uint8_t *data, uint32_t segment_length){
	/* Variable Initialization */
	Std_ReturnType fls_ret;


	/*getting respective logical address for flash driver*/
	uint32_t dst_point;
	if(!(flags_instance.programming_session && flags_instance.flashing_in_progress))
		return FLASH_FAILED;
	if(flags_instance.current_app == 0){
		dst_point   = FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1 + dst_address;
	}else{
		dst_point   = FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1 + dst_address;
	}

	/* check start address address alignment */
	if(dst_point % PAGE_SIZE != 0)
		return FLASH_STARTADDRESS_UNALIGNED;
	if(segment_length % QUAD_PAGE_SIZE != 0)
		return FLASH_DATALENGTH_CROSS_PAGE_BOUNDARY;


	if(segment_length < SECTOR_SIZE){
		fls_ret = Fls_Write(dst_point , data, segment_length);
		flsWaitUntilJobDone();
	}else{
		uint8_t num_of_sectors = ceil((double)segment_length  / SECTOR_SIZE ); //TODO: include something for ceil function
		uint8_t i = 0;
		for(i = 0; i < num_of_sectors; i++)
		{
			if(i == (num_of_sectors - 1)){
				uint16_t final_write_size;
				if(segment_length % SECTOR_SIZE != 0)
					final_write_size = segment_length  % SECTOR_SIZE;
				else{
					final_write_size = SECTOR_SIZE;
				}
				fls_ret = Fls_Write(dst_point +(SECTOR_SIZE * i) , data, final_write_size);
				flsWaitUntilJobDone();
			}else{
				fls_ret = Fls_Write(dst_point +(SECTOR_SIZE * i) , data, SECTOR_SIZE);
				flsWaitUntilJobDone();
			}
		}
	}
	return FLASH_OK;

}

UDS_Utils_ReturnType jump_segment(uint32_t start, uint32_t size){
	global_dst_address += size;
}

//TODO: return something
UDS_Utils_ReturnType flash_flashbank_metadata(uint16_t crc, uint32_t app_length){
	/* Variable Initialization */
	Std_ReturnType fls_ret;
	meta_data meta_data_instance;
	meta_data_instance.crc_ccitt = crc;
	meta_data_instance.app_length = app_length;
	uint32_t dst_address;

	if(flags_instance.current_app == 0)
		dst_address = (FLASHBANK_B_LOGICAL_ADDRESS_SECTOR_1 + FLASHBANK_SIZE - QUAD_PAGE_SIZE);
	else if(flags_instance.current_app == 1)
		dst_address = (FLASHBANK_A_LOGICAL_ADDRESS_SECTOR_1 + FLASHBANK_SIZE - QUAD_PAGE_SIZE);

	fls_ret = Fls_Write((Fls_AddressType)dst_address, (uint8_t *)&meta_data_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();

	return FLASH_OK;
}

UDS_Utils_ReturnType switch_and_validate_flashbank(void){
	Std_ReturnType fls_ret;
	if(flags_instance.current_app == 0)
	{
		flags_instance.current_app = 1;
		flags_instance.flashbank_B_valid = 1;
	}else{
		flags_instance.current_app = 0;
		flags_instance.flashbank_A_valid = 1;
	}

	fls_ret = Fls_Erase(FLAGS, SECTOR_SIZE);

	flsWaitUntilJobDone();


	fls_ret = Fls_Write((Fls_AddressType)FLAGS , (uint8_t *)&flags_instance, (Fls_LengthType)QUAD_PAGE_SIZE);
	flsWaitUntilJobDone();
	return FLASH_OK;
}

void reset_ecu(void){
	Mcu_PerformReset();
}

UDS_Utils_ReturnType parse_data(uint8_t* data, uint32_t data_length){
	UDS_Utils_ReturnType utils_ret;
	if(modifyFlashBankErasedFlagTrigger == 1)
	{
		if(read_flags(CURRENT_APP) == 0)
		{
			modify_flag(FLASHBANK_B_ERASED, FLAG_CLEAR);
		}
		else
		{
			modify_flag(FLASHBANK_A_ERASED, FLAG_CLEAR);
		}
		modifyFlashBankErasedFlagTrigger = 0;
	}
	if(data_length == 0)
		return PARAMETERS_INVALID;
	if((data[0] == JUMP_SEGMENT_BYTE_CODE || data[0] == COPY_SEGMENT_BYTE_CODE ) && data_length != 9)
		return PARAMETERS_INVALID;

	if((data[0] == ADD_SEGMENT_BYTE_CODE ) && data_length <= 9 )
	return PARAMETERS_INVALID;

	else if(data[0] == METADATA_SEGMENT_BYTE_CODE && data_length != 7)
		return PARAMETERS_INVALID;

		uint32_t start_address;
		uint32_t segment_length;
		uint16_t crc;
		uint16_t app_length;
	/*parse data bytes to respective variables*/
	if(data[0] != METADATA_SEGMENT_BYTE_CODE){
	
		start_address = (data[1] << 24) | (data[2] << 16) | (data[3] << 8) | data[4];
		segment_length = (data[5] << 24) | (data[6] << 16) | (data[7] << 8) | data[8];
	}
else{
		crc = (data[1] << 8) | data[2];
		app_length = (data[3] << 24) | (data[4] << 16) | (data[5] << 8) | data[6];
	}


	if(data[0] == ADD_SEGMENT_BYTE_CODE){
		utils_ret = add_segment(global_dst_address, (data + 9), segment_length);
		if(utils_ret != FLASH_OK)
			return FLASH_FAILED;

		global_dst_address += segment_length;
	}else if (data[0] == COPY_SEGMENT_BYTE_CODE){
		utils_ret = copy_segment(start_address, segment_length, global_dst_address);
		if(utils_ret != FLASH_OK)
			return FLASH_FAILED;

		global_dst_address += segment_length;
	}
	else if(data[0] == JUMP_SEGMENT_BYTE_CODE)
	{
		jump_segment(start_address,segment_length);
	}else{
		flash_flashbank_metadata(crc, app_length);
	}

	return FLASH_OK;
}

void UDSUtils_MainFunction(void)
{
	uint8_t i = 0;
	UDS_Utils_ReturnType ret;
	if(commandToEraseFlashBank == 1)
	{
		commandToEraseFlashBank = 0;
		for(;i<5;i++)
		{
			ret = erase_flashbank();
		}
	}
}

void flsWaitUntilJobDone(void)
{
	Fls_MainFunction();
	while(Fls_GetJobResult() == MEMIF_JOB_PENDING)
	{
		Fls_MainFunction();
	}
}
