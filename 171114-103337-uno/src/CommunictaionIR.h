#include "include.h"

#ifndef CommunictaionIR_H
#define CommunictaionIR_H

class communicationIR
{
  public:
    communicationIR(int frequenty);
    int send();

    int buffer[228];
    int bitToSend;
    int amountOfBits;

  private:
    void startTimers();
};

#endif
