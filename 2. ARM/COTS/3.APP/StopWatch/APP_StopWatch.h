/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *         File:  App_StopWatch.h
 *        Layer:  App
 *       Module:  StopWatch
 *      Version:  1.00
 *
 *  Description:  -
 *
 *********************************************************************************************************************/
#ifndef APP_STOPWATCH_H_
#define APP_STOPWATCH_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*****************************************************************************************************
 * \Syntax          : void APP_WriteCurrentCount(u8 Copy_HrCount,u8 Copy_MinCount,u8 Copy_SecCount)
 * \Description     : Write current time on LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_HrCount   Hours Count
 *                    Copy_MinCount  Minutes Count
 *                    Copy_SecCount  Seconds Count
 * \Parameters (out): None
 * \Return value:   : void
 *****************************************************************************************************/
void APP_WriteCurrentCount(u8 Copy_HrCount,u8 Copy_MinCount,u8 Copy_SecCount);

/******************************************************************************
 * \Syntax          : void System_Init(void)
 * \Description     : Initialize the System
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void System_Init(void);

/******************************************************************************
 * \Syntax          : void APP_Welcome(void)
 * \Description     : Display welcome Message to user
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_Welcome(void);

/******************************************************************************
 * \Syntax          : void APP_SysTickInit(void)
 * \Description     : Initialize the SysTick Timer
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_SysTickInit(void);

/******************************************************************************
 * \Syntax          : void APP_Switch1(void)
 * \Description     : Callback Function Passed to EXTI of PF0
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_Switch1(void);

/******************************************************************************
 * \Syntax          : void APP_Switch2(void)
 * \Description     : Callback Function Passed to EXTI of PF4
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_Switch2(void);

/******************************************************************************
 * \Syntax          : void APP_Counter(void)
 * \Description     : Callback Function Passed to SysTick
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_Counter(void);

#endif /* APP_STOPWATCH_H_ */
/**********************************************************************************************************************
 *  END OF FILE: APP_Calc.h
 *********************************************************************************************************************/
