void checkJoystickServo()
{
  int linearVelocity, rotationVelocity;
  
  int x_position = analogRead(PIN_ANALOG_SERVO_X);
  int y_position = analogRead(PIN_ANALOG_SERVO_Y);
  
  if (!debug)
    Serial.write('S');
  else
  {
    Serial.print(x_position);
    Serial.print("  ");
    Serial.print(y_position);
    Serial.print("  ||  ");

  }

  
  if (x_position > 520 && x_position < 530 && y_position > 495 && y_position < 505)
  {
    if (!debug)
    {
      Serial.write((byte)65);
      Serial.write((byte)76);
    }
    else
    {
      Serial.print("stop");
    }
    //Serial.write((byte)((SERVO_MAX + SERVO_MIN) / 2));
    //Serial.write((byte)((SERVO_MAX + SERVO_MIN) / 2));    
  } 
  else 
  {
    byte s1 = map(x_position, 0, 1023, SERVO_MIN, SERVO_MAX);
    byte s2 = map(y_position, 0, 1023, SERVO_MIN, SERVO_MAX);
   
    if (!debug)
    {
      Serial.write(s1);
      Serial.write(s2);
    }
    else
    {
    
    }
  } 
   if (debug)
    Serial.println(""); 
}

