#include "code_def.h"
#include <stdint.h>
#include <string.h>

extern uint32_t key3_flag, key2_flag, key1_flag, key0_flag;
void SYSInit(void)
{
	// IRQ enable
	NVIC_CTRL_ADDR	=	0x3f;

	// Systick initial
	Set_SysTick_CTRL(0);

	// CAMERA initial
	//CAMERA_Initial();
}

void delay(uint32_t time)
{
	Set_SysTick_CTRL(0);
	Set_SysTick_LOAD(time);
	Set_SysTick_VALUE(0);
	Set_SysTick_CTRL(0x7);
	__wfi();
}

char ReadUARTState()
{
    char state;
	state = UART -> UARTTX_STATE;
    return(state);
}

char ReadUART()
{
    char data;
	data = UART -> UARTRX_DATA;
    return(data);
}

void WriteUART(char data)
{
    while(ReadUARTState());
	UART -> UARTTX_DATA = data;
}

void UARTString(char *stri)
{
	int i;
	for(i=0;i<strlen(stri);i++)
	{
		WriteUART(stri[i]);
	}
}

void UARTHandle()
{
	int data;
	data = ReadUART();
	UARTString("Cortex-M0 : ");
	WriteUART(data);
	WriteUART('\n');
}
