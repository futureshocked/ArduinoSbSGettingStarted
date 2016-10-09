/*  RGB light sensor demo sketch
 * 
 * This sketch gets a color RGB reading from the light sensor 
 * on the Adafruit TCS34725 (or equivelant) breakout module.
 * 
 * This sketch was adapted from the original that comes with the 
 * Adafruit library for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Adafruit RGB TCS34725 sensor breakout or equivelant
 *  
 *  Libraries
 *  ---------
 *  - Wire
 *  - Adafruit_TCS34725
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VIN      |      5V
 *      GND      |      GND
 *      SCL      |      SCL or A5
 *      SDA      |      SDA or A4
 *      LED      |      GND to turn off (or any digital out set to LOW)
 *      INT      |      2 (but not used in this sketch)
 * 
 * Other information
 * -----------------
 *  For information on RGB color: https://en.wikipedia.org/wiki/RGB_color_model
 *  For information on color temperature: https://en.wikipedia.org/wiki/Color_temperature
 *  For more information on the breakout see https://www.adafruit.com/product/1334
 *  The repository for the library used is at https://github.com/adafruit/Adafruit_TCS34725
 *  
 *  Created on October 8 2016 by Peter Dalmaris
 * 
 */
 
#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
  
}

void loop() {
  uint16_t clear, red, green, blue;

  tcs.setInterrupt(false);      // turn on LED

  delay(60);  // takes 50ms to read 
  
  tcs.getRawData(&red, &green, &blue, &clear);

  tcs.setInterrupt(true);  // turn off LED
  
  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(red);
  Serial.print("\tG:\t"); Serial.print(green);
  Serial.print("\tB:\t"); Serial.println(blue);
}

