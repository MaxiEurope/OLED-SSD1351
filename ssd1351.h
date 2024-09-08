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

/* Color definitions */
#define SSD1351_ALICEBLUE 0xEFBF
#define SSD1351_ANTIQUEWHITE 0xF75A
#define SSD1351_AQUA 0x07FF
#define SSD1351_AQUAMARINE 0x7FFA
#define SSD1351_AZURE 0xEFFF
#define SSD1351_BEIGE 0xF7BB
#define SSD1351_BISQUE 0xFF18
#define SSD1351_BLACK 0x0000
#define SSD1351_BLANCHEDALMOND 0xFF59
#define SSD1351_BLUE 0x001F
#define SSD1351_BLUEVIOLET 0x897B
#define SSD1351_BROWN 0xA145
#define SSD1351_BURLYWOOD 0xDDB0
#define SSD1351_CADETBLUE 0x64F3
#define SSD1351_CHARTREUSE 0x7FE0
#define SSD1351_CHOCOLATE 0xD344
#define SSD1351_CORAL 0xFBEA
#define SSD1351_CORNFLOWERBLUE 0x64BD
#define SSD1351_CORNSILK 0xFFBB
#define SSD1351_CRIMSON 0xD8A7
#define SSD1351_CYAN 0x07FF
#define SSD1351_DARKBLUE 0x0011
#define SSD1351_DARKCYAN 0x0451
#define SSD1351_DARKGOLDENROD 0xB421
#define SSD1351_DARKGRAY 0xAD55
#define SSD1351_DARKGREEN 0x0320
#define SSD1351_DARKGREY 0xAD55
#define SSD1351_DARKKHAKI 0xBDAD
#define SSD1351_DARKMAGENTA 0x8811
#define SSD1351_DARKOLIVEGREEN 0x5346
#define SSD1351_DARKORANGE 0xFC60
#define SSD1351_DARKORCHID 0x9999
#define SSD1351_DARKRED 0x8800
#define SSD1351_DARKSALMON 0xE4AF
#define SSD1351_DARKSEAGREEN 0x8DD1
#define SSD1351_DARKSLATEBLUE 0x49F1
#define SSD1351_DARKSLATEGRAY 0x328A
#define SSD1351_DARKSLATEGREY 0x328A
#define SSD1351_DARKTURQUOISE 0x0679
#define SSD1351_DARKVIOLET 0x901A
#define SSD1351_DEEPPINK 0xF8B2
#define SSD1351_DEEPSKYBLUE 0x05FF
#define SSD1351_DIMGRAY 0x6B4D
#define SSD1351_DIMGREY 0x6B4D
#define SSD1351_DODGERBLUE 0x249F
#define SSD1351_FIREBRICK 0xB104
#define SSD1351_FLORALWHITE 0xFFDD
#define SSD1351_FORESTGREEN 0x2444
#define SSD1351_FUCHSIA 0xF81F
#define SSD1351_GAINSBORO 0xDEDB
#define SSD1351_GHOSTWHITE 0xF7BF
#define SSD1351_GOLDENROD 0xDD24
#define SSD1351_GOLD 0xFEA0
#define SSD1351_GRAY 0x8410
#define SSD1351_GREEN 0x0400
#define SSD1351_GREENYELLOW 0xAFE6
#define SSD1351_GREY 0x8410
#define SSD1351_HONEYDEW 0xEFFD
#define SSD1351_HOTPINK 0xFB56
#define SSD1351_INDIANRED 0xCAEB
#define SSD1351_INDIGO 0x4810
#define SSD1351_IVORY 0xFFFD
#define SSD1351_KHAKI 0xEF31
#define SSD1351_LAVENDERBLUSH 0xFF7E
#define SSD1351_LAVENDER 0xE73E
#define SSD1351_LAWNGREEN 0x7FC0
#define SSD1351_LEMONCHIFFON 0xFFD9
#define SSD1351_LIGHTBLUE 0xAEBC
#define SSD1351_LIGHTCORAL 0xEC10
#define SSD1351_LIGHTCYAN 0xDFFF
#define SSD1351_LIGHTGOLDENRODYELLOW 0xF7DA
#define SSD1351_LIGHTGRAY 0xD69A
#define SSD1351_LIGHTGREEN 0x9772
#define SSD1351_LIGHTGREY 0xD69A
#define SSD1351_LIGHTPINK 0xFDB7
#define SSD1351_LIGHTSALMON 0xFD0F
#define SSD1351_LIGHTSEAGREEN 0x2595
#define SSD1351_LIGHTSKYBLUE 0x867E
#define SSD1351_LIGHTSLATEGRAY 0x7453
#define SSD1351_LIGHTSLATEGREY 0x7453
#define SSD1351_LIGHTSTEELBLUE 0xAE1B
#define SSD1351_LIGHTYELLOW 0xFFFB
#define SSD1351_LIME 0x07E0
#define SSD1351_LIMEGREEN 0x3666
#define SSD1351_LINEN 0xF77C
#define SSD1351_MAGENTA 0xF81F
#define SSD1351_MAROON 0x8000
#define SSD1351_MEDIUMAQUAMARINE 0x6675
#define SSD1351_MEDIUMBLUE 0x0019
#define SSD1351_MEDIUMORCHID 0xBABA
#define SSD1351_MEDIUMPURPLE 0x939B
#define SSD1351_MEDIUMSEAGREEN 0x3D8E
#define SSD1351_MEDIUMSLATEBLUE 0x7B5D
#define SSD1351_MEDIUMSPRINGGREEN 0x07D3
#define SSD1351_MEDIUMTURQUOISE 0x4E99
#define SSD1351_MEDIUMVIOLETRED 0xC0B0
#define SSD1351_MIDNIGHTBLUE 0x18CE
#define SSD1351_MINTCREAM 0xF7FE
#define SSD1351_MISTYROSE 0xFF1B
#define SSD1351_MOCCASIN 0xFF16
#define SSD1351_NAVAJOWHITE 0xFEF5
#define SSD1351_NAVY 0x0010
#define SSD1351_OLDLACE 0xFFBC
#define SSD1351_OLIVE 0x8400
#define SSD1351_OLIVEDRAB 0x6C64
#define SSD1351_ORANGE 0xFD20
#define SSD1351_ORANGERED 0xFA20
#define SSD1351_ORCHID 0xDB9A
#define SSD1351_PALEGOLDENROD 0xEF35
#define SSD1351_PALEGREEN 0x97D2
#define SSD1351_PALETURQUOISE 0xAF7D
#define SSD1351_PALEVIOLETRED 0xDB92
#define SSD1351_PAPAYAWHIP 0xFF7A
#define SSD1351_PEACHPUFF 0xFED6
#define SSD1351_PERU 0xCC28
#define SSD1351_PINK 0xFDF9
#define SSD1351_PLUM 0xDD1B
#define SSD1351_POWDERBLUE 0xAEFC
#define SSD1351_PURPLE 0x8010
#define SSD1351_REBECCAPURPLE 0x61B3
#define SSD1351_RED 0xF800
#define SSD1351_ROSYBROWN 0xBC71
#define SSD1351_ROYALBLUE 0x435B
#define SSD1351_SADDLEBROWN 0x8A22
#define SSD1351_SALMON 0xF40E
#define SSD1351_SANDYBROWN 0xF52C
#define SSD1351_SEAGREEN 0x344B
#define SSD1351_SEASHELL 0xFFBD
#define SSD1351_SIENNA 0x9A85
#define SSD1351_SILVER 0xBDF7
#define SSD1351_SKYBLUE 0x867D
#define SSD1351_SLATEBLUE 0x6AD9
#define SSD1351_SLATEGRAY 0x7412
#define SSD1351_SLATEGREY 0x7412
#define SSD1351_SNOW 0xFFDE
#define SSD1351_SPRINGGREEN 0x07EF
#define SSD1351_STEELBLUE 0x4C16
#define SSD1351_TAN 0xD591
#define SSD1351_TEAL 0x0410
#define SSD1351_THISTLE 0xD5FA
#define SSD1351_TOMATO 0xFB09
#define SSD1351_TURQUOISE 0x46F9
#define SSD1351_VIOLET 0xEC1D
#define SSD1351_WHEAT 0xF6F6
#define SSD1351_WHITE 0xFFFF
#define SSD1351_WHITESMOKE 0xF7BE
#define SSD1351_YELLOW 0xFFE0
#define SSD1351_YELLOWGREEN 0x9E66

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

void SSD1351_DrawChar(uint8_t x, uint8_t y, char c, uint16_t color, uint16_t bg);

void SSD1351_DrawString(uint8_t x, uint8_t y, const char* str, uint16_t color, uint16_t bg);

uint8_t SSD1351_GetStringWidth(const char* str);

void SSD1351_DrawStringCentered(uint8_t y, const char* str, uint16_t color, uint16_t bg);

#endif // SSD1351_H
