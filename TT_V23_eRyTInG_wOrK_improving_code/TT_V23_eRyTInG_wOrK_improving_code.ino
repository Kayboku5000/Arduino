#include <ArduinoTrace.h>
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

int CompStep = 5;
int ElevStep = 1;
int AZstepDelaySpeed = 500;
int ELstepDelaySpeed = 500;

int CompassTestSouth = 90;
int CompassTestNorth = 270;
float headingDegrees;

int j;
int k;
float Bn55;

//--------------------------------------------------------------
// Receive with start- and end-markers combined with parsing
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing
// variables to hold the parsed data
char messageFromPC[numChars] = {0};
float orbAzi = 0.0;
float orbElv = 0.0;
boolean newData = false;

//------------------------------------------------------------------

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}
//---------------------------------------------------------

void parseData() {      // split the data into its parts
  char * strtokIndx; // this is used by strtok() as an index
  strtokIndx = strtok(tempChars, ",");     // get the first part - the string
  strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  orbAzi = atof(strtokIndx);     // convert this part to a float
  strtokIndx = strtok(NULL, ",");
  orbElv = atof(strtokIndx);     // convert this part to a float
}

//-------------------------------------------------------------

void Inclinometer() {
  sensors_event_t event;
  bno.getEvent(&event);
  Bn55 = (90 + ((float)event.orientation.y));
  //Serial.print("Inclinometer (degrees): "); Serial.print(Bn55);
  uint8_t sys, gyro, accel, mag = 0;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  delay(10);
}

//--------------------------------------

void Compass()  {
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  float declinationAngle = 5.23;
  heading += declinationAngle;
  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;
  headingDegrees = heading * 180 / M_PI;

  delay(10);
}

//-------------------------------------------

void AZforward() {
  digitalWrite(dirPinX, HIGH);
  for (int x = 0; x < CompStep; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(AZstepDelaySpeed);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(AZstepDelaySpeed);
  }
}

//---------------------------------------------------

void AZbackward() {
  digitalWrite(dirPinX, LOW);
  for (int x = 0; x < CompStep; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(AZstepDelaySpeed);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(AZstepDelaySpeed);
  }
}

//------------------------------------------------------

void ELforward() {
  digitalWrite(dirPinY, HIGH);
  for (int x = 0; x < ElevStep; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(ELstepDelaySpeed);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(ELstepDelaySpeed);
  }
}

//------------------------------------------------------

void ELbackward() {
  digitalWrite(dirPinY, LOW);
  for (int x = 0; x < ElevStep; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(ELstepDelaySpeed);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(ELstepDelaySpeed);
  }
}

void StartUp() {
  Compass();
  Inclinometer();


}


//****************************************************

void setup() {

  Serial.begin(9600);
  mag.begin();
  bno.begin();
  bno.setExtCrystalUse(true);
  pinMode(stepPinX, OUTPUT);   // X Motor / Azimuth
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);

}

//*************************************************************

void loop() {

  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    parseData();          //send to strtok to split data

    Compass();
    Inclinometer();

    if (orbElv > 170  && orbElv < 10) {
      delay(8000);
      TRACE();
    }

    else if (orbElv < 169  && orbElv > 11) {
      TRACE();

      while  (headingDegrees > orbAzi) {
        AZforward();
        Compass();
        newData == true;
        TRACE();
      }
      while (headingDegrees < orbAzi) {

        AZbackward();
        Compass();
        newData == true;
        TRACE();


      }


      while ( Bn55 > orbElv) {
        ELbackward();
        Inclinometer();
        TRACE();

      }

      while ( Bn55 < orbElv) {

        ELforward();
        Inclinometer();
        TRACE();

      }



      newData = false;
    }
  }
}
