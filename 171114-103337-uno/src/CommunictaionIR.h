#include "include.h"

#ifndef CommunictaionIR_H
#define CommunictaionIR_H

class communicationIR
{
  public:
    communicationIR(int frequenty);
    void fillBuffer(int *buffer, int x, int y, bool bomb);
  private:
    void startTimers();
};

#endif
