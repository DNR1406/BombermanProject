#include <avr/pgmspace.h>
#include <MI0283QT9.h>

#ifndef Drawings_H
#define Drawings_H

#define ___GREENB1 0b10001000
#define ___GREENB2 0b10011010
#define ______NONE 0b00000000
#define _____BLACK 0b10000000
#define _____GREY1 0b10101010
#define _____GREY2 0b10010101
#define _____WHITE 0b10111111
#define ______RED1 0b10110000
#define ______RED2 0b10100000
#define ______RED3 0b10010000
#define ____GREEN1 0b10001100
#define ____GREEN2 0b10001000
#define ____GREEN3 0b10000100
#define _____BLUE1 0b10000011
#define _____BLUE2 0b10000010
#define _____BLUE3 0b10000001
#define ___YELLOW1 0b10110100
#define ___YELLOW2 0b10111000
#define ___YELLOW3 0b10111100

void drawBombAdSCreen(uint16_t x, uint16_t y);
void deleteBombFromScreen(uint16_t x, uint16_t y, uint8_t barrels[9][9]);
void updateWick(uint16_t x, uint16_t y, uint32_t bombTime);
void explodeBomb(uint16_t x, uint16_t y, uint32_t bombTime, uint8_t barrels[9][9]);

#endif