#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

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
  void checkPlayerActions(uint8_t barrels[9][9]);

private:
  MI0283QT9 lcd;
  ArduinoNunchuk *nunchuk;
};

#endif