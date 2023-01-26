/*
 * KEYPAD_DRIVER.c
 *
 *  Created on: Jan 22, 2023
 *      Author: Bishoy Refaat
 */

#include "KEYPAD_DRIVER.h"

int keypad_R [4]= {R0 , R1 , R2 , R3};
int keypad_C [4]= {C0 , C1 , C2 , C3};
void KEYPAD_INIT(){
	KEYPAD_COLUMNS_PORT = (KEYPAD_COLUMNS_PORT & ~COLUMNS_PINS) | COLUMNS_PINS;
}
char KEYPAD_GET_CHAR(){
	int i,j;
	for (i = 0 ; i < 40 ; i++){
		wait_ms(10000);
		KEYPAD_COLUMNS_PORT = (KEYPAD_COLUMNS_PORT & ~COLUMNS_PINS) | COLUMNS_PINS;
		KEYPAD_COLUMNS_PORT &= (1 << keypad_C[i]);

		for(j = 0 ; j < 4 ; j++){
			if(!(KEYPAD_ROWS_PIN & (1 << keypad_R[i]))){
			//	while((KEYPAD_ROWS_PIN & (1 << keypad_R[i])));
				return '9';
			}

		}
	}
	return '\0';
}

