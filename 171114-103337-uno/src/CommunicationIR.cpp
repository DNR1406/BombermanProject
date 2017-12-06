#include "include.h"
#include <avr/interrupt.h>

communicationIR::communicationIR(int frequenty)
{
    this->startTimers();
}

void communicationIR::fillBuffer(int *buffer, int x, int y, bool bomb)
{
    int X = 7;
    int Y = 4;
    bool bomB = 1;

    int bufferCounter = 0;

    //startbit
    for (int i = 0; i < 24; i++)
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
     
    }

    //interval startbit
    for (int i = 0; i < 6; i++)
    {
        buffer[bufferCounter] = 0;
        bufferCounter++;
       
    }
//fill X nibble in buffer
    for (int i = 3; i >= 0; i--)
    {
        if (X >> i)
        {
            for (int i = 0; i < 12; i++)
            {
                buffer[bufferCounter] = 1;
                bufferCounter++;
            }
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                buffer[bufferCounter] = 1;
                bufferCounter++;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            buffer[bufferCounter] = 0;
            bufferCounter++;
        }
      
    }
    //fill y nibble in buffer
    for (int i = 3; i >= 0; i--)
    {
        if (Y >> i)
        {
            for (int i = 0; i < 12; i++)
            {
                buffer[bufferCounter] = 1;
                bufferCounter++;
            }
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                buffer[bufferCounter] = 1;
                bufferCounter++;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            buffer[bufferCounter] = 0;
            bufferCounter++;
        }
        
    }
    //Fill bomb bit in buffer
    for (int i = 1; i >= 0; i--)
    {
        if (bomB >> i)
        {
            for (int i = 0; i < 12; i++)
            {
                buffer[bufferCounter] = 1;
                bufferCounter++;
            }
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                buffer[bufferCounter] = 1;
                bufferCounter++;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            buffer[bufferCounter] = 0;
            bufferCounter++;
        }
        
    }
    for (int i = 0; i < 218; i++)
    {
        Serial.println(buffer[i]);
    }
}

void communicationIR::startTimers()
{
    //set registers to zero
    TCCR2A = 0;
    TCCR2B = 0;
    TCNT2 = 0;
    //TCNT2 count to 200
    OCR2A = 200;
    //enable CTC, counter counts to 200, after that it starts again
    TCCR2A |= (1 << WGM21);
    //prescaler 8
    TCCR2B |= (1 << CS21);
    //enable TIMER2_COMPA_vect
    TIMSK2 |= (1 << OCIE2A);
    //enable interrupts!
    sei();
}
