#include "UART1.h"


void UART1_Init (void){
	SYSCTL->RCGCUART |= 0x02;
	
	SYSCTL->RCGCGPIO |= 0x02;
	
	UART1->CTL &= ~(0x0001);
	
	UART1->CTL&= ~(0x0020);
	
	UART1->IBRD = 325;
	
	UART1->FBRD = 33;
	
	UART1->LCRH |= 0x60;
	
	UART1->LCRH |= 0x10;
	
	UART1->LCRH &= ~(0x08);
	
	UART1->LCRH &= ~0x02;
	
	UART1->CTL |= 0x01;
	
	GPIOB->AFSEL |= 0x03;
	
	GPIOB->PCTL &= ~0xFF;
	
	GPIOB->PCTL |= 0x10;
	
	GPIOB->PCTL |= 0x01;
	
	GPIOB->DEN |= 0x03;
}
	char UART1_Input_Character(void)
{
	while((UART1->FR & UART1_RECEIVE_FIFO_EMPTY_BIT_MASK) != 0);
	return (char)(UART1->DR & 0xFF);
}
void UART1_Output_Character(char data)
{
	while((UART1->FR & UART1_TRANSMIT_FIFO_FULL_BIT_MASK) != 0);
	UART1->DR = data;
}
void UART1_Input_String(char *buffer_pointer, uint16_t buffer_size)
{
	int length = 0;
	char character = UART1_Input_Character () ;
	while (character != UART1_CR)
{
	if (character == UART1_BS)
{
	if (length)
	{
	buffer_pointer --;
	length --;
	UART1_Output_Character (UART1_BS) ;
	}
}
else if (length < buffer_size)
{
*buffer_pointer = character;
buffer_pointer++;
length++;
UART1_Output_Character(character) ;
}
character = UART1_Input_Character () ;
}
*buffer_pointer = 0;
}
void UART1_Output_String(char *pt)
{
while(*pt)
	{
	UART1_Output_Character(*pt);
	pt++;
	}
}
