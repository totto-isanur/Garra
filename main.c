/*GPIO functional description (p.158)
Memory and bus architecture (p.46)

*/

//user defined libs
#include "gpio.h"
#include "leds.h"
#include "timers.h"
#include "garra.h"

int main(void){
	init_gpio();
	led_on_off(50);
	//led_onoff_timer2(1000);
	
	
	/*Using timers
	***************/
	//timer2_output_compare();
	//timer2_pwm();
	while(1){
	sec1();
  sec2();
	}
}