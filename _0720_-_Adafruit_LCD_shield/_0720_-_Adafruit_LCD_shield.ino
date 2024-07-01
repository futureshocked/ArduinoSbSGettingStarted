/*  Adafruit RGB Character LCD Shield demo sketch
 * 
 * This sketch shows you how to use the Adafruit RGB Character
 * LCD with buttons shield for the Arduino
 * 
 * This shield contains a 16x2 RGB LCD screen, 4 directional
 * buttons, one select button, one reset button, and a
 * potentiometer to control the contrast with.
 * 
 * Note that the shield is available in a kit that includes
 * the LCD screen. You can also use a monochrome LCD screen.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Adafruit RGB Character LCD Shield
 *  
 *  Libraries
 *  ---------
 *  - Wire
 *  - Adafruit_MCP23017
 *  - Adafruit_RGBLCDShield
 *
 * Connections
 * -----------
 *  
 * Just plug the shield on the Arduino Uno and you are good to go.
 *      
 * 
 * Other information
 * -----------------
 *  For information on the LCD chield: https://www.adafruit.com/product/714
 *  For information on the Adafruit_RGBLCDShield library: https://github.com/adafruit/Adafruit-RGB-LCD-Shield-Library/
 *  For information on the Adafruit_MCP23017 library: https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
 *  Install both libraries via the Library manager. Search for "Adafruit RGB LCD Shield Library" and "Adafruit MCP23017".
 *  
 *  Modified on November 18, 2016, by Peter Dalmaris from the original Adafruit demo sketch.
 *  Updated on July 1, 2024, by Peter Dalmaris.
 * 
 */
/*********************

Example code for the Adafruit RGB Character LCD Shield and Library

This code displays text on the shield, and also reads the buttons on the keypad.
When a button is pressed, the backlight changes color.

**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_MCP23X17.h> // This library has changed its name in newer versions. Old name was Adafruit_MCP2317
#include <Adafruit_RGBLCDShield.h> 

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);

  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.print("UP ");
      lcd.setBacklight(RED);
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("DOWN ");
      lcd.setBacklight(YELLOW);
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("LEFT ");
      lcd.setBacklight(GREEN);
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("RIGHT ");
      lcd.setBacklight(TEAL);
    }
    if (buttons & BUTTON_SELECT) {
      lcd.print("SELECT ");
      lcd.setBacklight(VIOLET);
    }
  }
}
