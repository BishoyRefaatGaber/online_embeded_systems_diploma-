/*
 * RCC.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Bishoy Refaat
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_
#include "STM32F103xx.h"
#include "GPIO.h"
#include "RCC.h"

#define HSI_RC_CLK 	(uint32_t)8000000
#define HSE_CLK 	(uint32_t)16000000

uint32_t MCAL_RCC_GET_SYS_CLK_FRQ(void);
uint32_t MCAL_RCC_GET_HCL_CLK_FRQ(void);
uint32_t MCAL_RCC_GET_PCLK1_FRQ(void);
uint32_t MCAL_RCC_GET_PCLK2_FRQ(void);



#endif /* INC_RCC_H_ */
