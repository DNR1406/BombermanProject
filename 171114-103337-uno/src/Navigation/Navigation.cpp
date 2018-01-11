// Own includes
#include "NavigationScreen.hpp"
#include "Navigation.hpp"
#include "../GameEngine.hpp"

// Other includes
#include <stdint.h>

// Constructor
Navigation::Navigation()
{
    //pointers to instances
    this->gameEngine = new GameEngine();
    this->screen = new NavigationScreen();
}

// Startscreen
void Navigation::drawStartScreen()
{
    // title
    this->screen->drawHeader(F("Bomberman"));

    // Draws start button
    this->screen->drawButton(F("START"), 1, 127, 108);

    // Draws options button
    this->screen->drawButton(F("OPTIONS"), 2, 110, 147);

    // Draws credits button
    this->screen->drawButton(F("CREDITS"), 3, 110, 187);
}

void Navigation::deleteStartScreen()
{
    // delete header of start screen
    this->screen->deleteHeader(F("Bomberman"));
    // delete buttons
    this->screen->deleteButton(1);
    this->screen->deleteButton(2);
    this->screen->deleteButton(3);
}

void Navigation::startStartScreen()
{
    // Draw buttons
    this->drawStartScreen();

    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (!pressed)
    {
        // Check for pressed
        pressed = this->screen->checkTouchscreen();

        // Delete startscreen after something is pressed
        if (pressed == 1 || pressed == 2 || pressed == 3)
        {
            this->deleteStartScreen();
        }

        // Check what to do after pressed
        switch (pressed)
        {
        case 1:
            // Start game
            this->startPlayerSelectScreen();
            this->drawStartScreen();
            pressed = 0;
            break;
        case 2:
            // Start options screen
            this->startOptionsScreen();
            this->drawStartScreen();
            pressed = 0;
            break;
        case 3:
            // Start credits screen
            this->startCreditScreen();
            this->drawStartScreen();
            pressed = 0;
            break;
        };
    }
}

// Options screen
void Navigation::drawOptionsScreen()
{
    //header and back button
    screen->drawBackButton();
    screen->drawHeader(F("  OPTIONS"));

    // Draws Brightness button
    screen->drawButton(F("BRIGHTNESS"), 1, 85, 108);

    // Draws Highscore button
    screen->drawButton(F("HIGHSCORE"), 2, 92, 147);
}

void Navigation::deleteOptionsScreen()
{
    // delete home button in corner of screen.
    this->screen->deleteBackButton();
    // delete headeer from options screen
    this->screen->deleteHeader(F("OPTIONS"));
    // delete buttons
    this->screen->deleteButton(1);
    this->screen->deleteButton(2);
    this->screen->deleteButton(3);
}

void Navigation::startOptionsScreen()
{
    // Draw buttons for optionscreen
    this->drawOptionsScreen();

    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (!pressed)
    {
        // Check for press
        pressed = this->screen->checkTouchscreen();

        // If anyting is pressed, delete options screen
        if (pressed)
        {
            this->deleteOptionsScreen();
        }

        // Check what is pressed
        switch (pressed)
        {
        case 1:
            // Start brightness Screen
            this->startBrightnessScreen();
            this->drawOptionsScreen();
            pressed = 0;
            break;
        case 2:
            // Highscore
            this->startHighScoreScreen();
            this->drawOptionsScreen();
            pressed = 0;
            break;
        case 3:
            break;
        case 4:
            // Go back
            return;
            break;
        };
    }
}

// Void to draw highscors 
void Navigation::drawHighscoreScreen()
{
    this->screen->drawHeader(F("HIGHSCORE"));
    this->screen->drawBackButton();
    this->screen->drawButton(F("Delete High"), 3, 80, 187);
    this->screen->readHighscoreFromEEPROM();
}

// Void to start highscores screen
void Navigation::startHighScoreScreen()
{
    this->drawHighscoreScreen();
    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (!pressed)
    {
        // Check for new press
        pressed = this->screen->checkTouchscreen();
        switch (pressed)
        {
        case 3:
            this->gameEngine->deleteScoreFromEEPROM();
            this->deleteHighScoreScreen();
            break;
        case 4:
            this->deleteHighScoreScreen();
            break;
        };
    }
}

// Credits screen
void Navigation::drawCreditsScreen()
{
    // Draw buttons
    this->screen->drawBackButton();
    this->screen->drawHeader(F("CREDITS"));
    this->screen->drawCredits();
}

// Delete creditsscreen
void Navigation::deleteCreditsScreen()
{
    // Delete buttons
    this->screen->deleteBackButton();
    this->screen->deleteHeader(F("CREDITS"));
    this->screen->deleteCredits();
}


// Delete highscore screen
void Navigation::deleteHighScoreScreen()
{
    this->screen->deleteHeader(F("HIGHSCORE   "));
    this->screen->deleteBackButton();
    this->screen->deleteButton(3);
    this->screen->deleteHighscoreButtons();
}

// Void to start creditsscreen
void Navigation::startCreditScreen()
{
    // Draw credit screen
    this->drawCreditsScreen();

    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (pressed != 4)
    {
        // Check for new press
        pressed = this->screen->checkTouchscreen();
    }
    this->deleteCreditsScreen();
}

// Brightness
void Navigation::drawBrightnessScreen()
{
    // Draw brightness screen
    this->screen->drawHeader(F("BRIGHTNESS"));
    this->screen->drawBackButton();
    this->screen->drawBrightness();
}

void Navigation::deleteBrightnessScreen()
{
    // Delete brightness screen
    this->screen->deleteHeader(F("BRIGHTNESS"));
    this->screen->deleteBackButton();
    this->screen->deleteBrightness();
}

void Navigation::startBrightnessScreen()
{
    // Draw brightness screen
    this->drawBrightnessScreen();

    // variablen for pressed and value
    uint8_t pressed = 0;
    long val = 0;

    // Loop while nothing is pressed
    while (pressed != 4)
    {
        // Check for new press
        pressed = this->screen->checkTouchscreen();

        // Read analog val
        val = this->getAnalogVal() / 10;

        // Set brightness
        this->screen->setBrightness(val);
    }

    this->deleteBrightnessScreen();
}

// Levelscreen
void Navigation::drawLevelScreen()
{
    this->screen->drawHeader(F("SELECT LEVEL"));
    this->screen->drawBackButton();
    this->screen->drawButton(F("LEVEL 1"), 1, 110, 108);
    this->screen->drawButton(F("LEVEL 2"), 2, 110, 147);
    this->screen->drawButton(F("LEVEL 3"), 3, 110, 187);
}

void Navigation::deleteLevelScreen()
{
    this->screen->deleteBackButton();
    this->screen->deleteHeader(F("SELECT LEVEL"));
    this->screen->deleteButton(1);
    this->screen->deleteButton(2);
    this->screen->deleteButton(3);
}

// Select between levels of amount of barrels
void Navigation::startLevelScreen()
{
    this->drawLevelScreen();

    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (!pressed)
    {
        // Check for press
        pressed = this->screen->checkTouchscreen();

        // If anyting is pressed, delete Levels screen
        if (pressed)
        {
            this->deleteLevelScreen();
            this->drawWaitingOnOponnentScreen();
        }

        // Check what is pressed
        switch (pressed)
        {
        case 1:
            // Start game with 18 barrels
            this->gameEngine->startGame(18, 36);
            this->splashScreen();
            this->startStartScreen();
            pressed = 0;
            break;
        case 2:
            // Start game with 36 barrels
            this->gameEngine->startGame(36, 36);
            this->splashScreen();
            this->startStartScreen();
            pressed = 0;
            break;
        case 3:
            // Start game with 55 barrels
            this->gameEngine->startGame(55, 36);
            this->splashScreen();
            this->startStartScreen();
            pressed = 0;
            break;
        case 4:
            // Go back
            return;
            break;
        };
    }
}

// Select payer
void Navigation::drawPlayerSelectScreen()
{
    this->screen->drawHeader(F("SELECT PLAYER"));
    this->screen->drawBackButton();
    this->screen->drawButton(F("PLAYER 1"), 1, 110, 108);
    this->screen->drawButton(F("PLAYER 2"), 2, 110, 147);
}

void Navigation::startPlayerSelectScreen()
{
    this->drawPlayerSelectScreen();

    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (!pressed)
    {
        // Check for press
        pressed = this->screen->checkTouchscreen();

        // If anyting is pressed, delete Levels screen
        if (pressed)
        {
            this->deleteLevelScreen();
        }

        // Check what is pressed
        switch (pressed)
        {
        case 1:
            this->startLevelScreen();
            this->drawPlayerSelectScreen();
            pressed = 0;
            break;
        case 2:
            this->drawWaitingOnOponnentScreen();
            this->gameEngine->startGame(56);
            this->splashScreen();
            pressed = 0;
            break;
        case 4:
            // Go back
            return;
            break;
        };
    }
}

// After player selecteted which player he is, it is deleted
void Navigation::deletePlayerSelectScreen()
{
    this->screen->deleteBackButton();
    this->screen->deleteHeader(F("                  "));
    this->screen->deleteButton(1);
    this->screen->deleteButton(2);
}

// Get analog value from pin 1..
int Navigation::getAnalogVal()
{
    uint16_t result;
    // Start conversion
    ADCSRA |= (1 << ADSC);
    // Wait
    while (ADCSRA & (1 << ADSC))
;
    result = ADC;
    return result;
}


// Void to draw waiting on oponend
void Navigation::drawWaitingOnOponnentScreen()
{
    this->screen->drawHeader(F("Waiting...     "));
}

// After game is finished, you lose/you win
void Navigation::splashScreen()
{
    this->screen->lcd.fillRect(0, 0, 320, 240, RGB(160, 182, 219));
    this->screen->drawBackButton();

    if (this->gameEngine->getPlayerLifes() == 0)
    {
        this->screen->drawHeader(F("YOU LOSE!"));
        this->screen->lcd.drawText(50, 50, "Your score:", RGB(26, 47, 197), RGB(160, 182, 219), 2);
        this->screen->lcd.drawInteger(230, 50, this->gameEngine->getPlayer1Score(), DEC, RGB(26, 47, 197), RGB(160, 182, 219), 2);
    }
    else
    {
        this->screen->drawHeader(F("YOU WIN!"));
        this->screen->lcd.drawText(50, 50, "Your score:", RGB(26, 47, 197), RGB(160, 182, 219), 2);
        this->screen->lcd.drawInteger(230, 50, this->gameEngine->getPlayer1Score(), DEC, RGB(26, 47, 197), RGB(160, 182, 219), 2);
    }
    
    //Wait till screen is pressed
    uint8_t pressed = 0;
    while (pressed != 4)
    {
        pressed = this->screen->checkTouchscreen();
    }
    //Delete header and buttons
    this->screen->deleteBackButton();
    this->screen->deleteHeader(F("           "));
    this->screen->lcd.fillRect(50, 50, 270, 20, RGB(160, 182, 219));
}
