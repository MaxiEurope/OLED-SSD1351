#include "main.h" // include the main header file from the MCU project
#include "ssd1351.h"

void SSD1351_Select() {
    HAL_GPIO_WritePin(SSD1351_CS_PORT, SSD1351_CS_PIN, GPIO_PIN_RESET);
}

void SSD1351_Deselect() {
    HAL_GPIO_WritePin(SSD1351_CS_PORT, SSD1351_CS_PIN, GPIO_PIN_SET);
}

static void SSD1351_Reset() {
    HAL_GPIO_WritePin(SSD1351_RST_PORT, SSD1351_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(SSD1351_RST_PORT, SSD1351_RST_PIN, GPIO_PIN_RESET);
    HAL_Delay(50);
    HAL_GPIO_WritePin(SSD1351_RST_PORT, SSD1351_RST_PIN, GPIO_PIN_SET);
    HAL_Delay(10);
}

static void SSD1351_Command(uint8_t cmd) {
    HAL_GPIO_WritePin(SSD1351_DC_PORT, SSD1351_DC_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&SSD1351_SPI, &cmd, sizeof(cmd), HAL_MAX_DELAY);
}

static void SSD1351_Data(uint8_t *data, size_t size) {
    HAL_GPIO_WritePin(SSD1351_DC_PORT, SSD1351_DC_PIN, GPIO_PIN_SET);

    while (size > 0) {
        size_t chunk = size > 32 ? 32 : size;
        HAL_SPI_Transmit(&SSD1351_SPI, data, chunk, HAL_MAX_DELAY);
        data += chunk;
        size -= chunk;
    }
}

void SSD1351_Init() {
    SSD1351_Select();
    SSD1351_Reset();

    SSD1351_Command(SSD1351_DISPLAY_OFF);

    SSD1351_Command(SSD1351_NORMAL_DISPLAY);
    SSD1351_Command(SSD1351_DISPLAY_ON);
}

static void SSD1351_SetWindow(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
    int column_offset = (128 - SSD1351_WIDTH) / 2;

    SSD1351_Command(SSD1351_SET_COLUMN);
    SSD1351_Data((uint8_t[]){ (x + column_offset) & 0xFF, (w + column_offset) & 0xFF }, 2);

    SSD1351_Command(SSD1351_SET_ROW);
    SSD1351_Data((uint8_t[]){ y & 0xFF, h & 0xFF }, 2);

    SSD1351_Command(SSD1351_WRITE_RAM);
}

void SSD1351_DrawPixel(uint8_t x, uint8_t y, uint16_t color) {
    if (x >= SSD1351_WIDTH || y >= SSD1351_HEIGHT) {
        return;
    }

    SSD1351_Select();

    SSD1351_SetWindow(x, y, x, y);
    SSD1351_Data((uint8_t[]){ color >> 8, color & 0xFF }, 2);

    SSD1351_Deselect();
}

void SSD1351_FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    if (x >= SSD1351_WIDTH || y >= SSD1351_HEIGHT) {
        return;
    }
    if (x + w > SSD1351_WIDTH) {
        w = SSD1351_WIDTH - x;
    }
    if (y + h > SSD1351_HEIGHT) {
        h = SSD1351_HEIGHT - y;
    }

    SSD1351_Select();

    SSD1351_SetWindow(x, y, x + w - 1, y + h - 1);

    uint8_t data[w * h * 2];
    for (int i = 0; i < w * h; i++) {
        data[i * 2] = color >> 8;
        data[i * 2 + 1] = color & 0xFF;
    }

    SSD1351_Data(data, w * h * 2);

    SSD1351_Deselect();
}

void SSD1351_FillScreen(uint16_t color) {
    SSD1351_FillRect(0, 0, SSD1351_WIDTH, SSD1351_HEIGHT, color);
}

void SSD1351_Clear() {
    SSD1351_FillScreen(0);
}
