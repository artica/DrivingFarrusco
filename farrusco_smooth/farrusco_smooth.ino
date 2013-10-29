#include <Servo.h>
#include <string.h>

Servo servoPan;
Servo servoTilt;

int s1Center = 65;
int s2Center = 76;

float s1Target, s2Target;

// motor pins
int motorA0 = 6;
int motorA1 = 11;

int motorB0 = 3;
int motorB1 = 5;
 
// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(19200);
  
  pinMode(13, OUTPUT);
  
  servoPan.attach(9);
  servoTilt.attach(10);
  
  servoPan.write(s2Center);
  servoTilt.write(s1Center);
  
  pinMode(motorA0, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB0, OUTPUT);
  pinMode(motorB1, OUTPUT);
  
  delay(1000);
}

void loop() 
{
    int vel1, vel2, inByte;
    byte s1, s2;
    
    while (!Serial.available());
    
    inByte = Serial.read();
    
    if (inByte == 'M') 
    {   
        while(Serial.available()==0);
        vel1 = Serial.read()<<8;
        while(Serial.available()==0);
        vel1 += Serial.read();
        while(Serial.available()==0);
        vel2 = Serial.read()<<8;
        while(Serial.available()==0);
        vel2 += Serial.read();
        DiffTurn(vel1, vel2);
    } 
    else if (inByte == 'S')
    {
      while(Serial.available()==0);
      s1 = Serial.read();
      while(Serial.available()==0);
      s2 = Serial.read();  
   
      s1Target = s1Target * (1.0-0.02) + s1 * 0.02;
      servoTilt.write((int)s1Target);
      
      s2Target = s2Target * (1.0-0.02) + s2 * 0.02;
      servoPan.write((int)s2Target);  
  }
}


