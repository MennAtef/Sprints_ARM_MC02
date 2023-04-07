/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Macros.h"
#include "std_types.h"
#include "IntCtrl.h"
#include "platform_types.h"
#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

#define PRIx(x)      *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+((0x0400+(x/4)*4)))
#define ENx(x)       *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+((0x0100+(x/32)*32)))
#define DISx(x)      *((volatile uint32*)CORTEXM4_CORE_PERI_BASE_ADDRESS+((0x0180+(x/32)*32)))
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void INT_CTRL_Init(void)
{
	uint32 priority;
	uint32 x;
	for( x =0;x<139;x++)
	{
		if(ARRAY_INTERRUPT[x]<8)
		{
			priority=ARRAY_INTERRUPT[x];
			//Priority number int_req /4
			uint32 PriorityNumber = x / 4;
			//Number of group of the priority
			uint32 GroupPriority = x % 4;
			//Enable Regiester number 
			uint32 RegiesterEnabledNumber = x /32;
			//Pin number to enable
			uint32 PinNumberEnabled = x % 32;

			//FIND THE GROUP AND THE SUB-GROUP
			switch(GroupPriority) 
			{
				case XXX: 
					NVIC_APINT |= 0xFA050000;  
				break;

				case XXY:
				    NVIC_APINT |= 0xFA050500; 
				break;

				case XYY:
					NVIC_APINT |= 0xFA050600;
				break;

				case YYY:
					NVIC_APINT |= 0xFA050700;
				break;
			}

			switch(PriorityNumber)
			{
				case 0:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI0=(NVIC_PRI0 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI0=(NVIC_PRI0 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI0=(NVIC_PRI0 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI0=(NVIC_PRI0 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 1:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI1=(NVIC_PRI1 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI1=(NVIC_PRI1 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI1=(NVIC_PRI1 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI1=(NVIC_PRI1 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 2:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI2=(NVIC_PRI2 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI2=(NVIC_PRI2 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI2=(NVIC_PRI2 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI2=(NVIC_PRI2 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 3:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI3=(NVIC_PRI3 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI3=(NVIC_PRI3 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI3=(NVIC_PRI3 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI3=(NVIC_PRI3 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;	

				case 4:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI4=(NVIC_PRI4 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI4=(NVIC_PRI4 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI4=(NVIC_PRI4 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI4=(NVIC_PRI4 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;	

				case 5:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI5=(NVIC_PRI5 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI5=(NVIC_PRI5 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI5=(NVIC_PRI5 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI5=(NVIC_PRI5 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 6:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI6=(NVIC_PRI6 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI6=(NVIC_PRI6 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI6=(NVIC_PRI6 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI6=(NVIC_PRI6 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;		

				case 7:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI7=(NVIC_PRI7 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI7=(NVIC_PRI7 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI7=(NVIC_PRI7 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI7=(NVIC_PRI7 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 8:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI8=(NVIC_PRI8 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI8=(NVIC_PRI8 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI8=(NVIC_PRI8 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI8=(NVIC_PRI8 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;
				
				case 9:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI9=(NVIC_PRI9 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI9=(NVIC_PRI9 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI9=(NVIC_PRI9 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI9=(NVIC_PRI9 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 10:
								switch(GroupPriority)
				{
				case 0:
					NVIC_PRI10=(NVIC_PRI10 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI10=(NVIC_PRI10 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI10=(NVIC_PRI10 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI10=(NVIC_PRI10 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 11:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI11=(NVIC_PRI11 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI11=(NVIC_PRI11 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI11=(NVIC_PRI11 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI11=(NVIC_PRI11 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 12:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI12=(NVIC_PRI12 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI12=(NVIC_PRI12 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI12=(NVIC_PRI12 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI12=(NVIC_PRI12 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 13:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI13=(NVIC_PRI13 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI13=(NVIC_PRI13 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI13=(NVIC_PRI13 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI13=(NVIC_PRI13 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 14:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI14=(NVIC_PRI14 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI14=(NVIC_PRI14 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI14=(NVIC_PRI14 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI14=(NVIC_PRI14 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 15:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI15=(NVIC_PRI15 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI15=(NVIC_PRI15 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI15=(NVIC_PRI15 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI15=(NVIC_PRI15 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 16:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI16=(NVIC_PRI16 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI16=(NVIC_PRI16 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI16=(NVIC_PRI16 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI16=(NVIC_PRI16 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 17:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI17=(NVIC_PRI17 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI17=(NVIC_PRI17 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI17=(NVIC_PRI17 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI17=(NVIC_PRI17 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 18:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI18=(NVIC_PRI18 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI18=(NVIC_PRI18 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI18=(NVIC_PRI18 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI18=(NVIC_PRI18 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 19:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI19=(NVIC_PRI19 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI19=(NVIC_PRI19 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI19=(NVIC_PRI19 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI19=(NVIC_PRI19 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 20:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI20=(NVIC_PRI20 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI20=(NVIC_PRI20 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI20=(NVIC_PRI20 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI20=(NVIC_PRI20 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 21:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI21=(NVIC_PRI21 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI21=(NVIC_PRI21 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI21=(NVIC_PRI21 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI21=(NVIC_PRI21 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 22:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI22=(NVIC_PRI22 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI22=(NVIC_PRI22 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI22=(NVIC_PRI22 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI22=(NVIC_PRI22 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 23:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI23=(NVIC_PRI23 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI23=(NVIC_PRI23 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI23=(NVIC_PRI23 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI23=(NVIC_PRI23 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 24:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI24=(NVIC_PRI24 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI24=(NVIC_PRI24 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI24=(NVIC_PRI24 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI24=(NVIC_PRI24 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 25:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI25=(NVIC_PRI25 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI25=(NVIC_PRI25 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI25=(NVIC_PRI25 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI25=(NVIC_PRI25 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 26:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI26=(NVIC_PRI26 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI26=(NVIC_PRI26 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI26=(NVIC_PRI26 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI26=(NVIC_PRI26 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 27:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI27=(NVIC_PRI27 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI27=(NVIC_PRI27 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI27=(NVIC_PRI27 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI27=(NVIC_PRI27 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 28:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI28=(NVIC_PRI28 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI28=(NVIC_PRI28 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI28=(NVIC_PRI28 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI28=(NVIC_PRI28 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 29:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI29=(NVIC_PRI29 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI29=(NVIC_PRI29 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI29=(NVIC_PRI29 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI29=(NVIC_PRI29 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 30:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI30=(NVIC_PRI30 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI30=(NVIC_PRI30 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI30=(NVIC_PRI30 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI30=(NVIC_PRI30 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 31:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI31=(NVIC_PRI31 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI31=(NVIC_PRI31 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI31=(NVIC_PRI31 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI31=(NVIC_PRI31 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 32:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI32=(NVIC_PRI32 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI32=(NVIC_PRI32 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI32=(NVIC_PRI32 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI32=(NVIC_PRI32 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 33:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI33=(NVIC_PRI33 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI33=(NVIC_PRI33 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI33=(NVIC_PRI33 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI33=(NVIC_PRI33 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;

				case 34:
				switch(GroupPriority)
				{
				case 0:
					NVIC_PRI34=(NVIC_PRI34 & 0xFFFFFF1F)|(((uint32)priority)<<5);
            	break;

        		case 1:
           			 NVIC_PRI34=(NVIC_PRI34 & 0xFFFF1FFF)|(((uint32)priority)<<13);
            	break;

        		case 2:
            		NVIC_PRI34=(NVIC_PRI34 & 0xFF1FFFFF)|(((uint32)priority)<<18);
            	break;

        		case 3:
            		NVIC_PRI34=(NVIC_PRI34 & 0x1FFFFFFF)|(((uint32)priority)<<29);
            	break;
				}
				break;
			}

			switch(RegiesterEnabledNumber)
			{
				case 0:
					NVIC_EN0|=(1<<PinNumberEnabled);
        		break;
				case 1:
					NVIC_EN1|=(1<<PinNumberEnabled);
        		break;
				case 2:
					NVIC_EN2|=(1<<PinNumberEnabled);
        		break;
				case 3:
					NVIC_EN3|=(1<<PinNumberEnabled);
        		break;
				case 4:
					NVIC_EN4|=(1<<PinNumberEnabled);
        		break;
			}
		}
	}
}
void INT_Req_DISABLE(uint32 INT_Req)
{
	
	uint32 DisabledRegiesterNumber = INT_Req / 32;
	uint32 DisabledPinNumber = INT_Req % 32;

	switch(DisabledRegiesterNumber)
	{
		case 0:
			NVIC_DIS0|=(uint32)DisabledPinNumber;
			ARRAY_INTERRUPT[INT_Req]=8;
		break;	

		case 1:
			NVIC_DIS1|=(uint32)DisabledPinNumber;
			ARRAY_INTERRUPT[INT_Req]=8;
        break;

		case 2:
			NVIC_DIS2|=(uint32)DisabledPinNumber;
			ARRAY_INTERRUPT[INT_Req]=8;
        break;

		case 3:
			NVIC_DIS3|=(uint32)DisabledPinNumber;
			ARRAY_INTERRUPT[INT_Req]=8;
        break;

		case 4:
			NVIC_DIS4|=(uint32)DisabledPinNumber;
			ARRAY_INTERRUPT[INT_Req]=8;
        break;
	}
}
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

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/