#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_ROWS_PORT   
#define KEYPAD_ROWS_DIR    
#define KEYPAD_ROWS_PIN  

#define KEYPAD_COLUMNS_PORT   
#define KEYPAD_COLUMNS_DIR   
#define KEYPAD_COLUMNS_PIN   

#define COLUMNS_PINS
#define ROW_PINS

#define R0  
#define R1  
#define R2  
#define R3  
#define C0  
#define C1  
#define C2  
#define C3  

void KEYPAD_INIT();
char KEYPAD_GET_CHAR();

#endif