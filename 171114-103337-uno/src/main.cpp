#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
// #include <SoftwareSerial.h>

#include "include.h"
#include <Arduino.h>

int buffer[362];
volatile int bitToSend;
Navigation navigation = Navigation();


int main()
{
    init();
    navigation.screenInit();
    navigation.calibrateScreen();
    navigation.drawStartscreenButtons();
       // Check if any buttons are pressed
    navigation.checkButtonPresses();

    DDRB |= (1 << PB5);

    // navigation.screenInit();
    // navigation.calibrateScreen();
    // navigation.drawStartscreenButtons();

    // communicationIR *commu = new communicationIR(36);
    // commu->fillBuffer(buffer, 1, 1, true);

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
    TCCR1A ^= _BV (COM1A0) ;
    if (counterTimer2 == 1000)
    {

    if (!(TCCR1A & _BV (COM1A0)) == 0 && buffer[bitToSend])
    {
        PORTB |= (1 << PB5);
    }
    else
    {
        PORTB &= ~(1 << PB5);
        
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
