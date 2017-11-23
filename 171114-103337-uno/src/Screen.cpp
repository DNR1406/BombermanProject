#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <stdint.h>
#include <Arduino.h>

#include <TFT.h> // Arduino TFT library
#include <Wire.h>
#include <digitalWriteFast.h>
#include <BMPheader.h>
#include <stdint.h>
#define SD_CS   8

#include "include.h"

//constructor
Screen::Screen() {
  //begin waardes, secs, x, y
  this->seconds = 0;
  this->x = 160;
  this->y = 120;
  //rgb van kleur
  this->r = 0;
  this->g = 200;
  this->b = 0;
}

//functie om de stip in het midden te zetten en het beelscherm te kleuren
void Screen::screenInit() {
  this->lcd.begin();
}

//de stip wit maken, dus weg halen
void Screen::clear() {

  this->lcd.drawCircle(this->x, this->y,6,RGB(  255, 255,  255));
  this->lcd.fillCircle(this->x, this->y,6,RGB(  255, 255,  255));
}

//nieuwe stip kleuren
void Screen::draw() {
  this->lcd.drawCircle(this->x, this->y,6,RGB(  this->r, this->g,  this->b));
  this->lcd.fillCircle(this->x, this->y,6,RGB(  this->r, this->g,  this->b));
}

//naar Links
void Screen::left() {
  //oude stip weg
  this->clear();
  //x tien vanaf
  if(this->x > 0)
    this->x -= 10;
  //nieuwe stip kleuren
  this->draw();
}


//zelfde functie als left, alleen voor right
void Screen::right() {
  this->clear();
  if(this->x < 320)
    this->x += 10;
  this->draw();
}

//zelfde functie als left, alleen voor down
void Screen::down() {
  this->clear();
  if(this->y > 0)
    this->y += 10;
  this->draw();
}

//zelfde functie als left, alleen voor up
void Screen::up() {
  this->clear();
  if(this->y < 240)
    this->y -= 10;
  this->draw();
}

//kleur veranderen met random functie
void Screen::changeColor() {
  this->clear();
  this->r = rand() % 255;
  this->g = rand() % 255;
  this->b = rand() % 255;
  draw();
}

//seconde toevoegen, deze functie wordt aangeropen bij de timerinteruptfunctie
void Screen::addSecond() {
  this->seconds++;
  this->lcd.drawInteger(2, 2, this->seconds, DEC, RGB(255,0,0), RGB(255,255,255), 1);
}









