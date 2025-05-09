/*
 * securityLevelsFunctions.c
 *
 *  Created on: May 9, 2025
 *      Author: omart
 */

#include <stdint.h>
uint8_t seed[2] = {0x06,0x12};
uint8_t* secLvl_0x00_seedFunc(void)
{
	return &seed;
}
uint8_t  secLvl_0x00_keyCheckFunc(uint8_t* key)
{
	return 1U;/*default level afta7 aman*/
}
uint8_t* secLvl_0x01_seedFunc(void)
{
	return &seed;
}
uint8_t  secLvl_0x01_keyCheckFunc(uint8_t* key)
{
	uint8_t i =0;
	for(;i<2;i++)
	{
		if(key[i]!=seed[i])
			return 0U;
	}
	return 1U;
}
