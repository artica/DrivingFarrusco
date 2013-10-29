void checkJoystickMotor()
{
  int linearVelocity, rotationVelocity;
  
  int x_position = analogRead(PIN_ANALOG_MOTOR_X);
  int y_position = analogRead(PIN_ANALOG_MOTOR_Y);

  if (!debug)
    Serial.write('M');
  
  if (x_position > X_THRESHOLD_LOW && x_position < X_THRESHOLD_HIGH && y_position > Y_THRESHOLD_LOW && y_position < Y_THRESHOLD_HIGH) 
  {
    if (!debug)
    {
      Serial.write((byte)0);
      Serial.write((byte)0);
      Serial.write((byte)0);
      Serial.write((byte)0);
    }
  
  } else {
    
    int linearVelocity = map(x_position, 0, 1023, FARRUSCO_MIN_VELOCITY, FARRUSCO_MAX_VELOCITY);
    int rotationVelocity = map(y_position, 0, 1023, FARRUSCO_MIN_VELOCITY, FARRUSCO_MAX_VELOCITY);
    int vel1 = linearVelocity + rotationVelocity;
    
    vel1=((vel1>255)?255:(vel1<-255)?-255:vel1);
    int vel2 = linearVelocity - rotationVelocity;
    vel2=((vel2>255)?255:(vel2<-255)?-255:vel2);
    
    if (!debug)
    {
      Serial.write((byte)(vel1>>8));
      Serial.write((byte)(vel1 & 0xFF));
      Serial.write((byte)(vel2>>8));
      Serial.write((byte)(vel2 & 0xFF));
    }
    //Serial.write(linearVelocity + rotationVelocity); Serial.write(linearVelocity - rotationVelocity);
  } 
}
