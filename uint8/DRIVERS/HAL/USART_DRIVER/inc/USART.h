/*
 * USART.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Bishoy Refaat
 */

#ifndef USART_DRIVER_INC_USART_H_
#define USART_DRIVER_INC_USART_H_

//-----------------------
//includes
//-----------------------

#include "STM32F103xx.h"
#include "GPIO.h"



//===============================================
//------------------------------------
//User Type Definitions (structures)
//------------------------------------


typedef struct {
	uint8_t USART_MODE ;   //Specifies which mode of USART to be configured transmit or receive
							// Configured as @ref USART_MODE_define


}USART_CFG_t;



//===========================================
//------------------------------
//Macros Configurations References
//------------------------------


		/*****@ref USART_MODE_define*****/
#define USART_MODE_TX		(uint32_t)(1 << 3)
#define USART_MODE_RX		(uint32_t)(1 << 2)
#define USART_MODE_TX_RX	(uint32_t)(1 << 2 | 1 << 3)

//========================================================
//------------------------------------
//APIs Supported by "MCAL GPIO DRIVER"
//------------------------------------







#endif /* USART_DRIVER_INC_USART_H_ */
