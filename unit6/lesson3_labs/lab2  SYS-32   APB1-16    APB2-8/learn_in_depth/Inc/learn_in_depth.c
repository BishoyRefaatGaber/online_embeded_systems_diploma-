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
	RCC_CR |= (1 << 0); //HSI_RC ON ---> 8MHZ
	RCC_CFGR &= ~(0b1111 << 18); //reset PLLMUL
	RCC_CFGR &= ~(1 << 16); //enable PLL -> HSI/2 ---> 4MHZ
	RCC_CFGR |= (0b0110 << 18); //PLLMUL multiplied by 8 ---> 32MHZ
	RCC_CR |= (1 << 24); //PLLON
	RCC_CFGR &= ~(0b11 << 0); //reset SW
	RCC_CFGR |= (0b10 << 0); //enable SW at PLLCLK ---> 32MHZ
	RCC_CFGR &= ~(0x1111 << 4); //AHB divided by 1 ---> 32MHZ
	RCC_CFGR &= ~(0b111 << 8);  //reset APB1
	RCC_CFGR |= (0b100 << 8);  //APB1 divided by 2 ---> 16MHZ
	RCC_CFGR &= ~(0b111 <<11); //reset APB2
	RCC_CFGR |= (0b101 << 11); //APB2 divided by 4 ---> 8MHZ
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
