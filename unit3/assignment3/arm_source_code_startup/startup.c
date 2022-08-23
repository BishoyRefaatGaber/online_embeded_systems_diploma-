#include "Platform.h"
/*HANDLER DEFINITION*/


extern uint_32 _stack_top;
extern uint_32 _S_DATA;
extern uint_32 _E_DATA;
extern uint_32 _S_bss;
extern uint_32 _E_bss;
extern uint_32 _E_text;

extern int main();
void Reset_Handler(void);

void Default_Handler(void){
	Reset_Handler();
}

void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void H_fault_handler(void)__attribute__((weak,alias("Default_Handler")));;
void MM_Fault_handler(void)__attribute__((weak,alias("Default_Handler")));;
void Bus_Fault_handler(void)__attribute__((weak,alias("Default_Handler")));;
/*HANDLER SECTIONING*/

uint_32 vectors[]__attribute__((section(".vectors"))) = {
	(uint_32) &_stack_top,
	(uint_32) &Reset_Handler,
	(uint_32) &NMI_Handler,
	(uint_32) &H_fault_handler,
	(uint_32) &MM_Fault_handler,
	(uint_32) &Bus_Fault_handler	
};

void Reset_Handler(void){
	uint_32 DATA_SIZE = (uint_8)&_E_DATA - (uint_8)&_S_DATA;
	uint_8* p_src =(uint_8*)&_E_text;
	uint_8* p_dst =(uint_8*)&_S_DATA;
	uint_32 i;
	for (i=0;i<DATA_SIZE;i++){
		*((uint_8*)p_dst++) = *((uint_8*)p_src++);
	}


	uint_32 BSS_SIZE = (uint_8*)&_E_bss - (uint_8*)&_S_bss;
	p_dst =(uint_8*)&_S_bss;
	for (i=0;i<BSS_SIZE;i++){
		*((uint_8*)p_dst++) = (uint_8)0;
	}

	main();
}