#include "include.h"

//Constructor
Map grid = Map();
Screen screen = Screen();
Communication c = Communication(1, 1);
PlayerMovement player = PlayerMovement(0, 0);
ArduinoNunchuk nunchuk = ArduinoNunchuk();

GameEngine::GameEngine()
{
}

// startGame function
void GameEngine::startGame()
{
    this->nunchuk = new ArduinoNunchuk();
    // draws grid on screen
    grid.drawGrid();
    grid.declareBarrels(30);

    

    // c.receiveMap(barrels);
    // grid.getBarrels(barrels);

    // c.sendMap(positions)

    player.draw();
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



    // player.x != walls[i].x && player.y != walls[i].y
    while (lifes)
    {
        player.upMove = true;
        player.downMove = true;
        player.leftMove = true;
        player.rightMove = true;

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
            //    lcd.fillCircle(player.x, player.y, 5, RGB(0, 0, 0));
        }

        // Move player upwards
        else if (nunchuk->analogY > 155 && player.upMove)
        {
            player.up();
        }
        //Move player downwards
        else if (nunchuk->analogY < 100 && player.downMove)
        {
            player.down();
        }
        //Move player to the right
        else if (nunchuk->analogX > 155 && player.rightMove)
        {
            player.right();
        }
        //Move player to the left
        else if (nunchuk->analogX < 100 && player.leftMove)
        {
            player.left();
        }
    }
}