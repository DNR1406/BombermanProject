#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

#ifndef Map_H
#define Map_H

class Map {
public:
    Map();
    void drawGrid();
    void drawBarrels(int x, int y);
    void declareBarrels(int amount);
 

   
  private:
  MI0283QT9 lcd;

   
};


#endif
