

#include "include.h"


//Constructor
Map grid = Map();
Screen screen = Screen();
BMPLoader player = BMPLoader();
Communication c =  Communication(1, 1);
GameEngine::GameEngine()
{


// startGame function
void GameEngine::startGame()
{
    int positions[58] = { 0 };
    // draws grid on screen
    grid.drawGrid();
    
    int barrels[58];

    c.receiveMap(barrels);

    for(int i = 0; i < 58; i++) {
        Serial.println(barrels[i]);
    }


    grid.getBarrels(barrels);


    c.sendMap(positions);
    
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





