/*
Welcome to the WeeW - Electronics
follow us on our Channel : https://www.youtube.com/channel/UCnTWd_4LwCEcAw19Jds0Vjg

The topic of this program is to:

- Set up an efficient UART communication 
- Using UART Interrupt


Related explanatory video : https://youtu.be/mb7G1-1RnZ8

*/

#include "stm32f10x.h"    
#include "gp_drive.h" 
#include "systick_time.h"
#include "uart_drive.h"
#include "garra.h"

char USART_1_msg[250];
unsigned short USART_1_cnt = 0;
unsigned short USART_1_sig = 0;
unsigned short USART_1_bdg = 0;

char USART_2_msg[250];
unsigned short USART_2_cnt = 0;
unsigned short USART_2_sig = 0;
unsigned short USART_2_bdg = 0;

char USART_3_msg[250];
unsigned short USART_3_cnt = 0;
unsigned short USART_3_sig = 0;
unsigned short USART_3_bdg = 0;
char pw1[] = "PWM1";
char pw2[]= "PWM2";


char chat = 'C';

char msg[30] = "Welcome to the WeeW\n";

int main(void)
{
systick_init();
UART_init(1,9600);
UART_init(3,9600);

DelayMs(100);

UART_SEND(1,"Nana");
UART_SEND(3,"Hey");
	

while(1)
	{
		if(USART_1_sig == 1)
		{
			UART_SEND(3,USART_1_msg);
			USART_1_sig = 0;
			str_empty(USART_1_msg);
		}
		if(USART_3_sig == 1)
		{
			UART_SEND(1,USART_3_msg);
			USART_3_sig = 0;
			str_empty(USART_3_msg);
		}
		
		
	}
}



void USART1_IRQHandler()
{
	UART_ISR(1,3,&USART_1_sig, &USART_1_cnt, USART_1_msg);
	if (USART_1_msg == pw1){
		motor1_sec1();
		
}
	}

void USART3_IRQHandler()
{
	UART_ISR(3,1,&USART_3_sig, &USART_3_cnt, USART_3_msg);
		if (USART_3_msg == pw2){
		motor2_sec1();
		
}


}

