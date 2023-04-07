#include "Set_Time.h"


int main(void)
{
	Sys_Init();
	
	uint8 led_port = Port_PinConfig[0].PortNum;
	uint8 led_pin  = Port_PinConfig[0].PortPinNum;
	
	uint8 button_port  = Port_PinConfig[1].PortNum;
	uint8 button_pin   = Port_PinConfig[1].PortPinNum;
	
	uint8 switch_port = Port_PinConfig[2].PortNum;
	uint8 switch_pin  = Port_PinConfig[2].PortPinNum;

	
	uint8 on_time = 0, off_time = 0;
	
	while(1){
		

		on_time = Set_Time(switch_port, switch_pin, button_port, button_pin);
		

		off_time = Set_Time(switch_port, switch_pin, button_port, button_pin);
		

		Dio_WriteChannel(led_port, led_pin);
		
		
		while((Dio_ReadChannel(switch_port, switch_pin) == 0) && (on_time > 0) && (off_time > 0))
		{
			on_SysTick_counts = SysTick_Set_Counts_Needed(on_time);
			
			off_SysTick_counts = SysTick_Set_Counts_Needed(off_time);
		}
		
	}
	
}





 

