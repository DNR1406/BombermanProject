#include "include.h"

#ifndef PlayerMovement_H
#define PlayerMovement_H

class PlayerMovement
{
  public:
    PlayerMovement(int x, int y);
    void left(uint8_t bombPlaced);
    void down(uint8_t bombPlaced);
    void up(uint8_t bombPlaced);
    void right(uint8_t bombPlaced);
    void clearPlayer();
    void draw();

    int x;
    int y;
    bool leftMove;
    bool rightMove;
    bool upMove;
    bool downMove;
    MI0283QT9 lcd;
};

#endif
