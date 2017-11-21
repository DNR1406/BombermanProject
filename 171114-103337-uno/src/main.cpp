#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "Beeldscherm.h"
#include "ArduinoNunchuk.h"

//Instancis voor de nunchuk en het beelscherm
Beeldscherm bs = Beeldscherm();
ArduinoNunchuk nunchuk = ArduinoNunchuk();

//teller voor timer
volatile uint8_t teller = 0;

//interupt functie
ISR(TIMER2_OVF_vect)
{                                //    macro met interrupt vector
    teller++;
    if ( teller >= 60 )            //    bij elke 60e interrupt ...
    {
        bs.addSecond();
        teller = 0;
    }
}

//functie om timer te initen
void init_timer () {
      TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); //
      TIMSK2 |= (1<<TOIE2);
      TCNT2 = 0;
      sei();                        //    enable interrupts!
}


int main()
{
	init();
	bs.readFromSDCard("credits.bmp");
	bs.drawStartscreenButtons();
	//beelscherm en de nunchuck initen en de timer
	// bs.beelschermInit();
	// nunchuk.init();
	// init_timer();

	// //oneindige loop
	// for(;;) {
	// 	//kijk of er iets veranderd is
	// 	nunchuk.update(); //refresh nunchuk parameters

	// 	//als de zknop ingedrukt is veranderd de kleur
	// 	if(nunchuk.zButton){ // reset scherm mbv Z knop
	// 			bs.changeColor();
	// 		}

	// 	//omhoog & naar beneden
	// 	if(nunchuk.analogY > 155){
	// 		bs.up();
	// 	} else if(nunchuk.analogY < 100){
	// 		bs.down();
	// 	}
	// 	//Links & rechts
	// 	if(nunchuk.analogX > 155){
	// 		bs.right();
	// 	}else if(nunchuk.analogX < 100){
	// 		bs.left();
	// 	}
	// } 
	return 0;
}
