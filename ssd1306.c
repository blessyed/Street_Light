#include "ssd1306.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t SSD1306_Buffer[1024];
uint8_t cursorX;
uint8_t cursorY;

void ssd1306_Init(void)
{
    uint8_t cmd[] = {
        0x00,
        0xAE,
        0x20, 0x10,
        0xB0,
        0xC8,
        0x00,
        0x10,
        0x40,
        0x81, 0xFF,
        0xA1,
        0xA6,
        0xA8, 0x3F,
        0xA4,
        0xD3, 0x00,
        0xD5, 0xF0,
        0xD9, 0x22,
        0xDA, 0x12,
        0xDB, 0x20,
        0x8D, 0x14,
        0xAF
    };

    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_I2C_ADDR, cmd, sizeof(cmd), 100);
}
void ssd1306_Fill(uint8_t color)
{
    for(int i=0;i<1024;i++)
        SSD1306_Buffer[i]=(color?0xFF:0x00);
}

void ssd1306_UpdateScreen(void)
{
    uint8_t data[1025];
    data[0] = 0x40;

    for(int i=0;i<1024;i++)
        data[i+1] = SSD1306_Buffer[i];

    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_I2C_ADDR, data, 1025, 100);
}

void ssd1306_SetCursor(uint8_t x, uint8_t y)
{
    cursorX=x;
    cursorY=y;
}

void ssd1306_WriteString(char* str)
{
    while(*str)
    {
        uint8_t *ptr = &SSD1306_Buffer[cursorX + (cursorY/8)*128];

        switch(*str)
        {
            case 'S': ptr[0]=0x46; ptr[1]=0x49; ptr[2]=0x49; ptr[3]=0x31; break;
            case 'T': ptr[0]=0x01; ptr[1]=0x7F; ptr[2]=0x01; break;
            case 'R': ptr[0]=0x7F; ptr[1]=0x09; ptr[2]=0x19; ptr[3]=0x66; break;
            case 'E': ptr[0]=0x7F; ptr[1]=0x49; ptr[2]=0x49; ptr[3]=0x41; break;
            case 'L': ptr[0]=0x7F; ptr[1]=0x40; ptr[2]=0x40; break;
            case 'I': ptr[0]=0x7F; break;
            case 'G': ptr[0]=0x3E; ptr[1]=0x41; ptr[2]=0x49; ptr[3]=0x3A; break;
            case 'H': ptr[0]=0x7F; ptr[1]=0x08; ptr[2]=0x08; ptr[3]=0x7F; break;
            case 'O': ptr[0]=0x3E; ptr[1]=0x41; ptr[2]=0x41; ptr[3]=0x3E; break;
            case 'N': ptr[0]=0x7F; ptr[1]=0x08; ptr[2]=0x10; ptr[3]=0x7F; break;
            case 'F': ptr[0]=0x7F; ptr[1]=0x09; ptr[2]=0x09; break;
            case ' ': break;
        }

        cursorX += 6;
        str++;
    }
}
