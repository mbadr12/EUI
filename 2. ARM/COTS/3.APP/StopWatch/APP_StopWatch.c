/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *         File:  App_StopWatch.c
 *        Layer:  App
 *       Module:  App
 *      Version:  1.00
 *
 *  Description:  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "NVIC_Interface.h"
#include "STK_Interface.h"
#include "EXTI_Interface.h"
#include "LCD_Interface.h"
#include "APP_StopWatch.h"

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

static u8 App_XPositon=0;
static u8 App_YPosition=0;

static LCD_Config_t LCD_Con={.ControlPinsPorts={GPIO_PORTA,GPIO_PORTA,GPIO_PORTA},.ControlPins={GPIO_PIN2, GPIO_PIN3, GPIO_PIN4},
                      .DataPinsPorts={GPIO_PORTE,GPIO_PORTE,GPIO_PORTE,GPIO_PORTE},
                      .DataPins={GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3},.XPosition=&App_XPositon,.Yposition=&App_YPosition,
                      .Cursor=LCD_NO_CURSOR,.Font=LCD_5_8_FONT,.Mode=LCD_4BIT_MODE,.LinesNum=LCD_TWO_LINES};

static volatile u8 APP_HrCounter=0;

static volatile u8 APP_MinCounter=0;

static volatile u8 APP_SecCounter=0;

static volatile u8 APP_StartStop=0;

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
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
void APP_WriteCurrentCount(u8 Copy_HrCount,u8 Copy_MinCount,u8 Copy_SecCount)
{
    LCD_SendChar(&LCD_Con, ((Copy_HrCount/10)+'0'));
    LCD_SendChar(&LCD_Con, ((Copy_HrCount%10)+'0'));
    LCD_SendChar(&LCD_Con, ':');
    LCD_SendChar(&LCD_Con, ((Copy_MinCount/10)+'0'));
    LCD_SendChar(&LCD_Con, ((Copy_MinCount%10)+'0'));
    LCD_SendChar(&LCD_Con, ':');
    LCD_SendChar(&LCD_Con, ((Copy_SecCount/10)+'0'));
    LCD_SendChar(&LCD_Con, ((Copy_SecCount%10)+'0'));
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

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
void System_Init(void)
{
    GPIO_Config_t Config[2]={{.Port=GPIO_PORTF,.Pin=GPIO_PIN0,.Dir=GPIO_PIN_INPUT,.Mode=GPIO_PIN_DIGITAL,.PinPull=GPIO_PIN_PULLUP},
                             {.Port=GPIO_PORTF,.Pin=GPIO_PIN4,.Dir=GPIO_PIN_INPUT,.Mode=GPIO_PIN_DIGITAL,.PinPull=GPIO_PIN_PULLUP}};
    EXTI_Config_t App_Config[2]={{.Port=EXTI_PORTF,.Pin=EXTI_PIN0,.Sence=EXTI_EDGE,.TrigTye=EXTI_FALLING_EDGE},
                                 {.Port=EXTI_PORTF,.Pin=EXTI_PIN4,.Sence=EXTI_EDGE,.TrigTye=EXTI_FALLING_EDGE}};
    /*Initialize Switches*/
    GPIO_Init(Config, 2);
    /*Enable EXTI from NVIC*/
    NVIC_SetInterruptState(NVIC_PORTF_IRQ, NVIC_INT_ENABLE);
    /*Initialize EXTI*/
    EXTI_Init(App_Config, 2);
    /*Initialize LCD*/
    LCD_Init(&LCD_Con);
    /*Set Callback of EXTI*/
    EXTI_SetCallBack(EXTI_PORTF,EXTI_PIN0, APP_Switch1);
    EXTI_SetCallBack(EXTI_PORTF,EXTI_PIN4, APP_Switch2);

}

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
void APP_Welcome(void)
{
    LCD_SendString(&LCD_Con, "Welcome to Badr    Stop Watch");
    STK_Delyms(3000);
    LCD_Clear(&LCD_Con);
    APP_WriteCurrentCount(APP_HrCounter, APP_MinCounter, APP_SecCounter);
}

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
void APP_SysTickInit(void)
{
    STK_SetCallBack(APP_Counter);
    STK_Init(STK_INT_OS_DIV_4, 4000000, STK_INT_DISABLED);
}

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
void APP_Switch1(void)
{
    APP_StartStop ^=1;
    if(APP_StartStop==1)
    {
        STK_SetIntState(STK_INT_ENABLED);
    }
    else
    {
        STK_SetIntState(STK_INT_DISABLED);
    }
}

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
void APP_Switch2(void)
{
    if(APP_StartStop==1)
    {
        LCD_GoToXY(&LCD_Con, 0, 1);
        APP_WriteCurrentCount(APP_HrCounter, APP_MinCounter, APP_SecCounter);
    }
    else
    {
        APP_HrCounter=0;
        APP_MinCounter=0;
        APP_SecCounter=0;
        LCD_Clear(&LCD_Con);
        LCD_SendString(&LCD_Con, "00:00:00");
    }
}

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
void APP_Counter(void)
{
    APP_SecCounter++;
    if(APP_SecCounter==60)
    {
        APP_MinCounter++;
        APP_SecCounter=0;
    }
    else
    {
        /*MISRA*/
    }
    if(APP_MinCounter==60)
    {
        APP_HrCounter++;
        APP_MinCounter=0;
    }
    else
    {
        /*MISRA*/
    }
    if(APP_HrCounter==24)
    {
        APP_HrCounter=0;
    }
    else
    {
        /*MISRA*/
    }
    LCD_GoToXY(&LCD_Con, 0, 0);
    APP_WriteCurrentCount(APP_HrCounter, APP_MinCounter, APP_SecCounter);
}

/**********************************************************************************************************************
 *  END OF FILE: APP_StopWatch.c
 *********************************************************************************************************************/
