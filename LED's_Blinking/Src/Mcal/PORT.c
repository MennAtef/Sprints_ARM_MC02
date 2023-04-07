/**********************************************************************************************************************
 *  FILE DENSCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDENS
 *********************************************************************************************************************/
#include "GPIO_cfg.h"
#include "TM4C123_Gpio_Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/



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
//ACTIVATE THE CLOCK
void GPIO_Clock_Init(Dio_PortType _PORT_)
{
	switch(_PORT_)
	{
		case PORTA:
		  SYSCTRL_RCGC2 |=0x1;
			SYSCTRL_RCGCGPIO|=0x1;
			PORTA_LOCK=0x4C4F434B;
			PORTA_CR|=0xff;
			PORTA_DEN|=0xff;
		break;

		case PORTB:
			SYSCTRL_RCGC2 |=0x2;
			SYSCTRL_RCGCGPIO|=0x2;
			PORTB_LOCK=0x4C4F434B;
			PORTB_CR|=0xff;
			PORTB_DEN|=0xff;
		break;

		case PORTC:
			SYSCTRL_RCGC2 |=0x4;
			SYSCTRL_RCGCGPIO |=0x4;
			PORTC_LOCK=0x4C4F434B;
			PORTC_CR|=0xff;
			PORTC_DEN|=0xff;
		break;

		case PORTD:
			SYSCTRL_RCGC2|=0x8;
			SYSCTRL_RCGCGPIO|=0x8;
			PORTD_LOCK=0x4C4F434B;
			PORTD_CR|=0xff;
			PORTD_DEN|=0xff;
		break;

		case PORTE:
			SYSCTRL_RCGC2|=0x10;
			SYSCTRL_RCGCGPIO|=0x10;
			PORTE_LOCK=0x4C4F434B;
			PORTE_CR|=0xff;
			PORTE_DEN|=0xff;
		break;

		case PORTF:
			SYSCTRL_RCGC2|=0x20;
			SYSCTRL_RCGCGPIO|=0x20;
			PORTF_LOCK=0x4C4F434B;
			PORTF_CR|=0xff;
			PORTF_DEN|=0xff;
		break;
	}
}
void GPIO_Init(Dio_PortType _PORT_,Dio_PinNumber _PIN_,ALTERNATIVE_FUNCTION _Function_)
{
	switch(_Function_)
	{
		case GPIO:
		switch(_PORT_)
		{
			case PORTA:
				CLR_BIT(PORTA_AFSEL,_PIN_);
			break;

			case PORTB:
				CLR_BIT(PORTB_AFSEL,_PIN_);
			break;

			case PORTC:
				CLR_BIT(PORTC_AFSEL,_PIN_);
			break;

			case PORTD:
				CLR_BIT(PORTD_AFSEL,_PIN_);
			break;

			case PORTE:
				CLR_BIT(PORTE_AFSEL,_PIN_);
			break;

			case PORTF:
				CLR_BIT(PORTF_AFSEL,_PIN_);
			break;
		}
		break;

		case ALTERNATIVE:
		switch(_PORT_)
		{
			case PORTA:
				SET_BIT(PORTA_AFSEL,_PIN_);
			break;

			case PORTB:
				SET_BIT(PORTB_AFSEL,_PIN_);
			break;

			case PORTC:
				SET_BIT(PORTC_AFSEL,_PIN_);
			break;

			case PORTD:
				SET_BIT(PORTD_AFSEL,_PIN_);
			break;

			case PORTE:
				SET_BIT(PORTE_AFSEL,_PIN_);
			break;

			case PORTF:
				SET_BIT(PORTF_AFSEL,_PIN_);
			break;
		}
		break;
	}
}
//CLOCK INACTIVATION
void GPIO_Clock_Disable(Dio_PortType _PORT_)
{
	switch(_PORT_)
	{
		case PORTA:
		CLR_BIT(SYSCTRL_RCGC2,0);
		break;

		case PORTB:
		CLR_BIT(SYSCTRL_RCGC2,1);
		break;

		case PORTC:
		CLR_BIT(SYSCTRL_RCGC2,2);
		break;

		case PORTD:
		CLR_BIT(SYSCTRL_RCGC2,3);
		break;

		case PORTE:
		CLR_BIT(SYSCTRL_RCGC2,4);
		break;

		case PORTF:
		CLR_BIT(SYSCTRL_RCGC2,5);
		break;
	}
}


/*Control the NVIC_GPIO*/
#if (PORTA_INT_STATUS == INT_ENB)
    Interrupt_Request(GPIO_PRIORITY,PortA);
#endif

#if (PORTB_INT_STATUS == INT_ENB)
    Interrupt_Request(GPIO_PRIORITY,PortB);
#endif

#if (PORTC_INT_STATUS == INT_ENB)
    Interrupt_Request(GPIO_PRIORITY,PortC);
#endif

#if (PORTD_INT_STATUS == INT_ENB)
    Interrupt_Request(GPIO_PRIORITY,PortD);
#endif

#if (PORTE_INT_STATUS == INT_ENB)
    Interrupt_Request(GPIO_PRIORITY,PortE);
#endif

#if (PORTF_INT_STATUS == INT_ENB)
    Interrupt_Request(GPIO_PRIORITY,PortF);
#endif

void DIO_SetPinDir (Dio_PortType _PORT_, Dio_PinNumber _PIN_, Port_State _STATUS_)
{
	switch(_STATUS_)
	{
		case INPUT:
		switch(_PORT_)
		{
			case PORTA:
				CLR_BIT(PORTA_DIR,_PIN_);
			break;

			case PORTB:
				CLR_BIT(PORTB_DIR,_PIN_);
			break;

			case PORTC:
				CLR_BIT(PORTC_DIR,_PIN_);
			break;

			case PORTD:
				CLR_BIT(PORTD_DIR,_PIN_);
			break;

			case PORTE:
				CLR_BIT(PORTE_DIR,_PIN_);
			break;

			case PORTF:
				CLR_BIT(PORTF_DIR,_PIN_);
			break;
		}
		break;

		case OUTPUT:
		switch(_PORT_)
		{
			case PORTA:
				SET_BIT(PORTA_DIR,_PIN_);
			break;

			case PORTB:
				SET_BIT(PORTB_DIR,_PIN_);
			break;

			case PORTC:
				SET_BIT(PORTC_DIR,_PIN_);
			break;

			case PORTD:
				SET_BIT(PORTD_DIR,_PIN_);
			break;

			case PORTE:
				SET_BIT(PORTE_DIR,_PIN_);
			break;

			case PORTF:
				SET_BIT(PORTF_DIR,_PIN_);
			break;
		}
		break;
	}
}
void DIO_SetPinVal (Dio_PortType _PORT_, Dio_PinNumber _PIN_, Pin_Status _STATE_)
{
	switch(_STATE_)
	{
		case HIGH:
		switch(_PORT_)
		{
			case PORTA:
				SET_BIT(PORTA_DATA,_PIN_);
			break;

			case PORTB:
				SET_BIT(PORTB_DATA,_PIN_);
			break;

			case PORTC:
				SET_BIT(PORTC_DATA,_PIN_);
			break;

			case PORTD:
				SET_BIT(PORTD_DATA,_PIN_);
			break;

			case PORTE:
				SET_BIT(PORTE_DATA,_PIN_);
			break;

			case PORTF:
				SET_BIT(PORTF_DATA,_PIN_);
			break;
		}
		break;

		case LOW:
		switch(_PORT_)
		{
			case PORTA:
				CLR_BIT(PORTA_DATA,_PIN_);
			break;

			case PORTB:
				CLR_BIT(PORTB_DATA,_PIN_);
			break;

			case PORTC:
				CLR_BIT(PORTC_DATA,_PIN_);
			break;

			case PORTD:
				CLR_BIT(PORTD_DATA,_PIN_);
			break;

			case PORTE:
				CLR_BIT(PORTE_DATA,_PIN_);
			break;

			case PORTF:
				CLR_BIT(PORTF_DATA,_PIN_);
			break;
		}
		break;

	}

}
uint32 DIO_ReadPinVal (Dio_PortType _PORT_, Dio_PinNumber _PIN_)
{
	uint32 Result = 0;
	switch(_PORT_)
	{
		case PORTA:
			Result= GET_BIT(PORTA_DATA,_PIN_);
		break;

		case PORTB:
			Result= GET_BIT(PORTB_DATA,_PIN_);
		break;

		case PORTC:
			Result= GET_BIT(PORTC_DATA,_PIN_);
		break;

		case PORTD:
			Result= GET_BIT(PORTD_DATA,_PIN_);
		break;

		case PORTE:
			Result= GET_BIT(PORTE_DATA,_PIN_);
		break;

		case PORTF:
			Result= GET_BIT(PORTF_DATA,_PIN_);
		break;
	}
	return Result;
}
uint32 DIO_ReadPortVal(Dio_PortType _PORT_)
{
	uint32 Result = 0;
	switch(_PORT_)
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
void DIO_TogglePinVal (Dio_PortType _PORT_, Dio_PinNumber _PIN_)
{
	switch(_PORT_)
	{
		case PORTA:
			TOG_BIT(PORTA_DATA,_PIN_);
		break;

		case PORTB:
			TOG_BIT(PORTB_DATA,_PIN_);
		break;

		case PORTC:
			TOG_BIT(PORTC_DATA,_PIN_);
		break;

		case PORTD:
			TOG_BIT(PORTD_DATA,_PIN_);
		break;

		case PORTE:
			TOG_BIT(PORTE_DATA,_PIN_);
		break;

		case PORTF:
			TOG_BIT(PORTF_DATA,_PIN_);
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