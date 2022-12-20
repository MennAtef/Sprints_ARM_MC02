/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Nvic.h>
 *       Module:  -
 *
 *  Description:  <header file for Nvic Driver>     
 *  
 *********************************************************************************************************************/
#ifndef <NVIC_H>
#define <NVIC_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    NVIC_GPIO_PORT_A                                ,
    NVIC_GPIO_PORT_B                                ,
    NVIC_GPIO_PORT_C                                ,
    NVIC_GPIO_PORT_D                                ,
    NVIC_GPIO_PORT_E                                ,

    NVIC_UART_0                                     ,
    NVIC_UART_1                                     ,

    NVIC_SSI_0                                      ,

    NVIC_I2C0                                       ,

    NVIC_PWM_0_FAULT                                ,

    NVIC_PWM_0_GENERATOR_0                          ,
    NVIC_PWM_0_GENERATOR_1                          ,
    NVIC_PWM_0_GENERATOR_2                          ,

    NVIC_QEI_0                                      ,
    NVIC_ADC_0_SEQUENCE_0                           ,
    NVIC_ADC_0_SEQUENCE_1                           ,
    NVIC_ADC_0_SEQUENCE_2                           ,
    NVIC_ADC_0_SEQUENCE_3                           ,

    NVIC_TIMER_WATCHDOG_0_1    		                ,

	NVIC_16_32_TIMER_0_A      		                ,
	NVIC_16_32_TIMER_0_B      		                ,
	NVIC_16_32_TIMER_1_A      		                ,
	NVIC_16_32_TIMER_1_B      		                ,
	NVIC_16_32_TIMER_2_A      		                ,
	NVIC_16_32_TIMER_2_B      		                ,
	
	NVIC_ANALOG_COMPARATOR_0   		                ,
	NVIC_ANALOG_COMPARATOR_1   		                ,
                 /*27 RESERVED*/
    NVIC_SYSTEM_CONTROL = 28   		                ,
	
	NVIC_FLASH_MEMORY_CONTROL_EEPROM_MEMORY_CONTROL ,
	
	NVIC_DIO_PORT_F    			                	,
                 /*31&32 RESERVED*/
    NVIC_UART_2 = 33   				                ,
	
	NVIC_SSI_1         				                ,
	
	NVIC_16_32_TIMER_3_A     		                ,
	NVIC_16_32_TIMER_3_B     		                ,
	
	NVIC_I2C_1         				                ,
	
	NVIC_QEI_1         				                ,
	
	NVIC_CAN_0         				                ,
	NVIC_CAN_1         				                ,
                 /*41&42 RESERVED*/ 
    NVIC_HIBERNATION = 43 			                ,
	
	NVIC_USB           				                ,
					
	NVIC_PWM_GEN_3     				                ,
					
	NVIC_UDMA_SOFTWARE 				                ,
	NVIC_UDMA_ERROR    				                ,
					
	NVIC_ADC_1_SEQ_0   				                ,
	NVIC_ADC_1_SEQ_1   				                ,
	NVIC_ADC_1_SEQ_2   				                ,
	NVIC_ADC_1_SEQ_3   				                ,
	
	            /*52:56 Reserved*/
	
	NVIC_SSI_2 = 57    				                ,
	NVIC_SSI_3         				                ,
					
	NVIC_UART_3        				                ,
	NVIC_UART_4        				                ,
	NVIC_UART_5        				                ,
	NVIC_UART_6        				                ,
	NVIC_UART_7        				                ,
	
	            /*64:67 Reserved*/
	
	NVIC_I2C_2 = 68    				                ,
	NVIC_I2C_3         				                ,
	
	NVIC_16_32_TIMER_4_A     		                ,
	NVIC_16_32_TIMER_4_B     		                ,
	
                /*72:91 Reserved*/
	
	NVIC_16_32_TIMER_5_A = 92		                ,
	NVIC_16_32_TIMER_5_B     		                ,
	NVIC_32_64_TIMER_0_A     		                ,
	NVIC_32_64_TIMER_0_B     		                ,
	NVIC_32_64_TIMER_1_A     		                ,
	NVIC_32_64_TIMER_1_B     		                ,
	NVIC_32_64_TIMER_2_A     		                ,
	NVIC_32_64_TIMER_2_B     		                ,
	NVIC_32_64_TIMER_3_A     		                ,
	NVIC_32_64_TIMER_3_B     		                ,
	NVIC_32_64_TIMER_4_A     		                ,
	NVIC_32_64_TIMER_4_B     		                ,
	NVIC_32_64_TIMER_5_A     		                ,
	NVIC_32_64_TIMER_5_B     		                ,
	
	NVIC_SYSTEM_EXCEPTION    		                ,
	
	            /*107:133 Reserved*/
	
	NVIC_PWM_1_GEN_0 = 134   		                ,
	NVIC_PWM_1_GEN_1         		                ,
	NVIC_PWM_1_GEN_2         		                ,
	NVIC_PWM_1_GEN_3         		                ,
	NVIC_PWM_1_FAULT
}Nvic_Int;


typedef struct 
{
    Nvic_Int        InterruptNumber;
    unit8           GroupPriority;
    uint8           SubGroupPriority;
}Nvic_CfgType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/ 
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Nvic_Init(void);
 
#endif  /* INTCTRL_CFGH_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/