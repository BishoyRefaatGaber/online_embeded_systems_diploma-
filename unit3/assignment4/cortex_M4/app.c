#include "Platform.h"

#define SYSCTL_RCGC2_R     (*((uint_32*)(0x400FE108)))
#define GPIO_PORTF_DATA_R  (*((uint_32*)(0x400253FC)))
#define GPIO_PORTF_DIR_R   (*((uint_32*)(0x40025400)))
#define GPIO_PORTF_DEN_R   (*((uint_32*)(0x4002551C)))
#define Bit_Num (1<<3)


uint_32 main(){

	vuint_32 delay;
	SYSCTL_RCGC2_R = 0x00000020;
	for(delay=0;delay<200;delay++);
	GPIO_PORTF_DIR_R |= Bit_Num;
	GPIO_PORTF_DEN_R |= Bit_Num;


	while(1){
		GPIO_PORTF_DATA_R |=1<<3;
		for(delay =0;delay<200;delay++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(delay =0;delay<200;delay++);
	}


	return 0;
}




 