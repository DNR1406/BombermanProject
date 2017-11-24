#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "include.h"

//Instancis voor de nunchuk en het beelscherm
// Screen screen = Screen();
ArduinoNunchuk nunchuk = ArduinoNunchuk();
Navigation navigation = Navigation();

//teller voor timer
volatile uint8_t teller = 0;

//interupt functie
// ISR(TIMER2_OVF_vect)
// {                                //    macro met interrupt vector
//     teller++;
//     if ( teller >= 60 )            //    bij elke 60e interrupt ...
//     {
//         screen.addSecond();
//         teller = 0;
//     }
// }

//functie om timer te initen
// void init_timer () {
//       TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); //
//       TIMSK2 |= (1<<TOIE2);
//       TCNT2 = 0;
//       sei();                        //    enable interrupts!
// }

int main()
{
    init();
    navigation.screenInit();
    navigation.calibrateScreen();
    // gameEngine.readFromSDCard("logo.bmp");
    navigation.drawStartscreenButtons();
    navigation.checkButtonPresses();

    return 0;
}
