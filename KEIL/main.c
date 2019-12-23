#include <stdint.h>
#include <stdio.h>
#include "code_def.h"

extern uint32_t key0_flag, key1_flag, key2_flag, key3_flag;

void game_mode(uint16_t x, uint16_t y, uint16_t dx, uint16_t dy) {
	uint16_t nx, ny;
	nx = x, ny = y;
	while (1) {
		LCD_Fill(x, y, x + dx, y + dy, WHITE);
		LCD_Fill(nx, ny, nx + dx, ny + dy, RED);
		x = nx;
		y = ny;
		while (!key0_flag && !key1_flag && !key2_flag && !key3_flag) ;
		if (key0_flag) {
			if (x >= dx) nx = x - dx;
		}
		if (key1_flag) {
			if (y + dy <= 300) ny = y + dy;
		}
		if (key2_flag) {
			if (y >= dy) ny = y - dy;
		}
		if (key3_flag) {
			if (x + dx <= 220) nx = nx + dx; 
		}
		// LCD_Clear(WHITE);
		key0_flag = key1_flag = key2_flag = key3_flag = 0;
	}
}

int main()
{
	uint16_t x, y;
	uint8_t dx, dy;
	SYSInit();
  	LCD->LCD_RST = 0;
	delay(5000000);
	LCD->LCD_RST = 1;
	x = 110;
	y = 150;
	dx = dy = 20;
	LCD_Init(1);
	CAMERA_Initial();
	photo();
	 for (x = 0; x < 240; x++) {
	 	for (y = 0; y < 320; y++) {
	 		LCD_Fast_DrawPoint(y, x, CAMERA->CAMERA_VALUE[x][y]);
	 	}
	 }
	//game_mode(x, y, dx, dy);
}
