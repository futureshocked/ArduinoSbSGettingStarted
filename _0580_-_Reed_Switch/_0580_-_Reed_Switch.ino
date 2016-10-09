/*  Reed switch demo sketch
 * 
 * This sketch demonstrates the use of a Reed switch.
 * The sensor works like a button or a Hall effect sensor. 
 * When a magnet is near it, the switch
 * closes and the LED on Pin 13 turns on.
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Reed switch
 *  - 10 KOhm resistor for pull-up.
 *  
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections
 * -----------
 *                                   10 KOhm
 *  5V -------(ReedSwitch)--------/\/\/\/\/\-------GND
 *                           |
 *                           |
 *                           |
 *                           |
 *                           2
 * 
 *      
 * 
 * Other information
 * -----------------
 *  For information on the Reed switch: https://en.wikipedia.org/wiki/Reed_switch
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
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

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
