/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "queue.h"
/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( uint8 ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( uint32 ) 115200 )
TaskHandle_t xHandle = NULL;

BaseType_t xTaskPeriodicCreate( TaskFunction_t pxTaskCode,
                            const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                            const configSTACK_DEPTH_TYPE usStackDepth,
                            void * const pvParameters,
                            UBaseType_t uxPriority,
                            TaskHandle_t * const pxCreatedTask,
														 TickType_t period									);
/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */

int task_1_in_time = 0, task_1_out_time = 0, task_1_total_time;														
int task_2_in_time = 0, task_2_out_time = 0, task_2_total_time;														
int task_3_in_time = 0, task_3_out_time = 0, task_3_total_time;														
int task_4_in_time = 0, task_4_out_time = 0, task_4_total_time;														
int task_5_in_time = 0, task_5_out_time = 0, task_5_total_time;														
int task_6_in_time = 0, task_6_out_time = 0, task_6_total_time;				
int system_time = 0;														
int cpu_load = 0;				
char RunTimeStatsBuff[190];														
static void prvSetupHardware( void );
														
typedef struct 
{
   char ucMessageID;
   char ucData[20 ];
} xMessage;

QueueHandle_t xQueue1 = NULL;

void Button_1_monitor( void * pvParameters )
{		
		/*button1 is on pin2*/
		/*trace hook on pin4*/
    TickType_t xLastWakeTime;
		const TickType_t xFrequency = 50;
		xMessage Button1_rising={'1', "Button 1 rising\n"};
		xMessage Button1_falling={'1', "Button 1 falling\n"};
		uint8_t LastButtonState=1;
		uint8_t CurrentButtonState;
		xLastWakeTime = xTaskGetTickCount();
		
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
		vTaskSetApplicationTaskTag( NULL, (void *) 1 );
    for( ;; )
    {
			vTaskDelayUntil( &xLastWakeTime, xFrequency );
			CurrentButtonState=GPIO_read(PORT_0, PIN1);
			if (CurrentButtonState == LastButtonState)
			{
				continue;
			}
			else
				if (CurrentButtonState == 1)
					xQueueSend(xQueue1,( void * ) &Button1_rising, ( TickType_t ) 10  != pdPASS );
				else 
					xQueueSend(xQueue1,( void * ) &Button1_falling, ( TickType_t ) 10  != pdPASS );
			LastButtonState = CurrentButtonState;
    }
}


void Button_2_monitor( void * pvParameters )
{
		/*button1 is on pin3*/
		/*trace hook on pin5*/
    TickType_t xLastWakeTime;
		xMessage Button2_rising={'2', "Button 2 rising\n"};
		xMessage Button2_falling={'2', "Button 2 falling\n"};
		uint8_t LastButtonState=1;
		uint8_t CurrentButtonState;
		const TickType_t xFrequency = 50;
		xLastWakeTime = xTaskGetTickCount();


    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
		vTaskSetApplicationTaskTag( NULL, (void *) 2 );
    for( ;; )
    {
			vTaskDelayUntil( &xLastWakeTime, xFrequency );
			CurrentButtonState=GPIO_read(PORT_0, PIN2);
			{
				continue;
			}
				if (CurrentButtonState == 1)
					xQueueSend(xQueue1,( void * ) &Button2_rising, ( TickType_t ) 10  != pdPASS );
				else 
					xQueueSend(xQueue1,( void * ) &Button2_falling, ( TickType_t ) 10  != pdPASS );
			LastButtonState = CurrentButtonState;
    }
}

void Periodic_Transmitter( void * pvParameters )
{		
		/*trace hook on pin6*/
	  TickType_t xLastWakeTime;
		const TickType_t xFrequency = 100;
		xMessage periodic_transmitter_data={'3', " peroidic       \n"};
		xLastWakeTime = xTaskGetTickCount();
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
		vTaskSetApplicationTaskTag( NULL, (void *) 3 );
    for( ;; )
    {
			vTaskDelayUntil( &xLastWakeTime, xFrequency );
			GPIO_write(PORT_0, PIN5, PIN_IS_HIGH);
			xQueueSend(xQueue1,( void * ) &periodic_transmitter_data, ( TickType_t ) 10  != pdPASS );
			GPIO_write(PORT_0, PIN5, PIN_IS_LOW);
    }
		
}


void UART_RECV( void * pvParameters )
{
		/*trace hook on pin7*/
		xMessage pxRxedPointer;
    TickType_t xLastWakeTime;
		const TickType_t xFrequency = 20;
		xLastWakeTime = xTaskGetTickCount();
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
		vTaskSetApplicationTaskTag( NULL, (void *) 4 );
    for( ;; )
    {
			vTaskDelayUntil( &xLastWakeTime, xFrequency );
			xQueueReceive( xQueue1, &pxRxedPointer, portMAX_DELAY);
			vSerialPutString(pxRxedPointer.ucData, 17);
    }
}

void Load_1_Simulation( void * pvParameters )
{	
		/*trace hook on pin8*/
		int i =0;
    TickType_t xLastWakeTime;
		const TickType_t xFrequency = 10;
		xLastWakeTime = xTaskGetTickCount();
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
		vTaskSetApplicationTaskTag( NULL, (void *) 5 );
    for( ;; )
    {
			for (i=0; i<35000; i++)			/*5ms*/
			{
				i=i;
			}
			vTaskDelayUntil( &xLastWakeTime, xFrequency );
    }
}


void Load_2_Simulation( void * pvParameters )
{
		/*trace hook on pin9*/	
		int i =0;
    TickType_t xLastWakeTime;
		const TickType_t xFrequency = 100;
		xLastWakeTime = xTaskGetTickCount();
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
		vTaskSetApplicationTaskTag( NULL, (void *) 6 );
    for( ;; )
    {
			for (i=0; i<80000; i++)		/*12ms*/
			{
				i=i;
			}
			vTaskGetRunTimeStats(RunTimeStatsBuff);
			vSerialPutString(RunTimeStatsBuff, 190);
			xSerialPutChar('\n');
			vTaskDelayUntil( &xLastWakeTime, xFrequency );
    }
}

void vApplicationIdleHook( void )
{
	GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
	GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
}

void vApplicationTickHook( void )
{
	GPIO_write(PORT_0, PIN1, PIN_IS_HIGH);
	GPIO_write(PORT_0, PIN1, PIN_IS_LOW);
}
int main( void )
{	
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
	xQueue1 = xQueueCreate(5, sizeof(xMessage));
	
	xTaskCreate( Button_1_monitor, ( const char * ) "A", configMINIMAL_STACK_SIZE, NULL, 4, NULL );
	xTaskCreate( Button_2_monitor, ( const char * ) "B", configMINIMAL_STACK_SIZE, NULL, 3, NULL );
	xTaskCreate( Periodic_Transmitter, ( const char * ) "C", configMINIMAL_STACK_SIZE, NULL, 2, NULL );
	xTaskCreate( UART_RECV, ( const char * ) "D", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
	xTaskCreate( Load_1_Simulation, ( const char * ) "E", configMINIMAL_STACK_SIZE, NULL, 6, NULL );
	xTaskCreate( Load_2_Simulation, ( const char * ) "F", configMINIMAL_STACK_SIZE, NULL, 1, NULL );

    /* Create Tasks here */


	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}


