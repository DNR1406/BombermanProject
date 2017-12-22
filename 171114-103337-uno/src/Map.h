#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

#ifndef Map_H
#define Map_H

class Map
{
public:
  Map();
  void drawPlayMap();
  void drawBarrels(int x, int y);
  void declareBarrels(uint8_t amount);
  void placeBomb(uint16_t x, uint8_t y);
  void deleteBarrels(uint16_t x, uint8_t y);
  uint16_t single_sample();
  void init_adc_single_sample();
  void drawWalls(int x, uint8_t y);
  uint8_t explosion(uint8_t x, uint8_t y);

  uint8_t barrels[9][9];

private:
  MI0283QT9 lcd;
};

#endif
