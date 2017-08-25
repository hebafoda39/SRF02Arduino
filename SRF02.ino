#include<Wire.h> // Library for I2C its a 2 wire protocol

void setup() {
  // put your setup code here, to run once:
 Wire.begin(); 
 Serial.begin(115200);
}
int readingInCms = 0;
int address = 112; // 0x70
// The original address is 0xE0
void loop() {
      readingInCms= getDistance(address);
      Serial.print("Object Detected at: ");
      Serial.println(readingInCms); 
      delay(200);
}
