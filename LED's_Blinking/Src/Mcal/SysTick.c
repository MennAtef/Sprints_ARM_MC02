/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
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
#include "SysTick.h"
#include "Nvic.h"
#include "SysTick_Cfg.h"
#include "platform_types.h"
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
void SysTick_Init(void)
{
	uint32 CLK_SOURCE, INT_STATE;
    if (INT_STATE == 1)
    {
        uint32 NvicCtrl_R ;
		NvicCtrl_R |= (1<<1) ;
	}
    else
    {
       uint32 NvicCtrl ;
	   NvicCtrl &=~ (1<<1) ; 
	}

    if(CLK_SOURCE == 1)
    {
        uint32 NvicCtrl_R;
		NvicCtrl_R |= (1<<2) ;
	}
    else
    {
       uint32 NvicCtrl; 
	   NvicCtrl &=~(1<<2) ; 
	}

    uint32 NvicCurrent_R = 0;
	if((DUTY_CYCLE) > 0 && DUTY_CYCLE<100)
    {
		//16000000/100
		uint32 NvicRelod=(16000000-((* DUTY_CYCLE)*160000))-1;
	}
}
void GPT__Init( const GPT__ConfigiurationType* ConfPtr)
{
	uint32 GPT__Base_Address;
	GPT__Ch_Type 						Ch_Temp ;					
	GPT__ChTickFrequencyuency 		TickFrequencyuency_Temp; 
	GPT__ChTickValueMax  		TickValueMax_Temp;
	Ch_Mode  						Mode_Temp;

    for(uint32 _Counter_ =0;_Counter_ <GPT__ACTIVATED_ChS_SIZE;_Counter_ ++)
    {
        Ch_Temp=ConfiGPT_r[_Counter_].Ch;			
        TickFrequencyuency_Temp=ConfiGPT_r[_Counter_].ChTickFrequency;	
        TickValueMax_Temp=ConfiGPT_r[_Counter_].ChTickMaxValue;	
        Mode_Temp=ConfiGPT_r[_Counter_].ChMode;
        locGPT_Notification[Ch_Temp]= ConfiGPT_r[_Counter_].GPT_Notification;
		
		//GPT_Base_Address = GPT__Base_Address[Ch_Temp];
	
		(*((volatile uint32*)(GPT__Base_Address[Ch_Temp] + GPT_MCTL_OFFSET  ))) &= ((uint32)(~(1<<0))); 

        (*((volatile uint32*)(GPT__Base_Address[Ch_Temp] + GPT_MCFG_OFFSET  ))) = 0x4;     

		(*((volatile uint32*)(GPT__Base_Address[Ch_Temp] + GPT_MTAMR_OFFSET  ))) |= ((uint32)(1<<TACDIR)); 

	    if	(Mode_Temp==GPT__CH_MODE_CONTINUOUS) 
        {
            (*((volatile uint32*)(GPT__Base_Address[Ch_Temp] + GPT_MTAMR_OFFSET  ))) |= 0x2;
        }
        else if (Mode_Temp==GPT__CH_MODE_ONESHOT)		
        {
            (*((volatile uint32*)(GPT__Base_Address[Ch_Temp] + GPT_MTAMR_OFFSET  ))) |= 0x1;
        }		 
        GPT__DisableNotification(Ch_Temp);
    }
}
void SysTick_Handler(void)
{
	uint32 PWR;
		if(PWR==0)
        { 
			SysTick_Stop();
			uint32 NvicCurrent = 0;
			//16000000/100
			uint32 NVIC_ST_RELOAD=((*DUTY_CYCLE)*160000)-1;	 
			PWR ^= 1;		
	    }

		else
        {		
			SysTick_Stop();
			uint32 NVIC_ST_CURRENT = 0;
			//16000000/100
			uint32 NvicRelod=(16000000-((*DUTY_CYCLE)*160000))-1;	
			PWR ^= 1;
	    }
	SysTick_CallBack();
	SysTick_Start();
}

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


void StartSysTick (uint32 Seconds_ms)
{
	uint32 NvicCtrl_R ;
	NvicCtrl_R |= (1<<1);
	uint32 _Counts_Number_ = 16000000/(1000 /Seconds_ms);		

	uint32 STRELOAD = (uint32)(_Counts_Number_ - 1);

	uint32 STCTRL ;
	STCTRL |= (1<<0);		
}
void GPT__StartTimer( GPT__Ch_Type Ch_, GPT__ValueType Value )
{
	uint32 _Counter_;
	uint32 PRE_SCALER;
	GPT__Ch_TickFrequencyuency 	locCh_TickFrequency=0;
	(*((volatile uint32*)(GPT__Base_Address[Ch_] + GPT_MTAILR_OFFSET  ))) = Value * PRE_SCALER;
	(*((volatile uint32*)(GPT__Base_Address[Ch_] + GPT_MCTL_OFFSET  ))) |= ((uint32)(1<<TAEN));
	 
	for(uint8 _Counter_=0; _Counter_ < MAX_NUMBER_OF_GPIO_GPT_ ; _Counter_++)
		{
			if (globalGPT_Config[_Counter_].Ch_ == Ch_)
			{
				locCh_TickFrequency = globalGPT_Config[_Counter_].Ch_TickFrequency;			
				break;
			}
		}
	
	PRE_SCALER = GlobalSystemClock / locCh_TickFrequency;
	

	
	for(_Counter_=2 ; ; _Counter_*=2)
	{

		if(PRE_SCALER/_Counter_ == 1)
		{
			if(PRE_SCALER%_Counter_ <= (_Counter_/2))
			{
				PRE_SCALER = _Counter_;
			}
			else
			{
				PRE_SCALER = _Counter_*2;
			}
			break;
		}
	}

}
void SysTick_CallBack_DC(uint32 * _DUTY_CYCLE_)
{
	DUTY_CYCLE = _DUTY_CYCLE_ ;
}
void StopSysTick (void)
{
	uint32 STCTRL ;
	STCTRL &= ~(1<<0);		
	STCTRL &= ~(1<<1);		
}
void SisTick_CallBack(void(*pointer)(void))
{
	SysTick_CallBack = pointer;
}
void SysTick_Handler(void)
{
		
		uint32 PWR; 
		if(PWR == 0)
		{ 
			uint32 NVIC_ST_CURRENT = 0;
			SisTick_Stop();
			NVIC_ST_CURRENT = 0;
			//16000000/100
			uint32 NVIC_ST_RELOAD=((*DUTY_CYCLE)*160000)-1;	 
			PWR ^=1;		
	}
		else{		//led was on
			SisTick_Stop();
			uint32 NVIC_ST_CURRENT = 0;
			//16000000/100
			uint32 NVIC_ST_RELOAD=(16000000-((*DUTY_CYCLE)*160000))-1;	
			PWR ^= 1;
	}
	SisTick_CallBack();
	SisTick_Start();
}
void GPT__EnableNotification( GPT__ChType _Ch_ )
{
	(*((volatile uint32*)(GPT__Base_Address[_Ch_] + _GPT_MIMR_OFFSET_  ))) |= ((uint32)(1<<0));
}


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

    



/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/