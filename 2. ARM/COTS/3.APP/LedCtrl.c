#include "Platform_Types.h"
#include "Std_Types.h"
#include "GPIO_Interface.h"
#include "STK_Interface.h"
int main(void)
{
    GPIO_PinValue_t Local_SW1Value;
    GPIO_PinValue_t Local_SW2Value;
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
    GPIO_Init(Config, 5);
    while(1)
    {
        GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN0, &Local_SW1Value);
        GPIO_GetPinValue(GPIO_PORTF, GPIO_PIN4, &Local_SW2Value);
        if(Local_SW1Value==GPIO_PIN_LOW)
        {
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN1,GPIO_PIN_HIGH);
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN2,GPIO_PIN_LOW);
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN3,GPIO_PIN_LOW);
        }
        else if(Local_SW2Value==GPIO_PIN_LOW)
        {
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN2,GPIO_PIN_HIGH);
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN1,GPIO_PIN_LOW);
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN3,GPIO_PIN_LOW);
        }
        else
        {
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN3,GPIO_PIN_HIGH);
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN2,GPIO_PIN_LOW);
            GPIO_SetPinValue(GPIO_PORTF, GPIO_PIN1,GPIO_PIN_LOW);
        }
    }
}
