/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <mcu_hw.h>
 *       Module:  -
 *
 *  Description:  <Contains all MCU Regiesters Definitions>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "platform_types.h"
#include "std_types.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_CORE_PERI_BASE_ADDRESS           0xE000E000
#define CORTEX_M4_SYSTEM_CONTROL_BASE_ADDRESS     0x400FE000
#define APINT                              *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+0xD0C)
#define INTCTRL                            *((volatile INTRCTRL_TAG*)CORTEXM4_CORE_PERI_BASE_ADDRESS+0xD04)

//NVIC REGIESTER
#define NVIC_ENABLE_BASE_ADDRESS             (CORTEXM4_CORE_PERI_BASE_ADDRESS +0x100)
#define NVIC_PRI_BASE_ADDRESS                (CORTEXM4_CORE_PERI_BASE_ADDRESS +0x400)
  
#define GPIO_PORTA_APB_BASE_ADDRESS             0x40004000
#define GPIO_PORTB_APB_BASE_ADDRESS             0x40005000
#define GPIO_PORTC_APB_BASE_ADDRESS             0x40006000
#define GPIO_PORTD_APB_BASE_ADDRESS             0x40007000
#define GPIO_PORTE_APB_BASE_ADDRESS             0x40024000
#define GPIO_PORTF_APB_BASE_ADDRESS             0x40025000

#define GPIO_PORTA_AHB_BASE_ADDRESS             0x40058000
#define GPIO_PORTA_AHB_BASE_ADDRESS             0x40059000
#define GPIO_PORTA_AHB_BASE_ADDRESS             0x4005A000
#define GPIO_PORTA_AHB_BASE_ADDRESS             0x4005B000
#define GPIO_PORTA_AHB_BASE_ADDRESS             0x4005C000
#define GPIO_PORTA_AHB_BASE_ADDRESS             0x4005D000

#define GPIODATA_OFFSET     0x000
#define GPIODIR_OFFSET      0x400
#define GPIOS_OFFSET        0x404
#define GPIOIBE_OFFSET      0x408
#define GPIOIEV_OFFSET      0x40C
#define GPIOIM_OFFSET       0x410
#define GPIORIS_OFFSET      0x414
#define GPIOMIS_OFFSET      0x418
#define GPIOICR_OFFSET      0x41C
#define GPIOAFSEL_OFFSET    0x420
#define GPIODR2R_OFFSET     0x500
#define GPIODR4R_OFFSET     0x504
#define GPIODR8R_OFFSET     0x508
#define GPIOODR_OFFSET      0x50C
#define GPIOPUR_OFFSET      0x510
#define GPIOPDR_OFFSET      0x514
#define GPIOSLR_OFFSET      0x518
#define GPIODEN_OFFSET      0x51C
#define GPIOLOCK_OFFSET     0x520
#define GPIOCR_OFFSET       0x524
#define GPIOAMSEL_OFFSET    0x528
#define GPIOPCTL_OFFSET     0x52C
#define GPIODCCTL_OFFSET    0x530
#define GPIODMACTL_OFFSET   0x534

#define _16_32_BIT_TIMER_0_BASE_ADDRESS      0x40030000
#define _16_32_BIT_TIMER_1_BASE_ADDRESS      0x40031000
#define _16_32_BIT_TIMER_2_BASE_ADDRESS      0x40032000
#define _16_32_BIT_TIMER_3_BASE_ADDRESS      0x40033000
#define _16_32_BIT_TIMER_4_BASE_ADDRESS      0x40034000
#define _16_32_BIT_TIMER_5_BASE_ADDRESS      0x40035000
#define _32_64_BIT_WIDE_TIMER_0_BASE_ADDRESS 0x40036000
#define _32_64_BIT_WIDE_TIMER_1_BASE_ADDRESS 0x40037000
#define _32_64_BIT_WIDE_TIMER_2_BASE_ADDRESS 0x4004C000
#define _32_64_BIT_WIDE_TIMER_3_BASE_ADDRESS 0x4004D000
#define _32_64_BIT_WIDE_TIMER_4_BASE_ADDRESS 0x4004E000
#define _32_64_BIT_WIDE_TIMER_5_BASE_ADDRESS 0x4004F000


#define GPTMCFG_OFFSET      0x000
#define GPTMTAMR_OFFSET     0x004
#define GPTMTBMR_OFFSET     0x008
#define GPTMIMR_OFFSET      0x018
#define GPTMCTL_OFFSET      0x00C
#define GPTMTAILR_OFFSET    0x028
#define GPTMTAV_OFFSET      0x050
#define GPTMTBV_OFFSET      0x054
#define GPTMTAPV_OFFSET     0x064
#define GPTMTBPV_OFFSET     0x068
//#define APINT                     *((volatile uint32*)0xE000ED0C)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    uint32  VECACT    :8;
    uint32            :3;
    uint32  RETBASE    :1;
    uint32  VECPEND   :8;
    uint32            :2;
    uint32  ISRPEND   :1;
    uint32  ISRPRE    :1;
    uint32            :1;
    uint32 PENDSTCLR  :1;
    uint32 PENDSTSET  :1;
    uint32 UNPENDSV   :1;
    uint32 PENDSV     :1;
    uint32            :2;
    uint32 NMISET     :1;
}INTCTRL_BITFIELD;

typedef union 
{ 
    uint32 R;
    INTCTRL_BITFIELD B;
}INTRCTRL_TAG;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/