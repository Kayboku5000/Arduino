#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (1000)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// Y Motor
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir
int  x = 1;



void setup() {
  Serial.begin(115200);
pinMode(stepPinY,OUTPUT);
pinMode(dirPinY,OUTPUT);
if(!bno.begin())
  delay(10);
  bno.setExtCrystalUse(true);
}

void sensY() {
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
}  

void loop(){
    while (x < 100) {  
        sensY();      
        digitalWrite(dirPinY,HIGH);
        digitalWrite(stepPinY,HIGH);
        delayMicroseconds(1500);
        digitalWrite(stepPinY,LOW);
        delayMicroseconds(1500);
        delay (1500);
        }
}
