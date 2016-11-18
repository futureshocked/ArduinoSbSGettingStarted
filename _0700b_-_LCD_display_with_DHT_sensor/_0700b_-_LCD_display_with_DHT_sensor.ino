/*  LCD screen with DHT22 sensor demo sketch
 * 
 * This sketch shows you how to use the 16x2 LCD display in
 * 4-bit mode with the Arduino Uno, and display data from
 * the DHT22 sensor.
 * 
 * The LiquidCrystal library works with all LCD displays that are 
 * compatible with the Hitachi HD44780 driver. There are many 
 * of them out there, and you  can usually tell them by the 
 * 16-pin interface.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - 10KOhm potentiometer
 *  - DHT22
 *  - 10KOhm resistor for the sensor
 *  - jumper wires
 *  - Breadboard
 *  
 *  Libraries
 *  ---------
 *  - LiquidCrystal (comes with Arduino IDE)
 *  - DHT
 *
 * Connections
 * -----------
 *  LCD screen    |    Arduino Uno
 *  -----------------------------
 *      1  (Vss)  |      GND
 *      2  (Vdd)  |      5V
 *      3  (VO)   |      Potentiometer
 *      4  (RS)   |      12
 *      5  (RW)   |      GND
 *      6  (E)    |      11
 *      7  (D0)   |      Not connected
 *      8  (D1)   |      Not connected
 *      9  (D2)   |      Not connected
 *      10 (D3)   |      Not connected
 *      11 (D4)   |      5
 *      12 (D5)   |      4
 *      13 (D6)   |      3
 *      14 (D7)   |      2
 *      15 (A)    |      5V
 *      16 (K)    |      GND
 *      
 * For the potentiometer, connect the middle pin
 * to pin 3 (V0) of the display. The other two, connect
 * to 5V and GND. It doesn't matter which pin goes to
 * 5V and to GND.
 * 
 * For the DHT22:
 * 
 *  * Hold the sensor so that the grill is towards you. Here are the connections
 * 
 *     -----------
 *     | - |  -  |
 *     | - |  -  |
 *     | - |  -  |
 *     | - |  -  |
 *     -----------
 *     |  |  |  |
 *     |  |  |  |
 *     |  |  |  |
 *     |  |  |  |
 *    5V  2     GND
 *      data
 *    
 * Connect a 10KOhm resistor between the 5V and data pin (2)
 * 
 * Other information
 * -----------------
 *  For information on the LiquidCrystal library: https://www.arduino.cc/en/Reference/LiquidCrystal
 *  
 *  Created on November 18 2016 by Peter Dalmaris
 * 
 */

#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 7     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("DHT test");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Can't get reading");
    lcd.setCursor(0, 1);
    lcd.print("from DHT");

  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" *C");
  }
}
