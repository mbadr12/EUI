/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  LCD_interface.h
 *		  Layer:  HAL
 *       Module:  LCD
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO_Interface.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    LCD_4BIT_MODE=4,
    LCD_8BIT_MODE=8
}LCD_Mode_t;

typedef enum
{
    LCD_NO_CURSOR=0,
    LCD_CUSROR_SOLID=2,
    LCD_CURSORBLINK
}LCD_Cursor_t;

typedef enum
{
    LCD_5_8_FONT=0,
    LCD_5_10_FONT
}LCD_Font_t;

typedef enum
{
    LCD_ONE_LINE=0,
    LCD_TWO_LINES,
}LCD_LineNum_t;

typedef struct
{
    GPIO_Port_t DataPinsPorts[8];
    GPIO_Port_t ControlPinsPorts[3];
    GPIO_Pin_t DataPins[8];
    GPIO_Pin_t ControlPins[3];
    LCD_Mode_t Mode;
    LCD_Cursor_t Cursor;
    LCD_Font_t Font;
    LCD_LineNum_t LinesNum;
    u8 *XPosition;
    u8 *Yposition;
}LCD_Config_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : ErrorState_t LCD_Init(LCD_Config_t* Copy_Config)
 * \Description     : Initialize the LCD module
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *******************************************************************************/
ErrorState_t LCD_Init(LCD_Config_t* Copy_Config);

/*****************************************************************************************
 * \Syntax          : ErrorState_t LCD_SendChar(LCD_Config_t* Copy_Config,char Copy_Char)
 * \Description     : Display a character on LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 *                    Copy_Char       character to be displayed on LCD
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 ******************************************************************************************/
ErrorState_t LCD_SendChar(LCD_Config_t* Copy_Config,char Copy_Char);

/***********************************************************************************************
 * \Syntax          : ErrorState_t LCD_SendString(LCD_Config_t* Copy_Config,char *Copy_String)
 * \Description     : Display string on LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 *                    Copy_String     String to be displayed on LCD
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *********************************************************************************************/
ErrorState_t LCD_SendString(LCD_Config_t* Copy_Config,char *Copy_String);

/***********************************************************************************************
 * \Syntax          : ErrorState_t LCD_Clear(LCD_Config_t* Copy_Config)
 * \Description     : Clear display of LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *********************************************************************************************/
ErrorState_t LCD_Clear(LCD_Config_t* Copy_Config);

/***********************************************************************************************
 * \Syntax          : ErrorState_t LCD_WriteNumber(LCD_Config_t* Copy_Config,s64 Copy_Number)
 * \Description     : Display Number on LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 *                    Copy_Number     Number to be displayed on LCD
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *********************************************************************************************/
ErrorState_t LCD_WriteNumber(LCD_Config_t* Copy_Config,s64 Copy_Number);

/***********************************************************************************************
 * \Syntax          : ErrorState_t LCD_GoToXY(LCD_Config_t* Copy_Config,u8 Copy_XPosition,u8 Copy_YPosition)
 * \Description     : Go to specific position on LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 *                    Copy_XPosition  Location on the row
 *                    Copy_YPosition  Location on the Column
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *********************************************************************************************/
ErrorState_t LCD_GoToXY(LCD_Config_t* Copy_Config,u8 Copy_XPosition,u8 Copy_YPosition);
#endif  /* LCD_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: LCD_interface.h
 *********************************************************************************************************************/
