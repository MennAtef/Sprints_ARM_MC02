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
void Nvic_Init(void)
{
	uint8 LOC_Grp, LOC_SubGrp, LOC_Grp_Field;
	/*Configure the Grouping and Sub-grouping */
    APINT = (APINT_VECTKEY << APINT_VECTKEY_FIELD_OFFSET) |
            (PRIORITY_GROUPING_SYSTEM << PRIORITY_GROUP_FIELD_OFFSET);



                      /*Create Group Field*/
    #if(PRIORITY_GROUPING_SYSTEM == PRIORITY_GROUPING_SYSTEM_XXX)
            LOC_Grp_Field = LOC_Grp;
    #elif(PRIORITY_GROUPING_SYSTEM == PRIORITY_GROUPING_SYSTEM_XXY)
            LOC_Grp_Field = ((LOC_Grp << 1)& 0x6) | (LOC_SubGrp & 0x1);
    #elif(PRIORITY_GROUPING_SYSTEM == PRIORITY_GROUPING_SYSTEM_XYY)
            LOC_Grp_Field = ((LOC_Grp << 2)& 0x4) | (LOC_SubGrp & 0x3);
    #elif(PRIORITY_GROUPING_SYSTEM == PRIORITY_GROUPING_SYSTEM_YYY)
            LOC_Grp_Field = LOC_Sub_Grp;
    #else
            #error WRONG GROUPING CHOICE
    #endif
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/