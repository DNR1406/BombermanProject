#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

typedef struct wall
{
  int x, y;
} wall;

#ifndef Map_H
#define Map_H

class Map
{
public:
  Map();
  void drawPlayMap();
  void drawBarrels(int x, int y);
  void declareBarrels(uint8_t amount);
  uint16_t single_sample();
  void init_adc_single_sample();

  uint8_t barrels[9][9];

private:
  MI0283QT9 lcd;
};

#endif
