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
  void startGame(int amount);
  void selectLevel();
  void incrementScore();
  void addPlayer();
  void checkPlayerActions();
  void deleteBomb();
  void endGameScreen();
  void updateScore(int score);
  void endOfGame();
  void readDataFromEEPROM();
  void writeScoreToEEPROM(int score);
  void showPlayerOneInfo();
  void showPlayerTwoInfo();
  void updateLifes();
  uint8_t checkPlayerDamage();

private:
  MI0283QT9 lcd;
  ArduinoNunchuk *nunchuk;
  Bomb *bombPlayer1;
  int lifes = 3;
};

#endif