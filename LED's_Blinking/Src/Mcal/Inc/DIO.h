/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <DIO.h>
 *     
 *********************************************************************************************************************/
#ifndef <DIO_H>
#define <DIO_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORTA_INT_STATUS INT_DIS
#define PORTB_INT_STATUS INT_DIS
#define PORTC_INT_STATUS INT_DIS
#define PORTD_INT_STATUS INT_DIS
#define PORTE_INT_STATUS INT_DIS
#define PORTF_INT_STATUS INT_DIS
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{

	Dio_Channel_A0,
	Dio_Channel_A1,
	Dio_Channel_A2,
	Dio_Channel_A3,
	Dio_Channel_A4,
	Dio_Channel_A5,
	Dio_Channel_A6,
	Dio_Channel_A7,

	Dio_Channel_B0,
	Dio_Channel_B1,
	Dio_Channel_B2,
	Dio_Channel_B3,
	Dio_Channel_B4,
	Dio_Channel_B5,
	Dio_Channel_B6,
	Dio_Channel_B7,

	Dio_Channel_C0,
	Dio_Channel_C1,
	Dio_Channel_C2,
	Dio_Channel_C3,
	Dio_Channel_C4,
	Dio_Channel_C5,
	Dio_Channel_C6,
	Dio_Channel_C7,

	Dio_Channel_D0,
	Dio_Channel_D1,
	Dio_Channel_D2,
	Dio_Channel_D3,
	Dio_Channel_D4,
	Dio_Channel_D5,
	Dio_Channel_D6,
	Dio_Channel_D7,

	Dio_Channel_E0,
	Dio_Channel_E1,
	Dio_Channel_E2,
	Dio_Channel_E3,
	Dio_Channel_E4,
	Dio_Channel_E5,
	Dio_Channel_E6_RESERVED,
	Dio_Channel_E7_RESERVED,

	Dio_Channel_F0,
	Dio_Channel_F1,
	Dio_Channel_F2,
	Dio_Channel_F3,
	Dio_Channel_F4,
	Dio_Channel_F5_RESERVED,
	Dio_Channel_F6_RESERVED,
	Dio_Channel_F7_RESERVED,

} Dio_ChannelType;

typedef enum
{

	PORTA = 0,
	PORTB = 1,
	PORTC = 2,
	PORTD = 3,
	PORTE = 4,
	PORTF = 5
} Dio_PortType;

typedef enum
{

	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7
} Dio_PinNumber;

typedef enum
{
	INPUT = 0,
	OUTPUT = 1
}Port_State;
//Define Status type
typedef enum
{
	LOW = 0,
	HIGH = 1
}Pin_Status;
//DUNNO WHAT DOES IT DO
typedef enum
{
    GPIO = 0,
    ALTERNATIVE = 1
}ALTERNATIVE_FUNC;
/*
typedef enum
{
    edge = 0,
    level = 1
}INT_SENS;

typedef enum
{
    one_edge = 0,
    both_edges = 1
}Edges;

typedef enum
{
    rising = 0,
    falling = 1
}Event;

typedef enum
{
    not_masked = 0,
    masked = 1
}INT_Mask;
*/



//SETWHICH PORT WILL BE ENABLED SO IIT CAN SET PRIORITY TYPE TO IT
static PRIORITY GPIO_PRIORITY = PRIORITY_3;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/