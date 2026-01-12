//
// Minimal SSD1306 helpers (I2C, 0x3C)
//
#ifndef SSD1306_H
#define SSD1306_H

#include "stm32f1xx_hal.h"

void SSD1306_Init(void);
void SSD1306_Clear(void);
void SSD1306_Fill(uint8_t value);
void SSD1306_DrawChar(uint8_t x, uint8_t page, char c);
void SSD1306_DrawString(uint8_t x, uint8_t page, const char *s);

#endif // SSD1306_H
