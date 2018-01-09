#include <MI0283QT9.h>
#include <stdint.h>

#ifndef Screen_H
#define Screen_H

class Screen
{
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

  //Drawing

private:
  void draw();
  uint8_t x;
  uint8_t y;
  uint8_t r;
  uint8_t g;
  uint8_t b;
  MI0283QT9 lcd;
};

#endif
