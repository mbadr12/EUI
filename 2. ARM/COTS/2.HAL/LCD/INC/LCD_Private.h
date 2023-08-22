/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  LCD_Private.h
 *		  Layer:  HAL
 *       Module:  LCD
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define LCD_RS              0

#define LCD_RW              1

#define LCD_E               2

#define LCD_MODE_BIT        4

#define LCD_FONT_BIT        2

#define LCD_LINE_BIT        3

#define LCD_CLEAR_VAL       0x01

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/***********************************************************************************************
 * \Syntax          : void LCD_SendComand(LCD_Config_t* Copy_Config,u8 Copy_Comand)
 * \Description     : Send Command to LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 *                    Copy_Command     Command to be sent to LCD
 * \Parameters (out): None
 * \Return value:   : void
 *********************************************************************************************/
static void LCD_SendComand(LCD_Config_t* Copy_Config,u8 Copy_Comand);

/***********************************************************************************************
 * \Syntax          : ErrorState_t LCD_SendData(LCD_Config_t* Copy_Config,char Copy_Data)
 * \Description     : Send data to LCD
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_Config     The Configuration structure for the module
 *                    Copy_Data     Data to be Sent to LCD
 * \Parameters (out): None
 * \Return value:   : ErrorState_t
 *********************************************************************************************/
static ErrorState_t LCD_SendData(LCD_Config_t* Copy_Config,char Copy_Data);

#endif  /* LCD_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: LCD_Private.h
 *********************************************************************************************************************/
