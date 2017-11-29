

#include "include.h"


//Constructor
Map grid = Map();
ArduinoNunchuk nunchuk = ArduinoNunchuk();
Screen screen = Screen();
GameEngine::GameEngine()
{
}


// startGame function
void GameEngine::startGame()
{
    // draws grid on screen
    grid.drawGrid();
    grid.declareBarrels(40);
    // checkPlayerActions();
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

	// This function checks all the movements of the player and corresponds them to the right action
void GameEngine::checkPlayerActions() {
    // Inits the nunchuck and the timer
	nunchuk.init();
	init_timer();

	// Stays in an infinite loop the keep checking the actions
	for(;;) {
		// checks if a state on the nunchuk has changed
		nunchuk.update(); //refresh nunchuk parameters

		// if Zbutton is pressed, a bomb will be placed on the last known location where the player was standing in the map
		if(nunchuk.zButton){ 
				// place bomb on x and y location
			}
		// checks if nunchuk controller movement is pressed upwards or downwards
		if(nunchuk.analogY > 155){
			screen.up();
		} else if(nunchuk.analogY < 100){
			screen.down();
		}
        // checks in nunchuk controller movement is pressed left or right
		if(nunchuk.analogX > 155){
			screen.right();
		}else if(nunchuk.analogX < 100){
			screen.left();
		}
	} 
}





