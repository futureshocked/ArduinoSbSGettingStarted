/*  Digital sound sensor demo sketch
 * 
 * This sketch detects loud noises using a digital sound sensor.
 * 
 * When the sensor detects a loud noise, it sends a message to the 
 * serial monitor.
 * 
 * This sketch was written for Arduino Step by Step by Peter Dalmaris.
 * 
 * Components
 * ----------
 *  - Arduino Uno
 *  - Digital sound sensor
 *  
 *  Libraries
 *  ---------
 *  - None
 *
 * Connections
 * -----------
 *  Break out    |    Arduino Uno
 *  -----------------------------
 *      +        |      5V
 *      G        |      GND
 *      D0       |      A0
 
 * 
 * Other information
 * -----------------
 *  This code is useful if you want to do things like detect a knock on a door,
 *  hands clapping, etc.
 *  
 *  Created on October 14 2016 by Peter Dalmaris
 * 
 */
 
int soundDetectedPin = 10; // Use Pin 10 as our Input
int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
boolean bAlarm = false;

unsigned long lastSoundDetectTime; // Record the time that we measured a sound


int soundAlarmTime = 500; // Number of milli seconds to keep the sound alarm high


void setup ()
{
  Serial.begin(9600);  
  pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
  pinMode (13, OUTPUT);               // The built-in LED on pin 13 will light
                                      // up when there is a noise.
}
void loop ()
{
  soundDetectedVal = digitalRead (soundDetectedPin) ; // read the sound alarm time
  if (soundDetectedVal == HIGH) // If we hear a sound
  {
    digitalWrite(13,HIGH);
  } else
  {
    digitalWrite(13,LOW);
  }
  
  if (soundDetectedVal == HIGH) // If we hear a sound
  {
  
    lastSoundDetectTime = millis(); // record the time of the sound alarm
    // The following is so you don't scroll on the output screen
    if (!bAlarm){
      Serial.println("LOUD, LOUD");
      bAlarm = true;
    }
  }
  else
  {
    if( (millis()-lastSoundDetectTime) > soundAlarmTime  &&  bAlarm){
      Serial.println("quiet");
      bAlarm = false;
    }
  }
}
