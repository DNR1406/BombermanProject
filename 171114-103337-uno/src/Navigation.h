#include <MI0283QT9.h>
#include "include.h"

#ifndef Navigation_H
#define Navigation_H

class Navigation
{
public:
  Navigation();
  void screenInit();

  void checkButtonPresses();
  void checkHomeButton();
  void checkOptionsBackButton();
  void checkOptionsButtons();
  
  void showCredits();
  void drawStartscreenButtons();

  void writeCalData(void);
  uint8_t readCalData(void);
  void calibrateScreen();

private:
  MI0283QT9 lcd;
};

#endif