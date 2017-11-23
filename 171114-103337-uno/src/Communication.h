#ifndef Communication_H
#define Communication_H

#include "include.h"

class Communication
{
  public:
    Communication();
    void setLocationPlayer1(int x, int y);
    void getPositionPlayer2(int *x, int *y);
    void setBombPlayer1(int x, int y);
    void getBombPlayer2(Bomb *bomb);

  private:
    void removeBombPlayer1();
    void removeBombPlayer2();

    Bomb *bombPlayer1, *bombPlayer2;
    int xPlayer1, yPlayer1, xPlayer2, yPlayer2;
};

#endif