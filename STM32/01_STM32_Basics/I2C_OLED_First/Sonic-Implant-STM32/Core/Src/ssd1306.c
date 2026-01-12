#include "ssd1306.h"

extern I2C_HandleTypeDef hi2c1;

#define SSD1306_ADDR (0x3C << 1)

static void SSD1306_WriteCommand(uint8_t cmd)
{
    uint8_t data[2] = {0x00, cmd};
    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_ADDR, data, 2, HAL_MAX_DELAY);
}

static void SSD1306_SetCursor(uint8_t x, uint8_t page)
{
    SSD1306_WriteCommand(0xB0 + page);
    SSD1306_WriteCommand(0x00 + (x & 0x0F));
    SSD1306_WriteCommand(0x10 + (x >> 4));
}

static void SSD1306_WriteData(const uint8_t *data, uint8_t len)
{
    uint8_t buf[1 + 16];
    if (len > 16)
        len = 16;
    buf[0] = 0x40;
    for (uint8_t i = 0; i < len; i++)
        buf[1 + i] = data[i];
    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_ADDR, buf, (uint16_t)(1 + len), HAL_MAX_DELAY);
}

static const uint8_t *SSD1306_GetCharRows(char c)
{
    static const uint8_t font_A[8] = {0x3C, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x00};
    static const uint8_t font_C[8] = {0x3C, 0x42, 0x40, 0x40, 0x40, 0x42, 0x3C, 0x00};
    static const uint8_t font_E[8] = {0x7E, 0x40, 0x40, 0x7C, 0x40, 0x40, 0x7E, 0x00};
    static const uint8_t font_H[8] = {0x42, 0x42, 0x42, 0x7E, 0x42, 0x42, 0x42, 0x00};
    static const uint8_t font_I[8] = {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00};
    static const uint8_t font_L[8] = {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x00};
    static const uint8_t font_M[8] = {0x42, 0x66, 0x5A, 0x5A, 0x42, 0x42, 0x42, 0x00};
    static const uint8_t font_N[8] = {0x42, 0x62, 0x52, 0x4A, 0x46, 0x42, 0x42, 0x00};
    static const uint8_t font_O[8] = {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x00};
    static const uint8_t font_P[8] = {0x7C, 0x42, 0x42, 0x7C, 0x40, 0x40, 0x40, 0x00};
    static const uint8_t font_R[8] = {0x7C, 0x42, 0x42, 0x7C, 0x48, 0x44, 0x42, 0x00};
    static const uint8_t font_S[8] = {0x3C, 0x42, 0x40, 0x3C, 0x02, 0x42, 0x3C, 0x00};
    static const uint8_t font_T[8] = {0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00};
    static const uint8_t font_W[8] = {0x42, 0x42, 0x42, 0x5A, 0x5A, 0x66, 0x42, 0x00};
    static const uint8_t font_space[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    switch (c)
    {
        case 'A': return font_A;
        case 'C': return font_C;
        case 'E': return font_E;
        case 'H': return font_H;
        case 'I': return font_I;
        case 'L': return font_L;
        case 'M': return font_M;
        case 'N': return font_N;
        case 'O': return font_O;
        case 'P': return font_P;
        case 'R': return font_R;
        case 'S': return font_S;
        case 'T': return font_T;
        case 'W': return font_W;
        case ' ': return font_space;
        default: return font_space;
    }
}

void SSD1306_Init(void)
{
    HAL_Delay(100);

    SSD1306_WriteCommand(0xAE);
    SSD1306_WriteCommand(0x20);
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xB0);
    SSD1306_WriteCommand(0xC8);
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0x10);
    SSD1306_WriteCommand(0x40);
    SSD1306_WriteCommand(0x81);
    SSD1306_WriteCommand(0x7F);
    SSD1306_WriteCommand(0xA1);
    SSD1306_WriteCommand(0xA6);
    SSD1306_WriteCommand(0xA8);
    SSD1306_WriteCommand(0x3F);
    SSD1306_WriteCommand(0xA4);
    SSD1306_WriteCommand(0xD3);
    SSD1306_WriteCommand(0x00);
    SSD1306_WriteCommand(0xD5);
    SSD1306_WriteCommand(0x80);
    SSD1306_WriteCommand(0xD9);
    SSD1306_WriteCommand(0xF1);
    SSD1306_WriteCommand(0xDA);
    SSD1306_WriteCommand(0x12);
    SSD1306_WriteCommand(0xDB);
    SSD1306_WriteCommand(0x40);
    SSD1306_WriteCommand(0x8D);
    SSD1306_WriteCommand(0x14);
    SSD1306_WriteCommand(0xAF);
}

void SSD1306_Clear(void)
{
    SSD1306_Fill(0x00);
}

void SSD1306_Fill(uint8_t value)
{
    uint8_t data[129];
    data[0] = 0x40;
    for (int i = 1; i < 129; i++)
        data[i] = value;

    for (uint8_t page = 0; page < 8; page++)
    {
        SSD1306_WriteCommand(0xB0 + page);
        SSD1306_WriteCommand(0x00);
        SSD1306_WriteCommand(0x10);
        HAL_I2C_Master_Transmit(&hi2c1, SSD1306_ADDR, data, 129, HAL_MAX_DELAY);
    }
}

void SSD1306_DrawChar(uint8_t x, uint8_t page, char c)
{
    uint8_t top[8];
    uint8_t bottom[8];
    const uint8_t *rows = SSD1306_GetCharRows(c);

    for (uint8_t col = 0; col < 8; col++)
    {
        uint16_t col_bits = 0;
        for (uint8_t row = 0; row < 8; row++)
        {
            uint8_t bit = (rows[row] >> (7 - col)) & 0x01;
            if (bit)
            {
                col_bits |= (uint16_t)1 << (row * 2);
                col_bits |= (uint16_t)1 << (row * 2 + 1);
            }
        }
        top[col] = (uint8_t)(col_bits & 0xFF);
        bottom[col] = (uint8_t)((col_bits >> 8) & 0xFF);
    }

    SSD1306_SetCursor(x, page);
    SSD1306_WriteData(top, 8);
    SSD1306_SetCursor(x, (uint8_t)(page + 1));
    SSD1306_WriteData(bottom, 8);
}

void SSD1306_DrawString(uint8_t x, uint8_t page, const char *s)
{
    while (*s && x <= 119)
    {
        SSD1306_DrawChar(x, page, *s++);
        x = (uint8_t)(x + 9);
    }
}
