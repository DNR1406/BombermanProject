#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
// #include <SoftwareSerial.h>

#include "include.h"

int buffer[362];
volatile int bitToSend;
<<<<<<< HEAD
volatile int send;

=======
Navigation navigation = Navigation();
>>>>>>> 569deaf3594d9fc4446f50dce56a6373f492a971


int main()
{

    init();
    Serial.begin(9600);
    navigation.screenInit();
    navigation.calibrateScreen();
    navigation.drawStartscreenButtons();
       // Check if any buttons are pressed
<<<<<<< HEAD
    // navigation.checkButtonPresses();
=======
    navigation.checkButtonPresses();
>>>>>>> 569deaf3594d9fc4446f50dce56a6373f492a971

    DDRB |= (1 << PB5);


    // communicationIR *commu = new communicationIR(36);
    // commu->fillBuffer(buffer, 1, 1, true);

   
    while (1)
    {
    }

    return 0;
}

// variable for counterTimer2
volatile uint32_t counterTimer2 = 0;
// interupt functie
ISR(TIMER2_COMPA_vect)
{
    if (counterTimer2 == 1000)
    {

    if (buffer[bitToSend])
    {
        send = 1;
    }
    else
    {
        send = 0; 
    }

    bitToSend++;

    if (bitToSend == 326)
    {
        bitToSend = 0;
    }
    counterTimer2 = 0;
    }
    counterTimer2++;
}
<<<<<<< HEAD
ISR(TIMER1_COMPA_vect)
{
    TCCR1A ^= _BV (COM1A0);
    
    if (send == 1) 
    {
    //     if (!(TCCR1A & _BV (COM1A0)) == 0){
            
    PORTB ^= (1 << PB5);
    }
    else
    {
    PORTB &= ~(1 << PB5);
    }
}
=======


>>>>>>> 569deaf3594d9fc4446f50dce56a6373f492a971
