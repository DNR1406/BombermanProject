#include <stdint.h>

#include "include.h"

#ifndef Communication_H
#define Communication_H



class Communication
{
public:
  Communication(int x, int y);
  //player1
  void setLocationPlayer1(int x, int y);
  void setLocationPlayer1(int x, int y, int bomb);

  //player2
  void getLocationPlayer2(int *x, int *y, int *bomb);

  //other
  void sendReceive();

  void sendMap(int positions[58]);
  void receiveMap(int *positions);

private:
  //player1
  void sendLocationPlayer1();
  int xPlayer1, yPlayer1;

  //player2
  void receiveLocationPlayer2();
  int xPlayer2, yPlayer2;

  //bomb
  int bombPlayer1, bombPlayer2;
};

#endif