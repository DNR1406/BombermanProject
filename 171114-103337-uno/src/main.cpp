#include <Arduino.h>


void PWMLed(int ldrVal) {
  DDRD |= (1<<DDD6);			// Arduino Digital Pin 6 is output

  TCCR0A |= (1<<COM0A1);					// Non-inverting mode A
	TCCR0A |= (1 << WGM01) | (1 << WGM00);	// set fast PWM Mode
	TCCR0B |= (1 << CS01);

	char step = ldrVal;


		OCR0A += step;
		if(OCR0A == 0 || OCR0A == 255) step = -step;

}

int main(void)
{
  init();
  Serial.begin(9600);
  Serial.println("start");
	for(int i = 100; i < 255; i++) {
      Serial.println(i);
    PWMLed(i);

    delay(100);
  }
}