typedef volatile unsigned int vuint32_t ;
#define RCC_BASE  0x40021000
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00
#define RCC_APB2ENR *((vuint32_t*)(RCC_BASE + 0x18))

#define GPIOA_CRH *((vuint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_CRL *((vuint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR *((vuint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR *((vuint32_t*)(GPIOA_BASE + 0x08))

#define GPIOB_CRL *((vuint32_t*)(GPIOB_BASE + 0x00))
#define GPIOB_CRH *((vuint32_t*)(GPIOB_BASE + 0x04))
#define GPIOB_IDR *((vuint32_t*)(GPIOB_BASE + 0x08))
#define GPIOB_ODR *((vuint32_t*)(GPIOB_BASE + 0x0C))

void init(){

	RCC_APB2ENR |= (1<<2); //enable GPIO CLOCK
	RCC_APB2ENR |= (1<<3); //enable GPIOB CLOCK


	GPIOA_CRL = 0;
	GPIOB_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_ODR = 0;




	GPIOA_CRH &= ~(0b1111 << 20); //GPIO PIN13 RESET
	GPIOA_CRH |= (0b0100 << 20); //GPIO PIN13 ENABLE  input -> pull down (float)
	GPIOA_CRL &= ~(0b1111 << 4); //GPIO PIN1 RESET
	GPIOA_CRL |= (0b0100 << 4); //GPIO PIN1 ENABLE  input -> pull down (float)

	GPIOB_CRH &= ~(0b1111 << 20); //GPIO PIN13 RESET
	GPIOB_CRH |= (0b0001 << 20); //GPIO PIN13 ENABLE  input -> pull down (float) MAXSPEED 10MHZ
	GPIOB_CRL &= ~(0b1111 << 4); //GPIO PIN1 RESET
	GPIOB_CRL |= (0b0001 << 4); //GPIO PIN1 ENABLE  input -> pull down (float)   MAXSPEED 10MHZ
}
void wait_ms(vuint32_t time){
	vuint32_t i=0,j=0;
	for(; i < time ; i++){
		for (; j < 255 ; j++);
	}
}
int main(void)
{
	init();
	while(1){
		if (((GPIOA_IDR & (1 << 1)) >> 1) == 0){
			GPIOB_ODR ^= (1 << 1);
			while (((GPIOA_IDR & (1 << 1)) >> 1) == 0);
		}

		if(((GPIOA_IDR & (1 << 13)) >> 13) == 1){
			GPIOB_ODR ^= (1 << 13);
		}
		wait_ms(1);
	}

	return 0;

}

