#include <MI0283QT9.h>
#include <stdint.h>
#include "include.h"

#define BOMBS 3

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
  void deleteBomb(uint8_t number);
  void endGameScreen();
  void updateScore(int score);
  void endOfGame();
  void readDataFromEEPROM();
  void writeScoreToEEPROM(int score);
  void showPlayerOneInfo();
  void showPlayerTwoInfo();
  void updateLifes();
  uint8_t checkPlayerDamage(uint8_t number);

private:
  MI0283QT9 lcd;
  ArduinoNunchuk *nunchuk;
  Bomb *bombs[BOMBS];
  int lifes = 3;

  uint8_t addBomb(uint8_t x, uint8_t y);
};

#endif