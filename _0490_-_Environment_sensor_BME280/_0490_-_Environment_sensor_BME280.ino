/*  BME280 sensor demo sketch
 * 
 * This sketch demonstrates the use of the BME280 environment sensor.
 * It extracts barometric pressure, temperature and humidity values
 * from the BME280breakout module.
 * 
 * This sensor can communicate via SPI or I2C
 * 
 * This sketch was adapted from the original that comes with the 
 * Adafruit Adafruit_BME280 library for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - BME280 sensor breakout or equivelant (the BMP085 will also work)
 *  
 *  Libraries
 *  ---------
 *  - Wire
 *  - Adafruit_Sensor
 *  - Adafruit_BME280
 *
 * Connections
 * -----------
 * In the demo, we will use both the SPI interface and I2C interfaces.
 * 
 * For SPI:
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VIN      |      5V
 *      GND      |      GND
 *      SCK      |      13 (can change)
 *      SDO      |      12 (can change)
 *      SDI      |      11 (can change)
 *      CS       |      10 (can change)
 *      
 * For I2C:
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VIN      |      5V
 *      GND      |      GND
 *      SCK      |      SCL or A5
 *      SDA      |      SDA or A4
 *      
 * 
 * Other information
 * -----------------
 *  For information on barometric pressure: https://en.wikipedia.org/wiki/Atmospheric_pressure
 *  For information on the Adafruit library is at https://github.com/adafruit/Adafruit_BME280_Library
 *  Adafruit product page: https://www.adafruit.com/products/2652
 *  Datasheet: https://www.bosch-sensortec.com/bst/products/all_products/bme280
 *  
 *  For best results, find the atmospheric pressure at sea level at the closest location to yours,
 *  and store it in the SEALEVELPRESSURE_HPA variable.
 *  
 *  Created on October 8 2016 by Peter Dalmaris
 *  
  */
/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//#define BME_SCK 13
//#define BME_MISO 12
//#define BME_MOSI 11
//#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1017.8)

//#define BME280_ADDRESS                (0x76)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
    delay(2000);
}
