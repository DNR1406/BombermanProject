#include <stdint.h>

#ifndef CommunictaionIR_H
#define CommunictaionIR_H

class CommunicationIR
{
public:
  CommunicationIR(uint8_t frequenty);

  void setPlayer1(uint8_t x, uint8_t y, uint8_t bomb);
  void getPlayer2(uint8_t *x, uint8_t *y);
  void getBombPlayer2(uint8_t *x, uint8_t *y);

private:
  void startTimer1();
  void stopTimer1();
  void startReceiving();
  void stopReceiving();
  uint8_t powerTwo(uint8_t power);

  void fillOutGoingBuffer(uint8_t *buffer, uint8_t x, uint8_t y, uint8_t *bomb);
  void getIncommingBuffer(uint8_t *bomb);

  uint8_t xPlayer1, yPlayer1, xPlayer2, yPlayer2, xBombPlayer2, yBombPlayer2;
};

#endif
