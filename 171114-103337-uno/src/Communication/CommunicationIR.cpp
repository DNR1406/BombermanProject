// Other includes
#include <avr/interrupt.h>

// Own includes
#include "../Globals.hpp"
#include "../Bomb.hpp"
#include "../Functions.hpp"
#include "../GameEngine.hpp"
#include "CommunicationIR.hpp"

// Counter for communication
volatile uint8_t communicationTimer2;

// Variable to remember which bit to send
volatile uint8_t bitToSend;
// Buffer for snding
uint8_t buffer[45];
// Variable if you are sending
volatile uint8_t send;

// Buffer with incomming values
uint8_t incommingBuffer[39];
// Variable to remember time which last data came in
volatile uint32_t lastIncommingTime;
// Counter for incoming values
volatile uint8_t counterIncomming;

// Seed which is sended
volatile uint8_t mapSeed;
// If game is started
volatile uint8_t start;
// Variable for amount data is sended
volatile uint16_t amountIncomming;
// Sended Level
volatile uint8_t levelG;
// If a bomb is sended
volatile uint8_t bomb;

// Counter for game
volatile uint32_t counterTimer2;
// If your data is confirmed
volatile uint8_t confirmed;
// If you have to confirm data from opponent
volatile uint8_t confirm;
// If you are sending newData or you sended your data already
volatile uint8_t newData;

// Variables for x and y from players
uint8_t xPlayer1, yPlayer1, xPlayer2, yPlayer2;

// start
void startCommunication(uint8_t frequenty)
{
    // Gill buffer with zero
    for (uint8_t i = 0; i < 45; i++)
    {
        buffer[i] = 0;
    }

    // Fil other buffer with zero
    for (uint8_t i = 0; i < 25; i++)
    {
        incommingBuffer[i] = 0;
    }

    // Check wich frequenty, 56 is 38 khz :()
    if (frequenty == 36)
    {
        timer1_36K();
    }
    else
    {
        timer1_56k();
    }

    // Start interupts on pin 2 for incoming values
    init_interuptPin2();
    // Start receiving the data
    startReceiving();
}

// Function to send map to player 2
uint8_t sendMap(uint8_t seed, uint8_t level)
{
    fillOutGoingBuffer(buffer, 0, 0, 0, seed, level, 0, 1);

    // Wait till value is confirmed
    confirmed = 0;
    while (!confirmed)
        ;

    // Send new data to opponent
    fillOutGoingBuffer(buffer, 0, 0, 0, seed, level, 1, 1);

    // Set to
    confirmed = 0;
    start = 1;
    amountIncomming = 0;
    return 1;
}

void getMap(uint8_t *seed, uint8_t *level)
{
    // If the seed and level are 3 times the same, we ll use them
    while (amountIncomming < 2)
        ;

    confirm = 1;
    fillOutGoingBuffer(buffer, 0, 0, 0, 0, 0, 0, 2);

    // Confirm the message
    while (confirm)
        ;

    start = 1;
    amountIncomming = 0;

    *seed = mapSeed;
    *level = levelG;
}

// Function to send data to
void setPlayer1(uint8_t x, uint8_t y)
{
    xPlayer1 = x;
    yPlayer1 = y;

    fillOutGoingBuffer(buffer, xPlayer1, yPlayer1, 0, 0, 0, 0, 0);
}

// Function to get x and y from player 2
void getPlayer2(uint8_t *x, uint8_t *y)
{
    // The data is receved more than 2 times
    if (amountIncomming >= 1)
    {
        *x = xPlayer2;
        *y = yPlayer2;
    }
}

// Function to set bomb
void setBombPlayer2(uint8_t x, uint8_t y)
{
    // Send bomb( 1 after x and y means you have placed a bomb)
    fillOutGoingBuffer(buffer, x, y, 1, 0, 0, 0, 0);

    // Wait till message is confirmed to make sure you didn't miss a bomb
    confirmed = 0;
    while (!confirmed)
        ;

    // After message is confirmed, you make a note that you are sending new data( the 1 on the second place from the right)
    fillOutGoingBuffer(buffer, x, y, 0, 0, 0, 1, 0);

    // Wait 54000 micro senconds to make sure the data is received
    uint32_t now = counterTimer2;
    while (counterTimer2 < (now + 400))
        ;

    // Set to
    confirmed = 0;
    amountIncomming = 0;
}

// Function to get Bomb from player 2
void getBombsPlayer2(Bomb **bombs)
{
    // If bomb is placed, otherwise go further
    if (bomb)
    {
        // Confirm you received the message, wait till newData bit is set
        confirm = 1;
        fillOutGoingBuffer(buffer, xPlayer1, yPlayer2, 0, 0, 0, 0, 0);
        while (confirm)
            ;

        // Check if bomb is already placed
        for (uint8_t i = 0; i < BOMBS; i++)
        {
            if ((bombs[i]->returnXlocation() == xPlayer2) && (bombs[i]->returnYlocation() == yPlayer2))
            {
                bomb = 0;
                return;
            }
        }

        // Ceck where is place to add the bomb
        for (uint8_t i = 0; i < BOMBS; i++)
        {
            if ((bombs[i]->readyForNew(xPlayer2, yPlayer2)))
            {
                bombs[i]->setXlocation(xPlayer2);
                bombs[i]->setYlocation(yPlayer2);
                bombs[i]->setTime(counterTimer2);
                bombs[i]->setExploded(0);

                bomb = 0;

                return;
            }
        }
    }
}

// Start timer1
void startTimer1()
{
    TIMSK1 |= (1 << OCIE1A);
}

// Stop timer1
void stopTimer1()
{
    TIMSK1 &= ~(1 << OCIE1A);
}

// Start receiving
void startReceiving()
{
    // Enable interupt INT0, pin 2
    EIMSK |= (1 << INT0);
}

// Stop Receiving
void stopReceiving()
{
    EIMSK &= ~(1 << INT0);
}

// Function to fill the outgoing buffer
void fillOutGoingBuffer(uint8_t *buffer, uint8_t x, uint8_t y, uint8_t bomb, uint8_t seed, uint8_t level, uint8_t newData, uint8_t function)
{
    // Wait till whole buffer is send
    while (bitToSend != 0)
    {
    }

    // Stop sending
    stopTimer1();

    // Startbit
    for (uint8_t i = 0; i < 4; i++)
    {
        buffer[i] = 1;
    }

    for (uint8_t i = 4; i < 45; i++)
    {
        buffer[i] = 0;
    }

    // Different functionalities, 0 is sending locations, 1 is sending map, 2 is only confirm val
    switch (function)
    {
    case 0:
        fillBufferFunction0(x, y, bomb);
        break;
    case 1:
        fillBufferFunction1(seed, level);
        break;
    case 2:
        fillBufferFunction2();
        break;
    }

    // Fill confirm in buffer
    if (confirm)
    {
        buffer[35] = 1;
        buffer[36] = 1;
        buffer[37] = 1;
    }
    else
    {
        buffer[36] = 1;
    }

    if (newData)
    {
        buffer[39] = 1;
        buffer[40] = 1;
    }
    else
    {
        buffer[39] = 1;
    }

    // Fill parity bit of all values in buffer
    if ((x + y + bomb + seed + level + confirm + newData) % 2)
    {
        buffer[42] = 1;
        buffer[43] = 1;
    }
    else
    {
        buffer[42] = 1;
    }

    bitToSend = 0;

    // Start sending
    startTimer1();
}

// Function to fill part of the buffer, x, y an bomb, function is used by fillOutGoingBuffer
void fillBufferFunction0(uint8_t x, uint8_t y, uint8_t bomb)
{
    // Variable to remeber where to fill in next value
    uint8_t bufferCounter = 5;

    // Fill x in buffer
    for (int8_t i = 3; i >= 0; i--)
    {
        if ((x >> i) & 1)
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        else
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        bufferCounter++;
    }

    // Fill y in buffer
    for (int8_t i = 3; i >= 0; i--)
    {
        if ((y >> i) & 1)
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        else
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        bufferCounter++;
    }

    //Fill bomb bit in buffer
    if (bomb)
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }
    else
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
    }

    bufferCounter++;
    buffer[bufferCounter] = 1;
}

// Function to fill part of the buffer, seed and level, function is used by fillOutGoingBuffer
void fillBufferFunction1(uint8_t seed, uint8_t level)
{
    uint8_t bufferCounter = 5;

    // Fill seed in buffer
    for (int8_t i = 7; i >= 0; i--)
    {
        if ((seed >> i) & 1)
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        else
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }

        bufferCounter++;
    }

    // Fill level in buffer
    for (int8_t i = 1; i >= 0; i--)
    {
        if ((level >> i) & 1)
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }
        else
        {
            buffer[bufferCounter] = 1;
            bufferCounter++;
        }

        bufferCounter++;
    }
}

// Function to fill part of the buffer function is used by fillOutGoingBuffer
void fillBufferFunction2()
{
    // Variable to remeber where to fill in next value
    uint8_t bufferCounter = 5;

    // Fill x in buffer
    for (int8_t i = 0; i < 10; i++)
    {
        buffer[bufferCounter] = 1;
        bufferCounter++;
        bufferCounter++;
    }
}

// Function to get incomming buffer
void getIncommingBuffer(uint8_t function)
{
    // Stop receiving data
    stopReceiving();

    // Variables for new data
    uint8_t xNew = 0, yNew = 0, bombNew = 0, parity = 0, startVal = 27, mapSeedNew = 0, levelNew = 0, confirmedNew = 0, newDataNew = 0;
    // Variable to read buffer
    uint8_t valCounter = 0;

    // Search startBit
    startVal = getStartBit();

    // If startvalue is still 27, stop function because no usefull data came in
    if (startVal == 27)
    {
        startReceiving();
        return;
    }

    // Next bit
    valCounter = startVal + 1;

    // Switch statement with different functions, 0 is receiving locations, 1 is receiving map
    switch (function)
    {
    case 0:
        getIncommingBufferFunction0(&xNew, &yNew, &bombNew, valCounter);
        break;
    case 1:
        getIncommingBufferFunction1(&mapSeedNew, &levelNew, valCounter);
        break;
    }

    // Check for confirm message
    if (incommingBuffer[startVal + 11] >= 16 && incommingBuffer[startVal + 11] <= 20)
    {
        confirmedNew = 1;
    }

    // Check for new data
    if (incommingBuffer[startVal + 12] >= 10 && incommingBuffer[startVal + 12] <= 14)
    {
        newDataNew = 1;
    }

    // Get parity bit
    if (incommingBuffer[startVal + 13] >= 10 && incommingBuffer[startVal + 13] <= 14)
    {
        parity = 1;
    }

    // Reading buffer is finished, start receiving for new data
    startReceiving();

    // Data(different per function) is put in global variables
    switch (function)
    {
    case 0:
        getIncommingBufferFunction0Process(xNew, yNew, bombNew, newDataNew, confirmedNew, parity);
        break;
    case 1:
        getIncommingBufferFunction1Process(mapSeedNew, levelNew, newDataNew, confirmedNew, parity);
        break;
    }

    // If new data arrived, your confrim message is over, so it is set to zero
    if (newData)
    {
        confirm = 0;
    }
}

// Function to get startbit, this function is used by getIncommingBuffer
uint8_t getStartBit()
{
    // Startval is 27
    uint8_t startVal = 27;

    // Look trough buffer for startbit
    for (uint8_t i = 0; i <= 26; i++)
    {
        // Startbit is betwee 22 and 26
        if (incommingBuffer[i] >= 22 && incommingBuffer[i] <= 26)
        {
            startVal = i;
            // Check if whole data row is usable
            for (uint8_t j = 1; j < 14; j++)
            {
                if (!(incommingBuffer[startVal + j] >= 4 && incommingBuffer[startVal + j] <= 20) && (incommingBuffer[startVal + j] != 9) && (incommingBuffer[startVal + j] != 15))
                {
                    startVal = 27;
                }
            }

            // Check if next bit is an other startbit from an data row
            if (!(incommingBuffer[startVal + 14] >= 22 && incommingBuffer[startVal + 14] <= 26) || (startVal + 14) == 39)
            {
                startVal = 27;
            }
        }

        // If startVAl is still 27, return it
        if (startVal != 27)
        {
            return startVal;
        }
    }
    return startVal;
}

// Function to get x and y and bomb, this function is used by getIncommingBuffer
void getIncommingBufferFunction0(uint8_t *xNew, uint8_t *yNew, uint8_t *bombNew, uint8_t valCounter)
{
    // Get x location
    for (int8_t i = 3; i >= 0; i--)
    {
        if (incommingBuffer[valCounter] >= 10 && incommingBuffer[valCounter] <= 14)
        {
            *xNew += powerTwo(i);
        }
        valCounter++;
    }

    // Get y location
    for (int8_t i = 3; i >= 0; i--)
    {
        if (incommingBuffer[valCounter] >= 10 && incommingBuffer[valCounter] <= 14)
        {
            *yNew += powerTwo(i);
        }
        valCounter++;
    }

    // Get bomb
    if (incommingBuffer[valCounter] >= 10 && incommingBuffer[valCounter] <= 14)
    {
        *bombNew = 1;
    }
    else
    {
        *bombNew = 0;
    }
}

// Function to get mapSeedNew and levelNew, this function is used by getIncommingBuffer
void getIncommingBufferFunction1(uint8_t *mapSeedNew, uint8_t *levelNew, uint8_t valCounter)
{
    // Get seed for map
    for (int8_t i = 7; i >= 0; i--)
    {
        if (incommingBuffer[valCounter] >= 10 && incommingBuffer[valCounter] <= 14)
        {
            *mapSeedNew += powerTwo(i);
        }

        valCounter++;
    }
    // Get level
    for (int8_t i = 1; i >= 0; i--)
    {
        if (incommingBuffer[valCounter] >= 10 && incommingBuffer[valCounter] <= 14)
        {
            *levelNew += powerTwo(i);
        }
        valCounter++;
    }
}

// Function to process new data, x and y and bomb, this function is used by getIncommingBuffer
void getIncommingBufferFunction0Process(uint8_t xNew, uint8_t yNew, uint8_t bombNew, uint8_t newDataNew, uint8_t confirmedNew, uint8_t parity)
{
    // If data is't received for the first time
    if ((xPlayer2 == xNew) && (yPlayer2 == yNew))
    {
        amountIncomming++;
    }
    else
    {
        amountIncomming = 0;
    }

    // Check for parity bit
    if (((xNew + yNew + bombNew + newDataNew + confirmedNew) % 2) == parity)
    {
        xPlayer2 = xNew;
        yPlayer2 = yNew;
        newData = newDataNew;
        confirmed = confirmedNew;
        bomb = bombNew;
    }
    else
    {
        amountIncomming = 0;
    }
}

// Function to process new data, mapSeedNew and levelNew, this function is used by getIncommingBuffer
void getIncommingBufferFunction1Process(uint8_t mapSeedNew, uint8_t levelNew, uint8_t newDataNew, uint8_t confirmedNew, uint8_t parity)
{
    // If data isn't received for the first time
    if (mapSeed == mapSeedNew && levelG == levelNew)
    {
        amountIncomming++;
    }
    else
    {
        amountIncomming = 0;
    }

    // Check for paritybit, if it is not correct, start receiving again.
    if (((mapSeedNew + levelNew + newDataNew + confirmedNew) % 2) == parity)
    {
        mapSeed = mapSeedNew;
        levelG = levelNew;
        newData = newDataNew;
        confirmed = confirmedNew;
    }
    else
    {
        amountIncomming = 0;
    }
}

// Function to get power from two
uint8_t powerTwo(uint8_t power)
{
    uint8_t returnVal = 1;

    for (uint8_t i = 0; i < power; i++)
    {
        returnVal *= 2;
    }

    return returnVal;
}