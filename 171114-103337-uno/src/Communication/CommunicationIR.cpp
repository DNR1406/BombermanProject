#include "../include.h"
#include <avr/interrupt.h>

communicationIR::communicationIR(int frequenty)
{
}

void communicationIR::fillBuffer(int *buffer, int x, int y, bool bomb)
{
    uint8_t bufferCounter = 0;

    for (uint8_t i = 0; i < 38; i++)
    {
        buffer[i] = 0;
    }

    //startbit
    for (uint8_t i = 0; i < 4; i++)
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }

    //interval startbit

    buffer[bufferCounter] = 0;
    bufferCounter++;

    //fill X nibble in buffer
    for (uint8_t i = 4; i >= 0; i--)
    {
        if ((x >> i) & 1)
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        else
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }

        buffer[bufferCounter] = 0;
        bufferCounter++;
    }
    //fill y nibble in buffer
    for (uint8_t i = 4; i >= 0; i--)
    {
        if ((y >> i) & 1)
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        else
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }

        buffer[bufferCounter] = 0;
        bufferCounter++;
    }

    //Fill bomb bit in buffer
    if (bomb)
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }
    else
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }

    buffer[bufferCounter] = 0;
    bufferCounter++;

    if ((x + y) % 2)
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }
    else
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }

    buffer[bufferCounter] = 0;
    bufferCounter++;
}
