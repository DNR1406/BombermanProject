#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

class ArduinoNunchuk;

#ifndef GameEngine_H
#define GameEngine_H

class GameEngine
{
public:
  GameEngine();
  void startGame();
  void selectLevel();
  void incrementScore();
  void addPlayer();
  void checkPlayerActions();
  int freeRam();

private:
  MI0283QT9 lcd;
  ArduinoNunchuk *nunchuk;
};

#endif