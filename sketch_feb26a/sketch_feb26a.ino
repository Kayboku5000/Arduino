

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
int ADXLAddress = 0x1E;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

const int stepPinX = 2;  //X.Step
const int dirPinX = 5;  //X.Dir
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir

int CompStep = 100;
int ElevStep = 100;
int AZstepDelaySpeed = 1500;
int ELstepDelaySpeed = 1500;

int CompassTestSouth = 90;
int CompassTestNorth = 270;
float headingDegrees;

int j;
int k;
int Bn55;



void ELforward() {
  digitalWrite(dirPinY, HIGH);
  for (int x = 0; x < ElevStep; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(ELstepDelaySpeed);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(ELstepDelaySpeed);
  }
}

void ELbackward() {
  digitalWrite(dirPinY, LOW);
  for (int x = 0; x < ElevStep; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(ELstepDelaySpeed);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(ELstepDelaySpeed);
  }
}








void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  mag.begin();
  bno.begin();
  bno.setExtCrystalUse(true);
  pinMode(stepPinX, OUTPUT);   // X Motor / Azimuth
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);





}

void loop() {
  // put your main code here, to run repeatedly:

  

    while (true) {
      ELbackward();
      
      delay(100);
    }

   
    


}
