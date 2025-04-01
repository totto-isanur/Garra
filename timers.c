#include "stm32f10x.h"
/* CNT-> counter register
	ARR -> Auto Reload Register, his value is continuously compared to CNT
	CR1 -> Control Register
	SR -> Status Register when ARR=CNT UIF(update interrupt flag) is set
	and CNT=0
*/

void delay_timer2()
{
	RCC->APB1ENR |= 1 << 0; //enable TIM2 clock 
	TIM2->ARR = 7;
	TIM2->SR |= ~(1 << 0); //clear uif flag
	TIM2->CR1 |= ~(1 << 4);//upcounting
	while (TIM2->SR & (1 << 0))
	TIM2->CR1 = ~(1 << 0); //counter disable 
}

void timer2_output_compare(){
	
	RCC->APB1ENR|= 1 << 0; //enable TIM2 clk
	/* 
	Tout=[(ARR+1)(PSC+1)]/Fclk
	or ARR = {[(Tout)(Fclk)]/(PSC+1)}-1
	Tout: is desired pulse width
	PSC: Prescaller (can be a supposed value, but must be ARR <= 65,535)
	Fclk: Clock frequency (72 Mhz if internal clock used)
	Example for 1ms pulse width and PSC=1
		ARR = [(1ms)(72Mhz)/(1+1)]-1 = 35,999
	*/
	TIM2->PSC=1;
	TIM2->ARR=35999;
	//OC1M in Toggle on Match Mode
	TIM2->CCMR1 |= (1 << 5) | (1 << 4);
	//capture/compare enable register
	TIM2->CCER |= (1 << 0);
	//enable timer
	TIM2->CR1 |= (1 << 0);
}

void timer2_pwm(){
	
	RCC->APB1ENR |= (1 << 0);	//enable TIM2 clk
	/* 
	DutyCycle = [CCR/(ARR+1]x100%
	Fpwm = Fclk/[(ARR + 1)(PSC+1)]
	Example: 1ms pulse over 20ms(50hz)
	Assuming PSC=21
	ARR = [(Fclk)/(F_pwm)(PSC+1)]-1 = [(72MHz)/(50Hz)(21+1)] -1 = 65453
	DutyCycle=(2ms/20ms)x100%=10%
	CCR = DutyCycle(ARR+1)
	CCR=0.05x(65453+1)=3,272.7
	*/
	TIM2->PSC=27;
	TIM2->ARR=64284;
	TIM2->CCR2 = 3273;
	TIM2->CCMR1 |= (1 << 4) | (1 << 5); //select pwm mode ch2
	TIM2->CCER	|=	(1 << 0);	//enable ch2
	TIM2->CR1		|=	(1 << 0); //enable timer
	/*
	while(1)
	{
		for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR2 = i;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM2->CCR2 = i;
				for (int j = 0;j < 65453;j++);
			}
	}
	*/
}
void timer3_pwm (){
	RCC->APB1ENR |= (1 << 1);	
	TIM3->PSC=27;
	TIM3->ARR=64284;
	TIM3->CCR2 = 3273;
	TIM3->CCMR1 |= (1 << 4) | (1 << 5); 
	TIM3->CCER	|=	(1 << 0);	
	TIM3->CR1		|=	(1 << 0); 

}
	
