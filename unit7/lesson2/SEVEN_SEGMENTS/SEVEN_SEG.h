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





//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

#define SEVEN_SEG_OUT                           //Output register
#define SEVEN_SEG_OUT_SHIFT                     //shift in this register
#define DOT_OUT
#define SEVEN_SEG_CONTROL                       //Output register
#define SEVEN_SEG_CONTROL_SHIFT                 //Shift in this register




//		|------------------------------------------------------------------|
//		|=============APIs Supported by "MCAL GPIO DRIVER"=================|
//		|------------------------------------------------------------------|

void SEVEN_SEG_Display_NUM(uint8_t NUM);

#endif