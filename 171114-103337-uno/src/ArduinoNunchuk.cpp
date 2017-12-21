#include <Wire.h>
#include <util/delay.h>
#include "Globals.h"

//#include "ArduinoNunchuk.h"
#include "include.h"
#define ADDRESS 0x52

ArduinoNunchuk::ArduinoNunchuk()
{
}
void ArduinoNunchuk::init()
{
  //start wire liberay
  Wire.begin();

  //verzenden van bytes
  ArduinoNunchuk::_sendByte(0x55, 0xF0);
  ArduinoNunchuk::_sendByte(0x00, 0xFB);

  //update, controleren of de status van de nunchuck veranderd is
  ArduinoNunchuk::update();
}

//functie om te controleren of er iets op de nunchuck veranderd is.
void ArduinoNunchuk::update()
{
  uint8_t count = 0;
  uint8_t values[6];

  //vraag gegevens op
  Wire.requestFrom(ADDRESS, 6);

  //stop ze in een array
  while (Wire.available())
  {
    values[count] = Wire.read();
    count++;
  }

  //uitlezen, de values komen in de onderstaande variabelen
  ArduinoNunchuk::analogX = values[0];
  ArduinoNunchuk::analogY = values[1];
  ArduinoNunchuk::accelX = (values[2] << 2) | ((values[5] >> 2) & 3);
  ArduinoNunchuk::accelY = (values[3] << 2) | ((values[5] >> 4) & 3);
  ArduinoNunchuk::accelZ = (values[4] << 2) | ((values[5] >> 6) & 3);
  ArduinoNunchuk::zButton = !((values[5] >> 0) & 1);
  ArduinoNunchuk::cButton = !((values[5] >> 1) & 1);

  //klaar
  ArduinoNunchuk::_sendByte(0x00, 0x00);
}

//functie om byte te versturen
void ArduinoNunchuk::_sendByte(char data, char location)
{
  Wire.beginTransmission(ADDRESS);

  Wire.write(location);
  Wire.write(data);

  Wire.endTransmission();

  // uint32_t nunchukDelay = counterTimer2; 
  // while(nunchukDelay + 30  < counterTimer2) {
    
  // }
  // int i;
  // while(i < 1000){
  //   i++;
  // }
  

  _delay_ms(100); // MOET VERVANGEN WORDEN DOOR TIMER!!
  

    
}

