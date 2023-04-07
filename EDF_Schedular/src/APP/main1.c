/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*
 * FreeRTOS Kernel 202212.00
 * Copyright (C) 2022 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
//Standard's
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Schedular's
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "queue.h"

//Peripharal's
#include "serial.h"
#include "GPIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
//To set UP I/0 and Processor
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

//Constant the ComTest demo app tasks
static void prvSetupHardware( void );
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
unsigned int BUTTON1,BUTTON2,LOAD1,LOAD2,Transmit_UART,Receive_UART,Sum_Exe,Load_CPU;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
BaseType_t xReturned;
TaskHandle_t B1_taskHandler,B2_taskHandler,Trans_TaskHandler,Receiv_TaskHandler,L1_TaskHandler,L2_TaskHandler;
QueueHandle_t q1,q2,q3;
char RT_state[400];
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Periodic_Transmit (void * pvParameters );
void Uart_Receive (void * pvParameters );
void Button_1_Monitor( void * pvParameters );
void Load_2_Simulation ( void * pvParameters );
void Button_2_Monitor( void * pvParameters );
void Load_1_Simulation ( void * pvParameters );
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
v void Periodic_Transmitter (void * pvParameters )
{   uint8_t i = 0,Size=15;
	char Sent_String[15] = "\nnew period.";
	TickType_t Final_WT = xTaskGetTickCount();
	for( ; ; )
	{
		for( i=0 ; i<Size ; i++)
		{	
			xQueueSend( q3 , Sent_String+i ,100); 
		}
		
		GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
	vTaskDelayUntil( &Final_WT , 100);
		
	GPIO_write(PORT_1,PIN2,PIN_IS_HIGH);
		
	 GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		
	GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	}
}

void Uart_Receiver (void * pvParameters )
{   uint8_t Size = 15,i=0;
	signed char B1, B2;
	TickType_t Final_WT = xTaskGetTickCount();
	char recveived_array[15];
	for( ; ; )
	{
		if( xQueueReceive( q1, &B1 , 0) && B1 != '.')
		{
			//first queue
		xSerialPutChar('\n');	
			if(B1=='+')
			{   char PositiveString[]="Positive edge from button1\n";
							vSerialPutString((signed char *) PositiveString, strlen(PositiveString));
			}
			else
			{  char NegativeString[]="Negative edge from button1\n";
							vSerialPutString((signed char *) NegativeString, strlen(NegativeString));
			}
		}
		else
		{
			//add space
			int x=0;
			for(x=0;x<5;x++){
			xSerialPutChar(' ');		
}
		}
		if( xQueueReceive( q2, &B2 , 0) && B2 != '.')
		{
			//second queue
			xSerialPutChar('\n');		
			if(B2=='+')
			{ char PositiveString[]=" Positive edge from button 2 \n";
							vSerialPutString((signed char *) PositiveString, strlen(PositiveString));
			}
			else
			{	char NegativeString[]=" Negative edge from button 2 \n";
							vSerialPutString((signed char *) NegativeString, strlen(NegativeString));
			}
		}
		else
		{
		 //add space
			int x=0;
			for(x=0;x<5;x++){
			xSerialPutChar(' ');		
}
		}
		
		//third queue
		if( uxQueueMessagesWaiting(q3) >0)
		{
			for( i=0 ; i<Size ; i++)
			{
				xQueueReceive( q3, (recveived_array+i) , 0);
			}
			vSerialPutString( (signed char *) recveived_array, strlen(recveived_array));
			xQueueReset(q3);
		}
				
		GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		vTaskDelayUntil( &Final_WT , 20);
	GPIO_write(PORT_1,PIN3,PIN_IS_HIGH);
	
	GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	}
}

void Button_1_Monitor( void * pvParameters )
{
	pinState_t B1State, PreviousState = GPIO_read(PORT_0 , PIN0); /*pin 16 */
	TickType_t Final_WT = xTaskGetTickCount();
	signed char edges = 0;
	for( ;; )
	{
	B1State = GPIO_read(PORT_0 , PIN0);
	if( B1State == PIN_IS_HIGH && PreviousState == PIN_IS_LOW)
		{
		   	edges = '+';
		}
	else if (B1State == PIN_IS_LOW && PreviousState == PIN_IS_HIGH)
	    {
		edges = '-';	
		}
		else
		{	//not positive nor negative
			edges = '.';
		}
		// update the prev state to the current state
		PreviousState = B1State;
		
		//send the corresponding data
	xQueueOverwrite( q1 , &edges );
		
	  GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
	vTaskDelayUntil( &Final_WT ,50);
		GPIO_write(PORT_1,PIN0,PIN_IS_HIGH);
		GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	}
}

void Button_1_Monitor( void * pvParameters )
{
	pinState_t B1State, PreviousState = GPIO_read(PORT_0 , PIN0); /*pin 16 */
	TickType_t Final_WT = xTaskGetTickCount();
	signed char Edges = 0;
	for( ;; )
	{
	B1State = GPIO_read(PORT_0 , PIN0);
	if( B1State == PIN_IS_HIGH && PreviousState == PIN_IS_LOW)
		{
		   	Edges = '+';
		}
	else if (B1State == PIN_IS_LOW && PreviousState == PIN_IS_HIGH)
	{
		Edges = '-';	
		}
		else
		{	//not positive nor negative
			Edges = '.';
		}
		// update the prev state to the current state
		PreviousState = B1State;
		
		//send the corresponding data
	xQueueOverwrite( q1 , &Edges );
		
	  GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
	vTaskDelayUntil( &Final_WT ,50);
		GPIO_write(PORT_1,PIN0,PIN_IS_HIGH);
		GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	}
}

void Button_2_Monitor( void * pvParameters )
{
	pinState_t B2State,PreviousState = GPIO_read(PORT_0 , PIN1);
	TickType_t Final_WT = xTaskGetTickCount();
	signed char Edges = 0;
	for( ;; )
	{
		B2State = GPIO_read(PORT_0 , PIN1);
	if( B2State == PIN_IS_HIGH && PreviousState == PIN_IS_LOW)
		{
			Edges = '+';
		}
	else if (B2State == PIN_IS_LOW && PreviousState == PIN_IS_HIGH)
		{
			Edges = '-';
		}
		else
		{
	  //not positive nor negative
		Edges = '.';
		}
	PreviousState = B2State;		
		// update the prev state to the current state
		//send the corresponding data
		xQueueOverwrite( q2 , &Edges ); 
		
		GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
	vTaskDelayUntil( &Final_WT , 50);
		
	GPIO_write(PORT_1,PIN1,PIN_IS_HIGH);

		GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		
		
		GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	}
}

void Load_1_Simulation ( void * pvParameters )
{
	uint32_t i = 0;

	TickType_t Final_WT = xTaskGetTickCount();

	for( ; ; )
	{ //using 7 ms of total delay
	for( i=0 ; i <= 12000*7; i++);
		
		GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
		vTaskDelayUntil( &Final_WT , 20);
		GPIO_write(PORT_1,PIN5,PIN_IS_HIGH);
	GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
		
GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	}
}

void Load_2_Simulation ( void * pvParameters )
{
	uint32_t i = 0;
TickType_t Final_WT = xTaskGetTickCount();
	for( ; ; )
	{	//using 13 ms of total delay
	for( i=0 ; i <= 12000*12; i++);

		GPIO_write(PORT_1,PIN6,PIN_IS_LOW);
	vTaskDelayUntil( &Final_WT , 100);
		
	GPIO_write(PORT_1,PIN6,PIN_IS_HIGH);
	GPIO_write(PORT_1,PIN0,PIN_IS_LOW);
		
	GPIO_write(PORT_1,PIN1,PIN_IS_LOW);
		
	GPIO_write(PORT_1,PIN2,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN4,PIN_IS_LOW);
	GPIO_write(PORT_1,PIN3,PIN_IS_LOW);
		
		GPIO_write(PORT_1,PIN5,PIN_IS_LOW);
	}
}

int main( void )
{
	/*Hardware setup */
	prvSetupHardware();
  // assigning each queue to a xcreated queue
q1 = xQueueCreate( 1, sizeof(char) );
q2 = xQueueCreate( 1, sizeof(char) );
q3 = xQueueCreate( 15, sizeof(char) );
    /* Create Tasks here */  
	
xTaskPeriodicCreate(Button_1_Monitor,"first",100,( void * ) 0,1,&B1_taskHandler,50);      				
					
xTaskPeriodicCreate(Button_2_Monitor,"second",100,( void * ) 0,1,&B2_taskHandler,50);  

xTaskPeriodicCreate(Periodic_Transmitter,"Trans",100,( void * ) 0,1,&Trans_TaskHandler,100);  

xTaskPeriodicCreate(Uart_Receiver,"Recv",100,( void * ) 0,1,&Receiv_TaskHandler,20);      				


xTaskPeriodicCreate(Load_1_Simulation, "load1", 100,( void * ) 0,1,&L1_TaskHandler,10);      				
										
										
xTaskPeriodicCreate(Load_2_Simulation, "load2", 100, ( void * ) 0,1, &L2_TaskHandler, 100);    

	vTaskStartScheduler();
	for( ;; );
}

void vApplicationTickHook (void)
{
	SET_PIN(PORT_0,PIN9); CLEAR_PIN(PORT_0,PIN9);
}

static void configTimer1(void)
{  
    T1PR = 1000; 
}

void timer1Reset(void)
{  T1TCR |= 0x2; T1TCR &= ~0x2;
}

static void prvSetupHardware( void )
{

	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  END OF FILE: main1.c
 *********************************************************************************************************************/