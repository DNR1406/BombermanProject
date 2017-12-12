#include "include.h"

//Constructor
Map playMap = Map();
Screen screen = Screen();
Communication c = Communication(1, 1);
PlayerMovement player = PlayerMovement(8, 8);
ArduinoNunchuk nunchuk = ArduinoNunchuk();

GameEngine::GameEngine()
{
}

// startGame function
void GameEngine::startGame(int amount)
{
    this->nunchuk = new ArduinoNunchuk();

    // draws playMap on screen 
    playMap.drawPlayMap();

    // Declare the barrels and draw them on the screen
    playMap.declareBarrels(amount);
    

    // c.receiveMap(barrels);
    // playMap.getBarrels(barrels);

    // c.sendMap(positions)

    // Draw player one
    player.draw();

    // Check what the player is doing, i.e. moving the joystick, pressing buttons, etc.
    checkPlayerActions();
}

// function to add players to the game
void GameEngine::addPlayer()
{
    // Player(); from player Class
}

// function to select level
void GameEngine::selectLevel()
{
}

// functie to increment player score
void GameEngine::incrementScore()
{
}

void GameEngine::checkPlayerActions()
{
    nunchuk->init();
    uint8_t lifes = 3;

    uint8_t bombPlaced; 
    while (lifes)
    {
        player.upMove = true;
        player.downMove = true;
        player.leftMove = true;
        player.rightMove = true;

        // If there is a barrel on the right side of the player
        if (playMap.barrels[player.x + 1][player.y] == 1)
        {
            player.rightMove = false;
        }

        // If there is a barrel on the left side of the player
        if (playMap.barrels[player.x - 1][player.y] == 1)
        {
            player.leftMove = false;
        }

        // If there is a barrel on the bottom side of the player
        if (playMap.barrels[player.x][player.y + 1] == 1)
        {
            player.downMove = false;
        }

        // If there is a barrel on the top side of the player
        if (playMap.barrels[player.x][player.y - 1] == 1)
        {
            player.upMove = false;
        }

        // If player is on 2nd (1) 4th (3) or 6th (5) or 8th (7) row from x, they can
        // Never move up or down
        if ((player.x % 2) && !(player.y % 2))
        {
            player.upMove = false;
            player.downMove = false;
        }

        // If player is on 1st (0) row from x they can never move left
        if (!player.x)
        {
            player.leftMove = false;
        }

        // If player is on 9th (8) row from x they can never move right
        if (player.x == 8)
        {
            player.rightMove = false;
        }

        // If player is on 2nd (1), 4th (3), 6th (5) or 8th (7) row from y, they can
        // Never move left or right
        if (!(player.x % 2) && (player.y % 2))
        {
            player.rightMove = false;
            player.leftMove = false;
        }

        // If player is on the 1st (0) from y they can never move up
        if (!player.y)
        {
            player.upMove = false;
        }

        // If player is on the 9th (8) row from y they can never move down
        if (player.y == 8)
        {
            player.downMove = false;
        }

        // Check if state of nunchuk had changed
        nunchuk->update(); //Update nunchuk conditions

        //Place bomb if zButton has been pressed
        if (nunchuk->zButton)
        {
            playMap.placeBomb(player.x, player.y);
            bombPlaced = 1;

            // if timer is 1 or 2 seconds
            // If there is a barrel on the right side of the player

            if (playMap.barrels[player.x + 1][player.y] == 1)
            {
                if (player.x < 8)
                {
                    playMap.deleteBarrels(player.x + 1, player.y);
                }
            }

            // If there is a barrel on the left side of the player
            if (playMap.barrels[player.x - 1][player.y] == 1)
            {
                if (player.x)
                {
                    playMap.deleteBarrels(player.x - 1, player.y);
                }
            }

            // If there is a barrel on the bottom side of the player
            if (playMap.barrels[player.x][player.y + 1] == 1)
            {
                if (player.y < 8)
                {
                    playMap.deleteBarrels(player.x, player.y + 1);
                }
            }

            // If there is a barrel on the top side of the player
            if (playMap.barrels[player.x][player.y - 1] == 1)
            {
                if (player.y)
                {
                    playMap.deleteBarrels(player.x, player.y - 1);
                }
            }
        }

        // Move player upwards
        else if (nunchuk->analogY > 155 && player.upMove)
        {
            player.up(bombPlaced);
            bombPlaced = 0;
        }
        //Move player downwards
        else if (nunchuk->analogY < 100 && player.downMove)
        {
            player.down(bombPlaced);
            bombPlaced = 0;
        }
        //Move player to the right
        else if (nunchuk->analogX > 155 && player.rightMove)
        {
            player.right(bombPlaced);
            bombPlaced = 0;
        }
        //Move player to the left
        else if (nunchuk->analogX < 100 && player.leftMove)
        {
            player.left(bombPlaced);
            bombPlaced = 0;
        }
        Serial.println(freeRam());
    }
}
int GameEngine::freeRam()
{
    extern int __heap_start, *__brkval;
    int v;
    return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}