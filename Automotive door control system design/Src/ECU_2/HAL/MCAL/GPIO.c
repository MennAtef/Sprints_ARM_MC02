/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "Macros.h"
#include "mcu_hw.h"
#include "platform_types.h"
#include "Port.h"
#include "Dio.h"

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

/**********************************************************************************************************************/
u8 Dio_ReadChannel(Port_PinType CHANNEL_ID)
 {	
		u8 x=0;
    if (CHANNEL_ID <=7)
    {

        x=GET_BIT(GPIO_PORTA_GPIODATA->R,CHANNEL_ID);
    }
    else if (CHANNEL_ID>=8 && CHANNEL_ID<=15)
    {
        x=GET_BIT(GPIO_PORTB_GPIODATA->R,CHANNEL_ID);
    }
    else if (CHANNEL_ID>=16 && CHANNEL_ID<=23)
    {
        x=GET_BIT(GPIO_PORTC_GPIODATA->R,CHANNEL_ID);
    }

    else if (CHANNEL_ID>=24 && CHANNEL_ID<=31)
    {
        x=GET_BIT(GPIO_PORTD_GPIODATA->R,CHANNEL_ID);
    }  

    else if (CHANNEL_ID>=32 && CHANNEL_ID<=37)
    {
       x=GET_BIT(GPIO_PORTE_GPIODATA->R,CHANNEL_ID);
    }

    else if (CHANNEL_ID>=38 && CHANNEL_ID<=42)
    {
       x=GET_BIT(GPIO_PORTF_GPIODATA->R,CHANNEL_ID);
    } 
return x;		
 }

void Dio_WriteOnChannel(Port_PinType CHANNEL_ID, Dio_Level Level)
 {
    if (CHANNEL_ID<=7)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTA_GPIODATA->R, CHANNEL_ID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTA_GPIODATA->R, CHANNEL_ID);
    }
    else if (CHANNEL_ID>=8 && CHANNEL_ID<=15)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTB_GPIODATA->R, CHANNEL_ID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTB_GPIODATA->R, CHANNEL_ID);
    }
    else if (CHANNEL_ID>=16 && CHANNEL_ID<=23)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTC_GPIODATA->R, CHANNEL_ID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTC_GPIODATA->R, CHANNEL_ID);
    }

    else if (CHANNEL_ID>=24 && CHANNEL_ID<=31)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTD_GPIODATA->R, CHANNEL_ID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTD_GPIODATA->R, CHANNEL_ID);
    }  

    else if (CHANNEL_ID>=32 && CHANNEL_ID<=37)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTE_GPIODATA->R, CHANNEL_ID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTE_GPIODATA->R, CHANNEL_ID);
    }

    else if (CHANNEL_ID>=38 && CHANNEL_ID<=42)
    {
        if(Level == HIGH)           SET_BIT(GPIO_PORTF_GPIODATA->R, CHANNEL_ID);
        else if (Level==LOW)        CLR_BIT(GPIO_PORTF_GPIODATA->R, CHANNEL_ID);
    }  
 }

u8 Dio_ReadPort(PortType Port)
 {
    switch (Port)
    {
    case PORTA:
        return (GPIO_PORTA_GPIODATA->R);
    case PORTB:
        return (GPIO_PORTB_GPIODATA->R);
    case PORTC:
        return (GPIO_PORTC_GPIODATA->R);
    case PORTD:
        return (GPIO_PORTD_GPIODATA->R);
    case PORTE:
        return (GPIO_PORTE_GPIODATA->R);
    case PORTF:
        return (GPIO_PORTF_GPIODATA->R);
    }
		return 0;
 }

 void Dio_WriteOnPort(PortType Port, Dio_PortLevelType Level)
 {
    switch (Port)
    {
    case PORTA:
        GPIO_PORTA_GPIODATA->R=Level;
        break;
    case PORTB:
        GPIO_PORTB_GPIODATA->R=Level;
        break;
    case PORTC:
        GPIO_PORTC_GPIODATA->R=Level;
        break;
    case PORTD:
        GPIO_PORTD_GPIODATA->R=Level;
        break;
    case PORTE:
        GPIO_PORTE_GPIODATA->R=Level;
        break;
    case PORTF:
        GPIO_PORTF_GPIODATA->R=Level;
        break;
    }   
 }

void Dio_FlipChannel(u8 CHANNEL_ID)
 {
    if ( CHANNEL_ID<=7)
    {
        TOG_BIT(GPIO_PORTA_GPIODATA->R,CHANNEL_ID);
    }
    else if (CHANNEL_ID>=8 && CHANNEL_ID<=15)
    {
        TOG_BIT(GPIO_PORTB_GPIODATA->R,CHANNEL_ID);
    }
    else if (CHANNEL_ID>=16 && CHANNEL_ID<=23)
    {
        TOG_BIT(GPIO_PORTC_GPIODATA->R,CHANNEL_ID);
    }

    else if (CHANNEL_ID>=24 && CHANNEL_ID<=31)
    {
        TOG_BIT(GPIO_PORTD_GPIODATA->R,CHANNEL_ID);
    }  

    else if (CHANNEL_ID>=32 && CHANNEL_ID<=37)
    {
       TOG_BIT(GPIO_PORTE_GPIODATA->R,CHANNEL_ID);
    }

    else if (CHANNEL_ID>=38 && CHANNEL_ID<=42)
    {
        TOG_BIT(GPIO_PORTF_GPIODATA->R,CHANNEL_ID);
    }     
}

/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/