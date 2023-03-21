/*
 * main.h
 *
 * Created: 12/29/2022 9:25:25 PM
 *  Author: refaa
 */ 


#ifndef MAIN_H_
#define MAIN_H_
#ifndef F_CPU
#define F_CPU 8000000UL
#endif


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
//PORTD
#define PORTD *((unsigned volatile int*)(0x32))
#define DDRD *((unsigned volatile int*)(0x31))
#define PIND *((unsigned volatile int*)(0x30))







#endif /* MAIN_H_ */