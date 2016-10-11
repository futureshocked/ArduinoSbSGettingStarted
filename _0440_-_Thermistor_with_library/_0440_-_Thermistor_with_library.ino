/*  Thermistor temperature sensor demonstration sketch
 * 
 * This sketch calculates the the temperature by reading the voltage of a 
 * thermistor connected in a voltage divider circuit.
 * 
 * It then does a caclulation to convert this raw reading into a temperature.
 * 
 * This sketch was adapted for Arduino Step by Step by Peter Dalmaris from the 
 * demo sketch that ships with the library, written by Daniel Berenguer.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - thermistor temperature sensor
 *  - 10 kOhm resistor
 *  
 *  Libraries
 *  ---------
 *  Thermistor.h
 *
 * Connections
 * -----------
 * 
 * Connect the Arduino 5V pin to one end of the
 * thermistor. Connect the resistor to the Arduino GND
 * pin. Connect the free pins on the thermistor and 
 * resistor together. Connect the thermistor and resistor
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
 * 
 * About the termistor: https://en.wikipedia.org/wiki/Thermistor
 * The Github repository for the library: https://github.com/panStamp/thermistor
 * 
 * 
 * 
 *  Created on October 8 2016 by Peter Dalmaris
 * 
 */

/**
 * Copyright (c) 2015 panStamp S.L.U. <contact@panstamp.com>
 * 
 * This file is part of the panStamp project.
 * 
 * panStamp  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * panStamp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with panStamp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer
 * Creation date: 06/24/2015
 */

#include "thermistor.h"

// Analog pin used to read the NTC
#define NTC_PIN               A0

// Thermistor object
THERMISTOR thermistor(NTC_PIN,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor

// Global temperature reading
uint16_t temp;

/**
 * setup
 *
 * Arduino setup function
 */
void setup()
{
  Serial.begin(9600);
}

/**
 * loop
 *
 * Arduino main loop
 */
void loop()
{
  temp = thermistor.read();   // Read temperature

  Serial.print("Temp in 1/10 ºC : ");
  Serial.println(temp);

  delay(5000);
}

