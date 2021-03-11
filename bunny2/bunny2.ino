#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (1000)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void setup()
{
  Serial.begin(115200);
  if(!bno.begin())
  delay(10);
  bno.setExtCrystalUse(true);  
}

void loop()
{
 sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
}
