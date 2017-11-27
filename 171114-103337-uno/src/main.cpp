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
<<<<<<< HEAD
    Serial.begin(9600);
    navigation.screenInit();
    navigation.calibrateScreen();
=======
    gameEngine.gameInit();
    gameEngine.calibrateScreen();
>>>>>>> 193d23370c0477f186f5ad5158b5f85cf9f43c32
    // gameEngine.readFromSDCard("logo.bmp");
    gameEngine.drawStartscreenButtons();
    gameEngine.checkButtonPresses();



    // Serial.begin(9600);

    // DDRB = (1 << PB5);

    // int xOponent = 1, yOponent = 1, xOwn = 1, yOwn = 1;

    // while (1)
    // {
    //     if (xOponent == 4)
    //     {
    //         PORTB = (1 << PB5);
    //     }
    //     else
    //     {
    //         PORTB = 0;
    //     }

    //     c.setLocationPlayer1(xOwn, yOwn);
    //     c.getLocationPlayer2(&xOponent, &xOponent);

    //     xOwn = (xOwn < 9) ? xOwn + 1 : 0;
    //     yOwn = (yOwn < 9) ? yOwn + 1 : 0;


    //     delay(500);

    //     c.sendReceive();
    // }

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