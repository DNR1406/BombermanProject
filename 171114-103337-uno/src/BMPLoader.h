#include <MI0283QT9.h>
#include "include.h"

#ifndef BMPLoader_H
#define BMPLoader_H

class BMPLoader {
public:
    BMPLoader();
    uint8_t OpenBMPFile(char *file, int16_t x, int16_t y);
    void readFromSDCard(char *file);
 

   
  private:
  MI0283QT9 lcd;

   
};


#endif