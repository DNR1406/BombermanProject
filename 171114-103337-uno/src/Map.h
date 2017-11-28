#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

#ifndef Map_H
#define Map_H

class Map {
public:
    Map();
    void drawGrid();
    void drawBarrels(int, int);
    void declareBarrels();
 

   
  private:
  MI0283QT9 lcd;

   
};


#endif
