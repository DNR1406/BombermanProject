#ifndef include_H
#define include_H

/*---------------------------------------------------------------------------
If you create a header file, put it here: */
#include "Communication/Communication.h"
#include "Communication/CommunictaionIR.h"
#include "Navigation/Navigation.h"
#include "Navigation/NavigationScreen.h"

#include "ArduinoNunchuk.h"
#include "Bomb.h"
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Screen.h"
#include "Options.h"
#include "PlayerMovement.h"

#include "Functions.h"

//other
#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <EEPROM.h>

#include <stdint.h>


/*---------------------------------------------------------------------------
global variables */

extern volatile uint8_t buffer[362];
extern volatile uint8_t bitToSend;
extern volatile uint8_t send;
extern volatile uint32_t counterTimer2;


#endif