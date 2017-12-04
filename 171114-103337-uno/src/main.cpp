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

//Instancis voor de nunchuk en het beelscherm
// Screen screen = Screen();
Navigation navigation = Navigation();

void testCommunication()
{

    Communication c = Communication(1, 1);

    int positions[58];

    c.receiveMap(positions);
    Serial.println("ontvangen");

    c.sendMap(positions);
}

int main()
{
    init();
    const byte rxPin = 0;
    const byte txPin = 1;
    
    // set up a new serial object
    SoftwareSerial mySerial(rxPin, txPin);

    Serial.begin(9600);

    //testCommunication();

    navigation.screenInit();
    navigation.calibrateScreen();

    navigation.drawStartscreenButtons();

    return 0;
}
