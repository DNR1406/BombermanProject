#include "include.h"

//Constructor
Map grid = Map();
Screen screen = Screen();
Communication c = Communication(1, 1);
GameEngine::GameEngine()
{
}

// startGame function
void GameEngine::startGame()
{
    int positions[59] = {};
    // draws grid on screen
    grid.drawGrid();
    // grid.declareBarrels(59, positions);
    // int barrels[58];

    // c.receiveMap(barrels);
    // grid.getBarrels(barrels);

    // c.sendMap(positions);
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
