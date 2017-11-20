#include <MI0283QT9.h>

#ifndef Beeldscherm_H
#define Beeldscherm_H

class Beeldscherm {
public:
    Beeldscherm();
    void left();
    void down();
    void up();
    void right();
    void changeColor();
    void addSecond();
    void beelschermInit();
    void clear();
    void readFromSDCard(char *file);
   
  private:
    void draw();
    uint8_t OpenBMPFile(char *file, int16_t x, int16_t y);
    int x;
    int y;
    int r;
    int g;
    int b;
    int seconds;
    MI0283QT9 lcd;
};


#endif
