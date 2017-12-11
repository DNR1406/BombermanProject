#include "include.h"

int buffer[362];
volatile int bitToSend;
volatile int send;

int main()
{

    init();
    Serial.begin(9600);

    init_in_out_put();
    init_single_Sample();

    Navigation *navigation = new Navigation();
    navigation->startStartScreen();

    while (1)
    {
    }

    return 0;
}

// variable for counterTimer2
volatile uint32_t counterTimer2 = 0;
// interupt functie
ISR(TIMER2_COMPA_vect)
{
    if (counterTimer2 == 1000)
    {

        if (buffer[bitToSend])
        {
            send = 1;
        }
        else
        {
            send = 0;
        }

        bitToSend++;

        if (bitToSend == 326)
        {
            bitToSend = 0;
        }
        counterTimer2 = 0;
    }
    counterTimer2++;
}
ISR(TIMER1_COMPA_vect)
{
    TCCR1A ^= _BV(COM1A0);

    if (send == 1)
    {
        //     if (!(TCCR1A & _BV (COM1A0)) == 0){

        PORTB ^= (1 << PB5);
    }
    else
    {
        PORTB &= ~(1 << PB5);
    }
}
