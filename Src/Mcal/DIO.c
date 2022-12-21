/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Platform_Types.h"
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static const uint32 Port_APB_BaseAddress[6] = 
{
	GPIO_PORTA_APB_BASE_ADDRESS,
	GPIO_PORTB_APB_BASE_ADDRESS,
	GPIO_PORTC_APB_BASE_ADDRESS,
	GPIO_PORTD_APB_BASE_ADDRESS,
	GPIO_PORTE_APB_BASE_ADDRESS,
	GPIO_PORTF_APB_BASE_ADDRESS};

static const uint32 Port_AHB_BaseAddress[6] = 
{
GPIO_PORTA_AHB_BASE_ADDRESS,
GPIO_PORTB_AHB_BASE_ADDRESS,
GPIO_PORTC_AHB_BASE_ADDRESS,
GPIO_PORTD_AHB_BASE_ADDRESS,
GPIO_PORTE_AHB_BASE_ADDRESS,
GPIO_PORTF_AHB_BASE_ADDRESS
};
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{

	Dio_LevelType level;
	uint8 portPos, channelPos;
	portPos = ChannelId / 8;
	channelPos = ChannelId % 8;
	uint32 GPIO_DATA = Port_APB_BaseAddress[portPos] +
     GPIODATA_OFFSET + (4 * (1 << channelPos));
	level = ((HwAccess(GPIO_DATA) >> channelPos) & 1);
	return level;
}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 portPos, channelPos;
	portPos = ChannelId / 8;
	channelPos = ChannelId % 8;
	uint32 GPIO_DATA = Port_APB_BaseAddress[portPos] + GPIODATA_OFFSET + (4 * (1 << channelPos));
	HwAccess(GPIO_DATA) = ((uint32)(Level << channelPos));
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType portLevel;
	uint32 GPIO_DATA = Port_APB_BaseAddress[PortId] + GPIODATA_OFFSET + 0X3FC;
	portLevel = ((uint8)HwAccess(GPIO_DATA));
	return portLevel;
}
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	uint32 GPIO_DATA = Port_APB_BaseAddress[PortId] + GPIODATA_OFFSET + GPIO_ShiftedLeft_2Bits;
	HwAccess(GPIO_DATA) = Level;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/