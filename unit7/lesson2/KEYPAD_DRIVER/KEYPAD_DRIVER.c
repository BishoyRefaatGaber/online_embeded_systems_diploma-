#include "KEYPAD_DRIVER.h"
 
int keypad_R [4]= {R0 , R1 , R2 , R3};
int keypad_C [4]= {C0 , C1 , C2 , C3};
void KEYPAD_INIT(){
	KEYPAD_COLUMNS_DIR |= COLUMNS_PINS;
	KEYPAD_COLUMNS_PORT |= COLUMNS_PINS;
	KEYPAD_ROWS_DIR &= ~(ROW_PINS);
	KEYPAD_ROWS_PORT |= (ROW_PINS);
}
char KEYPAD_GET_CHAR(){
	int i,j;
	for (i = 0; i < 4; i++){
		KEYPAD_COLUMNS_PORT |= COLUMNS_PINS;
		KEYPAD_COLUMNS_PORT &= ~(1 << keypad_C[i]);
		for(j = 0; j < 4 ; j++){
			if(!(KEYPAD_ROWS_PIN & (1 << keypad_R[j]))){
				while(!(KEYPAD_ROWS_PIN & (1 << keypad_R[j])));
				switch (i){
					case(0):
						if( j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '!';
						break;
					case(1):
						if( j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case(2):
						if( j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case(3):
						if( j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
				}
				
			}
		}
	}
	return '\0';
}


