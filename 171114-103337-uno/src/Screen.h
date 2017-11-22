#include <MI0283QT9.h>
#include <stdint.h>

#ifndef Screen_H
#define Screen_H

class Screen {
public:
    Screen();
    void left();
    void down();
    void up();
    void right();
    void changeColor();
    void addSecond();
    void screenInit();
    void clear();
   
  private:
    void draw();
    int x;
    int y;
    int r;
    int g;
    int b;
    int seconds;
    MI0283QT9 lcd;
};


#endif
