#ifndef SSD1351_H
#define SSD1351_H

#include <stdint.h>

/* SPI handle */
#define SSD1351_SPI hspi1
extern SPI_HandleTypeDef SSD1351_SPI;

/* Pin definitions */
#define SSD1351_RST_PIN GPIO_PIN_9
#define SSD1351_RST_PORT GPIOA
#define SSD1351_CS_PIN GPIO_PIN_0
#define SSD1351_CS_PORT GPIOB
#define SSD1351_DC_PIN GPIO_PIN_1
#define SSD1351_DC_PORT GPIOB

/* Display dimensions */
#define SSD1351_WIDTH 96
#define SSD1351_HEIGHT 96

/* Command definitions */
#define SSD1351_DISPLAY_OFF 0xAE
#define SSD1351_DISPLAY_ON 0xAF
#define SSD1351_NORMAL_DISPLAY 0xA6
#define SSD1351_INVERT_DISPLAY 0xA7
#define SSD1351_SET_COLUMN 0x15
#define SSD1351_SET_ROW 0x75
#define SSD1351_WRITE_RAM 0x5C

/* Font structure */
typedef struct {
    const uint8_t *data;
    uint8_t height;
    uint8_t start_char;
    uint8_t end_char;
} SSD1351_FONT;

extern SSD1351_FONT current_font;

void SSD1351_Select();

void SSD1351_Deselect();

void SSD1351_Init();

void SSD1351_DrawPixel(uint8_t x, uint8_t y, uint16_t color);

void SSD1351_FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);

void SSD1351_FillScreen(uint16_t color);

void SSD1351_Clear();

void SSD1351_DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint16_t color);

void SSD1351_DrawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);

void SSD1351_SetFont(const uint8_t* font);

#endif // SSD1351_H
