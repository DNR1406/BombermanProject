// Other includes
#include <MI0283QT9.h>

#define BOMBS 3
// #define SINGLEPLAYER 1

class ArduinoNunchuk;
class Bomb;
class Map;
class Screen;
class PlayerMovement;
class CommunicationIR;

#ifndef GameEngine_H
#define GameEngine_H

class GameEngine
{
public:
  GameEngine();
  void startGame(int amount, uint8_t frequenty);
  void startGame(uint8_t frequenty);
  void selectLevel();
  void incrementScore();
  void addPlayer();
  void checkPlayerActions();
  void deleteBomb(Bomb **bombs, uint8_t bombPlace, PlayerMovement *player);
  void endGameScreen();
  void endOfGame();
  void readDataFromEEPROM();
  void writeScoreToEEPROM(int score);
  void showPlayerOneInfo();
  void showPlayerTwoInfo();
  void checkPlayerDamage(Bomb **bombs, uint8_t number, PlayerMovement *player);

private:
  MI0283QT9 lcd;
  ArduinoNunchuk *nunchuk;
  Map *playMap;
  Screen *screen;
  PlayerMovement *player1;
  PlayerMovement *player2;

  Bomb *bombsPlayer1[BOMBS];
  Bomb *bombsPlayer2[BOMBS];
  uint8_t oldXPlayer2, oldYPlayer2, sidePlayer2;

  uint8_t player;

  uint8_t addBomb(uint8_t x, uint8_t y);

  void updatePlayer1();
  void updatePlayer2();
  void checkBombs();
};

#endif