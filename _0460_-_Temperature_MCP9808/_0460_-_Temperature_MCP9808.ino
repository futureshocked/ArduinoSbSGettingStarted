/*  Temperature MCP9808 sensor demo sketch
 * 
 * This sketch reads the temperature from the MCP9808 precision sensor 
 * on the Adafruit TCS34725 (or equivelant) breakout module.
 * 
 * This sketch was adapted from the original that comes with the 
 * Adafruit library for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Adafruit MCP9808 breakout module (or equivelant)
 *  
 *  Libraries
 *  ---------
 *  - Wire
 *  - Adafruit_MCP9808
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VIN      |      5V
 *      GND      |      GND
 *      SCL      |      SCL or A5
 *      SDA      |      SDA or A4

 * 
 * Other information
 * -----------------
 *  There are three pads on the sensor breakout that can be used
 *  to change the I2C address.
 *  MCP9808 datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/25095A.pdf
 *  Adafruit product page: https://www.adafruit.com/product/1782
 *  Adafruit library on Github: https://github.com/adafruit/Adafruit_MCP9808_Library
 *  
 *  Created on October 8 2016 by Peter Dalmaris
 * 
 */

/**************************************************************************/
/*!
This is a demo for the Adafruit MCP9808 breakout
----> http://www.adafruit.com/products/1782
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!
*/
/**************************************************************************/

#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

void setup() {
  Serial.begin(9600);
  Serial.println("MCP9808 demo");
  
  // Make sure the sensor is found, you can also pass in a different i2c
  // address with tempsensor.begin(0x19) for example
  if (!tempsensor.begin()) {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
}

void loop() {
  // Read and print out the temperature, then convert to *F
  float c = tempsensor.readTempC();
  float f = c * 9.0 / 5.0 + 32;
  Serial.print("Temp: "); Serial.print(c); Serial.print("*C\t"); 
  Serial.print(f); Serial.println("*F");
  delay(250);
  
  Serial.println("Shutdown MCP9808.... ");
  tempsensor.shutdown_wake(1); // shutdown MSP9808 - power consumption ~0.1 mikro Ampere
  
  delay(2000);
  
  Serial.println("wake up MCP9808.... "); // wake up MSP9808 - power consumption ~200 mikro Ampere
  tempsensor.shutdown_wake(0);
  
   
}
