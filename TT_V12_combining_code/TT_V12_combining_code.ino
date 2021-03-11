#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// X Motor  Rotation/ Azimuth
const int stepPinX = 2;  //X.Step
const int dirPinX = 5;  //X.Dir

// Y Motor / Elevation
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir

// Receive with start- and end-markers combined with parsing
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing
// variables to hold the parsed data
char messageFromPC[numChars] = {0};
float orbAzi = 0.0;
float orbElv = 0.0;

boolean newData = false;

//============

void setup() {

  // Sets the 2 pins as Outputs
  pinMode(stepPinX, OUTPUT);   // X Motor  Rotation/ Azimuth
  pinMode(dirPinX, OUTPUT);

  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);

  Serial.begin(115200);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);
  if (!bno.begin())
    delay(10);
  bno.setExtCrystalUse(true);
}

//============

void loop() {

  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    // this temporary copy is necessary to protect the original data
    //   because strtok() used in parseData() replaces the commas with \0
    parseData();          //send to strtok to split data
    showParsedData();    //not needed, only for serial print of data
    sensY();             //BNo055 data pickup
    motorsMove();      //azimuth motor stepping
    sensors_event_t event;    //BNo055 loop does not seem to pickup event data from function, this needs to be in the loop
    bno.getEvent(&event);     //BNo055 loop does not seem to pickup event data from function, this needs to be in the loop
    if (orbElv > ((float)event.orientation.y)) {          //elevation
      ELforwardStep();
    }

    else if (orbElv < ((float)event.orientation.y)) {
      ELbackwardStep();
    }
    else {
      digitalWrite(stepPinY, LOW);
    }
    newData = false;
  }
}

//============

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

//============

void parseData() {      // split the data into its parts
  char * strtokIndx; // this is used by strtok() as an index
  strtokIndx = strtok(tempChars, ",");     // get the first part - the string
  strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  orbAzi = atof(strtokIndx);     // convert this part to an integer
  strtokIndx = strtok(NULL, ",");
  orbElv = atof(strtokIndx);     // convert this part to a float
}

//============

void showParsedData() {
  Serial.print("Message ");
  Serial.println(messageFromPC);
  Serial.print("Integer ");
  Serial.println(orbAzi);
  Serial.print("Float ");
  Serial.println(orbElv);
}

void motorsMove() {                 //Rotation/ Azimuth
  if (orbAzi > 1) {
    AZforwardStep();
  }
}

void motorsMove2() {             //Elevation

  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
  int Mstop = (orbElv == ((float)event.orientation.y));

  if (orbElv > ((float)event.orientation.y)) {
    ELforwardStep();
  }

  else if (orbElv < ((float)event.orientation.y)) {
    ELbackwardStep();
  }
  else {
    digitalWrite(stepPinY, LOW);
  }
}

void sensY() {
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
}



void ELforwardStep() {           //elevation forward
  digitalWrite(dirPinY, HIGH); // Enables the motor to move forward
  // Makes 1 pulse for making one step
  for (int w = 0 ; w < 50 ; w++)  {     //make w < 100 for 100 steps at once, or w<1 for 1 step at a time
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(2500);
  }
}

void ELbackwardStep() {           //elevation backward
  digitalWrite(dirPinY, LOW); // Enables the motor to move reverse
  // Makes 1 pulse for making one step
  for (int z = 0; z < 50 ; z++) {      //make z < 100 for 100 steps at once, or z<1 for 1 step at a time
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(2500);
  }
}

void AZforwardStep() {              //azimuth forward
  digitalWrite(dirPinX, HIGH); // Enables the motor to move forward
  // Makes 1 pulse for making one step
  for (int y = 0; y < 50; y++) {       //make y < 100 for 100 steps at once, or y<1 for 1 step at a time
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(2500);
  }
}

void AZbackwardStep() {               //azimuth backward
  digitalWrite(dirPinX, LOW); // Enables the motor to move reverse
  // Makes 1 pulse for making one step
  for (int x = 0; x < 50; x++) {    //make x < 100 for 100 steps at once, or x<1 for 1 step at a time
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(2500);
  }
}
