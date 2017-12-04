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
  void checkPlayerActions();
  uint8_t GameEngine::OpenBMPFile(char *file, int16_t x, int16_t y);
  void GameEngine::calibrateScreen();
  void GameEngine::readFromSDCard(char *file);


private:
  int score;
  MI0283QT9 lcd;
};

#endif