/*
 * RCC.c
 *
 *  Created on: Feb 3, 2023
 *      Author: Bishoy Refaat
 */

#include "RCC.h"

const uint8_t APBPressecTable[8] = {0 , 0 , 0 , 0 , 1 , 2 , 3 , 4};  // register >> APBPressecTable[x] = multiply by 2^x
const uint8_t AHBPressecTable[16] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 2 , 3 , 4 , 6 , 7 , 8 , 9};
uint32_t MCAL_RCC_GET_SYS_CLK_FRQ(void){
	switch((RCC->CFGR >> 2) & 0b11){
	case 0 :
		return HSI_RC_CLK;
		break;
	case 1 :
		return HSE_CLK;
		break;
	case 2 :
		return 16000000;
		break;
	}
}

uint32_t MCAL_RCC_GET_HCL_CLK_FRQ(void){

	return (MCAL_RCC_GET_SYS_CLK_FRQ() >> AHBPressecTable[(RCC->CFGR >> 4) & 0b111]);
}


uint32_t MCAL_RCC_GET_PCLK1_FRQ(void){

	return (MCAL_RCC_GET_HCL_CLK_FRQ() >> APBPressecTable[(RCC->CFGR >> 8) & 0b111]);
}
uint32_t MCAL_RCC_GET_PCLK2_FRQ(void){

	return (MCAL_RCC_GET_HCL_CLK_FRQ() >> APBPressecTable[(RCC->CFGR >> 11) & 0b111]);
}

