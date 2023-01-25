/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Gpio_Port.h>
    
 *  
 *********************************************************************************************************************/
#ifndef <GPIO_PORT_H>
#define <GPIO_PORT_H>

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define UNLOCK_KEY 0x4C4F434B

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/*PORT A*/
#define PORTA_DATA		     *((volatile uint32*)0x400043FC)
#define PORTA_DIR	         *((volatile uint32*)0x40004400)
#define PORTA_IS             *((volatile uint32*)0x40004404)
#define PORTA_IBE            *((volatile uint32*)0x40004408)
#define PORTA_IEV            *((volatile uint32*)0x4000440C)
#define PORTA_IM             *((volatile uint32*)0x40004410)
#define PORTA_RIS            *((volatile uint32*)0x40004414)
#define PORTA_MIS            *((volatile uint32*)0x40004418)
#define PORTA_ICR            *((volatile uint32*)0x4000441C)
#define PORTA_AFSEL          *((volatile uint32*)0x40004420)
#define PORTA_PUR            *((volatile uint32*)0x40004510)
#define PORTA_PDR            *((volatile uint32*)0x40004514)
#define PORTA_DEN            *((volatile uint32*)0x4000451C)
#define PORTA_LOCK           *((volatile uint32*)0x40004520)
#define PORTA_CR             *((volatile uint32*)0x40004524)
#define PORTA_AMSEL          *((volatile uint32*)0x40004528)
#define PORTA_PCTL           *((volatile uint32*)0x4000452C)

/*PORT B*/
#define PORTB_DATA		     *((volatile uint32*)0x400053FC)
#define PORTB_DIR	         *((volatile uint32*)0x40005400)
#define PORTB_IS             *((volatile uint32*)0x40005404)
#define PORTB_IBE            *((volatile uint32*)0x40005408)
#define PORTB_IEV            *((volatile uint32*)0x4000540C)
#define PORTB_IM             *((volatile uint32*)0x40005410)
#define PORTB_RIS            *((volatile uint32*)0x40005414)
#define PORTB_MIS            *((volatile uint32*)0x40005418)
#define PORTB_ICR            *((volatile uint32*)0x4000541C)
#define PORTB_AFSEL          *((volatile uint32*)0x40005420)
#define PORTB_PUR            *((volatile uint32*)0x40005510)
#define PORTB_PDR            *((volatile uint32*)0x40005514)
#define PORTB_DEN            *((volatile uint32*)0x4000551C)
#define PORTB_LOCK           *((volatile uint32*)0x40005520)
#define PORTB_CR             *((volatile uint32*)0x40005524)
#define PORTB_AMSEL          *((volatile uint32*)0x40005528)
#define PORTB_PCTL           *((volatile uint32*)0x4000552C)

/*PORT C*/
#define PORTC_DATA		     *((volatile uint32*)0x400063FC)
#define PORTC_DIR	         *((volatile uint32*)0x40006400)
#define PORTB_IS             *((volatile uint32*)0x40006404)
#define PORTC_IBE            *((volatile uint32*)0x40006408)
#define PORTC_IEV            *((volatile uint32*)0x4000640C)
#define PORTC_IM             *((volatile uint32*)0x40006410)
#define PORTC_RIS            *((volatile uint32*)0x40006414)
#define PORTC_MIS            *((volatile uint32*)0x40006418)
#define PORTC_ICR            *((volatile uint32*)0x4000641C)
#define PORTC_AFSEL          *((volatile uint32*)0x40006420)
#define PORTC_PUR            *((volatile uint32*)0x40006510)
#define PORTC_PDR            *((volatile uint32*)0x40006514)
#define PORTC_DEN            *((volatile uint32*)0x4000651C)
#define PORTC_LOCK           *((volatile uint32*)0x40006520)
#define PORTC_CR             *((volatile uint32*)0x40006524)
#define PORTC_AMSEL          *((volatile uint32*)0x40006528)
#define PORTC_PCTL           *((volatile uint32*)0x4000652C)

/*PORT D*/
#define PORTD_DATA		     *((volatile uint32*)0x400073FC)
#define PORTD_DIR	         *((volatile uint32*)0x40007400)
#define PORTD_IS             *((volatile uint32*)0x40007404)
#define PORTD_IBE            *((volatile uint32*)0x40007408)
#define PORTD_IEV            *((volatile uint32*)0x4000740C)
#define PORTD_IM             *((volatile uint32*)0x40007410)
#define PORTD_RIS            *((volatile uint32*)0x40007414)
#define PORTD_MIS            *((volatile uint32*)0x40007418)
#define PORTD_ICR            *((volatile uint32*)0x4000741C)
#define PORTD_AFSEL          *((volatile uint32*)0x40007420)
#define PORTD_PUR            *((volatile uint32*)0x40007510)
#define PORTD_PDR            *((volatile uint32*)0x40007514)
#define PORTD_DEN            *((volatile uint32*)0x4000751C)
#define PORTD_LOCK           *((volatile uint32*)0x40007520)
#define PORTD_CR             *((volatile uint32*)0x40007524)
#define PORTD_AMSEL          *((volatile uint32*)0x40007528)
#define PORTD_PCTL           *((volatile uint32*)0x4000752C)

/*PORT E*/
#define PORTE_DATA		     *((volatile uint32*)0x400243FC)
#define PORTE_DIR	         *((volatile uint32*)0x40024400)
#define PORTE_IS             *((volatile uint32*)0x40024404)
#define PORTE_IBE            *((volatile uint32*)0x40024408)
#define PORTE_IEV            *((volatile uint32*)0x4002440C)
#define PORTE_IM             *((volatile uint32*)0x40024410)
#define PORTE_RIS            *((volatile uint32*)0x40024414)
#define PORTE_MIS            *((volatile uint32*)0x40024418)
#define PORTE_ICR            *((volatile uint32*)0x4002441C)
#define PORTE_AFSEL          *((volatile uint32*)0x40024420)
#define PORTE_PUR            *((volatile uint32*)0x40024510)
#define PORTE_PDR            *((volatile uint32*)0x40024514)
#define PORTE_DEN            *((volatile uint32*)0x4002451C)
#define PORTE_LOCK           *((volatile uint32*)0x40024520)
#define PORTE_CR             *((volatile uint32*)0x40024524)
#define PORTE_AMSEL          *((volatile uint32*)0x40024528)
#define PORTE_PCTL           *((volatile uint32*)0x4002452C)

/*PORT F*/
#define PORTF_DATA		     *((volatile uint32*)0x400253FC)
#define PORTF_DIR	         *((volatile uint32*)0x40025400)
#define PORTF_IS             *((volatile uint32*)0x40025404)
#define PORTF_IBE            *((volatile uint32*)0x40025408)
#define PORTF_IEV            *((volatile uint32*)0x4002540C)
#define PORTF_IM             *((volatile uint32*)0x40025410)
#define PORTF_RIS            *((volatile uint32*)0x40025414)
#define PORTF_MIS            *((volatile uint32*)0x40025418)
#define PORTF_ICR            *((volatile uint32*)0x4002541C)
#define PORTF_AFSEL          *((volatile uint32*)0x40025420)
#define PORTF_PUR            *((volatile uint32*)0x40025510)
#define PORTF_PDR            *((volatile uint32*)0x40025514)
#define PORTF_DEN            *((volatile uint32*)0x4002551C)
#define PORTF_LOCK           *((volatile uint32*)0x40025520)
#define PORTF_CR             *((volatile uint32*)0x40025524)
#define PORTF_AMSEL          *((volatile uint32*)0x40025528)
#define PORTF_PCTL           *((volatile uint32*)0x4002552C)

//DUNNO WHAT IS THIS 
//Run Mode clock gating control
#define SYSCTL_RCGC2_R  				(*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* GPIO_PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/