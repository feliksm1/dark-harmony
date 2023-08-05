/*****************************************
  Mroczna Harmonia

  font.c   xxxxxxxxxxxx

  (C) 2001, 2023  M. Feliks
*****************************************/

#include "globals.h"

unsigned char chardata[];

void init_font(void)
{
}

void put_char(char ascii_code, int x, int y, unsigned char* where)
{
    int i, j, col;
    unsigned char *ptr_char, color;

    if (ascii_code >= 'a' && ascii_code <= 'z') {
       ascii_code += ('A' - 'a');
    }

    ptr_char = &chardata[((ascii_code - ' ') & 63) << 3];

    for (i = 0; i < 8; i++, ptr_char++) {
        for (j = 0; j < 8; j++) {
            col = 7 - j;
            if ((*ptr_char >> col) & 1) {
                color = (unsigned char)(22 + i);
            }
            else {
                color = 0;
            }
            *(where + (i + y) * 320 + j + x) = color;
        }
    }
}

void put_string(char* text, int x, int y, unsigned char* where)
{
    int i = 0;

    while (text[i]) {
        put_char(text[i], x, y, where);
        i++;
        x += 8;
    }
}

unsigned char chardata[] = 
{
0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x18,  0x18,  0x18,
0x18,  0x08,  0x00,  0x18,  0x00,  0x28,  0x28,  0x28,  0x00,  0x00,  0x00,
0x00,  0x00,  0x28,  0x7c,  0x28,  0x28,  0x28,  0x7c,  0x28,  0x00,  0x10,
0x7e,  0x40,  0x7e,  0x86,  0xfe,  0x10,  0x00,  0xe2,  0xa4,  0xe8,  0x10,
0x2e,  0x4a,  0x8e,  0x00,  0x38,  0x28,  0x7c,  0x44,  0xc4,  0xce,  0xfc,
0x00,  0x10,  0x10,  0x10,  0x00,  0x00,  0x00,  0x00,  0x00,  0x02,  0x04,
0x0c,  0x08,  0x0c,  0x04,  0x02,  0x00,  0x80,  0x40,  0x60,  0x20,  0x60,
0x40,  0x80,  0x00,  0x00,  0x54,  0x38,  0x6c,  0x38,  0x54,  0x00,  0x00,
0x00,  0x10,  0x10,  0x7c,  0x10,  0x10,  0x00,  0x00,  0x00,  0x00,  0x00,
0x00,  0x00,  0x18,  0x08,  0x00,  0x00,  0x00,  0x00,  0x38,  0x00,  0x00,
0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x18,  0x00,  0x04,
0x04,  0x08,  0x10,  0x20,  0x40,  0x40,  0x00,  0x7e,  0x42,  0x42,  0xc2,
0xc6,  0xc6,  0xfe,  0x00,  0x38,  0x00,  0x08,  0x18,  0x18,  0x18,  0x18,
0x00,  0x7c,  0x04,  0x7c,  0xc0,  0xc0,  0xc6,  0xfe,  0x00,  0x7e,  0x02,
0x1e,  0x06,  0x06,  0xc6,  0xfe,  0x00,  0x26,  0x22,  0x3e,  0x06,  0x06,
0x06,  0x06,  0x00,  0x7c,  0x40,  0x7c,  0x06,  0x06,  0xc6,  0xfe,  0x00,
0x78,  0x40,  0x7e,  0x46,  0xc6,  0xc6,  0xfe,  0x00,  0xfe,  0x86,  0x0c,
0x0c,  0x18,  0x18,  0x18,  0x00,  0x3c,  0x24,  0x7e,  0x42,  0xc2,  0xc6,
0xfe,  0x00,  0x7e,  0x42,  0x7e,  0x02,  0x06,  0xc6,  0xfe,  0x00,  0x00,
0x00,  0x18,  0x00,  0x18,  0x00,  0x00,  0x00,  0x00,  0x00,  0x18,  0x00,
0x18,  0x08,  0x00,  0x00,  0x0c,  0x18,  0x30,  0x60,  0x30,  0x18,  0x0c,
0x00,  0x00,  0x00,  0x7c,  0x00,  0x7c,  0x00,  0x00,  0x00,  0x60,  0x30,
0x18,  0x0c,  0x18,  0x30,  0x60,  0x00,  0x1c,  0x36,  0x66,  0x0c,  0x18,
0x00,  0x18,  0x00,  0x7c,  0x42,  0x1a,  0x2a,  0x2a,  0x2a,  0x1c,  0x00,
0x3c,  0x26,  0x7e,  0x42,  0xc2,  0xc6,  0xc6,  0x00,  0x78,  0x4c,  0x78,
0xcc,  0xc6,  0xc6,  0xfc,  0x00,  0x7e,  0x42,  0xc0,  0xc0,  0xc0,  0xc6,
0xfe,  0x00,  0x78,  0x4c,  0x42,  0xc2,  0xc6,  0xce,  0xfc,  0x00,  0x7e,
0x42,  0x40,  0xf0,  0xc0,  0xc6,  0xfe,  0x00,  0x7e,  0x42,  0x40,  0xf0,
0xc0,  0xc0,  0xc0,  0x00,  0x7e,  0x46,  0x40,  0xc0,  0xce,  0xc6,  0xfe,
0x00,  0x42,  0x42,  0x7e,  0xc2,  0xc2,  0xc2,  0xc6,  0x00,  0x08,  0x08,
0x08,  0x18,  0x18,  0x18,  0x18,  0x00,  0x02,  0x06,  0x06,  0x06,  0xc6,
0xc6,  0xfe,  0x00,  0x48,  0x50,  0x70,  0xd8,  0xcc,  0xc6,  0xc6,  0x00,
0x40,  0x40,  0x40,  0xc0,  0xc0,  0xc6,  0xfe,  0x00,  0x42,  0x66,  0x7e,
0xda,  0xc2,  0xc2,  0xc6,  0x00,  0x62,  0x62,  0x52,  0xda,  0xce,  0xc6,
0xc6,  0x00,  0x7e,  0x42,  0x42,  0xc2,  0xc6,  0xc6,  0xfe,  0x00,  0x7c,
0x42,  0x42,  0xfc,  0xc0,  0xc0,  0xc0,  0x00,  0x7e,  0x42,  0x42,  0xc2,
0xce,  0xc6,  0xfe,  0x00,  0x7c,  0x46,  0x7c,  0xd8,  0xc8,  0xce,  0xc6,
0x00,  0x7e,  0x40,  0x7e,  0x06,  0x06,  0xc6,  0xfe,  0x00,  0x7e,  0x08,
0x08,  0x18,  0x18,  0x18,  0x18,  0x00,  0x46,  0x46,  0xc2,  0xc2,  0xc2,
0xc2,  0xfe,  0x00,  0x46,  0x46,  0x62,  0x32,  0x36,  0x1c,  0x1c,  0x00,
0x46,  0x46,  0xc2,  0xd2,  0xfe,  0xee,  0xc6,  0x00,  0xc6,  0x6c,  0x38,
0x10,  0x38,  0x6c,  0xc6,  0x00,  0x46,  0x46,  0x7c,  0x38,  0x18,  0x18,
0x18,  0x00,  0x7e,  0x06,  0x3c,  0x30,  0xe0,  0xe6,  0xfe,  0x00,  0x38,
0x20,  0x20,  0x20,  0x20,  0x20,  0x38,  0x00,  0x40,  0x40,  0x20,  0x10,
0x08,  0x04,  0x04,  0x00,  0x38,  0x08,  0x08,  0x08,  0x08,  0x08,  0x38,
0x00,  0x10,  0x28,  0x28,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,
0x00,  0x00,  0x00,  0x00,  0xfe,  0x00,  0xff,  0xff,  0xff,  0xff,  0xff,
0xff,  0xff,  0xff,  0x00,  
};
