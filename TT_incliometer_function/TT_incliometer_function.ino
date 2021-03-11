#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void Inclinometer() {
 sensors_event_t event;
  bno.getEvent(&event);
  Serial.println((float)event.orientation.y);
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  delay(BNO055_SAMPLERATE_DELAY_MS);  
}

void setup()
{
  Serial.begin(115200);
  bno.begin();
  bno.setExtCrystalUse(true);
}

void loop()
{
 Inclinometer();
}
