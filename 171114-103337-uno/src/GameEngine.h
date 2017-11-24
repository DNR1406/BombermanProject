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


private:
  int score;
  MI0283QT9 lcd;
};

#endif