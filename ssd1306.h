#ifndef __SSD1306_H
#define __SSD1306_H

#include "main.h"

#define SSD1306_I2C_ADDR 0x78

void ssd1306_Init(void);
void ssd1306_Fill(uint8_t color);
void ssd1306_UpdateScreen(void);
void ssd1306_SetCursor(uint8_t x, uint8_t y);
void ssd1306_WriteString(char* str);

#endif
