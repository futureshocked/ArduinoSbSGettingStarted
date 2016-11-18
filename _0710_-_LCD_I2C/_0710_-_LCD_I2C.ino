/*  LCD screen with the I2C backpack demo sketch
 * 
 * This sketch shows you how to use the 16x2 LCD display 
 * using the I2C backpack adaptor. This way, we can save a
 * lot of digital pins on the Arduino.
 * 
 * This I2C LCD backpack contains the PCF8574 port-expander
 * IC. Beware that this sketch can work with backpacks that
 * contains this IC, but may not work with variations.
 * 
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - An I2C to LCD backpack adaptor
 *  - jumper wires
 *  - Breadboard
 *  
 *  Libraries
 *  ---------
 *  - LCD
 *  - LiquidCrystal_I2C
 *
 * Connections
 * -----------
 *  I2C backpack  |    Arduino Uno
 *  -----------------------------
 *      GND       |      GND
 *      Vcc       |      5V
 *      SDA       |      SDA or A4
 *      SCL       |      SCL or A5
 *      
 * 
 * Other information
 * -----------------
 *  For information on the LiquidCrystal library: https://github.com/marcoschwartz/LiquidCrystal_I2C
 *  
 *  Created on November 18 2016 by Peter Dalmaris
 * 
 */
 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Hello world!");
    lcd.setCursor(0, 1);
    lcd.print("Row number: ");
    lcd.setCursor(12, 1);
    lcd.print("2");
}
void loop()
{
 
}
