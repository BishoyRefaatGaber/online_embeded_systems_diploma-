/*
 * LCD_KEYPAD.c
 *
 * Created: 12/4/2022 10:52:07 PM
 * Author : refaa
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#include "LCD/LCD_DRIVER.h"
#include "KEYPAD/KEYPAD_DRIVER.h"
#include "GPIO.h"
#include "util/delay.h"
#include "stdlib.h"

int main(void)
{
    LCD_INIT();
	KEYPAD_INIT();
	char key;
    while (1) 
     {
		 key = KEYPAD_GET_CHAR();
	     switch( key)
	     {
		     case  ('\0'): break; //No Key Pressed
		     case  ('!'):  LCD_WRITE_COMMAND(LCD_Clear_Display);break;
		     default: LCD_WRITE_CHAR(key);;break;
	     }
	 }
	 

}

