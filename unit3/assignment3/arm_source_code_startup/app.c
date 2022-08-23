#include "Platform.h"
#define RCC_BASE   0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR  *((vuint_32*)(RCC_BASE + 0x18))
#define GPIO_CRH     *((vuint_32*)(PortA_BASE + 0x04))
#define GPIO_ODR     *((vuint_32*)(PortA_BASE + 0x0C))

typedef union{
	vuint_32 allfield;
	struct{
	vuint_32 reserved:13;
	vuint_32 pin13:1;
	}pin;
}R_ODR_T;
volatile R_ODR_T* R_ODR= (volatile R_ODR_T*)(PortA_BASE + 0x0C);

int main()
{

	RCC_APB2ENR |=1<<2;
	GPIO_CRH    &=0xff0fffff;
	GPIO_CRH    |=0x00200000;
	int i=0;
	while(1){
		R_ODR->pin.pin13=1;
		for(i=0;i<5000;i++);
		R_ODR->pin.pin13=0;
		for(i=0;i<5000;i++);
	}
	return 0;

}
