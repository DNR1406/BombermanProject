#include "include.h"

#ifndef ArduinoNunchuk_H
#define ArduinoNunchuk_H


class ArduinoNunchuk
{
  public:
    int analogX;
    int analogY;
    int accelX;
    int accelY;
    int accelZ;
    int zButton;
    int cButton;
    ArduinoNunchuk();
    void init();
    void update();

  private:
    void _sendByte(char data, char location);
};

#endif
