#include "NavigationScreen.h"
#include "Navigation.h"
#include "../Debug/Memory.h"

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
    this->screen->deleteHeader();
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
            this->startLevelScreen();
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
    screen->drawHeader(F("OPTIONS"));

    // Draws start button
    screen->drawButton(F("BRIGHTNESS"), 1, 85, 108);

    // Draws options button
    screen->drawButton(F("VOLUME"), 2, 115, 147);

    // Draws credits button
    screen->drawButton(F("HIGHSCORE"), 3, 90, 187);
}

void Navigation::deleteOptionsScreen()
{
    // delete home button in corner of screen.
    this->screen->deleteBackButton();
    // delete headeer from options screen
    this->screen->deleteHeader();
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
            // Volume (Not finished)
            this->drawNotFinishedYet();
            delay(1000);
            this->deleteNotFinishedYet();
            this->drawOptionsScreen();
            pressed = 0;
            break;
        case 3:
            // Highscore (Not finished)
            this->drawNotFinishedYet();
            delay(1000);
            this->deleteNotFinishedYet();
            this->drawOptionsScreen();
            pressed = 0;
            break;
        case 4:
            // Go back
            return;
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

void Navigation::deleteCreditsScreen()
{
    // Delete buttons
    this->screen->deleteBackButton();
    this->screen->deleteHeader();
    this->screen->deleteCredits();
}

void Navigation::startCreditScreen()
{
    // Draw credit screen
    this->drawCreditsScreen();

    // Loop while nothing is pressed
    uint8_t pressed = 0;
    while (!pressed)
    {
        // Check for new press
        pressed = this->screen->checkTouchscreen();

        //Go back
        if (pressed == 4)
        {
            this->deleteCreditsScreen();

            return;
        }
    }
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
    this->screen->deleteHeader();
    this->screen->deleteBackButton();
    this->screen->deleteBrightness();
}

void Navigation::startBrightnessScreen()
{
    // Draw brightness screen
    this->drawBrightnessScreen();

    // variablen for pressed and value
    uint8_t pressed = 0, val = 0;

    // Loop while nothing is pressed
    while (pressed != 4)
    {
        // Check for new press
        pressed = this->screen->checkTouchscreen();

        // Read analog val
        val = this->getAnalogVal();
        // If it is less than 10, val becomes 10
        val = (val < 10) ? 10 : val;
        // Set brightness
        this->screen->setBrightness(val);
    }

    this->deleteBrightnessScreen();
}

// Levelscreen
void Navigation::drawLevelScreen()
{
    this->screen->drawHeader(F("LEVEL SLCT"));
    this->screen->drawBackButton();
    this->screen->drawButton(F("LEVEL 1"), 1, 110, 108);
    this->screen->drawButton(F("LEVEL 2"), 2, 110, 147);
    this->screen->drawButton(F("LEVEL 3"), 3, 110, 187);
}

void Navigation::deleteLevelScreen()
{
    this->screen->deleteBackButton();
    this->screen->deleteHeader();
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
        }

        // Check what is pressed
        switch (pressed)
        {
        case 1:
            // Start game with 18 barrels
            this->gameEngine->startGame(18);
            this->drawLevelScreen();
            pressed = 0;
            break;
        case 2:
            // Start game with 36 barrels
            this->gameEngine->startGame(36);
            this->drawLevelScreen();
            pressed = 0;
            break;
        case 3:
            // Start game with 55 barrels
            this->gameEngine->startGame(55);
            this->drawLevelScreen();
            pressed = 0;
            break;
        case 4:
            // Go back
            return;
            break;
        };
    }
}

// Other
int Navigation::getAnalogVal()
{
    uint16_t result;
    // Start conversion
    ADCSRA |= (1 << ADSC);
    // Wait
    while (ADCSRA & (1 << ADSC))
        ;
    result = ADC;
    return result / 10;
}

// Functions for stuff that is not finished
void Navigation::drawNotFinishedYet()
{
    this->screen->drawHeader(F("Not finished yet..."));
}

void Navigation::deleteNotFinishedYet()
{
    this->screen->deleteHeader();
}
