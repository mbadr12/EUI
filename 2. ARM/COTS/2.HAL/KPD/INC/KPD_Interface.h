/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  KPD_interface.h
 *		  Layer:  HAL
 *       Module:  KPD
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Interface.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    GPIO_Port_t RowPinsPorts[4];
    GPIO_Port_t ColumnPinsPorts[4];
    GPIO_Pin_t RowPins[4];
    GPIO_Pin_t ColumnPins[4];
    u8 RawsNum;
    u8 ColumnsNum;
}KPD_Config_t;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
ErrorState_t KPD_Init(KPD_Config_t* Copy_Config);

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
ErrorState_t KPD_GetPressedKey(KPD_Config_t* Copy_Config,u8* Copy_PressedKey);
 
#endif  /* KPD_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: KPD_interface.h
 *********************************************************************************************************************/
