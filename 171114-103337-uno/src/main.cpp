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
Navigation navigation = Navigation();
BMPLoader bmpLoader = BMPLoader();
Options highscore = Options();

void testCommunication()
{

<<<<<<< HEAD
    DDRB |= (1 << PB5);

    Communication c = Communication(1, 1);

    int x, y, bomb;
    int xO = 0, yO = 0, bombO = 0;

    while (1)
    {
        c.setLocationPlayer1(x, y, bomb);
        c.getLocationPlayer2(&xO, &yO, &bombO);

        x++;
        y++;

        if (xO == 5 && yO == 6 && bombO == 1)
        {
            PORTB |= (1 << PB5);
        }
        else
        {
            PORTB &= ~(1 << PB5);
        }

        bomb = !bomb;

        c.sendReceive();
        delay(500);
    }
=======
  Communication c = Communication(1, 1);

    int positions[58];
    
    c.receiveMap(positions);
    Serial.println("ontvangen");

    c.sendMap(positions);
>>>>>>> df7f83ee9ccb812d288b1a44e55623c6f9d63b7c
}

int main()
{
    init();
    Serial.begin(9600);

    //testCommunication();

    navigation.screenInit();
    // highscore.readHighscoreFile();
    navigation.calibrateScreen();
    bmpLoader.readFromSDCard("logo.bmp");
    // navigation.readHighscoreFile();
    // navigation.drawStartscreenButtons();

    return 0;
}
<<<<<<< HEAD

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
=======
>>>>>>> df7f83ee9ccb812d288b1a44e55623c6f9d63b7c
