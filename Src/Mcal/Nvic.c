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
/*                                          PRIGROUP BIT FIELD NUMBER*/
#define PRIORITY_GROUPING_SYSTEM_XXX                4    
#define PRIORITY_GROUPING_SYSTEM_XXY                5
#define PRIORITY_GROUPING_SYSTEM_XYY                6
#define PRIORITY_GROUPING_SYSTEM_YYY                7

#define APINT_VECTKEY                               0x05FA
#define PRIORITY_GROUP_FIELD_OFFSET                 0x8
#define APINT_VECTKEY_FIELD_OFFSET                  16
#define NVIC_REGIESTER_PRI_FIELD                    4
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