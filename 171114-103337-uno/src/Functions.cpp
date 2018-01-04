#include <avr/interrupt.h>
#include <Arduino.h>
#include "Communication/CommunicationIR.h"
#include "Functions.h"
#include "Globals.h"

void init_begin()
{
    init();
    Serial.begin(9600);

    init_in_out_put();
    init_single_Sample();
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

    // Sets pin 3,4 and 10 to output
    DDRD |= (1 << DDD3) | (1 << DDD4);
    DDRB |= (1 << DDB2);

    PORTD |= (1 << PD2);
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

void timer1_36K()
{
    //set to
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    //TCNT2 count to 53
    OCR1A = 27;
    //enable CTC, counter counts to 200, after that it walks back again
    TCCR1B |= (1 << WGM12);
    //prescaler 8
    TCCR1B |= (1 << CS11);
}

void timer1_56k()
{
    //set to
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    //TCNT2 count to 18
    OCR1A = 420;
    //enable CTC, counter counts to 200, after that it walks back again
    TCCR1B |= (1 << WGM12);
    // Prescaler 8
    TCCR1B |= (1 << CS10);
}

void init_interuptPin2()
{
    // Interupt by falling and rising
    EICRA |= (1 << ISC00);
}

//pos 100 micro
void init_timer2()
{
    //set to
    TCCR2A = 0;
    TCCR2B = 0;
    TCNT2 = 0;

    //TCNT2 count to 200
    OCR2A = 199;
    //enable CTC, counter counts to 200, after that it walks back again
    TCCR2A |= (1 << WGM21);
    //prescaler 8
    TCCR2B |= (1 << CS21);
    //enable TIMER2_COMPA_vect
    TIMSK2 |= (1 << OCIE2A);
}

// Interupt for timer 2 (10 000 hz)
ISR(TIMER2_COMPA_vect)
{
    // Count till 6, 6*100 = 600 micro sec
    if (communicationTimer2 == 6)
    {
        // Check in buffer if what next val is.
        if (buffer[bitToSend])
        {
            send = 0;
        }
        else
        {
            send = 1;
        }

        // Next value for next send
        bitToSend++;

        // End of buffer? start again
        if (bitToSend == 45)
        {
            if (start)
            {
                getIncommingBuffer(0);
            }
            else
            {
                getIncommingBuffer(1);
            }
            bitToSend = 0;
        }

        // Set to
        communicationTimer2 = 0;
    }

    // One interupt done
    communicationTimer2++;
    // Counter for game
    counterTimer2++;
}

// Timer 1 (36000 hz)
ISR(TIMER1_COMPA_vect)
{
    // If bit SEND in communicationS is set, toggle led
    if (send)
    {
        PORTD ^= (1 << PD3);
    }
    // Else set it to zero
    else
    {
        PORTD &= ~(1 << PD3);
    }
}

// Interupt function on Pin 2
ISR(INT0_vect)
{
    // Low
    if (PIND & (1 << PD2))
    {
        lastIncommingTime = counterTimer2;
    }
    // High
    else
    {
        uint8_t time = counterTimer2 - lastIncommingTime;

        incommingBuffer[counterIncomming] = time;
        counterIncomming++;

        if (counterIncomming == 39)
        {
            counterIncomming = 0;
        }
    }
}
