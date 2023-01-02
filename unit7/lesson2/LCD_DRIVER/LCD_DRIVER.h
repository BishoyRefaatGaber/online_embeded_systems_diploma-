/*
 * LCD_DRIVER.h
 *
 * Created: 12/3/2022 8:32:25 PM
 *  Author: Bishoy Refaat
 */


#ifndef _LCD_DRIVER_H_
#define _LCD_DRIVER_H_

//                       **************DECUMENTATION**************   
//__________________________________________________________________________
//LCD_PIN  RS | R/W | E   |  DB0 | DB1 | DB2 | DB3 | DB4 | DB5 | DB6 | DB7
//PORT_PIN B7 | B6  |B5   |  A0  | A1  | A2  | A3  | A4  | A5  | A6  | A7   
//__________________________________________________________________________

		/**************************************/
//#define INPUT  0x00
//#define OUTPUT 0xFF
#define PORT_INPUT_PINS
#define PORT_OUTPUT_PINS
#define MOST_BIT_PIN
#define LEAST_BIT_PIN 
#define RS
#define EN
#define WR
#define BF_PIN
//MICROCONTROLLER CONFIGURATIONS
#define LCD_DATA              
#define LCD_CTRL             
#define LCD_DATA_DIR         
#define LCD_CTRL_DIR        
#define CONFIG_DATA_CTRL(x,y) LCD_DATA_DIR = ((LCD_DATA_DIR & PORT_INPUT_PINS) | PORT_##x##_PINS); LCD_CTRL_DIR = ((LCD_DATA_DIR & PORT_INPUT_PINS) | PORT_##y##_PINS);
		/**************************************/

//LCD CONTROL
#define LCD_ENABLE                   LCD_CTRL |=(1<<EN); _delay_ms(50); LCD_CTRL&= ~(1<<EN); _delay_us(200);						
#define LCD_READ_DATA                      ((1<<WR) | (1<<RS))
#define LCD_READ_INSTRUCTION               ((1<<WR) & ~(1<<RS))
#define LCD_WRITE_DATA                     (~(1<<WR) & (1<<RS))
#define LCD_WRITE_INSTRUCTION             ~((1<<WR) | (1<<RS))

		/**************************************/

//LCD MODES

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

		/**************************************/

//LCD INSTRUCTIONS
#define LCD_Clear_Display              0x01 
#define LCD_Return_Home                0x02
#define LCD_Enty_Mode_Set_Dec          0x04
#define LCD_Enty_Mode_Set_Inc_Shift    0x05
#define LCD_Enty_Mode_Set_Inc          0x06
#define LCD_Enty_Mode_Set_Dec_Shift    0x07
#define LCD_DISP_OFF                   0x08
#define LCD_DISP_ON                    0x0C
#define LCD_DISP_ON_BLINK              0x0D
#define LCD_DISP_ON_CURSOR             0x0E
#define LCD_DISP_ON_CURSOR_BLINK       0x0F
#define LCD_MOV_CURSOR_LEFT            0x10
#define LCD_MOV_CURSOR_RIGHT           0x14
#define LCD_MOV_DISP_LEFT              0x18
#define LCD_MOV_DISP_RIGHT             0x1C
#define LCD_4BITS_2LINES_5X10          0x2C
#define LCD_4BITS_2LINES_5X8           0x28
#define LCD_4BITS_1LINE_5X10           0x24
#define LCD_4BITS_1LINE_5X8            0x20
#define LCD_8BITS_2LINES_5X10          0x3C
#define LCD_8BITS_2LINES_5X8           0x38
#define LCD_8BITS_1LINE_5X10           0x34
#define LCD_8BITS_1LINE_5X8            0x30
#define LCD_ROW1_COLUMN1               0x80
#define LCD_ROW2_COLUMN2               0xC0
#define BAISX   128
#define BAISY   64

		/**************************************/

//LCD FUNCTIONS

void LCD_INIT();
void LCD_BF_CHECK(void);
void LCD_WRITE_NUM(int num);
void LCD_WRITE_REAL_NUM(double num);
void LCD_WRITE_STRING(char* string);
void GOTO_XY(unsigned char x ,unsigned char y);
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
#endif
