#include "Arduino.h"
#include <XTools.h>

//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);

}

// The loop function is called in an endless loop
void loop()
{
	  XPRINTLNS("HIGH");
	  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(500);                        // wait for a second
	  XPRINTLNS("LOW");
	  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	  delay(3000);

}
