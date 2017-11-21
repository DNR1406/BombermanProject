
#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <stdint.h>
#include <Arduino.h>
#include <SD.h>
#include <TFT.h> // Arduino TFT library
#include <Wire.h>
#include <digitalWriteFast.h>
#include <GraphicsLib.h>
#include <BMPheader.h>
#include <stdint.h>
#define SD_CS   8

#include "Beeldscherm.h"

//constructor
Beeldscherm::Beeldscherm () {
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
void Beeldscherm::beelschermInit() {
  this->lcd.begin();
  this->lcd.fillScreen(RGB(255,255,255));
  this->lcd.led(50);
  this->draw();
}

//de stip wit maken, dus weg halen
void Beeldscherm::clear() {

  this->lcd.drawCircle(this->x, this->y,6,RGB(  255, 255,  255));
  this->lcd.fillCircle(this->x, this->y,6,RGB(  255, 255,  255));
}

//nieuwe stip kleuren
void Beeldscherm::draw() {
  this->lcd.drawCircle(this->x, this->y,6,RGB(  this->r, this->g,  this->b));
  this->lcd.fillCircle(this->x, this->y,6,RGB(  this->r, this->g,  this->b));
}

//naar Links
void Beeldscherm::left() {
  //oude stip weg
  this->clear();
  //x tien vanaf
  if(this->x > 0)
    this->x -= 10;
  //nieuwe stip kleuren
  this->draw();
}


//zelfde functie als left, alleen voor right
void Beeldscherm::right() {
  this->clear();
  if(this->x < 320)
    this->x += 10;
  this->draw();
}

//zelfde functie als left, alleen voor down
void Beeldscherm::down() {
  this->clear();
  if(this->y > 0)
    this->y += 10;
  this->draw();
}

//zelfde functie als left, alleen voor up
void Beeldscherm::up() {
  this->clear();
  if(this->y < 240)
    this->y -= 10;
  this->draw();
}

//kleur veranderen met random functie
void Beeldscherm::changeColor() {
  this->clear();
  this->r = rand() % 255;
  this->g = rand() % 255;
  this->b = rand() % 255;
  draw();
}

//seconde toevoegen, deze functie wordt aangeropen bij de timerinteruptfunctie
void Beeldscherm::addSecond() {
  this->seconds++;
  this->lcd.drawInteger(2, 2, this->seconds, DEC, RGB(255,0,0), RGB(255,255,255), 1);
}

void Beeldscherm::readFromSDCard(char *file) {
   int x, i;
  
  //init Display
  lcd.begin();

  //init SD-Card
  if (SD.begin(4)) {
    OpenBMPFile(file, 0, 0);
  } else {
    lcd.drawText(5, 5, "Mislukt", RGB(0,0,0), RGB(255,255,255), 1);
  }
}


uint8_t Beeldscherm::OpenBMPFile(char *file, int16_t x, int16_t y)
{
  File myFile;
  uint8_t buf[40]; //read buf (min. size = sizeof(BMP_DIPHeader))
  BMP_Header *bmp_hd;
  BMP_DIPHeader *bmp_dip;
  int16_t width, height, w, h;
  uint8_t pad;
  
  //open file
  myFile = SD.open(file);
  if(myFile)
  {
    //BMP Header
    myFile.read(&buf, sizeof(BMP_Header));
    bmp_hd = (BMP_Header*)&buf[0];
    if((bmp_hd->magic[0] == 'B') && (bmp_hd->magic[1] == 'M') && (bmp_hd->offset == 54))
    {
      //BMP DIP-Header
      myFile.read(&buf, sizeof(BMP_DIPHeader));
      bmp_dip = (BMP_DIPHeader*)&buf[0];
      if((bmp_dip->size == sizeof(BMP_DIPHeader)) && (bmp_dip->bitspp == 24) && (bmp_dip->compress == 0))
      {
        //BMP Data (1. pixel = bottom left)
        width  = bmp_dip->width;
        height = bmp_dip->height;
        pad    = width % 4; //padding (line is multiply of 4)
        if((x+width) <= lcd.getWidth() && (y+height) <= lcd.getHeight())
        {
          lcd.setArea(x, y, x+width-1, y+height-1);
          for(h=(y+height-1); h >= y; h--) //for every line
          {
            for(w=x; w < (x+width); w++) //for every pixel in line
            {
              myFile.read(&buf, 3);
              lcd.drawPixel(w, h, RGB(buf[2],buf[1],buf[0]));
            }
            if(pad)
            {
              myFile.read(&buf, pad);
            }
          }
        }
        else
        {
          lcd.drawText(x, y, "Pic out of screen!", RGB(0,0,0), RGB(255,255,255), 1);
        }
      }
    }

    myFile.close();
  }
  
}
void Beeldscherm::drawStartscreenButtons() {
  // Draws start button
  lcd.fillRoundRect(95,125,120,30,5,RGB(  0,  100,100));
  lcd.drawRoundRect(95,125,120,30,5,RGB(  0,  0,  0));
  lcd.drawText(117, 133, "START", RGB(255,0,0), RGB(0,100,100), 2);
  
  // Draws options button
  lcd.fillRoundRect(95,160,120,30,5,RGB(  0,  100,100));
  lcd.drawRoundRect(95,160,120,30,5,RGB(  0,  0,  0));
  lcd.drawText(100, 168, "OPTIONS", RGB(255,0,0), RGB(0,100,100), 2); 

  // Draws credits button
  lcd.fillRoundRect(95,195,120,30,5,RGB(  0,  100,100));
  lcd.drawRoundRect(95,195,120,30,5,RGB(  0,  0,  0));
  lcd.drawText(100, 203, "CREDITS", RGB(255,0,0), RGB(0,100,100), 2); 
  
}

