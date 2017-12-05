#ifndef include_H
#define include_H

/*---------------------------------------------------------------------------
If you use a define, put it here: */
#define DEBUG 1
    /*
    Gebruik debug variable zo:
    #ifdef DEBUG
    #if (DEBUG == 1)
    printf("Debug");
    #endif
    */

#define ADDRESS 0x52
#define SD_CS   8


/*---------------------------------------------------------------------------
If you create a header file, put it here: */
#include "ArduinoNunchuk.h"
#include "Bomb.h"
#include "Communication.h"
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Screen.h"
#include "Options.h"
#include <SPI.h>
#include <Arduino.h>
#include "Functions.h"
#include "PlayerMovement.h"


#include <MI0283QT9.h>
#include "Navigation.h"



/*---------------------------------------------------------------------------
If you use a struct, put it here: */
typedef struct location {
   int x, y;
} location;





#endif