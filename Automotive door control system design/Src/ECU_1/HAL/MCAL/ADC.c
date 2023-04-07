/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ADC.c
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "IntCtrl_types.h"

#include "std_types.h"
#include "platform_types.h"
#include "Macros.h"
#include "mcu_hw.h"

#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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


/******************************************************************************/
void IntCtrl_Init(void)
{
    if (GPIO_PORTA_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit0=Enable;
    if (GPIO_PORTB_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit1=Enable;
    if (GPIO_PORTC_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit2=Enable;
    if (GPIO_PORTD_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit3=Enable;
    if (GPIO_PORTE_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit4=Enable;
    if (GPIO_PORTF_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit30=Enable;
	/*Configure groups and subgrous with APINT*/
    SCB_REG->APINT.R|= (APINTKEY<<16)|(Int_Group_and_Subgroup_config<<8);


    /*Group\subgroup priority in NVIC regiesters*/
    NVIC_REGISTER_PRI->N0.R|=(PRI_GPIO_PORTA<<5)|(PRI_GPIO_PORTB<<13)|(PRI_GPIO_PORTC<<21)|(PRI_GPIO_PORTD<<29);
    NVIC_REGISTER_PRI->N1.R|=(PRI_GPIO_PORTE<<5u)|(PRI_UART0<<13u)|(PRI_UART1<<21u);
    NVIC_REGISTER_PRI->N2.R|=(PRI_I2C0<<5)|(PRI_PWM0_Fault<<13)|(PRI_PWM0_Generator0<<21)|(PRI_PWM0_Generator1<<29);
    NVIC_REGISTER_PRI->N3.R|=(PRI_PWM0_Generator2<<5)|(PRI_QEI0<<13)|(PRI_ADC0_Sequence0<<21);
    NVIC_REGISTER_PRI->N4.R|=(PRI_ADC0_Sequence2<<5)|(PRI_ADC0_Sequence3<<13)|(PRI_Watchdog_Timers0and1<<21)|(PRI_Timer0A <<29);
    NVIC_REGISTER_PRI->N5.R|=(PRI_Timer0B <<5)|(PRI_Timer1A <<13)|(PRI_Timer1B <<21)|(PRI_Timer2A <<29);
    NVIC_REGISTER_PRI->N6.R|=(PRI_Timer2B <<5)|(PRI_Analog_Comparator0<<13)|(PRI_Analog_Comparator1<<21);
    NVIC_REGISTER_PRI->N7.R|=(PRI_SystemControl<<5)|(PRI_FMCAndEEPROMC<<13)|(PRI_GPIO_PortF<<21);
    NVIC_REGISTER_PRI->N8.R|=(PRI_UART2<<13)|(PRI_SSI1<<21)|(PRI_Timer3A <<29);
    NVIC_REGISTER_PRI->N9.R|=(PRI_Timer3B <<5)|(PRI_I2C1<<13)|(QEI1_<<21);
    NVIC_REGISTER_PRI->N10.R|=(PRI_CAN1<<5)|(PRI_HibernationModule<<13);
    NVIC_REGISTER_PRI->N11.R|=(PRI_USB<<5)|(PRI_PWM0_Generator3<<13)|(PRI_uDMA_Software<<21);
    NVIC_REGISTER_PRI->N12.R|=(PRI_ADC1_Sequence0<<5)|(PRI_ADC1_Sequence1<<13)|(PRI_ADC1_Sequence2<<21);
    NVIC_REGISTER_PRI->N14.R|=(PRI_SSI2<<13)|(PRI_SSI3<<21);
    NVIC_REGISTER_PRI->N15.R|=(PRI_UART4<<5)|(PRI_UART5<<13)|(PRI_UART6<<21);
    NVIC_REGISTER_PRI->N17.R|=(PRI_I2C2<<5)|(PRI_I2C3<<13)|(PRI_Timer4A <<21)|(PRI_Timer4B <<29);
    NVIC_REGISTER_PRI->N23.R|=(PRI_Timer5A <<5)|(PRI_Timer5B <<13)|(PRI_Timer0A <<21)|(PRI_Timer0B <<29);
    NVIC_REGISTER_PRI->N24.R|=(PRI_Timer1A <<5)|(PRI_Timer1B <<13)|(PRI_Timer2A <<21)|(PRI_Timer2B <<29);
    NVIC_REGISTER_PRI->N25.R|=(PRI_Timer3A <<5)|(PRI_Timer3B <<13)|(PRI_Timer4A <<21)|(PRI_Timer4B <<29);
    NVIC_REGISTER_PRI->N26.R|=(PRI_Timer5A <<5)|(PRI_Timer5B <<13)|(PRI_SystemException<<21);
    NVIC_REGISTER_PRI->N33.R|=(PRI_PWM1_Generator0<<21)|(PRI_PWM1_Generator1<<29);
    NVIC_REGISTER_PRI->N34.R|=(PRI_PWM1_Generator2<<5)|(PRI_PWM1_Generator3<<13)|(PRI_PWM1_Fault<<21);

    SCB_REG->SYSPRI1.R|=(SYSPRI_MEM<<5)|(SYSPRI_BUS<<13)|(SYSPRI_USAGE<<21);
    SCB_REG->SYSPRI2.R|=(SYSPRI_SVC<<29);
    SCB_REG->SYSPRI3.R|=(SYSPRI_DEBUG<<5)|(SYSPRI_PENDSV<<21)|(SYSPRI_TICK<<21);

    /*Enable or Disable*/
    if (UART0_IntState==Enable)   	                NVIC_REGISTER_EN->Num0Bit5=Enable;
    if (UART1_IntState==Enable)   	                NVIC_REGISTER_EN->Num0Bit6=Enable;
    if (UART2_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit1=Enable;
    if (UART3_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit27=Enable;
    if (UART4_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit28=Enable;
    if (UART5_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit29=Enable;
    if (UART6_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit30=Enable;
    if (UART7_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit31=Enable;

    if (SSI0_IntState==Enable)   	                NVIC_REGISTER_EN->Num0Bit7=Enable;
    if (SSI1_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit2=Enable;
    if (SSI2_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit25=Enable;
    if (SSI3_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit26=Enable;

    if (I2C0_IntState==Enable)   	                NVIC_REGISTER_EN->Num0Bit8=Enable;
    if (I2C1_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit5=Enable;
    if (I2C2_IntState==Enable)   	                NVIC_REGISTER_EN->Num2Bit4=Enable;
    if (I2C3_IntState==Enable)   	                NVIC_REGISTER_EN->Num2Bit5=Enable;

    if (PWM0_Fault_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit9=Enable;
    if (PWM0_Generator0_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit10=Enable;
    if (PWM0_Generator1_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit11=Enable;
    if (PWM0_Generator2_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit12=Enable;
    if (PWM0_Generator3_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit13=Enable;

    if (PWM1_Fault_IntState==Enable)   	        NVIC_REGISTER_EN->Num4Bit10=Enable;
    if (PWM1_Generator0_IntState==Enable)   	    NVIC_REGISTER_EN->Num4Bit6=Enable;
    if (PWM1_Generator1_IntState==Enable)   	    NVIC_REGISTER_EN->Num4Bit7=Enable;
    if (PWM1_Generator2_IntState==Enable)   	    NVIC_REGISTER_EN->Num4Bit8=Enable;
    if (PWM1_Generator3_IntState==Enable)   	    NVIC_REGISTER_EN->Num4Bit9=Enable;

    if (QEI0_IntState==Enable)   	                NVIC_REGISTER_EN->Num0Bit13=Enable;
    if (QEI1_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit6=Enable;

    if (ADC0_Sequence0_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit14=Enable;
    if (ADC0_Sequence1_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit15=Enable;
    if (ADC0_Sequence2_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit16=Enable;
    if (ADC0_Sequence3_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit17=Enable;
    if (ADC1_Sequence0_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit21=Enable;
    if (ADC1_Sequence1_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit22=Enable;
    if (ADC1_Sequence2_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit23=Enable;
    if (ADC1_Sequence3_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit24=Enable;


    if (Watchdog_Timers0and1_IntState==Enable)   	NVIC_REGISTER_EN->Num0Bit18=Enable;

    if (Timer0A_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit19=Enable;
    if (Timer0B_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit20=Enable;
    if (Timer1A_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit21=Enable;
    if (Timer1B_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit22=Enable;
    if (Timer2A_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit23=Enable;
    if (Timer2B_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit24=Enable;
    if (Timer3A_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit3=Enable;
    if (Timer3B_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit4=Enable;
    if (Timer4A_IntState==Enable)   	    NVIC_REGISTER_EN->Num2Bit6=Enable;
    if (Timer4B_IntState==Enable)   	    NVIC_REGISTER_EN->Num2Bit7=Enable;
    if (Timer5A_IntState==Enable)   	    NVIC_REGISTER_EN->Num2Bit28=Enable;
    if (Timer5B_IntState==Enable)   	    NVIC_REGISTER_EN->Num2Bit29=Enable;
    if (Timer0A_IntState==Enable)   	    NVIC_REGISTER_EN->Num2Bit30=Enable;
    if (Timer0B_IntState==Enable)    	NVIC_REGISTER_EN->Num2Bit31=Enable;

    if (Timer1A_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit1=Enable;
    if (Timer1B_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit2=Enable;
    if (Timer2A_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit3=Enable;
    if (Timer2B_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit4=Enable;
    if (Timer3A_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit5=Enable;
    if (Timer3B_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit6=Enable;
    if (Timer4A_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit7=Enable;
    if (Timer4B_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit8=Enable;
    if (Timer5A_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit9=Enable;
    if (Timer5B_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit10=Enable;

    if (Analog_Comparator0_IntState==Enable)   	NVIC_REGISTER_EN->Num0Bit25=Enable;
    if (Analog_Comparator1_IntState==Enable)   	NVIC_REGISTER_EN->Num0Bit26=Enable;

    if (SystemControl_IntState==Enable)   	        NVIC_REGISTER_EN->Num0Bit28=Enable;
    if (FMC_and_EEPROMC_IntState==Enable)   	    NVIC_REGISTER_EN->Num0Bit29=Enable;
    if (CAN0_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit7=Enable;
    if (CAN1_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit8=Enable;
    if (HibernationModule_IntState==Enable)   	    NVIC_REGISTER_EN->Num1Bit11=Enable;
    if (USB_IntState==Enable)   	                NVIC_REGISTER_EN->Num1Bit12=Enable;
    if (UDMA_Software_IntState==Enable)   	        NVIC_REGISTER_EN->Num1Bit14=Enable;
    if (UDMA_Error_IntState==Enable)   	        NVIC_REGISTER_EN->Num1Bit15=Enable;
    if (SystemException_IntState==Enable)   	    NVIC_REGISTER_EN->Num3Bit11=Enable;

    SCB_REG->SYSHNDCTRL.R|=(MEMA_State<<MEMA)|(BUS_State<<BUSA)|(USGA_State<<USGA)|(SVCA_State<<SVCA)|(MON_State<<MON)|(PNDSV_State<<PNDSV)|(TICK_State<<TICK)|(USAGEP_State<<USAGEP)|(MEMP_State<<MEMP)|(BUSP_State<<BUSP)|(SVC_State<<SVC)|(MEM_State<<MEM)|(BUS_State<<BUS)|(USAGE_State<<USAGE);
	SCB_REG->INTCTRL.B. Bit26=1;
}
/**********************************************************************************************************************
 *  END OF FILE: ADC.c
 *********************************************************************************************************************/