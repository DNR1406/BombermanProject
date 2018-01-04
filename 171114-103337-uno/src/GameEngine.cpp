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

//Total score player 1
int score = 0;

GameEngine::GameEngine()
{
}

// startGame function
void GameEngine::startGame(int amount)
{
    this->nunchuk = new ArduinoNunchuk();

    for (uint8_t i = 0; i < BOMBS; i++)
    {
        this->bombs[i] = (Bomb *)malloc(sizeof(Bomb *));
        this->bombs[i] = new Bomb(15, 15, 0);
    }

    // draws playMap on screen
    playMap.drawPlayMap();

    // Declare the barrels and draw them on the screen
    playMap.declareBarrels(amount);

    // Draw player one
    player.draw();

    // Check what the player is doing, i.e. moving the joystick, pressing buttons, etc.
    checkPlayerActions();
    writeScoreToEEPROM(score);
    // readDataFromEEPROM();
    // endGameScreen();
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

void GameEngine::endGameScreen()
{
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(110, 130, "YOU LOSE", RGB(0, 0, 0), RGB(160, 182, 219), 2);
}

void GameEngine::checkPlayerActions()
{

    updateScore(score);
    updateLifes();
    // Inits the nunchuk and reads its data
    nunchuk->init();

    uint8_t bombPlace = 0;

    // Set all leds
    PORTD |= (1 << PORTD3);
    PORTD |= (1 << PORTD4);
    PORTB |= (1 << PORTB2);
    score = 1;
    while (this->lifes)
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
        else
        {
            // If player is on the 1st (0) from y they can never move up or If there is a barrel on the top side of the player
            if (!player.y || playMap.barrels[player.x][player.y - 1] == 1 || playMap.barrels[player.x][player.y - 1] == 5)
            {
                player.upMove = false;
            }
            //

            // If player is on the 9th (8) row from y they can never move down or If there is a barrel on the bottom side of the player
            if (player.y == 8 || playMap.barrels[player.x][player.y + 1] == 1 || playMap.barrels[player.x][player.y + 1] == 5)
            {
                player.downMove = false;
            }
        }

        // If player is on 2nd (1), 4th (3), 6th (5) or 8th (7) row from y, they can
        // Never move left or right
        if (!(player.x % 2) && (player.y % 2))
        {
            player.rightMove = false;
            player.leftMove = false;
        }
        else
        {
            // If player is on 9th (8) row from x they can never move right, or if there is a barrel on the right side of the player
            if (player.x == 8 || playMap.barrels[player.x + 1][player.y] == 1 || playMap.barrels[player.x + 1][player.y] == 5)
            {
                player.rightMove = false;
            }

            // If player is on 1st (0) row from x they can never move left or If there is a barrel on the left side of the player
            if (!player.x || playMap.barrels[player.x - 1][player.y] == 1 || playMap.barrels[player.x - 1][player.y] == 5)
            {
                player.leftMove = false;
            }
        }

        // Check if state of nunchuk had changed
        nunchuk->update();

        //Place bomb if zButton has been pressed
        if (nunchuk->zButton)
        {
            bombPlace = this->addBomb(player.x, player.y);

            if (bombPlace)
            {
                bombPlace--;
                // Make sure player can't walk over bomb
                playMap.barrels[this->bombs[bombPlace]->returnXlocation()][this->bombs[bombPlace]->returnYlocation()] = 5;

                // Draw the bomb on the screen
                playMap.placeBomb(this->bombs[bombPlace]->returnXlocation(), this->bombs[bombPlace]->returnYlocation());

                bombPlace++;
            }
        }

        // Move player upwards
        if (nunchuk->analogY > 200 && player.upMove)
        {
            player.up(bombPlace);
            bombPlace = 0;
        }
        //Move player downwards
        else if (nunchuk->analogY < 55 && player.downMove)
        {
            player.down(bombPlace);
            bombPlace = 0;
        }
        //Move player to the right
        else if (nunchuk->analogX > 155 && player.rightMove)
        {
            player.right(bombPlace);
            bombPlace = 0;
        }
        //Move player to the left
        else if (nunchuk->analogX < 100 && player.leftMove)
        {
            player.left(bombPlace);
            bombPlace = 0;
        }

        for (uint8_t bombPlace = 0; bombPlace < BOMBS; bombPlace++)
        {
            if (this->bombs[bombPlace]->checkDetonation())
            {
                this->bombs[bombPlace]->setExploded(1);
                score += playMap.explosion(this->bombs[bombPlace]->returnXlocation(), this->bombs[bombPlace]->returnYlocation());

                // Delete the bomb, make the bomb dissapear as a barrel instance and make bombPlaced 0
                deleteBomb(bombPlace);
                updateScore(score);
                updateLifes();
            }
        }
    }
}

void GameEngine::deleteBomb(uint8_t bombPlace)
{
    // Converting x and y position to lcd screen pixel position
    int x = 120 + (this->bombs[bombPlace]->returnXlocation() * 21);
    int y = 35 + (this->bombs[bombPlace]->returnYlocation() * 21);
    lcd.fillCircle(x, y, 8, RGB(29, 79, 22));

    // Checks if the location of the player is in the radius of the bomb
    if (checkPlayerDamage(bombPlace))
    {
        if (score - 13 < 0)
        {
            score = 1;
        }
        else
        {
            score -= 13;
        }
        updateScore(score);

        // Decrease player's life
        this->lifes--;

        // Putting leds out
        if (lifes == 2)
        {
            PORTB &= ~(1 << PORTB2);
        }
        else if (lifes == 1)
        {
            PORTD &= ~(1 << PORTD4);
        }
        else
        {
            PORTD &= ~(1 << PORTD3);
        }
    }

    playMap.barrels[this->bombs[bombPlace]->returnXlocation()][this->bombs[bombPlace]->returnYlocation()] = 0;

    // Setting bomb location to 15,15 so it's out of the radius
    this->bombs[bombPlace]->setXlocation(15);
    this->bombs[bombPlace]->setYlocation(15);
}

uint8_t GameEngine::checkPlayerDamage(uint8_t bombPlace)
{

    // Checks if the player in within the range of the bombs at detonation
    if (player.x == this->bombs[bombPlace]->returnXlocation() + 1 && player.y == this->bombs[bombPlace]->returnYlocation())
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() - 1 && player.y == this->bombs[bombPlace]->returnYlocation())
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() && player.y == this->bombs[bombPlace]->returnYlocation())
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() && player.y == this->bombs[bombPlace]->returnYlocation() + 1)
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() && player.y == this->bombs[bombPlace]->returnYlocation() - 1)
    {
        return 1;
    }

    else if (player.x == this->bombs[bombPlace]->returnXlocation() - 2 && player.y == this->bombs[bombPlace]->returnYlocation() && playMap.barrels[this->bombs[bombPlace]->returnXlocation() - 1][this->bombs[bombPlace]->returnYlocation()] != 2)
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() + 2 && player.y == this->bombs[bombPlace]->returnYlocation() && playMap.barrels[this->bombs[bombPlace]->returnXlocation() + 1][this->bombs[bombPlace]->returnYlocation()] != 2)
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() && player.y == this->bombs[bombPlace]->returnYlocation() + 2 && playMap.barrels[this->bombs[bombPlace]->returnXlocation()][this->bombs[bombPlace]->returnYlocation() + 1] != 2)
    {
        return 1;
    }
    else if (player.x == this->bombs[bombPlace]->returnXlocation() && player.y == this->bombs[bombPlace]->returnYlocation() - 2 && playMap.barrels[this->bombs[bombPlace]->returnXlocation()][this->bombs[bombPlace]->returnYlocation() - 1] != 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void GameEngine::readDataFromEEPROM()
{
    byte value = EEPROM.read(50);
}

void GameEngine::writeScoreToEEPROM(int score)
{

    if (score > EEPROM.read(50))
    {
        EEPROM.write(52, EEPROM.read(51));
        EEPROM.write(51, EEPROM.read(50));
        EEPROM.write(50, score + 1);
    }
    else if (score > EEPROM.read(51))
    {
        EEPROM.write(52, EEPROM.read(51));  
        EEPROM.write(51, score + 1);
        }
    else if (score > EEPROM.read(52))
    {
        EEPROM.write(51, score + 1);
    }

    // // Initializes the used address
    // int addr1 = 50;

    // // Writes each part of the score to their address
    // EEPROM.write(addr1, score + 1);
}

void GameEngine::updateScore(int score)
{
    lcd.drawInteger(62, 130, score, DEC, RGB(31, 255, 0), RGB(50, 50, 50), 1);
}

void GameEngine::updateLifes()
{
    lcd.drawInteger(62, 120, this->lifes, DEC, RGB(31, 255, 0), RGB(50, 50, 50), 1);
}

uint8_t GameEngine::addBomb(uint8_t x, uint8_t y)
{
    uint8_t bombPlace, placed;

    for (uint8_t i = 0; i < BOMBS; i++)
    {
        if ((this->bombs[i]->returnXlocation() == x) && (this->bombs[i]->returnYlocation() == y))
        {
            return i + 1;
        }
    }

    for (uint8_t i = 0; i < BOMBS; i++)
    {
        if ((this->bombs[i]->readyForNew(x, y)))
        {
            this->bombs[i]->setXlocation(x);
            this->bombs[i]->setYlocation(y);
            this->bombs[i]->setTime(counterTimer2);
            this->bombs[i]->setExploded(0);

            return i + 1;
        }
    }

    return 0;
}
