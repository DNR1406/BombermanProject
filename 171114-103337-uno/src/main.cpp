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


void testCommunication() {

  Communication c = Communication(1, 1);

    int positions[58];
    
    c.receiveMap(positions);
    Serial.println("ontvangen");

    c.sendMap(positions);
}



int main()
{
    init();
    Serial.begin(9600);

    //testCommunication();

    navigation.screenInit();
    navigation.calibrateScreen();



    // Serial.begin(9600);

    navigation.drawStartscreenButtons();


    return 0;
}
