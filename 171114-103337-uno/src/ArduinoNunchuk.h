#ifndef ArduinoNunchuk_H
#define ArduinoNunchuk_H

#include "include.h"


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

    void init();
    void update();

  private:
    void _sendByte(char data, char location);
};

#endif
