/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  LCD_Config.h
 *		  Layer:  HAL
 *       Module:  LCD
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*Choose:
 * GPIO_PORTA
 * GPIO_PORTB
 * GPIO_PORTC
 * GPIO_PORTD
 * GPIO_PORTE
 * GPIO_PORTF
 * */
#define LCD_DATA1_PORT       GPIO_PORTD
#define LCD_DATA2_PORT       GPIO_PORTE

#define LCD_CONTROL_PORT    GPIO_PORTA

/*Choose:
 * GPIO_PIN0
 * GPIO_PIN1
 * GPIO_PIN2
 * GPIO_PIN3
 * GPIO_PIN4
 * GPIO_PIN5
 * GPIO_PIN6
 * GPIO_PIN7
 * */
#define LCD_RS_PIN              GPIO_PIN2

#define LCD_RW_PIN              GPIO_PIN3

#define LCD_E_PIN               GPIO_PIN4

#endif  /* LCD_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: LCD_Config.h
 *********************************************************************************************************************/
