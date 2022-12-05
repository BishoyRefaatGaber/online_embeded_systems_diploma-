/*
 * GPIO_LAB.c
 *
 * Created: 11/26/2022 11:40:51 AM
 * Author : Bishoy Refaat
 */ 

#define F_CPU 8000000UL
#include "util/delay.h"
//PORTA
#define PORTA *((unsigned volatile int*)(0x3B))
#define DDRA *((unsigned volatile int*)(0x3A))
#define PINA *((unsigned volatile int*)(0x39))

//PORTB
#define PORTB *((unsigned volatile int*)(0x38))
#define DDRB *((unsigned volatile int*)(0x37))
#define PINB *((unsigned volatile int*)(0x36))

//PORTC
#define PORTC *((unsigned volatile int*)(0x35))
#define DDRC *((unsigned volatile int*)(0x34))
#define PINC *((unsigned volatile int*)(0x33))
volatile unsigned char SEG [10] = {0x7E , 0x0C , 0xB6 , 0x9E , 0xCC , 0xDA , 0xFA , 0x0E , 0xFE , 0xDE }; //7SEG values
volatile unsigned char count = 0;
void PORT_INIT(){
	
	//PORTA
	DDRA |= 0xFE; //output for 7segment 0b11111110
	//PORTB
	DDRB |= 0x1;  //dot output for 7SEG 0b00000001
	//PORTC 
	DDRC = 0x0;  //reset port c
	DDRC |= 0xE7; //output for the 3 LEDs & the 2 COMs for 7SEG & 3 inputs for LEDs(Switches) 0b11100111
	PORTC |= (1 << 3); // activate pull up resistance for input pin 3
}
void delay (unsigned char x){
	unsigned long i;
	for (i = 0 ; i < x*(6400000000000) ; i++);
}
void COUNTER_VALUE (unsigned char x){
	unsigned char  j;
	for (j=0;j<=x;j++){
		PORTC |= (1 << 6);
		PORTC &= ~(1 << 7);
		PORTA = SEG[x]  ;
		_delay_ms(10);
		PORTC &= ~(1 << 6);
		PORTC |= (1 << 7);
		PORTA = SEG[0];
		_delay_ms(10);
	}
}
int main(void)
{
	PORT_INIT();
	count = 0;
	while (1) 
    {
		
		COUNTER_VALUE (count);
		
		if(((PINC & (1 << 3)) >> 3 ) == 0){
			if (count == 0){
			PORTC |= (1 << 0);
			while(((PINC & (1 << 3)) >> 3 ) == 0);
			COUNTER_VALUE (++count);
			}
			else if (count == 1){
				PORTC |= (1 << 1);
				while(((PINC & (1 << 3)) >> 3 ) == 0);
				COUNTER_VALUE (++count);
			}
			else if (count == 2){
				PORTC |= (1 << 2);
				while(((PINC & (1 << 3)) >> 3 ) == 0);
				COUNTER_VALUE (++count);
			}
			else if (count == 3){
				PORTC |= (1 << 5);
				while(((PINC & (1 << 3)) >> 3 ) == 0);
				_delay_ms(2000);
				PORTC &= ~(1 << 5);
				PORTC &= ~(1 << 0);
				PORTC &= ~(1 << 1);
				PORTC &= ~(1 << 2);
				count = 0;
			}
  }
}
}
