/*
 * SEVEN_SEG.h
 *
 * Created: 2/15/2023 1:11:34 PM
 * Author : Bishoy Refaat
 */

#ifndef _SEVEN_SEG_H_
#define  _SEVEN_SEG_H_

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "GPIO.h"
#include "STM32F103xx.h"


//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

#define SEVEN_SEG_OUT	GPIOA->ODR
#define SEVEN_SEG_OUT_SHIFT		8
//#define DOT_OUT
#define SEVEN_SEG_CONTROL	GPIOB->ODR
#define SEVEN_SEG_CONTROL_SHIFT		0




//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|

void SEVEN_SEG_Display_NUM(uint8_t NUM);

extern void wait_ms(uint32_t time);
#endif
