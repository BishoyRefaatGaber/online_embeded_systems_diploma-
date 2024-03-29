/*
 * LCD_DRIVER.h
 *
 * Created: 12/3/2022 8:32:25 PM
 *  Author: Bishoy Refaat
 */



#include "LCD_DRIVER.h"
#include "GPIO.h"
#include "util/delay.h"
#include "avr/io.h"
#include "stdlib.h"
#include "stdio.h"
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#ifdef FOUR_BIT_MODE
void LCD_INIT(){
	_delay_ms(20);
	CONFIG_DATA_CTRL(OUTPUT);
	LCD_DATA_CTRL &= ~(1 << EN);
	LCD_WRITE_COMMAND(LCD_Return_Home);
	LCD_WRITE_COMMAND(LCD_4BITS_2LINES_5X8);
	LCD_WRITE_COMMAND(LCD_DISP_ON);
	LCD_WRITE_COMMAND(LCD_Clear_Display);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK); 

}
void GOTO_XY(unsigned char x ,unsigned char y){
	CONFIG_DATA_CTRL(OUTPUT);
	LCD_WRITE_COMMAND(BAISX+x+BAISY*y);

}


void LCD_WRITE_NUM(int num){
	char str[16];
	sprintf(str,"%d",num);
	LCD_WRITE_STRING(str);
}

void LCD_WRITE_REAL_NUM(double num){
	char str[16];
	char *Sign = (num < 0) ? "-" : "";
	float Val = (num < 0) ? -num : num ;

	int Int1 = Val;
	float Frac = Val - Int1;
	int Int2 = Frac * 10000;

	sprintf(str ,"%c%d%c%.04d",*Sign,Int1,'.',Int2);
	LCD_WRITE_STRING(str);
}

void LCD_WRITE_COMMAND(unsigned char command){
	CONFIG_DATA_CTRL(OUTPUT);
	LCD_DATA_CTRL = (LCD_DATA_CTRL & LCD_WRITE_INSTRUCTION);
	LCD_DATA_CTRL = ((LCD_DATA_CTRL & PORT_INPUT_PINS) | ((command & 0xF0) >> MOST_BIT_PIN)) ;    
	LCD_ENABLE;
	LCD_DATA_CTRL = (LCD_DATA_CTRL & LCD_WRITE_INSTRUCTION);
	LCD_DATA_CTRL =((LCD_DATA_CTRL & PORT_INPUT_PINS) | ((command & 0x0F) << LEAST_BIT_PIN));
	LCD_ENABLE;
}

void LCD_WRITE_CHAR(unsigned char character){
	static char COUNT_CHAR = 0 ;
	CONFIG_DATA_CTRL(OUTPUT);
	if(character){
	LCD_DATA_CTRL = ((LCD_DATA_CTRL & ~LCD_WRITE_DATA) | LCD_WRITE_DATA);
	LCD_DATA_CTRL = ((LCD_DATA_CTRL & PORT_INPUT_PINS) | ((character & 0xF0) >> MOST_BIT_PIN));
	LCD_ENABLE;
	LCD_DATA_CTRL = ((LCD_DATA_CTRL & ~LCD_WRITE_DATA) | LCD_WRITE_DATA);
	LCD_DATA_CTRL = ((LCD_DATA_CTRL & PORT_INPUT_PINS) | ((character & 0x0F) << LEAST_BIT_PIN));
	LCD_ENABLE;
	COUNT_CHAR++;
	}
	if (COUNT_CHAR == 15){
		GOTO_XY(0,1);
	}
	else if (COUNT_CHAR == 30){
		COUNT_CHAR = 0;
		LCD_WRITE_COMMAND(LCD_Clear_Display);
		GOTO_XY(0,0);
	}
}
void LCD_WRITE_STRING(char* string){
	unsigned char i = 0 , COUNT_STRING = 1 ;
	CONFIG_DATA_CTRL(OUTPUT);
	while(string[i]){
		LCD_DATA_CTRL = ((LCD_DATA_CTRL & ~LCD_WRITE_DATA) | LCD_WRITE_DATA);
		LCD_DATA_CTRL = ((LCD_DATA_CTRL & PORT_INPUT_PINS) | ((string[i] & 0xF0) >> MOST_BIT_PIN));
		LCD_ENABLE;
		LCD_DATA_CTRL = ((LCD_DATA_CTRL & ~LCD_WRITE_DATA) | LCD_WRITE_DATA);
		LCD_DATA_CTRL = ((LCD_DATA_CTRL & PORT_INPUT_PINS) | ((string[i] & 0x0F) << LEAST_BIT_PIN));
		LCD_ENABLE;
		COUNT_STRING++;
		if (COUNT_STRING == 15){
			GOTO_XY(0,1);
		}
		else if (COUNT_STRING == 30){
			COUNT_STRING = 0;
			LCD_WRITE_COMMAND(LCD_Clear_Display);
			GOTO_XY(0,0);
		}
		i++;
	}
}

#endif

