/*  Photo-light sensor demo sketch
 * 
 * This sketch gets an analog reading from a photosensor.
 * A photosensor is a light-dependant resistor (LDR).
 * The reading is proportional to the ambient light.
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Light sensor
 *  - 10 kΩ resistor (or close)
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 * 
 * Connect the Arduino 5V pin to one end of the
 * LDR. Connect the resistor to the Arduino GND
 * pin. Connect the free pins on the LDR and 
 * resistor together. Connect the LDR and resistor
 * junction to the Arduino analog pin 0. This
 * structure is called a "voltage divider".
 *                    10 kΩ
 *  5V -----OOO------\/\/\/-----GND
 *                |
 *                |
 *                |
 *                A0
 *  
 * 
 * Other information
 * -----------------
 * For information on the photoresistors: https://en.wikipedia.org/wiki/Photoresistor
 * For information on the voltage divider: https://en.wikipedia.org/wiki/Voltage_divider
 * For a voltage divider calculator go to: http://txplo.re/2e65gSX 
 *  
 * Created on October 8 2016 by Peter Dalmaris
 * 
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);
}
