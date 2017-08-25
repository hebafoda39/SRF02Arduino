int getDistance(int address){
    // put your main code here, to run repeatedly:
  Wire.beginTransmission(address);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51)); // Used for telling the sensor to send back value in cm
  Wire.endTransmission();
  // So this here code would tell the sensor to do its work
  delay(70); 
  Wire.beginTransmission(address);
  Wire.write(byte(0x02)); // Sets the register pointer
  Wire.endTransmission();

  Wire.requestFrom(112,2); // We request 2 bytes from the sensor
  if(2 <=Wire.available()){
      readingInCms = Wire.read();
      readingInCms = readingInCms << 8;
      readingInCms |= Wire.read();
      return readingInCms;
   }
}

