/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  STK_Program.c
 *		  Layer:  MCAL
 *       Module:  STK
 *		Version:  1.00
 *	
 *  Description:  Implementation of the module function
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "TM4C123xx.h"
#include "Std_Types.h"
#include "Bit_Math.h"

#include "STK_Interface.h"
#include "STK_Private.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax          : void STK_Delyms(u32 Copy_Delayms)
 * \Description     : used for delay of max 4192 ms
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Delayms    Delay in ms
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void STK_Delyms(u32 Copy_Delayms)
{
    /*Max count 4192 ms*/
    /*Program the value of Load*/
    /*To convert the time to ms we must multiply by 4000*/
    STK->LOAD=Copy_Delayms*STK_FACTOR;
    /*Clear current*/
    STK->CURRENT=0;
    /*Set the clock source*/
    CLR_BIT(STK->CTRL,STK_CLK_SRC);
    /*Enable the STK*/
    SET_BIT(STK->CTRL,STK_ENABLE);
    /*Busy waiting until it counts to zero*/
    while(GET_BIT(STK->CTRL,STK_COUNT)==0);
}

/**********************************************************************************************************************
 *  END OF FILE: STK_Program.c
 *********************************************************************************************************************/
