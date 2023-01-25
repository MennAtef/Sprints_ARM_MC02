/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO_cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


//GPIO_CONTROL_NVIC
#if (PORTA_INT_STATUS == INT_ENABLE)
    SELECT_INT_Req(GPIO_PRIORITY,PortA);
#endif

#if (PORTB_INT_STATUS == INT_ENABLE)
    SELECT_INT_Req(GPIO_PRIORITY,PortB);
#endif

#if (PORTC_INT_STATUS == INT_ENABLE)
    SELECT_INT_Req(GPIO_PRIORITY,PortC);
#endif

#if (PORTD_INT_STATUS == INT_ENABLE)
    SELECT_INT_Req(GPIO_PRIORITY,PortD);
#endif

#if (PORTE_INT_STATUS == INT_ENABLE)
    SELECT_INT_Req(GPIO_PRIORITY,PortE);
#endif

#if (PORTF_INT_STATUS == INT_ENABLE)
    SELECT_INT_Req(GPIO_PRIORITY,PortF);
#endif
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
//INITIALIZE THE CLOCK
void GPIO_Clock_Init(Dio_PortType port)
{
	switch(port)
	{
		case PORTA:
		    SYSCTL_RCGC2|=0x1;
			SYSCTL_RCGCGPIO|=0x1;
			PORTA_LOCK=0x4C4F434B;
			PORTA_CR|=0xff;
			PORTA_DEN|=0xff;
		break;

		case PORTB:
			SYSCTL_RCGC2|=0x2;
			SYSCTL_RCGCGPIO|=0x2;
			PORTB_LOCK=0x4C4F434B;
			PORTB_CR|=0xff;
			PORTB_DEN|=0xff;
		break;

		case PORTC:
			SYSCTL_RCGC2|=0x4;
			SYSCTL_RCGCGPIO|=0x4;
			PORTC_LOCK=0x4C4F434B;
			PORTC_CR|=0xff;
			PORTC_DEN|=0xff;
		break;

		case PORTD:
			SYSCTL_RCGC2|=0x8;
			SYSCTL_RCGCGPIO|=0x8;
			PORTD_LOCK=0x4C4F434B;
			PORTD_CR|=0xff;
			PORTD_DEN|=0xff;
		break;

		case PORTE:
			SYSCTL_RCGC2|=0x10;
			SYSCTL_RCGCGPIO|=0x10;
			PORTE_LOCK=0x4C4F434B;
			PORTE_CR|=0xff;
			PORE_DEN|=0xff;
		break;

		case PORTF:
			SYSCTL_RCGC2|=0x20;
			SYSCTL_RCGCGPIO|=0x20;
			PORTF_LOCK=0x4C4F434B;
			PORTF_CR|=0xff;
			PORTF_DEN|=0xff;
		break;
	}
}
//DISABLE THE CLOCK
void GPIO_Clock_Disable(Dio_PortType port)
{
	switch(port)
	{
		case PORTA:
		CLR_BIT(SYSCTL_RCGC2,0);
		break;

		case PORTB:
		CLR_BIT(SYSCTL_RCGC2,1);
		break;

		case PORTC:
		CLR_BIT(SYSCTL_RCGC2,2);
		break;

		case PORTD:
		CLR_BIT(SYSCTL_RCGC2,3);
		break;

		case PORTE:
		CLR_BIT(SYSCTL_RCGC2,4);
		break;

		case PORTF:
		CLR_BIT(SYSCTL_RCGC2,5);
		break;
	}
}

void GPIO_Init(Dio_PortType port,Dio_PinNumber pin,ALTERNATIVE_FUNC FUN)
{
	switch(FUN)
	{
		case GPIO:
		switch(port)
		{
			case PORTA:
				CLR_BIT(PORTA_AFSEL,pin);
			break;

			case PORTB:
				CLR_BIT(PORTB_AFSEL,pin);
			break;

			case PORTC:
				CLR_BIT(PORTC_AFSEL,pin);
			break;

			case PORTD:
				CLR_BIT(PORTD_AFSEL,pin);
			break;

			case PORTE:
				CLR_BIT(PORTE_AFSEL,pin);
			break;

			case PORTF:
				CLR_BIT(PORTF_AFSEL,pin);
			break;
		}
		break;

		case ALTERNATIVE:
		switch(port)
		{
			case PORTA:
				SET_BIT(PORTA_AFSEL,pin);
			break;

			case PORTB:
				SET_BIT(PORTB_AFSEL,pin);
			break;

			case PORTC:
				SET_BIT(PORTC_AFSEL,pin);
			break;

			case PORTD:
				SET_BIT(PORTD_AFSEL,pin);
			break;

			case PORTE:
				SET_BIT(PORTE_AFSEL,pin);
			break;

			case PORTF:
				SET_BIT(PORTF_AFSEL,pin);
			break;
		}
		break;
	}
}

void DIO_SetPinDir (Dio_PortType port, Dio_PinNumber pin, Port_State state)
{
	switch(state)
	{
		case INPUT:
		switch(port)
		{
			case PORTA:
				CLR_BIT(PORTA_DIR,pin);
			break;

			case PORTB:
				CLR_BIT(PORTB_DIR,pin);
			break;

			case PORTC:
				CLR_BIT(PORTC_DIR,pin);
			break;

			case PORTD:
				CLR_BIT(PORTD_DIR,pin);
			break;

			case PORTE:
				CLR_BIT(PORTE_DIR,pin);
			break;

			case PORTF:
				CLR_BIT(PORTF_DIR,pin);
			break;
		}
		break;

		case OUTPUT:
		switch(port)
		{
			case PORTA:
				SET_BIT(PORTA_DIR,pin);
			break;

			case PORTB:
				SET_BIT(PORTB_DIR,pin);
			break;

			case PORTC:
				SET_BIT(PORTC_DIR,pin);
			break;

			case PORTD:
				SET_BIT(PORTD_DIR,pin);
			break;

			case PORTE:
				SET_BIT(PORTE_DIR,pin);
			break;

			case PORTF:
				SET_BIT(PORTF_DIR,pin);
			break;
		}
		break;
	}
}
void DIO_SetPinVal (Dio_PortType port, Dio_PinNumber pin, Pin_Status status)
{
	switch(status)
	{
		case HIGH:
		switch(port)
		{
			case PORTA:
				SET_BIT(PORTA_DATA,pin);
			break;

			case PORTB:
				SET_BIT(PORTB_DATA,pin);
			break;

			case PORTC:
				SET_BIT(PORTC_DATA,pin);
			break;

			case PORTD:
				SET_BIT(PORTD_DATA,pin);
			break;

			case PORTE:
				SET_BIT(PORTE_DATA,pin);
			break;

			case PORTF:
				SET_BIT(PORTF_DATA,pin);
			break;
		}
		break;

		case LOW:
		switch(port)
		{
			case PORTA:
				CLR_BIT(PORTA_DATA,pin);
			break;

			case PORTB:
				CLR_BIT(PORTB_DATA,pin);
			break;

			case PORTC:
				CLR_BIT(PORTC_DATA,pin);
			break;

			case PORTD:
				CLR_BIT(PORTD_DATA,pin);
			break;

			case PORTE:
				CLR_BIT(PORTE_DATA,pin);
			break;

			case PORTF:
				CLR_BIT(PORTF_DATA,pin);
			break;
		}
		break;

	}

}
uint8 DIO_ReadPinVal (Dio_PortType port, Dio_PinNumber pin)
{
	uint32 Result = 0;
	switch(port)
	{
		case PORTA:
			Result= GET_BIT(PORTA_DATA,pin);
		break;

		case PORTB:
			Result= GET_BIT(PORTB_DATA,pin);
		break;

		case PORTC:
			Result= GET_BIT(PORTC_DATA,pin);
		break;

		case PORTD:
			Result= GET_BIT(PORTD_DATA,pin);
		break;

		case PORTE:
			Result= GET_BIT(PORTE_DATA,pin);
		break;

		case PORTF:
			Result= GET_BIT(PORTF_DATA,pin);
		break;
	}
	return Result;
}
uint32 DIO_ReadPortVal(Dio_PortType port)
{
	uint32 Result = 0;
	switch(port)
	{
		case PORTA:
			Result= PORTA_DATA;
		break;

		case PORTB:
			Result= PORTB_DATA;
		break;

		case PORTC:
			Result= PORTC_DATA;
		break;

		case PORTD:
			Result= PORTD_DATA;
		break;

		case PORTE:
			Result= PORTE_DATA;
		break;

		case PORTF:
			Result= PORTF_DATA;
		break;
	}
	return Result;
}
void DIO_TogglePinVal (Dio_PortType port, Dio_PinNumber pin)
{
	switch(port)
	{
		case PORTA:
			TOG_BIT(PORTA_DATA,pin);
		break;

		case PORTB:
			TOG_BIT(PORTB_DATA,pin);
		break;

		case PORTC:
			TOG_BIT(PORTC_DATA,pin);
		break;

		case PORTD:
			TOG_BIT(PORTD_DATA,pin);
		break;

		case PORTE:
			TOG_BIT(PORTE_DATA,pin);
		break;

		case PORTF:
			TOG_BIT(PORTF_DATA,pin);
		break;
	}
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/