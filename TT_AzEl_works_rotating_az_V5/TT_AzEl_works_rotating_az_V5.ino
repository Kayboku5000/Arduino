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

int CompStep = 10;
int ElevStep = 400;
int AZstepDelaySpeed = 1500;
int ELstepDelaySpeed = 1500;

int CompassTestSouth = 90;
int CompassTestNorth = 270;
float headingDegrees;

int j;
int k;

void Inclinometer() {
  sensors_event_t event;
  bno.getEvent(&event);
  int Bn55 = 90 + ((float)event.orientation.y);
  Serial.print("Inclinometer (degrees): "); Serial.print(Bn55);
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  delay(10);
}

void Compass()  {
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  if (heading < 0)
    heading += 2 * PI;
  headingDegrees = heading * 180 / M_PI;
  Serial.print("   Compass (degrees): "); Serial.println(headingDegrees);
  delay(10);
}


void AZforward() {
  digitalWrite(dirPinX, HIGH);
  for (int x = 0; x < CompStep; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(AZstepDelaySpeed);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(AZstepDelaySpeed);
  }
}

void AZbackward() {
  digitalWrite(dirPinX, LOW);
  for (int x = 0; x < CompStep; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(AZstepDelaySpeed);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(AZstepDelaySpeed);
  }
}

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

  Compass();
  while  (headingDegrees > 300.00) {
    AZforward();
    //AZbackward();
    Compass();
    delay(100);

  }
  while (headingDegrees < 340.0) {

    AZbackward();
    Compass();
    delay(100);




  }
}
