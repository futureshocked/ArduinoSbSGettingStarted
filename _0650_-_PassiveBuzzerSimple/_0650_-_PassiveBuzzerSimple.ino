/*  Passive buzzer demo sketch 1
 * 
 * This sketch shows you how to play a tone using a passive
 * buzzer and the tone function that comes with the standard
 * Arduino library
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Passive buzzer with two or three pins
 *  
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections
 * -----------
 *  If you have a two pin passive buzzer, connect the pin marked "-"
 *  to Arduino GND, and the other pin to Arduino pin 8.
 * 
 *  If you have a three pin passive buzzer, connect the pin marked "-"
 *  to GND, the pin marked "S" to Arduino digital pin 8, and the last
 *  pin to Arduino pin 8.
 *  
 *  Created on November 21 2016 by Peter Dalmaris
 * 
 */
 
const int buzzer = 8; 

void setup(){ 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 8 as an output
}

void loop(){
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}
