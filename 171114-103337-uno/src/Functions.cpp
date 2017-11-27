#include <avr/interrupt.h>
#include "include.h"


//function to init timer
void init_timer()
{
    //set registers to zero
    TCCR2A = 0;
    TCCR2B = 0;
    TCNT2  = 0;

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