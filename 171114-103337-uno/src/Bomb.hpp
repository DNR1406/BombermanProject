#include <stdint.h>

#ifndef Bomb_H
#define Bomb_H

class Bomb
{
public:
  Bomb();
  Bomb(uint8_t x, uint8_t y, uint32_t startTime);
  uint8_t checkDetonation();
  uint8_t returnXlocation();
  uint8_t returnYlocation();
  uint8_t returnExploded();
  void setTime(uint32_t time);
  void setExploded(uint8_t exploded);
  void setXlocation(uint8_t x);
  void setYlocation(uint8_t y);
  uint8_t readyForNew(uint8_t x, uint8_t y);

private:
  uint8_t lastXlocation;
  uint8_t lastYlocation;
  uint32_t lastKnownTime;
  uint8_t exploded;
};

#endif