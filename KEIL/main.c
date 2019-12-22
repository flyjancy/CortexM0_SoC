#include <stdint.h>
#include <stdio.h>
#include "code_def.h"

extern uint32_t key0_flag, key1_flag, key2_flag, key3_flag;

int main()
{
	uint16_t x, y;
	uint8_t dx, dy;
	SYSInit();
  LCD->LCD_RST = 0;
	delay(5000000);
	LCD->LCD_RST = 1;
	x  = y  = 110;
	dx = dy = 150;
	LCD_Init(1);
	CAMERA_Initial();
	photo();
	for (x = 0; x < 240; x++) {
		for (y = 0; y < 320; y++) {
			POINT_COLOR = CAMERA->CAMERA_VALUE[x][y];
			// POINT_COLOR = RED;
			LCD_DrawPoint(y, x);
		}
	}
	// while (1) {
		// LCD_Fill(x, y, x + dx, y + dy, RED);
		// while (!key0_flag && !key1_flag && !key2_flag && !key3_flag) ;
		// if (key0_flag) {
		// 	if (x >= dx) x -= dx;
		// }
		// if (key1_flag) {
		// 	if (y + dy <= 300) y += dy;
		// }
		// if (key2_flag) {
		// 	if (y >= dy) y -= dy;
		// }
		// if (key3_flag) {
		// 	if (x + dx <= 220) x += dx; 
		// }
		// LCD_Clear(WHITE);
		// key0_flag = key1_flag = key2_flag = key3_flag = 0;
	// }
}
