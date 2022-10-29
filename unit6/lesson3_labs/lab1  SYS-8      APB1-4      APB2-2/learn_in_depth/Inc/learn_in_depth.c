#define RCC_BASE   0x40021000
#define PortA_BASE 0x40010800
typedef volatile unsigned int vuint32_t ;
#define RCC_CR  *((vuint32_t*)(RCC_BASE + 0x00))
#define RCC_CFGR *((vuint32_t*)(RCC_BASE + 0x04))
#define RCC_AHBENR *((vuint32_t*)(RCC_BASE + 0x14))
#define RCC_APB2ENR *((vuint32_t*)(RCC_BASE + 0x18))
#define GPIO_CRH *((vuint32_t*)(PortA_BASE + 0x04))
#define GPIO_ODR *((vuint32_t*)(PortA_BASE + 0x0C))

typedef union{
	vuint32_t allfield;
	struct{
		vuint32_t reserved:13;
		vuint32_t pin13:1;
	}pin;
}R_ODR_T;
volatile R_ODR_T* R_ODR= (volatile R_ODR_T*)(PortA_BASE + 0x0C);

int main(void)
{
	RCC_CR |= (0b1<<0); //HSI_RC ON
	RCC_CFGR &= (0b00 << 0); //enable SW at HSI
	RCC_CFGR &= (0x0000<<4); //AHB divide by 1
	RCC_CFGR &= ~(0b111 << 8);  //reset APB1
	RCC_CFGR |= (0b100 << 8);  //APB1 divide by 2
	RCC_CFGR &= ~(0b111 <<11); //reset APB2
	RCC_CFGR |= (0b101 << 11); //APB2 divide by 4
	RCC_APB2ENR |=1<<2; //enable CLOCK
	GPIO_CRH    &=0xff0fffff;
	GPIO_CRH    |=0x00200000;

	while(1){
		R_ODR->pin.pin13=1;
		for(int i=0;i<5000;i++);
		R_ODR->pin.pin13=0;
		for(int i=0;i<5000;i++);
	}
	return 0;

}
