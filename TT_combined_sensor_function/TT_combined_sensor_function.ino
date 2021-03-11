#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
int ADXLAddress = 0x1E;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void Inclinometer() {
  sensors_event_t event;
  bno.getEvent(&event);
  int Bn55 = 90 + ((float)event.orientation.y);
  Serial.print("Inclinometer (degrees): ");Serial.print(Bn55);
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  delay(100);
}

void Compass()  {

  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  if (heading < 0)
    heading += 2 * PI;
  float headingDegrees = heading * 180 / M_PI;
  Serial.print("   Compass (degrees): "); Serial.println(headingDegrees);
  delay(100);
}



void setup()
{
  Serial.begin(115200);
  mag.begin();
  bno.begin();
  bno.setExtCrystalUse(true);

}

void loop()
{
  Compass();
  Inclinometer();
}
