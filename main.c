/*GPIO functional description (p.158)
Memory and bus architecture (p.46)

*/


#include "gpio.h"
#include "leds.h"
#include "timers.h"
#include "garra.h"
#include "interrupts.h"
#include "usart.h"

int main(void){
	init_gpio();
	//ext_interrupt_1();
	//ext_interrupt_2();
	
	led_on_off(50);
	//led_onoff_timer2(1000);
	
	
	/*Using timers
	***************/
	//timer2_ch1_oc();
	//timer3_ch1_pwm();
	usart_polling();
	
	while(1){
		
	}
}