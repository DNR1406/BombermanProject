#include "include.h"

#ifndef PlayerMovement_H
#define PlayerMovement_H

class PlayerMovement
{
public:
  PlayerMovement(uint8_t x, uint8_t y, uint8_t player);
  void left(uint8_t bombPlaced, uint8_t playerOverWalk, uint8_t player);
  void down(uint8_t bombPlaced, uint8_t playerOverWalk, uint8_t player);
  void up(uint8_t bombPlaced, uint8_t playerOverWalk, uint8_t player);
  void right(uint8_t bombPlaced, uint8_t playerOverWalk, uint8_t player);
  void clearPlayer();
  void draw(uint8_t player);
  uint8_t getXLocation();
  uint8_t getYLocation();
  uint8_t getScore();
  uint8_t getLifes();
  void setScore(uint8_t score);
  void setLifes(uint8_t lifes);
  void updateScore();
  void updateLives();

  uint8_t player;
  uint8_t x;
  uint8_t y;
  bool leftMove;
  bool rightMove;
  bool upMove;
  bool downMove;

  uint8_t score;
  uint8_t lifes;

  MI0283QT9 lcd;
};

#endif
