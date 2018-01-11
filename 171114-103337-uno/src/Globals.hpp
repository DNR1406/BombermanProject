#include <stdint.h>

#define STARTONE 10;
#define ENDONE 15;

#ifndef Globals_H
#define Globals_H

// Counter for communication
extern volatile uint8_t communicationTimer2;

// Variable to remember which bit to send
extern volatile uint8_t bitToSend;
// Buffer for snding
extern uint8_t buffer[45];
// Variable if you are sending
extern volatile uint8_t send;

// Buffer with incomming values
extern uint8_t incommingBuffer[39];
// Variable to remember time which last data came in
extern volatile uint32_t lastIncommingTime;
// Counter for incoming values
extern volatile uint8_t counterIncomming;

// Seed which is sended
extern volatile uint8_t mapSeed;
// If game is started
extern volatile uint8_t start;
// Variable for amount data is sended
extern volatile uint16_t amountIncomming;
// Sended Level
extern volatile uint8_t levelG;
// If a bomb is sended
extern volatile uint8_t bomb;

// Counter for game
extern volatile uint32_t counterTimer2;
// If your data is confirmed
extern volatile uint8_t confirmed;
// If you have to confirm data from opponent
extern volatile uint8_t confirm;
// If you are sending newData or you sended your data already
extern volatile uint8_t newData;
extern volatile uint8_t newDataSend;
extern volatile uint8_t newDataCounterSend;

#endif