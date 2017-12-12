#include "Map.h"
#include "Screen.h"
#include "Communication/Communication.h"
#include "PlayerMovement.h"
#include "ArduinoNunchuk.h"

#include <stdint.h>

#include "Globals.h"

//Constructor
Map playMap = Map();
Screen screen = Screen();
Communication c = Communication(1, 1);
PlayerMovement player = PlayerMovement(8, 8);
ArduinoNunchuk nunchuk = ArduinoNunchuk();

//volatile uint32_t counterTimer2;

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
            if (this->bombPlayer1->returnExploded())
            {
                // Creates new instance of a bomb and saves x, y and last known time
                this->bombPlayer1 = new Bomb(player.x, player.y, counterTimer2);

                playMap.placeBomb(player.x, player.y);
                bombPlaced = 1;
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

        // Runs a timer and executes when timer reaches its limit
        if (bombPlayer1->checkDetonation())
        {
            this->bombPlayer1->setExploded(1);

            // if timer is 1 or 2 seconds
            // If there is a barrel on the right side of the player
            if (playMap.barrels[this->bombPlayer1->returnXlocation() + 1][this->bombPlayer1->returnYlocation()] == 1)
            {
                if (this->bombPlayer1->returnXlocation() < 8)
                {
                    deleteBomb();
                    playMap.deleteBarrels(this->bombPlayer1->returnXlocation() + 1, this->bombPlayer1->returnYlocation());
                }
            }

            // If there is a barrel on the left side of the player
            else if (playMap.barrels[this->bombPlayer1->returnXlocation() - 1][this->bombPlayer1->returnYlocation()] == 1)
            {
                if (this->bombPlayer1->returnXlocation())
                {
                    deleteBomb();
                    playMap.deleteBarrels(this->bombPlayer1->returnXlocation() - 1, this->bombPlayer1->returnYlocation());
                }
            }

            // If there is a barrel on the bottom side of the player
            else if (playMap.barrels[this->bombPlayer1->returnXlocation()][this->bombPlayer1->returnYlocation() + 1] == 1)
            {
                if (this->bombPlayer1->returnYlocation() < 8)
                {
                    deleteBomb();
                    playMap.deleteBarrels(this->bombPlayer1->returnXlocation(), this->bombPlayer1->returnYlocation() + 1);
                }
            }

            // If there is a barrel on the top side of the player
            else if (playMap.barrels[this->bombPlayer1->returnXlocation()][this->bombPlayer1->returnYlocation() - 1] == 1)
            {
                if (this->bombPlayer1->returnYlocation())
                {
                    deleteBomb();
                    playMap.deleteBarrels(this->bombPlayer1->returnXlocation(), this->bombPlayer1->returnYlocation() - 1);
                }
            }
            else
            {
                deleteBomb();
            }
        }
    }
}

void GameEngine::deleteBomb()
{
    int x = 120 + (this->bombPlayer1->returnXlocation() * 21);
    int y = 35 + (this->bombPlayer1->returnYlocation() * 21);
    lcd.fillCircle(x, y, 8, RGB(30, 107, 7));
}
