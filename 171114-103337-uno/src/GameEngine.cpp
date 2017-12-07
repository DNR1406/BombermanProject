#include "include.h"

//Constructor
Map grid = Map();
Screen screen = Screen();
Communication c = Communication(1, 1);
PlayerMovement player = PlayerMovement(121, 36);
ArduinoNunchuk nunchuk = ArduinoNunchuk();

GameEngine::GameEngine()
{
}

// startGame function
void GameEngine::startGame()
{
    this->nunchuk = new ArduinoNunchuk();
    int positions[59] = {};
    // draws grid on screen
    grid.drawGrid();
    grid.declareBarrels(55, positions);

    // int barrels[58];

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
    // lcd.drawText(100, 20, "WERKEN", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    int lifes = 3;
    wall *walls = (wall *)(malloc(sizeof(wall[16])));
    grid.getImmovableObjects(walls);
    // for (int i = 0; i < 16; i++)
    // {
    //     Serial.print(walls[i].x);
    //     Serial.print(" ");
    //     Serial.println(walls[i].y);
    // }
    int i = 0;



    // player.x != walls[i].x && player.y != walls[i].y
    while ((player.x != walls[i].x -5 && player.y != walls[i].y -5))
    {

       

        // Check if state of nunchuk had changed
        nunchuk->update(); //Update nunchuk conditions

        //Place bomb if zButton has been pressed
        if (nunchuk->zButton)
        {
            //    lcd.fillCircle(player.x, player.y, 5, RGB(0, 0, 0));
        }

        // Move player upwards
        else if (nunchuk->analogY > 155)
        {   
        
            player.up();
        }
        //Move player downwards
        else if (nunchuk->analogY < 100)
        {
            player.down();
        }
        //Move player to the right
        else if (nunchuk->analogX > 155)
        {
            player.right();
        }
        //Move player to the left
        else if (nunchuk->analogX < 100)
        {
            player.left();
        }
        i++;
        if (i == 16) {
            i = 0;
        } 
    }
}
