/*  BMP180 sensor demo sketch
 * 
 * This sketch extracts barometric pressure and temperature 
 * from the BMP180 breakout module.
 * 
 * This sketch was adapted from the original that comes with the 
 * Adafruit Adafruit_BMP085_U library for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - BMP180 sensor breakout or equivelant (the BMP085 will also work)
 *  
 *  Libraries
 *  ---------
 *  - Wire
 *  - Adafruit_Sensor
 *  - Adafruit_BMP085_U
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
 *  For information on barometric pressure: https://en.wikipedia.org/wiki/Atmospheric_pressure
 *  For information on the Adafruit library is at https://www.adafruit.com/product/1603
 *  
 *  For best results, find the atmospheric pressure at sea level at the closest location to yours,
 *  and store it in the seaLevelPressure variable.
 *  
 *  Created on October 8 2016 by Peter Dalmaris
 *  
 * 
 * This driver uses the Adafruit unified sensor library (Adafruit_Sensor),
 * which provides a common 'type' for sensor data and some helper functions.
 * 
 * To use this driver you will also need to download the Adafruit_Sensor
 * library and include it in your libraries folder.
 * 
 * You should also assign a unique ID to this sensor for use with
 * the Adafruit Sensor API so that you can identify this particular
 * sensor in any data logs, etc.  To assign a unique ID, simply
 * provide an appropriate value in the constructor below (12345
 * is used by default in this example).
 * 
 * Connections
 * ===========
 * Connect SCL to analog 5
 * Connect SDA to analog 4
 * Connect VDD to 3.3V DC
 * Connect GROUND to common ground
 *  
 * History
 * =======
 * 2013/JUN/17  - Updated altitude calculations (KTOWN)
 * 2013/FEB/13  - First version (KTOWN)
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>


   
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

/**************************************************************************/
/*
    Displays some basic information on this sensor from the unified
    sensor API sensor_t type (see Adafruit_Sensor for more information)
*/
/**************************************************************************/
void displaySensorDetails(void)
{
  sensor_t sensor;
  bmp.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" hPa");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" hPa");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" hPa");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Pressure Sensor Test"); Serial.println("");
  Serial.println("Starting");

    bmp.begin();
  /* Initialise the sensor */
//  if(!bmp.begin())
//  {
//    /* There was a problem detecting the BMP085 ... check your connections */
//    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
//    while(1);
//  }
  Serial.println("Started");
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event;
  bmp.getEvent(&event);
 
  /* Display the results (barometric pressure is measure in hPa) */
  if (event.pressure)
  {
    /* Display atmospheric pressue in hPa */
    Serial.print("Pressure:    ");
    Serial.print(event.pressure);
    Serial.println(" hPa");
    
    /* Calculating altitude with reasonable accuracy requires pressure    *
     * sea level pressure for your position at the moment the data is     *
     * converted, as well as the ambient temperature in degress           *
     * celcius.  If you don't have these values, a 'generic' value of     *
     * 1013.25 hPa can be used (defined as SENSORS_PRESSURE_SEALEVELHPA   *
     * in sensors.h), but this isn't ideal and will give variable         *
     * results from one day to the next.                                  *
     *                                                                    *
     * You can usually find the current SLP value by looking at weather   *
     * websites or from environmental information centers near any major  *
     * airport.                                                           *
     *                                                                    *
     * For example, for Paris, France you can check the current mean      *
     * pressure and sea level at: http://bit.ly/16Au8ol                   */
     
    /* First we get the current temperature from the BMP085 */
    float temperature;
    bmp.getTemperature(&temperature);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    /* Then convert the atmospheric pressure, and SLP to altitude         */
    /* Update this next line with the current SLP for better results      */
//    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    float seaLevelPressure = 1017.8;
    Serial.print("Altitude:    "); 
    Serial.print(bmp.pressureToAltitude(seaLevelPressure,
                                        event.pressure)); 
    Serial.println(" m");
    Serial.println("");
  }
  else
  {
    Serial.println("Sensor error");
  }
  delay(1000);
}
