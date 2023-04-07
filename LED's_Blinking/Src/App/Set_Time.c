#include "Set_Time.h"


uint8 on_SysTick_counts;
uint8 off_SysTick_counts;





/* SysTick Handler */
static void SysTick_ISR(void)
{

	static uint8 counter;
	

	static uint8  flag;

	counter++;	
	
	if(Dio_ReadChannel(Port_PinConfig[2].PortNum, Port_PinConfig[2].PortPinNum) == 0)
	{
		

		if((flag == 0) && (counter == on_SysTick_counts))
		{
			Dio_ClearChannel(Port_PinConfig[0].PortNum, Port_PinConfig[0].PortPinNum);
			flag = 1;
			counter = 0;
		}
	
		else if((flag == 1) && (counter == off_SysTick_counts))
		{
			Dio_WriteChannel(Port_PinConfig[0].PortNum, Port_PinConfig[0].PortPinNum);
			off_SysTick_counts = 0 , on_SysTick_counts = 0;
			counter = 0;
			flag = 0;
		}
		
	}
	
	else{
		counter = 0;
		flag = 0;
	}
}






void Sys_Init()
{

	SysTick_Init(&SysTick_Config_Modes);

	Port_Init(Port_PinConfig);

	Interrupt_CB(SysTick_ISR);
}
	






uint8 Set_Time(uint8 switch_port, uint8 switch_pin, uint8 button_port, uint8 button_pin)
{
	uint8 counts = 0;
	
	 /*Only Will Enter this Loop When the Switch is Closed  */
		while(Dio_ReadChannel(switch_port, switch_pin) == 1)
		{
			if(Dio_ReadChannel(button_port, button_pin) == 1)
			{
				counts++;
			}
		}
		return counts;
}

