/*  TMP36 temperature sensor demonstration sketch
 * 
 * This sketch reads the the voltage of the TMP36 sensor output pin.
 * It then does a caclulation to convert this raw reading into a temperature.
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - TMP36 temperature sensor
 *  
 *  Libraries
 *  ---------
 *  NONE
 *
 * Connections
 * -----------
 * 
 * As you look at the sensor with the label facing you, the left most pin is #1
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      1        |         5V
 *      2        |         A0
 *      3        |         GND
 *      
 * 
 * Other information
 * -----------------
 * 
 *  Created on October 8 2016 by Peter Dalmaris
 * 
 */

int sensorPin = 0; // The reading is obtained from analog pin 0 (A0)
 
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
}
 
void loop()                    
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree with 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 // now convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 
 delay(1000);                                     //waiting a second
}
