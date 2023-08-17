#include "Platform_Types.h"
#include "Std_Types.h"
#include "GPIO_Interface.h"
#include "EXTI_Interface.h"
void EXTI0_CallBack(void);
void EXTI4_CallBack(void);
int main(void)
{
    /*
     * 1.Port
     * 2. Pin
     * 3. Direction
     * 4. Mode
     * 5. State
     * 6. Pull
     * 7. Output Current
     * 8. Alternate function Number
     * */
    const GPIO_Config_t Config[5]={{GPIO_PORTF,GPIO_PIN0,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                   {GPIO_PORTF,GPIO_PIN4,GPIO_PIN_INPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                   {GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                   {GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                   {GPIO_PORTF,GPIO_PIN3,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0}};
        /*
         * 1.Port
         * 2. Pin
         * 3. Sense
         * 4. Trigger Type
         * */
    EXTI_Config_t EXTI_Con[2]={{EXTI_PORTF,EXTI_PIN0,EXTI_EDGE,EXTI_FALLING_EDGE},{EXTI_PORTF,EXTI_PIN4,EXTI_EDGE,EXTI_FALLING_EDGE}};
    GPIO_Init(Config, 5);
    EXTI_Init(EXTI_Con, 2);
    EXTI_SetCallBack(EXTI_PORTF,EXTI_PIN0, EXTI0_CallBack);
    EXTI_SetCallBack(EXTI_PORTF,EXTI_PIN4, EXTI4_CallBack);
	while(1);
}
void EXTI0_CallBack(void)
{
    /*The switch change the color of the led every time the button pressed*/
    static u8 Local_Counter=0;
    switch(Local_Counter)
    {
    case 0: GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1, GPIO_PIN_HIGH); GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN3, GPIO_PIN_LOW);
    GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2, GPIO_PIN_LOW); Local_Counter++; break;
    case 1: GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2, GPIO_PIN_HIGH); GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1, GPIO_PIN_LOW);
    GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN3, GPIO_PIN_LOW); Local_Counter++; break;
    case 3: GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN3, GPIO_PIN_HIGH); GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1, GPIO_PIN_LOW);
    GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2, GPIO_PIN_LOW); Local_Counter=0; break;
    }
}
void EXTI4_CallBack(void)
{
    /*Make the led white*/
    GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1, GPIO_PIN_HIGH);
    GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN2, GPIO_PIN_HIGH);
    GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN3, GPIO_PIN_HIGH);
}
