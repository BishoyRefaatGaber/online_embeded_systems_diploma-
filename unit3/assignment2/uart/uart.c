#include "uart.h"
#include "Platform.h"
#define UART0DR *((vuint_32 * const)((uint_32 *)0x101f1000))

void uart_send_string(uint_8 *str){
	while(*str != '\0'){

		UART0DR =(uint_32)(*str);
		str++;
	}
}