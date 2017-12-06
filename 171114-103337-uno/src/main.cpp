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

//Instancis voor de nunchuk en het beelscherm
// Screen screen = Screen();
Navigation navigation = Navigation();
// ArduinoNunchuk nunchuk = ArduinoNunchuk();

// void testCommunication()
// {

//     Communication c = Communication(1, 1);

//     DDRB |= (1 << PB5);

//     int x, y, bomb;
//     int xO = 0, yO = 0, bombO = 0;

//     while (1)
//     {
//         c.setLocationPlayer1(x, y, bomb);
//         c.getLocationPlayer2(&xO, &yO, &bombO);

//         x++;
//         y++;

//         if (xO == 5 && yO == 6 && bombO == 1)
//         {
//             PORTB |= (1 << PB5);
//         }
//         else
//         {
//             PORTB &= ~(1 << PB5);
//         }

//         bomb = !bomb;
int buffer[210];
volatile int bitToSend;


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
