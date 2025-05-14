#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "UART0.h"
#include "DHT_22.h"
#include <stdio.h>

int main(void) {
    SysTick_Delay_Init();
    UART0_Init();
    DHT22_Init();
    while (1) 
		{
						
						Execute_Selection();
            SysTick_Delay1ms(2000);
						UART0_Output_String("     ");
    }
		
}