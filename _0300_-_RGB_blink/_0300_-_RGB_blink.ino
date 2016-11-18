/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN takes care 
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
*/

//const int red_pin = 3;

#define RED_PIN   3
#define BLUE_PIN  6
#define GREEN_PIN 5

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(RED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(RED_PIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(BLUE_PIN, HIGH);
  delay(1000);                       // wait for a second
  digitalWrite(BLUE_PIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(GREEN_PIN, HIGH);
  delay(1000);
}
