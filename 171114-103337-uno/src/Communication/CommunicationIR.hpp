#include <stdint.h>

#ifndef CommunictaionIR_H
#define CommunictaionIR_H

class Bomb;

// start
void startCommunication(uint8_t frequenty);

// Function to send map to player 2
uint8_t sendMap(uint8_t seed, uint8_t level);

void getMap(uint8_t *seed, uint8_t *level);

// Function to send data to
void setPlayer1(uint8_t x, uint8_t y);

// Function to get x and y from player 2
void getPlayer2(uint8_t *x, uint8_t *y);

// Function to set bomb
uint8_t setBombPlayer2(uint8_t x, uint8_t y);

// Function to get Bomb from player 2
void getBombsPlayer2(Bomb **bombs);

// Start timer1
void startTimer1();

// Stop timer1
void stopTimer1();

// Start receiving
void startReceiving();

// Stop Receiving
void stopReceiving();

// Function to fill the outgoing buffer
void fillOutGoingBuffer(uint8_t *buffer, uint8_t x, uint8_t y, uint8_t bomb, uint8_t seed, uint8_t level, uint8_t function);

// Function to fill part of the buffer, x, y an bomb, function is used by fillOutGoingBuffer
void fillBufferFunction0(uint8_t x, uint8_t y, uint8_t bomb);

// Function to fill part of the buffer, seed and level, function is used by fillOutGoingBuffer
void fillBufferFunction1(uint8_t seed, uint8_t level);

// Function to fill part of the buffer function is used by fillOutGoingBuffer
void fillBufferFunction2();

// Function to get incomming buffer
void getIncommingBuffer(uint8_t function);

// Function to get startbit, this function is used by getIncommingBuffer
uint8_t getStartBit();

// Function to get x and y and bomb, this function is used by getIncommingBuffer
void getIncommingBufferFunction0(uint8_t *xNew, uint8_t *yNew, uint8_t *bombNew, uint8_t valCounter);

// Function to get mapSeedNew and levelNew, this function is used by getIncommingBuffer
void getIncommingBufferFunction1(uint8_t *mapSeedNew, uint8_t *levelNew, uint8_t valCounter);

// Function to process new data, x and y and bomb, this function is used by getIncommingBuffer
void getIncommingBufferFunction0Process(uint8_t xNew, uint8_t yNew, uint8_t bombNew, uint8_t newDataNew, uint8_t confirmedNew, uint8_t parity);

// Function to process new data, mapSeedNew and levelNew, this function is used by getIncommingBuffer
void getIncommingBufferFunction1Process(uint8_t mapSeedNew, uint8_t levelNew, uint8_t newDataNew, uint8_t confirmedNew, uint8_t parity);

// Function to get power from two
uint8_t powerTwo(uint8_t power);

#endif
