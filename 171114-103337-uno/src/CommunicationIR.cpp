#include "include.h"
#include <avr/interrupt.h>

communicationIR::communicationIR(int frequenty)
{
    this->startTimer1();
    this->startTimer2();
}

void communicationIR::fillBuffer(int *buffer, int x, int y, bool bomb)
{
    int X = 9;
    int Y = 200;
    bool bomB = 1;
    int XPLUSY = X + Y;

    int bufferCounter = 0;

    for (int i = 0; i < 362; i++)
    {
        buffer[i] = 0;
    }

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
    for (int i = 7; i >= 0; i--)
    {
        if (X >> i & 1)
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
    for (int i = 7; i >= 0; i--)
    {
        if (Y >> i & 1)
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
    if (bomB)
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
if ( XPLUSY % 2 == 0)
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

    for (int i = 0; i < 362; i++)
    {
        Serial.print(i);
        Serial.print("\t");
        Serial.println(buffer[i]);
        
    }
    
}

void communicationIR::startTimer2()
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
void communicationIR::startTimer1()
{
 TCCR1A = 0; 
 TCCR1B = _BV(WGM12) | _BV (CS11);   // CTC, No prescaler
 OCR1A =  254;          // compare A register value (210 * clock speed)
                        //  = 13.125 nS , so frequency is 1 / (2 * 13.125) = 38095
}
