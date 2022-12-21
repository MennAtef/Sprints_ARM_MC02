/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  Confiigure all the Mcu interrupts priority into groups and subgroups,
 *                Enable and Disable Navic Interrupt Gate for Periphrals
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Lcfg.c"
#include "Mcu_Hw.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
#define PRIx(i)      *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+((0x0400+(i/4)*4)))
#define ENx(i)       *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+((0x0100+(i/32)*32)))
#define DISx(i)      *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+((0x0180+(i/32)*32)))
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void SetPriorityGrouping();
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

void IntCrtl_Init(void)
{
uint8 Counter , Group_Temp , SubGroup_Temp , Interrupt_Number_Temp ,Grouping_Field	;
uint32 PriRegOffset	,PriBitOffset , EnRegOffset ,EnBitOffset;
	
APINT.B.VECTKEY=APINT_VECTKEY; 					 
APINT.B.ENDIANESS=STD_low;					    
APINT.B.PRIGROUP = GROUPING_SYSTEM;      
	
for(Counter=0 ;Counter < NUM_OF_ACTIVATED_GROUPS;Counter++){
	
Interrupt_Number_Temp = Interrupt_Groups[Counter].Interrupt_Number;	
Group_Temp = Interrupt_Groups[Counter].Group_Priority;
SubGroup_Temp =	Interrupt_Groups[Counter].SubGroup_Priority;
	
EnRegOffset = (Interrupt_Number_Temp/32)*4;
EnBitOffset = Interrupt_Number_Temp%32;
	
(*((volatile uint32*)(NVIC_ENX_BASE_ADDRESS + EnRegOffset  )))|= (1 << EnBitOffset);
	
if ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXX)
	{
	Grouping_Field=Group_Temp ;
    }
else if ( GROUPING_SYSTEM == GROUPING_SYSTEM_XXY)
	{
	Grouping_Field=(((Group_Temp<<1)&(0x6))|((SubGroup_Temp)&(0x1)));
    }
else if ( GROUPING_SYSTEM == GROUPING_SYSTEM_XYY)
	{
	Grouping_Field=(((Group_Temp<<2)&(0x4))|((SubGroup_Temp)&(0x3)));	
    }
else if ( GROUPING_SYSTEM == GROUPING_SYSTEM_YYY)
	{
	Grouping_Field= SubGroup_Temp ;
    }
else
    {
    // Do Nothing
    }

PriRegOffset = (Interrupt_Number_Temp/4)*4;
PriBitOffset = 5 + (8 * (Interrupt_Number_Temp%4));
(*((volatile uint32*)(NVIC_PRIX_BASE_ADDRESS + PriRegOffset  ))) |= ((uint32)(Grouping_Field << PriBitOffset));
}	
}
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/