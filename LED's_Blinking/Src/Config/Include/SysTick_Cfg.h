#ifndef SYSTICK_CFG_H
#define SYSTICK_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NVIC_ST_CTRL          *((volatile  uint32 *)0xE000E010)
#define NVIC_ST_RELOAD       *((volatile   uint32 *)0xE000E014)
#define NVIC_ST_CURRENT      *((volatile   uint32 *)0xE000E018)

#define PRECESSION_CLK 0
#define INTRERNAL_CLK  1

#define INT_STATE   INT_ENB
#define CLK_SRC  INTRERNAL_CLK

#define INT_DIS    0
#define INT_ENB    1





/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/ 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel );
 
#endif  /* SYSTICK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Cfg.h
 *********************************************************************************************************************/