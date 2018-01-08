// Own includes
#include "Map.hpp"
#include "Screen.hpp"
#include "PlayerMovement.hpp"
#include "Globals.hpp"
#include "ArduinoNunchuk.hpp"
#include "GameEngine.hpp"
#include "Functions.hpp"
#include "Bomb.hpp"
#include "Communication/CommunicationIR.hpp"
#include "Drawings.hpp"

// Other includes
#include <EEPROM.h>
#include <avr/interrupt.h>
#include <Arduino.h>

GameEngine::GameEngine()
{
    this->playMap = new Map();
    this->screen = new Screen();
    this->nunchuk = new ArduinoNunchuk();

    for (uint8_t i = 0; i < BOMBS; i++)
    {
        this->bombsPlayer1[i] = (Bomb *)malloc(sizeof(Bomb *));
        this->bombsPlayer1[i] = new Bomb(15, 15, 0);
    }

    for (uint8_t i = 0; i < BOMBS; i++)
    {
        this->bombsPlayer2[i] = (Bomb *)malloc(sizeof(Bomb *));
        this->bombsPlayer2[i] = new Bomb(15, 15, 0);
    }
}

// startGame function
void GameEngine::startGame(int amount, uint8_t frequenty)
{
    init_timer2();
    startCommunication(frequenty);
    sei();

    uint8_t seed = this->playMap->single_sample();
    uint8_t level = 3;

    if (amount == 18)
    {
        level = 1;
    }
    else if (amount == 36)
    {
        level = 2;
    }

#ifndef SINGLEPLAYER

    while (!sendMap(seed, level))
        ;

#endif

    // draws playMap on screen
    this->playMap->drawPlayMap();
    // Declare the barrels and draw them on the screen
    this->playMap->declareBarrels(amount, seed);

    // for (int i = 0; i < 9; i++)
    // {
    //     for (int j = 0; j < 9; j++)
    //     {
    //         Serial.print(this->playMap->barrels[i][j]);
    //         Serial.print(" ");
    //     }
    //     Serial.println();
    // }

    this->player1 = new PlayerMovement(0, 0, 1);
    this->player2 = new PlayerMovement(8, 8, 2);

    // Draw player one
    this->player1->draw(1);
    this->player2->draw(2);

    // Check what the player is doing, i.e. moving the joystick, pressing buttons, etc.
    this->checkPlayerActions();
    this->writeScoreToEEPROM(this->player1->getScore());
    this->player = player;
}

// startGame function
void GameEngine::startGame(uint8_t frequenty)
{
    init_timer2();
    startCommunication(frequenty);
    sei();

    uint8_t seed = 0, level = 0, amount = 55;

    getMap(&seed, &level);

    if (level == 1)
    {
        amount = 18;
    }
    else if (level == 2)
    {
        amount = 36;
    }

    // draws playMap on screen
    this->playMap->drawPlayMap();
    // Declare the barrels and draw them on the screen
    this->playMap->declareBarrels(amount, seed);

    this->player1 = new PlayerMovement(8, 8, 1);
    this->player2 = new PlayerMovement(0, 0, 2);

    // Draw player one
    this->player1->draw(1);
    this->player2->draw(2);

    // Check what the player is doing, i.e. moving the joystick, pressing buttons, etc.
    this->checkPlayerActions();
    this->writeScoreToEEPROM(this->player1->getScore());
    this->player = player;
}

void GameEngine::endGameScreen()
{
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(110, 130, "YOU LOSE", RGB(0, 0, 0), RGB(160, 182, 219), 2);
}

void GameEngine::checkPlayerActions()
{
    this->player1->updateScore();
    this->player1->updateLives();
    this->player2->updateLives();
    // Inits the nunchuk and reads its data
    this->nunchuk->init();

    // Set all leds
    PORTD |= (1 << PORTD3);
    PORTD |= (1 << PORTD4);
    PORTB |= (1 << PORTB2);

    this->player1->setScore(1);
    this->player2->setScore(1);

    while (this->player1->getLifes() && this->player2->getLifes())
    {
        // Update player 1
        this->updatePlayer1();
// Update player 2
#ifndef SINGLEPLAYER
        this->updatePlayer2();
#endif
        // Check if bombs are exploded
        this->checkBombs();
// Send location of own player
#ifndef SINGLEPLAYER
        setPlayer1(this->player1->x, this->player1->y);
#endif
    }
}

void GameEngine::checkBombs()
{
    // Loop trough bombs of player1
    for (uint8_t bombPlace = 0; bombPlace < BOMBS; bombPlace++)
    {
        // If bomb can be deleted
        if (this->bombsPlayer1[bombPlace]->checkDetonation(this->playMap->barrels))
        {
            // Delete the bomb, make the bomb dissapear as a barrel instance and make bombPlaced 0
            deleteBomb(this->bombsPlayer1, bombPlace, this->player1);
        }
    }
    // Loop troug bombs of player 2
    for (uint8_t bombPlace = 0; bombPlace < BOMBS; bombPlace++)
    {
        // Draw bomb
        this->playMap->placeBomb(this->bombsPlayer2[bombPlace]->returnXlocation(), this->bombsPlayer2[bombPlace]->returnYlocation());

        // Check if bomb can be deleted
        if (this->bombsPlayer2[bombPlace]->checkDetonation(this->playMap->barrels))
        {
            // Delete the bomb, make the bomb dissapear as a barrel instance and make bombPlaced 0
            deleteBomb(this->bombsPlayer2, bombPlace, this->player2);
        }
    }
}

void GameEngine::deleteBomb(Bomb **bombs, uint8_t bombPlace, PlayerMovement *player)
{
    // Set score by player
    player->setScore(player->getScore() + this->playMap->explosion(bombs[bombPlace]->returnXlocation(), bombs[bombPlace]->returnYlocation()));
    player->updateScore();

    // Converting x and y position to lcd screen pixel  position
    deleteBombFromScreen(bombs[bombPlace]->returnXlocation(), bombs[bombPlace]->returnYlocation(), this->playMap->barrels);

    // Checks if the location of the player is in the radius of the bomb
    checkPlayerDamage(bombs, bombPlace, this->player1);
    checkPlayerDamage(bombs, bombPlace, this->player2);

    // Bomb is set to zero in array
    this->playMap->barrels[bombs[bombPlace]->returnXlocation()][bombs[bombPlace]->returnYlocation()] = 0;

    // Set bomb settings to defuault
    bombs[bombPlace]->setExploded(1);
    bombs[bombPlace]->setTime(0);
    bombs[bombPlace]->setXlocation(15);
    bombs[bombPlace]->setYlocation(15);
}

void GameEngine::checkPlayerDamage(Bomb **bombs, uint8_t bombPlace, PlayerMovement *player)
{
    uint8_t damage;
    if (player->x == bombs[bombPlace]->returnXlocation() + 1 && player->y == bombs[bombPlace]->returnYlocation())
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() - 1 && player->y == bombs[bombPlace]->returnYlocation())
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() && player->y == bombs[bombPlace]->returnYlocation())
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() && player->y == bombs[bombPlace]->returnYlocation() + 1)
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() && player->y == bombs[bombPlace]->returnYlocation() - 1)
    {
        damage = 1;
    }

    else if (player->x == bombs[bombPlace]->returnXlocation() - 2 && player->y == bombs[bombPlace]->returnYlocation() && this->playMap->barrels[bombs[bombPlace]->returnXlocation() - 1][bombs[bombPlace]->returnYlocation()] != 2)
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() + 2 && player->y == bombs[bombPlace]->returnYlocation() && this->playMap->barrels[bombs[bombPlace]->returnXlocation() + 1][bombs[bombPlace]->returnYlocation()] != 2)
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() && player->y == bombs[bombPlace]->returnYlocation() + 2 && this->playMap->barrels[bombs[bombPlace]->returnXlocation()][bombs[bombPlace]->returnYlocation() + 1] != 2)
    {
        damage = 1;
    }
    else if (player->x == bombs[bombPlace]->returnXlocation() && player->y == bombs[bombPlace]->returnYlocation() - 2 && this->playMap->barrels[bombs[bombPlace]->returnXlocation()][bombs[bombPlace]->returnYlocation() - 1] != 2)
    {
        damage = 1;
    }
    else
    {
        damage = 0;
    }

    if (damage)
    {
        if (player->getScore() - 13 < 0)
        {
            player->setScore(1);
        }
        else
        {
            player->setScore(player->getScore() - 13);
        }

        // Decrease player's life
        player->setLifes(player->getLifes() - 1);
        player->updateLives();
    }
}

void GameEngine::readDataFromEEPROM()
{
    //Niet gebruikt?
    // byte value = EEPROM.read(50);
}

void GameEngine::writeScoreToEEPROM(int score)
{
    // Initializes the used address
    int addr1 = 50;

    // Writes each part of the score to their address
    EEPROM.write(addr1, score + 1);
}

// Function to add bomb, returns 0 if there is no bomb added, otherwise the location +1 of the bomb
uint8_t GameEngine::addBomb(uint8_t x, uint8_t y)
{
    // Check if bomb is already placed
    for (uint8_t i = 0; i < BOMBS; i++)
    {
        if ((this->bombsPlayer1[i]->returnXlocation() == x) && (this->bombsPlayer1[i]->returnYlocation() == y))
        {
            return i + 1;
        }
    }

#ifndef SINGLEPLAYER
    // Send bomb to opponent
    setBombPlayer2(x, y);
#endif

    for (uint8_t i = 0; i < BOMBS; i++)
    {
        if ((this->bombsPlayer1[i]->readyForNew(x, y)))
        {
            this->bombsPlayer1[i]->setXlocation(x);
            this->bombsPlayer1[i]->setYlocation(y);
            this->bombsPlayer1[i]->setTime(counterTimer2);
            this->bombsPlayer1[i]->setExploded(0);

            return i + 1;
        }
    }

    return 0;
}

void GameEngine::updatePlayer1()
{
    uint8_t bombPlace;
    uint8_t playerOverWalk;

    this->player1->upMove = true;
    this->player1->downMove = true;
    this->player1->leftMove = true;
    this->player1->rightMove = true;

    // If player is on 2nd (1) 4th (3) or 6th (5) or 8th (7) row from x, they can
    // Never move up or down
    if ((this->player1->x % 2) && !(this->player1->y % 2))
    {
        this->player1->upMove = false;
        this->player1->downMove = false;
    }
    else
    {
        // If player is on the 1st (0) from y they can never move up or If there is a barrel on the top side of the player
        if (!this->player1->y || this->playMap->barrels[this->player1->x][this->player1->y - 1] == 1 || this->playMap->barrels[this->player1->x][this->player1->y - 1] == 5)
        {
            this->player1->upMove = false;
        }
        //

        // If player is on the 9th (8) row from y they can never move down or If there is a barrel on the bottom side of the player
        if (this->player1->y == 8 || this->playMap->barrels[this->player1->x][this->player1->y + 1] == 1 || this->playMap->barrels[this->player1->x][this->player1->y + 1] == 5)
        {
            this->player1->downMove = false;
        }
    }

    // If player is on 2nd (1), 4th (3), 6th (5) or 8th (7) row from y, they can
    // Never move left or right
    if (!(this->player1->x % 2) && (this->player1->y % 2))
    {
        this->player1->rightMove = false;
        this->player1->leftMove = false;
    }
    else
    {
        // If player is on 9th (8) row from x they can never move right, or if there is a barrel on the right side of the player
        if (this->player1->x == 8 || this->playMap->barrels[this->player1->x + 1][this->player1->y] == 1 || this->playMap->barrels[this->player1->x + 1][this->player1->y] == 5)
        {
            this->player1->rightMove = false;
        }

        // If player is on 1st (0) row from x they can never move left or If there is a barrel on the left side of the player
        if (!this->player1->x || this->playMap->barrels[this->player1->x - 1][this->player1->y] == 1 || this->playMap->barrels[this->player1->x - 1][this->player1->y] == 5)
        {
            this->player1->leftMove = false;
        }
    }

    // Check if state of nunchuk had changed
    nunchuk->update();

    //Place bomb if zButton has been pressed
    if (nunchuk->zButton)
    {

        bombPlace = this->addBomb(this->player1->x, this->player1->y);

        if (bombPlace)
        {
            bombPlace--;
            // Make sure player can't walk over bomb
            this->playMap->barrels[this->bombsPlayer1[bombPlace]->returnXlocation()][this->bombsPlayer1[bombPlace]->returnYlocation()] = 5;

            // Draw the bomb on the screen
            this->playMap->placeBomb(this->bombsPlayer1[bombPlace]->returnXlocation(), this->bombsPlayer1[bombPlace]->returnYlocation());

            bombPlace++;
        }
    }

    if (this->playMap->barrels[this->player1->x][this->player1->y] == 5)
    {
        bombPlace = 1;
    }

    if (this->player1->x == this->player2->x && this->player1->y == this->player2->y)
    {
        playerOverWalk = 1;
    }
    else
    {
        playerOverWalk = 0;
    }

    // Move player upwards
    if (nunchuk->analogY > 155 && this->player1->upMove)
    {
        this->player1->up(bombPlace, playerOverWalk, 1);
        bombPlace = 0;
        playerOverWalk = 0;
    }
    //Move player downwards
    else if (nunchuk->analogY < 100 && this->player1->downMove)
    {
        this->player1->down(bombPlace, playerOverWalk, 1);
        bombPlace = 0;
        playerOverWalk = 0;
    }
    //Move player to the right
    else if (nunchuk->analogX > 155 && this->player1->rightMove)
    {
        this->player1->right(bombPlace, playerOverWalk, 1);
        bombPlace = 0;
        playerOverWalk = 0;
    }
    //Move player to the left
    else if (nunchuk->analogX < 100 && this->player1->leftMove)
    {
        this->player1->left(bombPlace, playerOverWalk, 1);
        bombPlace = 0;
        playerOverWalk = 0;
    }
}
// Get data of opponent
void GameEngine::updatePlayer2()
{
    // Delete player
    this->player2->clearPlayer();

    // Get new data
    getPlayer2(&this->player2->x, &this->player2->y);

    // Draw player 2
    this->player2->draw(2);

    // Get bombs from opponent, put them in this->bombsPlayer2
    getBombsPlayer2(this->bombsPlayer2);
}
