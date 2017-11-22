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


/*---------------------------------------------------------------------------
If you create a header file, put it here: */
#include "ArduinoNunchuk.h"
#include "Bomb.h"
#include "Communication.h"
#include "GameEngine.h"
#include "Map.h"
#include "Player.h"
#include "Screen.h"
#include "Settings.h"

/*---------------------------------------------------------------------------
If you use a struct, put it here: */
typedef struct location {
   int x, y;
} location;




