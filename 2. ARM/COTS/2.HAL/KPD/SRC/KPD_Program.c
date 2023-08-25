/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  KPD_Program.c
 *		  Layer:  HAL
 *       Module:  KPD
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "TM4C123xx.h"
#include "Std_Types.h"
#include "Bit_Math.h"

#include "KPD_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : ErrorState_t KPD_Init(KPD_Config_t* Copy_Config)
 * \Description     : Initialize the keypad Pins
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     Keypad Configuration Structure
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *******************************************************************************/
ErrorState_t KPD_Init(KPD_Config_t* Copy_Config)
{
    ErrorState_t Local_ErrorState=E_OK;
    GPIO_Config_t Local_KPDConfig[8];
    u8 Local_Counter=0;
    if(Copy_Config==NULL)
    {
        Local_ErrorState=E_NULL_POINTER;
    }
    else
    {
        for( ;Local_Counter<(Copy_Config->RawsNum);Local_Counter++)
        {
            Local_KPDConfig[Local_Counter].Port=Copy_Config->RowPinsPorts[Local_Counter];
            Local_KPDConfig[Local_Counter].Pin=Copy_Config->RowPins[Local_Counter];
            Local_KPDConfig[Local_Counter].Dir=GPIO_PIN_INPUT;
            Local_KPDConfig[Local_Counter].Mode=GPIO_PIN_DIGITAL;
            Local_KPDConfig[Local_Counter].PinPull=GPIO_PIN_PULLUP;
            Local_KPDConfig[Local_Counter].PinState=GPIO_PIN_PUSHPULL;
        }
        for(Local_Counter=0 ;Local_Counter<(Copy_Config->ColumnsNum);Local_Counter++)
        {
            Local_KPDConfig[Local_Counter+(Copy_Config->RawsNum)].Port=Copy_Config->ColumnPinsPorts[Local_Counter];
            Local_KPDConfig[Local_Counter+(Copy_Config->RawsNum)].Pin=Copy_Config->ColumnPins[Local_Counter];
            Local_KPDConfig[Local_Counter+(Copy_Config->RawsNum)].Dir=GPIO_PIN_OUTPUT;
            Local_KPDConfig[Local_Counter+(Copy_Config->RawsNum)].Mode=GPIO_PIN_DIGITAL;
            Local_KPDConfig[Local_Counter+(Copy_Config->RawsNum)].PinPull=GPIO_PIN_FLOATING;
            Local_KPDConfig[Local_Counter+(Copy_Config->RawsNum)].PinState=GPIO_PIN_PUSHPULL;
        }
        Local_ErrorState=GPIO_Init(Local_KPDConfig, ((Copy_Config->RawsNum)+(Copy_Config->ColumnsNum)));
        for(Local_Counter=0 ;Local_Counter<(Copy_Config->ColumnsNum);Local_Counter++)
        {
            GPIO_SetPinValue(Copy_Config->ColumnPinsPorts[Local_Counter], Copy_Config->ColumnPins[Local_Counter], GPIO_PIN_HIGH);
        }
    }
    return Local_ErrorState;
}

/******************************************************************************************************
 * \Syntax          : ErrorState_t KPD_GetPressedKey(KPD_Config_t* Copy_Config,u8* Copy_PressedKey)
 * \Description     : Get the Pressed key
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config       Keypad Configuration Structure
 * \Parameters (out): Copy_PressedKey   The value of pressed key
 * \Return value:   : ErrorState_t
 ******************************************************************************************************/
ErrorState_t KPD_GetPressedKey(KPD_Config_t* Copy_Config,u8* Copy_PressedKey)
{
    ErrorState_t Local_ErrorState=E_OK;
    u8 Local_KeypadArr[KPD_MAX_ROW][KPD_MAX_COLUMN]=KPD_ARRAY;
    *Copy_PressedKey=(u8)KPD_NOT_PRESSED;
    GPIO_PinValue_t Local_State=GPIO_PIN_HIGH;
    u8 Local_RowIndex=0,Local_ColumnIndex=0;
    if((Copy_Config == NULL) || (Copy_PressedKey == NULL))
    {
        Local_ErrorState=E_NULL_POINTER;
    }
    else
    {
        for(Local_ColumnIndex=0;Local_ColumnIndex<Copy_Config->ColumnsNum;Local_ColumnIndex++)
        {
            /*Set the current column to low*/
            GPIO_SetPinValue(Copy_Config->ColumnPinsPorts[Local_ColumnIndex], Copy_Config->ColumnPins[Local_ColumnIndex], GPIO_PIN_LOW);
            /*Traverse throw raws to find if any Button is pressed*/
            for(Local_RowIndex=0;Local_RowIndex<Copy_Config->RawsNum;Local_RowIndex++)
            {
                Local_ErrorState=GPIO_GetPinValue(Copy_Config->RowPinsPorts[Local_RowIndex], Copy_Config->RowPins[Local_RowIndex], &Local_State);
                if(Local_State==GPIO_PIN_LOW)
                {
                    *Copy_PressedKey=Local_KeypadArr[Local_RowIndex][Local_ColumnIndex];
                    /*stay here until the button un-pressed*/
                    while(Local_State==GPIO_PIN_LOW)
                    {
                        GPIO_GetPinValue(Copy_Config->RowPinsPorts[Local_RowIndex], Copy_Config->RowPins[Local_RowIndex], &Local_State);
                    }
                    break;
                }
                else
                {
                    /* For MISRA */
                }
            }
            if(*Copy_PressedKey!=(u8)KPD_NOT_PRESSED)
            {
                break;
            }
            else
            {
                GPIO_SetPinValue(Copy_Config->ColumnPinsPorts[Local_ColumnIndex], Copy_Config->ColumnPins[Local_ColumnIndex], GPIO_PIN_HIGH);
            }
        }
    }
    return Local_ErrorState;
}

/**********************************************************************************************************************
 *  END OF FILE: KPD_Program.c
 *********************************************************************************************************************/
