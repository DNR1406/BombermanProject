#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"


typedef struct barrel {
    uint8_t x,y, barrel;
} barrel;

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
    void drawGrid();
    void drawBarrels(int x, int y);
    void declareBarrels(uint8_t amount, barrel *positions);
    void getBarrels(uint8_t barrels[55]);
    int single_sample();
    void init_adc_single_sample();

  private:
  MI0283QT9 lcd;
  barrel barrels[55];
};

#endif
