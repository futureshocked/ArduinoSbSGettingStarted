/*  ADXL335 3-axis acceleration sensor demo sketch 2
 * 
 * This sketch gets X-Y-Z acceleration readings from the 
 * ADXL335 sensor and calculates the G-force for each axis.
 * 
 * The readings come from any 3 available analog inputs.
 * 
 * Notice that the breakout only works at 3.3V voltage level. Therefore, 
 * connect Vcc to the Arduino's 3.3V pin. To ensure that the Arduino analog
 * inputs are sampled at that level, connect the breakout VCC to the 
 * Arduino HREF pin.
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - ADXL335 sensor breakout or equivelant
 *  
 *  Libraries
 *  ---------
 *  - NONE
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      VCC      |      3.3V
 *      GND      |      GND
 *      X        |      A0
 *      Y        |      A1
 *      Z        |      A2
 *      VCC      |      AREF  This will ensure that the Arduino uses 0-3.3V as the sampling range
 
 * 
 * Other information
 * -----------------
 *  For information on acceleration: https://en.wikipedia.org/wiki/Acceleration
 *  ADXL335 datasheet: http://www.analog.com/media/en/technical-documentation/data-sheets/ADXL335.pdf
 *  
 *  As per the datasheet, the sensitivity of the sensor is ~300mV/g at 3V. We can use this information
 *  to convert the analog reading into G-force reading.
 *  
 *  Created on October 8 2016 by Peter Dalmaris
 * 
 */

int x, y, z;  // Use these variables to store the acceleration readings
double x_volt, y_volt, z_volt; // To calculate G-forces I must first calculate voltages
double x_g, y_g, z_g; // These vars will hold the G-forces

int X_axis = 3;
int Y_axis = 2;
int Z_axis = 1;

double largest_x, largest_y, largest_z;

double zero_g_voltage;


double sensitivity = 0.300; // 0.300 V/g

char outstr[5]; // These char arrays are used to 
                                            // format the final results into 
                                            // a number with only 1 decimal.

void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
  largest_x = 0;
  largest_y = 0;
  largest_z = 0;

  delay(1000);
  x = analogRead(X_axis); //Take a reading in x-axis to establish zero-g voltage
  zero_g_voltage = x;
}

void loop()
{
  x = analogRead(X_axis);       // read analog input pin 0
  y = analogRead(Y_axis);       // read analog input pin 1
  z = analogRead(Z_axis);       // read analog input pin 1

  x_volt = x * 3.3 / 1023;
  y_volt = y * 3.3 / 1023;
  z_volt = z * 3.3 / 1023;

  x_g = (x_volt-zero_g_voltage) / sensitivity;
  y_g = (y_volt-zero_g_voltage) / sensitivity;
  z_g = (z_volt-zero_g_voltage) / sensitivity;

  if (largest_x < x_g)
    largest_x = x_g;

  if (largest_y < y_g)
    largest_y = y_g;

  if (largest_z < z_g)
    largest_z = z_g;


//  dtostrf(largest_y,3, 1, outstr_y);
//  dtostrf(largest_z,3, 1, outstr_z);
  
  Serial.print("G-forces are x, y, z, largest x-y-z: ");
  Serial.print(x, DEC);    // print the acceleration in the X axis
  Serial.print(" ");       // prints a space between the numbers
  Serial.print(y, DEC);    // print the acceleration in the Y axis
  Serial.print(" ");       // prints a space between the numbers
  Serial.print(z, DEC);  // print the acceleration in the Z axis
  Serial.print(", ");
  dtostrf(largest_x,3, 1, outstr);
  Serial.print(outstr);
  Serial.print(" - ");
  dtostrf(largest_y,3, 1, outstr);
  Serial.print(outstr);
  Serial.print(" - ");
  dtostrf(largest_z,3, 1, outstr);
  Serial.print(outstr);
  Serial.print(", zero G: ");
  Serial.println(zero_g_voltage);
  delay(100);              // wait 100ms for next reading
}
