typedef volatile unsigned int vuint32_t ;
#define RCC_BASE  0x40021000
#define GPIO_BASE 0x40010800
#define EXTI_BASE 0x40010400
#define AFIO_BASE 0x40010000
#define RCC_APB2ENR *((vuint32_t*)(RCC_BASE + 0x18))
#define GPIO_CRH *((vuint32_t*)(GPIO_BASE + 0x04))
#define GPIO_CRL *((vuint32_t*)(GPIO_BASE + 0x00))
#define GPIO_ODR *((vuint32_t*)(GPIO_BASE + 0x0C))
#define EXTI_IMR *((vuint32_t*)(EXTI_BASE + 0x00))
#define EXTI_RTSR *((vuint32_t*)(EXTI_BASE + 0x08))
#define EXTI_PR *((vuint32_t*)(EXTI_BASE + 0x14))
#define AFIO_EXTICR1 *((vuint32_t*)(AFIO_BASE + 0x08))
#define NVIC_EXTIE0 *((vuint32_t*)(0xE000E100))
void init(){
	RCC_APB2ENR |=1<<2; //enable GPIO CLOCK
	RCC_APB2ENR |=1<<0; //enable AFIO CLOCK
	GPIO_CRH &=0xff0fffff; //GPIO PIN13 RESET
	GPIO_CRH |=0x00200000; //GPIO PIN13 ENABLE
	EXTI_IMR |= 0b1; //enable line bit 0
	EXTI_RTSR |= 0b1; //enable rising trigger bit 0
	EXTI_PR |=0b1; //enable pending register
	AFIO_EXTICR1 = 0; //enable AFIO
	GPIO_CRL |= (1 << 2); //enable pin0 floating input
	NVIC_EXTIE0 |= (1 << 6); //enable NVIC
}
int main(void)
{

	init();
	while(1);

	return 0;

}
void EXTI0_IRQHandler(void){
	GPIO_ODR ^= (1 << 13);
	EXTI_PR |=0b1; //disable pending register
}
