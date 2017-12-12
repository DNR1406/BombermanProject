#include "include.h"
#include "Globals.h"

Bomb::Bomb()
{
}

Bomb::Bomb(uint8_t x, uint8_t y, uint32_t startTime)
{
    this->lastXlocation = x;
    this->lastYlocation = y;
    this->lastKnownTime = startTime;
    this->exploded = 0;
}

uint8_t Bomb::checkDetonation()
{
    return ((this->lastKnownTime + 500) < counterTimer2);
}

uint8_t Bomb::returnXlocation()
{
    return this->lastXlocation;
}

uint8_t Bomb::returnYlocation()
{
    return this->lastYlocation;
}

uint8_t Bomb::returnExploded()
{
    return this->exploded;
}

void Bomb::setExploded(uint8_t exploded)
{
    this->exploded = exploded;
}