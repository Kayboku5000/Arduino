
#include <Wire.h>
const int blinkPin = 12; //msg received blink
const int blinkAZPin = 11; //msg received blink

int CompStep = 5;
int ElevStep = 1;
int AZstepDelaySpeed = 500;
int ELstepDelaySpeed = 500;

int CompassTestSouth = 90;
int CompassTestNorth = 270;
float headingDegrees;

int j;
int k;


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

void orbElvLED()   {
  if (orbElv > 0 && orbElv < 180) {
    digitalWrite(blinkPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(3000);                       // wait for a second
    digitalWrite(blinkPin, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
  }
  else {
    digitalWrite(blinkPin, LOW);
    delay(100);
  }
}


//-------------------------------------------------------------

void orbAziLED()   {
  if (orbAzi > 0 && orbAzi < 360) {
    digitalWrite(blinkAZPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(3000);                       // wait for a second
    digitalWrite(blinkAZPin, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
  }
  else {
    digitalWrite(blinkAZPin, LOW);
    delay(100);
  }
}



//-------------------------------------------------------------

void requestEvent() {
  Wire.write("hello "); // respond with message of 6 bytes
  // as expected by master
  // function that executes whenever data is requested by master
  // this function is registered as an event, see setup()
}

//-------------------------------------------------------------

void setup() {

  //Serial.begin(9600);
  Wire.begin(8);     // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  pinMode(blinkPin, OUTPUT);
  pinMode(blinkAZPin, OUTPUT);
}

//-------------------------------------------------------------


void loop() {
  // put your main code here, to run repeatedly:
  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    parseData();          //send to strtok to split data
    orbElvLED();
    orbAziLED();
    delay(100);

  }
  newData = false;
}
