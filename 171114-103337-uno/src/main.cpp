#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <SoftwareSerial.h>

#include "include.h"
#include <Arduino.h>

int buffer[228];
volatile int bitToSend;
Navigation navigation = Navigation();


int main()
{
    init();
    Serial.begin(9600);
    navigation.screenInit();
    navigation.calibrateScreen();
    navigation.drawStartscreenButtons();
       // Check if any buttons are pressed
    navigation.checkButtonPresses();

    // communicationIR *commu = new communicationIR(36);

    // while (1)
    //     ;
    DDRB |= (1 << PB5);

    navigation.screenInit();
    navigation.calibrateScreen();
    navigation.drawStartscreenButtons();

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

    if (buffer[bitToSend])
    {
        PORTB |= (1 << PB5);
    }
    else
    {
        PORTB &= ~(1 << PB5);
    }

    bitToSend++;

    if (bitToSend == 228)
    {
        bitToSend = 0;
    }
}
