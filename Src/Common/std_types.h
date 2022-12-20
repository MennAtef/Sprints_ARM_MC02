/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Std_Types.h>
 *       Module:  -
 *
 *  Description:  <Standart types provision>     
 *  
 *********************************************************************************************************************/
#ifndef <STD_TYPES_H>
#define <STD_TYPES_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_types.h"
#include "Compiler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//Physical state 5V
#define STD_HIGH                1
//Physical state 3.3V
#define STD_HIGH                0

//Logical state active
#define STD_ACTIVE              1
//Logical state idle
#define STD_IDLE                0

#define STD_ON                  1
#define STD_OFF                 0 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define uint8 Std_Return_Type;
#define E_OK                     0
#define E_NOT_OK                 1

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* STD_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/