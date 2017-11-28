#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "include.h"
#include <Arduino.h>

//Instancis voor de nunchuk en het beelscherm
// Screen screen = Screen();
ArduinoNunchuk nunchuk = ArduinoNunchuk();
Navigation navigation = Navigation();

int main()
{
    init();
    Serial.begin(9600);
    navigation.screenInit();
    navigation.calibrateScreen();
<<<<<<< HEAD
    navigation.drawStartscreenButtons();



    // Serial.begin(9600);
=======
>>>>>>> 9d02f8a774d619946e7f56a49acd695db94de6ac

    navigation.drawStartscreenButtons();


    return 0;
}

// stuff----------------------------------------------------------------------------------
/*
    gameEngine.gameInit();
    gameEngine.calibrateScreen();
    // gameEngine.readFromSDCard("logo.bmp");
    gameEngine.drawStartscreenButtons();
    gameEngine.checkButtonPresses();
*/

//variable for counterTimer2
volatile uint32_t counterTimer2 = 0;
//interupt functie
//ISR(TIMER2_COMPA_vect)
//{
//     counterTimer2++;

//     if (counterTimer2 == 1000) //Ten times per sec.
//     {
//         c.receiveLocationPlayer2();
//         c.sendLocationPlayer1();

//         Serial.println("interrupt: " + String(c.xPlayer1));
//         PORTB ^= (1 << PB5);
//         counterTimer2 = 0;
//     }
//}