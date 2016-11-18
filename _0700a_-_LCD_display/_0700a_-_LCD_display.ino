/*  LCD screen demo sketch
 * 
 * This sketch shows you how to use the 16x2 LCD display in
 * 4-bit mode with the Arduino Uno.
 * 
 * The LiquidCrystal
 * library works with all LCD displays that are compatible with the 
 * Hitachi HD44780 driver. There are many of them out there, and you
 * can usually tell them by the 16-pin interface.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - 10KOhm potentiometer
 *  - jumper wires
 *  - Breadboard
 *  
 *  Libraries
 *  ---------
 *  - LiquidCrystal (comes with Arduino IDE)
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
 * Other information
 * -----------------
 *  For information on the LiquidCrystal library: https://www.arduino.cc/en/Reference/LiquidCrystal
 *  
 *  Created on November 18 2016 by Peter Dalmaris
 * 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
}
