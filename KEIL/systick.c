#include "code_def.h"
#include <stdint.h>

void Set_SysTick_CTRL(uint32_t ctrl)
{
	SysTick->CTRL = ctrl;
}

void Set_SysTick_LOAD(uint32_t load)
{
	SysTick->LOAD = load;
}

uint32_t Read_SysTick_VALUE(void)
{
	return(SysTick->VALUE);
}

void Set_SysTick_CALIB(uint32_t calib)
{
	SysTick->CALIB = calib;
}

void Set_SysTick_VALUE(uint32_t value)
{
	SysTick->VALUE = value;
}
void SysTickHandler(void)
{
    Set_SysTick_CTRL(0);
    SCB->ICSR = SCB->ICSR | (1 << 25);
}
uint32_t Timer_Ini(void)
{
	SysTick->CTRL = 0;
	SysTick->LOAD = 0xffffff;
	SysTick->VALUE = 0;
	SysTick->CTRL = 0x5;
	while(SysTick->VALUE == 0);
	return(SysTick->VALUE);
}
uint8_t Timer_Stop(uint32_t *duration_t,uint32_t start_t)
{
	uint32_t stop_t;
	stop_t = SysTick->VALUE;
	if((SysTick->CTRL & 0x10000) == 0)
	{
		*duration_t = start_t - stop_t;
		return(1);
	}
	else
	{
		return(0);
	}
}
