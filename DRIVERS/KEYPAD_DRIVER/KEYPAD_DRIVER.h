#ifndef KEYPAD_H_
#define KEYPAD_H_


//		|-----------------------------------------------|
//		|===================Includes====================|
//		|-----------------------------------------------|

 
//		|-----------------------------------------------|
//		|================GENERIC MACROS=================|
//		|-----------------------------------------------|

#define KEYPAD_ROWS_INPUT 			//Input register of rows
#define KEYPAD_COLUMNS_OUTPUT  		//Output register of columns

#define COLUMNS_PINS		//Ones on the columns pins used for configurations
#define ROW_PINS			//Ones on the rows pins used for configurations

//Rows pin numbers
#define R0  
#define R1  
#define R2  
#define R3  

//Columns pin numbers
#define C0  
#define C1  
#define C2  
#define C3  

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

#endif