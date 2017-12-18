#include "include.h"

#ifndef ArduinoNunchuk_H
#define ArduinoNunchuk_H


class ArduinoNunchuk
{
  public:
    ArduinoNunchuk();
    int analogX;
    int analogY;
    int accelX;
    int accelY;
    int accelZ;
    int zButton;
    int cButton;
    void init();
    void update();
    uint8_t nunchukDelay(uint32_t nunchukTimer);

  private:
    void _sendByte(char data, char location);
};

#endif
