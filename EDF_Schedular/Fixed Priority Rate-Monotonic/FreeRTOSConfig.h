/*
 * FreeRTOS V202112.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <lpc21xx.h>
#include "gpio.h"
/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE. 
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION		1
#define configUSE_IDLE_HOOK			1
#define configUSE_TICK_HOOK			1
#define configCPU_CLOCK_HZ			( ( unsigned long ) 60000000 )	/* =12.0MHz xtal multiplied by 5 using the PLL. */
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES		( 4 )
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 90 )
#define configTOTAL_HEAP_SIZE		( ( size_t ) 13 * 1024 )
#define configMAX_TASK_NAME_LEN		( 8 )
#define configUSE_16_BIT_TICKS		0
#define configIDLE_SHOULD_YIELD		1
#define configUSE_TRACE_FACILITY                1

#define configQUEUE_REGISTRY_SIZE 	0

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 		0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
extern int task_1_in_time, task_1_out_time, task_1_total_time;														
extern int task_2_in_time, task_2_out_time, task_2_total_time;														
extern int task_3_in_time, task_3_out_time, task_3_total_time;														
extern int task_4_in_time, task_4_out_time, task_4_total_time;														
extern int task_5_in_time, task_5_out_time, task_5_total_time;														
extern int task_6_in_time, task_6_out_time, task_6_total_time;				
extern int system_time;													
extern int cpu_load;			
#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1

#define configUSE_EDF_SCHEDULER		0
#define configUSE_TIME_SLICING    1

#define configUSE_APPLICATION_TASK_TAG 	1

#define configUSE_STATS_FORMATTING_FUNCTIONS 1
#define configGENERATE_RUN_TIME_STATS 1
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
#define portGET_RUN_TIME_COUNTER_VALUE() (T1TC)

#define traceTASK_SWITCHED_OUT()	do\
																	{\
																		if ((int)pxCurrentTCB->pxTaskTag == 1)\
																		{\
																			GPIO_write(PORT_0, PIN4, PIN_IS_LOW);\
																			task_1_out_time = T1TC;\
																			task_1_total_time += (task_1_out_time - task_1_in_time);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 2)\
																		{\
																			GPIO_write(PORT_0, PIN5, PIN_IS_LOW);\
																			task_2_out_time = T1TC;\
																			task_2_total_time += (task_2_out_time - task_2_in_time);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 3)\
																		{\
																			GPIO_write(PORT_0, PIN6, PIN_IS_LOW);\
																			task_3_out_time = T1TC;\
																			task_3_total_time += (task_3_out_time - task_3_in_time);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 4)\
																		{\
																			GPIO_write(PORT_0, PIN7, PIN_IS_LOW);\
																			task_4_out_time = T1TC;\
																			task_4_total_time += (task_4_out_time - task_4_in_time);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 5)\
																		{\
																			GPIO_write(PORT_0, PIN8, PIN_IS_LOW);\
																			task_5_out_time = T1TC;\
																			task_5_total_time += (task_5_out_time - task_5_in_time);\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 6)\
																		{\
																			GPIO_write(PORT_0, PIN9, PIN_IS_LOW);\
																			task_6_out_time = T1TC;\
																			task_6_total_time += (task_6_out_time - task_6_in_time);\
																		}\
																		system_time=T1TC;\
																		cpu_load= ( (task_1_total_time + task_2_total_time + task_3_total_time + task_4_total_time + task_5_total_time + task_6_total_time) / (float) system_time )*100;\
																	}while(0)
#define traceTASK_SWITCHED_IN()	do\
																	{\
																		if ((int)pxCurrentTCB->pxTaskTag == 1)\
																		{\
																			GPIO_write(PORT_0, PIN4, PIN_IS_HIGH);\
																			task_1_in_time= T1TC;\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 2)\
																		{\
																			GPIO_write(PORT_0, PIN5, PIN_IS_HIGH);\
																			task_2_in_time= T1TC;\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 3)\
																		{\
																			GPIO_write(PORT_0, PIN6, PIN_IS_HIGH);\
																			task_3_in_time= T1TC;\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 4)\
																		{\
																			GPIO_write(PORT_0, PIN7, PIN_IS_HIGH);\
																			task_4_in_time= T1TC;\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 5)\
																		{\
																			GPIO_write(PORT_0, PIN8, PIN_IS_HIGH);\
																			task_5_in_time= T1TC;\
																		}\
																		else if ((int)pxCurrentTCB->pxTaskTag == 6)\
																		{\
																			GPIO_write(PORT_0, PIN9, PIN_IS_HIGH);\
																			task_6_in_time= T1TC;\
																		}\
																	}while(0)


																	
#endif /* FREERTOS_CONFIG_H */