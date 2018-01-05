#include "Screen.hpp"

//constructor
Screen::Screen() {
  // Start values for secs, x, y
  this->x = 160;
  this->y = 120;
  // RGB for color
  this->r = 0;
  this->g = 200;
  this->b = 0;
}

//de stip wit maken, dus weg halen
void Screen::clear() {

  lcd.drawCircle(x, y,6,RGB(  255, 255,  255));
  lcd.fillCircle(x, y,6,RGB(  255, 255,  255));
}

//nieuwe stip kleuren
void Screen::draw() {
  lcd.drawCircle(x, y,6,RGB(  r, g,  b));
  lcd.fillCircle(x, y,6,RGB(  r, g,  b));
}

//naar Links
void Screen::left() {
  //oude stip weg
  clear();
  //x tien vanaf
  if(x > 0)
    x -= 10;
  //nieuwe stip kleuren
  draw();
}


//zelfde functie als left, alleen voor right
void Screen::right() {
  clear();
  if(x < 320)
    x += 10;
  draw();
}

//zelfde functie als left, alleen voor down
void Screen::down() {
  clear();
  if(y > 0)
    y += 10;
  draw();
}

//zelfde functie als left, alleen voor up
void Screen::up() {
  clear();
  if(y < 240)
    y -= 10;
  draw();
}

//kleur veranderen met random functie
void Screen::changeColor() {
  clear();
  r = rand() % 255;
  g = rand() % 255;
  b = rand() % 255;
  draw();
}









