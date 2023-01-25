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


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NVIC_EN0              *((volatile uint32 *)0xE000E100)
#define NVIC_EN1              *((volatile uint32 *)0xE000E104)
#define NVIC_EN2              *((volatile uint32 *)0xE000E108)
#define NVIC_EN3              *((volatile uint32 *)0xE000E10C)
#define NVIC_EN4              *((volatile uint32 *)0xE000E110)

#define NVIC_DIS0             *((volatile uint32 *)0xE000E180)
#define NVIC_DIS1             *((volatile uint32 *)0xE000E184)
#define NVIC_DIS2             *((volatile uint32 *)0xE000E188)
#define NVIC_DIS3             *((volatile uint32 *)0xE000E18C)
#define NVIC_DIS4             *((volatile uint32 *)0xE000E190)

#define NVIC_PRI0             *((volatile uint32 *)0xE000E400)
#define NVIC_PRI1             *((volatile uint32 *)0xE000E404)
#define NVIC_PRI2             *((volatile uint32 *)0xE000E408)
#define NVIC_PRI3             *((volatile uint32 *)0xE000E40C)
#define NVIC_PRI4             *((volatile uint32 *)0xE000E410)
#define NVIC_PRI5             *((volatile uint32 *)0xE000E414)
#define NVIC_PRI6             *((volatile uint32 *)0xE000E418)
#define NVIC_PRI7             *((volatile uint32 *)0xE000E41C)
#define NVIC_PRI8             *((volatile uint32 *)0xE000E420)
#define NVIC_PRI9             *((volatile uint32 *)0xE000E424)
#define NVIC_PRI10            *((volatile uint32 *)0xE000E428)
#define NVIC_PRI11            *((volatile uint32 *)0xE000E42C)
#define NVIC_PRI12            *((volatile uint32 *)0xE000E430)
#define NVIC_PRI13            *((volatile uint32 *)0xE000E434)
#define NVIC_PRI14            *((volatile uint32 *)0xE000E438)
#define NVIC_PRI15            *((volatile uint32 *)0xE000E43C)
#define NVIC_PRI16            *((volatile uint32 *)0xE000E440)
#define NVIC_PRI17            *((volatile uint32 *)0xE000E444)
#define NVIC_PRI18            *((volatile uint32 *)0xE000E448)
#define NVIC_PRI19            *((volatile uint32 *)0xE000E44C)
#define NVIC_PRI20            *((volatile uint32 *)0xE000E450)
#define NVIC_PRI21            *((volatile uint32 *)0xE000E454)
#define NVIC_PRI22            *((volatile uint32 *)0xE000E458)
#define NVIC_PRI23            *((volatile uint32 *)0xE000E45C)
#define NVIC_PRI24            *((volatile uint32 *)0xE000E460)
#define NVIC_PRI25            *((volatile uint32 *)0xE000E464)
#define NVIC_PRI26            *((volatile uint32 *)0xE000E468)
#define NVIC_PRI27            *((volatile uint32 *)0xE000E46C)
#define NVIC_PRI28            *((volatile uint32 *)0xE000E470)
#define NVIC_PRI29            *((volatile uint32 *)0xE000E474)
#define NVIC_PRI30            *((volatile uint32 *)0xE000E478)
#define NVIC_PRI31            *((volatile uint32 *)0xE000E47C)
#define NVIC_PRI32            *((volatile uint32 *)0xE000E480)
#define NVIC_PRI33            *((volatile uint32 *)0xE000E484)
#define NVIC_PRI34            *((volatile uint32 *)0xE000E488)

#define NVIC_APINT            *((volatile uint32 *)0xE000ED0C)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    NVIC_GPIO_PORT_A  = 0                           ,
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

 
#endif  /* INTCTRL_CFGH_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/