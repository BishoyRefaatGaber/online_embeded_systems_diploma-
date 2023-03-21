/*
 * KEYPAD_DRIVER.h
 *
 *  Created on: Jan 22, 2023
 *      Author: Bishoy Refaat
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "STM32F103xx.h"
#include "GPIO.h"


//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|


#define KEYPAD_ROWS_OUTPUT		GPIOB->ODR		//Output register of rows
#define KEYPAD_COLUMNS_OUTPUT  	GPIOB->ODR		//Output register of columns
#define KEYPAD_ROWS_INPUT		GPIOB->IDR		//Input register of rows


#define COLUMNS_PINS	0x0078		//Ones on the columns pins used for configurations
#define ROW_PINS		0x0780		//Ones on the rows pins used for configurations

//Columns pin numbers PORTB
#define C0	3
#define C1	4
#define C2	5
#define C3	6

//Rows pin numbers PORTB
#define R0	7
#define R1	8
#define R2	9
#define R3	10


//		|------------------------------------------------------------------|
//		|=============APIs Supported by " HAL KEYPAD DRIVER "==============|
//		|------------------------------------------------------------------|


/**================================================================
* @Fn - KEYPAD_INIT
* @brief - initialize the KEYPAD
* @retval - none
*/
void KEYPAD_INIT();


/**================================================================
* @Fn - KEYPAD_GET_CHAR
* @brief - Get input from the KEYPAD
* @retval - Character
*/
char KEYPAD_GET_CHAR();

//Just a delay
extern void wait_ms(uint32_t time);
#endif
