#include "Platform.h"

#define RCC_BASE  0x40021000
#define GPIO_BASE 0x40010800

#define RCC_APB2ENR *((vuint_32 *)(RCC_BASE + 0X18))
#define GPIO_CRH    *((vuint_32*)(GPIO_BASE + 0X04))
#define GPIO_ODR    *((vuint_32*)(GPIO_BASE + 0x0C))
#define RCC_IOPAEN (1<<2)
typedef union {
	vuint_32 all_fields;
	struct{
		vuint_32 reserved:13;
		vuint_32 p_13:1;
	}pin;
}R_ODR_T;

volatile R_ODR_T* R_ODR = (volatile R_ODR_T*)(GPIO_BASE + 0x0C);

int main(void){
RCC_APB2ENR |=RCC_IOPAEN;
GPIO_CRH    &=0xff0fffff;
GPIO_CRH    |=0x00200000;
uint_32 i=0;
while(1){
	R_ODR->pin.p_13=1;
	for(;i<5000;i++);
	R_ODR->pin.p_13=0;
	for(;i<5000;i++);	
}

}