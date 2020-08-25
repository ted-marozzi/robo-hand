/*
  This code is designed for my Hand V3 design.
  Created by Ted Marozzi.
*/
#include <Arduino.h>

// Pins
#define FSR A3
#define MOTOR_IN1 10
#define MOTOR_IN2 11

#define FSR_AMPLITIDE 250
#define TIME_TO_OPEN_MS 400
#define TIME_TO_CLOSE_MS 1500

#define STRENGTH 255

void openHand();
void closeHand();
bool toDigital(int analogRead, int THRESHOLD);
void moveHand();

// Variables
bool isHandOpen = true;

void setup() {

  Serial.begin(9600);
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);

  closeHand();
  openHand();
}

void loop() {
   
  int fsrRead = analogRead(FSR);

  if(toDigital(fsrRead, FSR_AMPLITIDE))
  {
    moveHand();
  }

}

bool toDigital(int analogRead, int THRESHOLD)
{
  return !(analogRead <= THRESHOLD);
}

void moveHand()
{
  if(isHandOpen)
  {
    closeHand();
  }
  else
  {
    openHand(); 
  } 

}

void openHand()
{
  analogWrite(MOTOR_IN2, STRENGTH);
  delay(TIME_TO_OPEN_MS);
  digitalWrite(MOTOR_IN2, LOW);

  isHandOpen = true;
}

void closeHand()
{
  analogWrite(MOTOR_IN1, STRENGTH);
  delay(TIME_TO_CLOSE_MS);
  digitalWrite(MOTOR_IN1, LOW);

  isHandOpen = false;

}
