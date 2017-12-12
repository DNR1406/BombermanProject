#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

class ArduinoNunchuk;
class Bomb;

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
  void deleteBomb();

private:
  MI0283QT9 lcd;
  ArduinoNunchuk *nunchuk;
  Bomb *bombPlayer1;
};

#endif