#include <MI0283QT9.h>
#include "include.h"

#ifndef Options_H
#define Options_H

class Options
{
public:
  Options();
  void checkOptionsBackButton();
  void checkOptionsButtons();
  void createOptionsButtons();
  void changeBrightness();

private:
  MI0283QT9 lcd;
};

#endif