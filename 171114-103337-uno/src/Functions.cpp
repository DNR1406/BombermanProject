#include <avr/interrupt.h>
#include <Arduino.h>

#include "Functions.h"
#include "Globals.h"

//variables
volatile uint8_t buffer[38];
volatile uint8_t bitToSend;
volatile uint8_t send;
volatile uint32_t counterTimer2;

void init_begin()
{
    init();

    init_in_out_put();
    init_single_Sample();
    init_timer1();
    init_timer2();
    sei();
}

//function for in/output
void init_in_out_put()
{
    //in/out put register B
    DDRB = 0;
    //in/out put register C
    DDRC = 0;
    //in/out put register D
    DDRD = 0;
}

//function to init single sample
void init_single_Sample()
{
    // input analog A0 Arduino
    ADMUX = 0;
    // 5 volt
    ADMUX |= (1 << REFS0);
    // clock/128
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    // ADC enable
    ADCSRA |= (1 << ADEN);
}

// Function to init timer 2
void init_timer1()
{
    // CTC, No prescaler
    TCCR1B = _BV(WGM12) | _BV(CS10);
    // compare A register value (210 * clock speed)
    //  = 13.125 nS , so frequency is 1 / (2 * 13.125) = 38095
    OCR1A = 209;
    TIMSK1 |= (1 << OCIE1A);
}

//function to init timer 1
void init_timer2()
{
    //TCNT2 count to 200
    OCR2A = 200;
    //enable CTC, counter counts to 200, after that it starts again
    TCCR2A |= (1 << WGM21);
    //prescaler 8
    TCCR2B |= (1 << CS21);
    //enable TIMER2_COMPA_vect
    TIMSK2 |= (1 << OCIE2A);
}

/*--------------------------------------------------------------------------
Timer functions:
*/

ISR(TIMER2_COMPA_vect)
{
    if (!(counterTimer2 == 6))
    {
        // if (buffer[bitToSend])
        // {
        //     send = 1;
        // }
        // else
        // {
        //     send = 0;
        // }

        // bitToSend++;

        // if (bitToSend == 326)
        // {
        //     bitToSend = 0;
        // }
        // counterTimer2 = 0;
    }

    // if (!(counterTimer2 % 100))
    // {
    //     // Serial.println(counterTimer2);
    // }

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
