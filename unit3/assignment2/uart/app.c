#include "uart.h"
#include "Platform.h"
uint_8 stringaia [100]="learn_in_depth : BIRG16";

void main(void){

	uart_send_string(stringaia);


}