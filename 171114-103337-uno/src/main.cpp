#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <SoftwareSerial.h>
#include <avr/interrupt.h>

#include "include.h"
#include <Arduino.h>

int buffer[210];
volatile int bitToSend;

Navigation navigation = Navigation();

int main()
{
    init();
    Serial.begin(9600);

    communicationIR *commu = new communicationIR(36);

    while (1)
        ;

    return 0;
}

// variable for counterTimer2
volatile uint32_t counterTimer2 = 0;
// interupt functie
ISR(TIMER2_COMPA_vect)
{
    counterTimer2++;

    if (counterTimer2 == 1000) //Ten times per sec.
    {
        PORTB ^= (1 << PB5);
        counterTimer2 = 0;
    }
}
