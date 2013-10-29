#include <Wire.h>

#define FARRUSCO_MAX_VELOCITY 255
#define FARRUSCO_MIN_VELOCITY -255
#define SERVO_MAX 160
#define SERVO_MIN 20
#define X_THRESHOLD_LOW 515
#define X_THRESHOLD_HIGH 525    
#define Y_THRESHOLD_LOW 510
#define Y_THRESHOLD_HIGH 520

// Store the Arduino pin associated with each input

const byte PIN_ANALOG_MOTOR_X = 5;
const byte PIN_ANALOG_MOTOR_Y = 4;
const byte PIN_ANALOG_SERVO_X = 2;
const byte PIN_ANALOG_SERVO_Y = 3;

boolean debug = false;

void setup() {
  Serial.begin(19200);
  delay(1000);  
}

void loop() 
{
  checkJoystickMotor();
  delay(10);
  
  checkJoystickServo();
  delay(10);
}
