/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
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

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#define MCU_CLOCK_GATE_GPIOA 
#define MCU_CLOCK_GATE_GPIOB
#define MCU_CLOCK_GATE_GPIOE

#define MCU_CLOCK_GATE_WD0
#define MCU_CLOCK_GATE_WD1

#define Mcu_Clock_0
#define Mcu_Clock_1
#define Mcu_Clock_2
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
uint8 Mcu_ActivatedClockGates[MCU_ACTIVATED_CLOCK_SIZE]=
{
    MCU_CLOCK_GATE_GPIOA,
    MCU_CLOCK_GATE_GPIOB,
    MCU_CLOCK_GATE_GPIOE,
    MCU_CLOCK_GATE_WD0
};

const Mcu_ConfigType McuConfig[MCU_CLOCK_SETTINGS_SIZE]=
{
    //ClockSettingID              ClockSource                   PllUse     Freq_KHz
    /*0            */             {MCU_CLOCK_SOURCE_MOSC       ,ENABLE     ,25000},
    /*1            */             {MCU_CLOCK_SOURCE_PIOSC      ,DISABLE    ,16000},
};
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

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/