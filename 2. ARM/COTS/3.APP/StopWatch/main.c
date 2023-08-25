#include "Std_Types.h"
#include "APP_StopWatch.h"

int main(void)
{
    System_Init();
    APP_Welcome();
    APP_SysTickInit();
    while(1);
}
