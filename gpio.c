#include <stm32f10x.h>

void init_gpio(void){
	//init portA
	RCC->APB2ENR |= 1 << 2; //enable clk
	/***********output compare***************/
	//PA0 mode 2MHz.
	GPIOA->CRL |= (1 << 1);
	GPIOA->CRL &= ~(1 << 0);
	//PA0 alternate function pushpull
	GPIOA->CRL |= (1 << 3);
	GPIOA->CRL &= ~(1 << 2);

	/***********pwm***************/
	//PA1 mode 2MHz.
	GPIOA->CRL |= (1 << 5);
	GPIOA->CRL &= ~(1 << 4);
	//PA1 alternate function pushpull
	GPIOA->CRL |= (1 << 7);
	GPIOA->CRL &= ~(1 << 6);

	//alternate function remap
	AFIO->MAPR &= ~((1 << 9)|(1 << 8));
	
	
	//init portC
	RCC->APB2ENR |= (1 << 4);
	//PC13 as Output push/pull
	GPIOC->CRH &= ~((1 << 23)|(1 << 22)|(1 << 20));
	GPIOC->CRH |= (1 << 21);
	
	// Timer 3
	GPIOA -> CRL |= (1 << 27);
	GPIOA -> CRL &= ~(1 << 26);
	GPIOA -> CRL |= (1 << 25); 
	GPIOA -> CRL &=  ~( 1 << 24);
}
