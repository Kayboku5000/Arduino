#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
int ADXLAddress = 0x1E;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void Compass()  {
  
 sensors_event_t event; 
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  if(heading < 0)
    heading += 2*PI;
  float headingDegrees = heading * 180/M_PI; 
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  delay(500);  
}



void setup() 
{
  Serial.begin(9600); 
 mag.begin();
}

void loop() 
{
 Compass();
}
