#include "main.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_ROWS_PORT   PORTB
#define KEYPAD_ROWS_DIR    DDRB
#define KEYPAD_ROWS_PIN    PINB

#define KEYPAD_COLUMNS_PORT   PORTD
#define KEYPAD_COLUMNS_DIR    DDRD
#define KEYPAD_COLUMNS_PIN    PIND

#define COLUMNS_PINS  0x3C
#define ROW_PINS      0xF0

#define R0  0x4
#define R1  0x5
#define R2  6
#define R3  7
#define C0  2
#define C1  3
#define C2  4
#define C3  5

void KEYPAD_INIT();
char KEYPAD_GET_CHAR();

#endif