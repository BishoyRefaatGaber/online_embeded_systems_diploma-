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

#include "ATMEGA32.h"
#include "GPIO.h"


//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

//PORTA 1:7
#define SEVEN_SEG_OUT	PORTA->PORT                    //Output register
#define SEVEN_SEG_OUT_SHIFT 1                    //shift in this register
//#define DOT_OUT
#define SEVEN_SEG_CONTROL  PORTC->PORT                     //Output register
#define SEVEN_SEG_CONTROL_SHIFT   6              //Shift in this register




//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|

void SEVEN_SEG_Display_NUM(uint8_t NUM);

#endif