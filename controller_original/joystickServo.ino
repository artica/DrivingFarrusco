void checkJoystickServo()
{
  int linearVelocity, rotationVelocity;
  
  int x_position = analogRead(PIN_ANALOG_SERVO_X);
  int y_position = analogRead(PIN_ANALOG_SERVO_Y);
  
  Serial.write('S');
  
  
  if (x_position > 520 && x_position < 530 && y_position > 495 && y_position < 505)
  {
    Serial.write((byte)((SERVO_MAX + SERVO_MIN) / 2));
    Serial.write((byte)((SERVO_MAX + SERVO_MIN) / 2));
    //Serial.println("dead   ");
    
  } 
  else 
  {
    byte s1 = map(x_position, 0, 1023, SERVO_MIN, SERVO_MAX);
    byte s2 = map(y_position, 0, 1023, SERVO_MIN, SERVO_MAX);
  
    Serial.write(s1);
    Serial.write(s2);
  
  }  
}

