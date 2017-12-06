#include "include.h"
#include <avr/interrupt.h>

communicationIR::communicationIR(int frequenty)
{
    this->startTimers();
}

void communicationIR::fillBuffer(int *buffer, int x, int y, bool bomb)
{
    int p = 1;
    for(int i = 0; i < 228; i ++) {
        buffer[i] = p;
        p = !p;
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
