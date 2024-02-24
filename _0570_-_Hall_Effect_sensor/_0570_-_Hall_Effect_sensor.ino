/*  Hall Effect sensor demo sketch
 * 
 * This sketch demonstrates the use of a simple Hall Effect sensor.
 * The sensor works like a button. When a magnet is near it, the sensor
 * closes and the LED on Pin 13 turns on.
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Hall Effect sensor, like the USB1542 or equivelant
 *  - 10 KOhm resistor for pull-up.
 *  
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections
 * -----------
 * 
 * Looking at the sensor facing the text:
 * 
 *  Sensor       |    Arduino Uno
 *  -----------------------------
 *      1      |      5V
 *      2      |      GND
 *      3      |      2
 *      
 *  Connect the resistor between sensor pins 1 and 3.
 *      
 * 
 * Other information
 * -----------------
 *  For information on the Hall effect sensor: https://en.wikipedia.org/wiki/Hall_effect_sensor
 *  
 *  Created on October 8 2016 by Peter Dalmaris
 * 
 */

// constants won't change. They're used here to
// set pin numbers:
const int sensor = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(sensor, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(sensor);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
