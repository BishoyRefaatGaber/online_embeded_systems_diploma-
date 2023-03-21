/*
 * KEYPAD_DRIVER.c
 *
 *  Created on: Jan 22, 2023
 *      Author: Bishoy Refaat
 */

//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

#include "KEYPAD_DRIVER.h"


//		|-----------------------------------------------|
//		|=============GENERIC VARIABLES=================|
//		|-----------------------------------------------

int keypad_R [4]= {R0 , R1 , R2 , R3};  //Array of rows numbers
int keypad_C [4]= {C0 , C1 , C2 , C3};	//Array of the columns numbers


//		|------------------------------------------------------------------|
//		|=============APIs Supported by " HAL KEYPAD DRIVER "==============|
//		|------------------------------------------------------------------|


void KEYPAD_INIT(){
	KEYPAD_COLUMNS_OUTPUT  = (KEYPAD_COLUMNS_OUTPUT & ~(COLUMNS_PINS)) | COLUMNS_PINS;  //Make all columns output one
	KEYPAD_ROWS_OUTPUT  = (KEYPAD_ROWS_OUTPUT & ~(ROW_PINS)) | ROW_PINS;
}

char KEYPAD_GET_CHAR(){
	int i,j;

//Switch zero between columns to get the char
	for (i = 0; i < 4; i++){
		KEYPAD_COLUMNS_OUTPUT = (KEYPAD_COLUMNS_OUTPUT & ~(COLUMNS_PINS)) | COLUMNS_PINS;		//Make all columns output one
		KEYPAD_ROWS_OUTPUT |= ROW_PINS;
		KEYPAD_COLUMNS_OUTPUT &= ~(1 << keypad_C[i]); 	//Make one columns output zero
		for(j = 0; j < 4 ; j++){
			if(!(KEYPAD_ROWS_INPUT & (1 << keypad_R[j]))){		//Check if any row's input is zero
				while(!(KEYPAD_ROWS_INPUT & (1 << keypad_R[j])));	//infinity loop while pressing
				//Get the character according to row and columns
				// j -> row number , i -> column number
				switch (i){
				//First column
					case(0):
						if(j == 0) return '7'; //First row
						else if (j == 1) return '4'; //second row
						else if (j == 2) return '1'; //third row
						else if (j == 3) return '!'; //fourth row
						break;
					//Second column
					case(1):
						if( j == 0) return '8'; //First row
						else if (j == 1) return '5'; //second row
						else if (j == 2) return '2'; //third row
						else if (j == 3) return '0'; //fourth row
						break;
					//Third column
					case(2):
						if( j == 0) return '9'; //First row
						else if (j == 1) return '6'; //second row
						else if (j == 2) return '3'; //third row
						else if (j == 3) return '='; //fourth row
						break;
					//Fourth column
					case(3):
						if( j == 0) return '/'; //First row
						else if (j == 1) return '*'; //second row
						else if (j == 2) return '-'; //third row
						else if (j == 3) return '+'; //fourth row
						break;
				}

			}
		}
	}
	return '\0';
}


