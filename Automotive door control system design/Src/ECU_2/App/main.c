#include "std_types.h"
#include "platform_types.h"
#include "Macros.h"
#include "mcu_hw.h"
#include "IntCtrl_types.h"
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "ExternalInterrupts.h"
#include "Port.h"
#include "Dio.h"
#include "/SysTick.h"
#include "IntCtrl_Cfg.h"
#include "Sys_Ctrl_Cfg.h"
#include "Port_Cfg.h"
#include "LED.h"
#include "LED_Cfg.h"

static uint8 Count=0;

uint8 On_Count = on_time/1;
uint8 Off_Count = (off_time/1);

int main()
{
	IntCtrl_Init();
	SYS_CTRL_INIT();
	PORT_init();
    SYS_TICK_init(1);

	while(1)
	{

    }
}

void SysTick_Handler(void)
{
	/*1,1*/
	
	if (Count<On_Count)
		led_state(PinF4, 1);
	else if (Count >=(Off_Count+On_Count))
	{
		Count = 0;
		led_state(PinF4, 1);
	}
	else if (Count>=On_Count)
		led_state(PinF4, 0);
	Count++;
}