/*
 * KEYPAD_DRIVER.h
 *
 *  Created on: Jan 22, 2023
 *      Author: Bishoy Refaat
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STM32F103xx.h"
#include "GPIO.h"

#define KEYPAD_ROWS_PORT  GPIOB->ODR

#define KEYPAD_ROWS_PIN		 GPIOB->IDR

#define KEYPAD_COLUMNS_PORT  GPIOB->ODR

#define KEYPAD_COLUMNS_PIN		GPIOB->IDR

#define COLUMNS_PINS	0x0078
#define ROW_PINS		0x0780


#define C0	3
#define C1	4
#define C2	5
#define C3	6
#define R0	7
#define R1	8
#define R2	9
#define R3	10


void KEYPAD_INIT();
char KEYPAD_GET_CHAR();
extern void wait_ms(uint32_t time);
#endif
