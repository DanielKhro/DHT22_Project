#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include <stdint.h>
#include "UART0.h"
#include <stdio.h>
#include "DHT_22.h"
#include "GPIO.h"
#include "math.h"


#define DHT22_PIN        2
#define DHT22_MASK       0x04

uint8_t humidity_int, humidity_dec, temp_int, temp_dec, checksum;


void DHT22_Init(void) {
    SYSCTL->RCGCGPIO |= 0x01;        
    SysTick_Delay1ms(1);     					
		GPIOA->AMSEL &= ~DHT22_MASK;	       
    GPIOA->AFSEL &= ~DHT22_MASK; 
		GPIOA->DIR |= DHT22_MASK;
    GPIOA->DEN |= DHT22_MASK;       
           
}

// Send start pulse to DHT22
static void DHT22_Start(void) {
    GPIOA->DIR |= DHT22_MASK;        
    GPIOA->DATA &= ~DHT22_MASK;      
    SysTick_Delay1ms(3);           	
		GPIOA->DATA |= DHT22_MASK;
		SysTick_Delay1us(30);
		GPIOA->DIR &= ~DHT22_MASK;
}

uint8_t DHT22_ReadByte(void)
{
    uint8_t i, result = 0;
    for (i = 0; i < 8; i++)
    {
        uint32_t timeout = 10000;
        while ((GPIOA->DATA & DHT22_MASK) == 0 && timeout--)
            SysTick_Delay1us(1);

        SysTick_Delay1us(35);
        result <<= 1;
        if (GPIOA->DATA & DHT22_MASK)
            result |= 1;

        timeout = 10000;
        while ((GPIOA->DATA & DHT22_MASK) && timeout--)
            SysTick_Delay1us(1);
    }
    return result;
}


void Execute_Selection(void)
{
    uint16_t raw_humidity, raw_temp;
    float humidity, temp_c;

    DHT22_Start();

    // Sync response
    uint32_t timeout = 10000;
    while ((GPIOA->DATA & DHT22_PIN) && timeout--) SysTick_Delay1us(1);
    timeout = 10000;
    while (!(GPIOA->DATA & DHT22_PIN) && timeout--) SysTick_Delay1us(1);
    timeout = 10000;
    while ((GPIOA->DATA & DHT22_PIN) && timeout--) SysTick_Delay1us(1);

    humidity_int = DHT22_ReadByte();
    humidity_dec = DHT22_ReadByte();
    temp_int = DHT22_ReadByte();
    temp_dec = DHT22_ReadByte();
    checksum = DHT22_ReadByte();

    raw_humidity = (humidity_int << 8) | humidity_dec;
    raw_temp = (temp_int << 8) | temp_dec;

    humidity = raw_humidity / 10.0;
    if (raw_temp & 0x8000)
    {
        raw_temp &= 0x7FFF;
        temp_c = -1 * (raw_temp / 10.0);
    }
    else
    {
        temp_c = raw_temp / 10.0;
    }
		UART0_Output_String("RH%: ");
		UART0_Output_Unsigned_Decimal(humidity*.1);
		UART0_Output_String("%");
		UART0_Output_Newline();
		UART0_Output_String("Celsius: ");
		UART0_Output_Unsigned_Decimal(temp_c * .01);
		UART0_Output_String(" C");
		UART0_Output_Newline();
	}

	
