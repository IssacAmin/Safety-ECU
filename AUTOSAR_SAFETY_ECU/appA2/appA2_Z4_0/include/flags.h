/*
 * flags.h
 *
 *  Created on: Mar 5, 2025
 *      Author: Issac Amin
 */

#ifndef FLAGS_H_
#define FLAGS_H_

#include <stdint.h>

#define FLAGS_SECTION_BASE_ADDRESS		0x00FA0000
#define FLAGS_SECTION_LOGICAL_ADDRESS 	0
#define FLAGS							FLAGS_SECTION_LOGICAL_ADDRESS + 0


/* struct should be 128 bytes for aligned write operation */
typedef struct{
	uint32_t programming_session;
	uint32_t uds_last_securityLvl;
	uint32_t current_app;
	uint32_t flashbank_A_valid;
	uint32_t flashbank_A_Erased;
	uint32_t flashbank_B_valid;
	uint32_t flashbank_B_Erased;
	uint32_t flashing_in_progress;
	uint32_t reset_during_flash;
	uint32_t reserved_section[23];
}flags;

#endif /* FLAGS_H_ */
