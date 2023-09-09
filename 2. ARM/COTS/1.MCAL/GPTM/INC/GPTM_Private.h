/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *	   	   File:  GPTM_Private.h
 *		  Layer:  MCAL
 *       Module:  GPTM
 *		Version:  1.00
 *	
 *  Description:  -     
 *  
 *********************************************************************************************************************/

#ifndef GPTM_PRIVATE_H
#define GPTM_PRIVATE_H

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define GPTMS_NUM           12

#define GPTM_TACDIR         4

#define GPTM_TAEN           0

#define GPTM_TBAMS          3

#define GPTM_TBCMR          2

#define GPTM_TBMR           1

#define GPTM_CHANNELS       2

#define GPTM_INT_SOURCES    4

#define GPTMN_CONFIG        Copy_Config[Local_Counter]

#define GPTMN               GPTM_Arr[GPTMN_CONFIG.TimerBlock]

#define GPTMN_CHANNEL       GPTMN_CONFIG.TimerChannel

#define GPTM_ENABLE         (Copy_TimerChannel*8)

#define GPTM_SET_EVENT      (Copy_TimerChannel*8+2)

#define GPTM_SET_PWM        (Copy_TimerChannel*8+6)

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* GPTM_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: GPTM_Private.h
 *********************************************************************************************************************/
