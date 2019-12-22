#include <stdint.h>
#include "code_def.h"

uint32_t key3_flag;
uint32_t key2_flag;
uint32_t key1_flag;
uint32_t key0_flag;

void KEY0(void)
{
	key0_flag = 1;
}

void KEY1(void)
{
	key1_flag = 1;
}

void KEY2(void)
{
	key2_flag = 1;
}

void KEY3(void)
{
	key3_flag = 1;
}
