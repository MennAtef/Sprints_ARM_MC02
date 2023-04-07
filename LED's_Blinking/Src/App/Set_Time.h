
#ifndef SET_TIME_H
#define SET_TIME_H





#include "PORT.h"
#include "IntCtrl.h"
#include "SysTick.h"
#include "Bit_Math.h"


extern uint8 on_SysTick_counts;
extern uint8 off_SysTick_counts;


void Sys_Init();
uint8 Set_Time(uint8 switch_port, uint8 switch_pin, uint8 button_port, uint8 button_pin);


#endif