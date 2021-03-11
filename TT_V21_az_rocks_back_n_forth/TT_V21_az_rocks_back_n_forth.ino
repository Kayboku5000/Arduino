#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

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
//float Bn55;
//============

void displaySensorDetails(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
 
}




void setup() {
Serial.begin(115200);
  // Sets the 2 pins as Outputs
  pinMode(stepPinX, OUTPUT);   // X Motor  Rotation/ Azimuth
  pinMode(dirPinX, OUTPUT);

  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);

 // Serial.begin(115200);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);
  if (!bno.begin())
    delay(10);
  bno.setExtCrystalUse(true);


  
  
  
  /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
   
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();


}

//============

void loop() {


 /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
 
 

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
  
  
  delay(100);





  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    // this temporary copy is necessary to protect the original data
    //   because strtok() used in parseData() replaces the commas with \0
    parseData();          //send to strtok to split data
    showParsedData();    //not needed, only for serial print of data
    
    //my coding

 // start of adding azimuth rotation with compass
    
//   motorsMove();      //azimuth motor stepping

 if ((orbAzi > headingDegrees -10) && (orbAzi < headingDegrees +10)) {
    delay(8000);
   }
    else if  (orbAzi  > headingDegrees && orbAzi< 359) {          //azimuth
      AZforwardStep();
    }

    else if (orbAzi < headingDegrees && orbAzi >1 ) {
      AZbackwardStep();
    }
 
    
    newData = false;

  
//end of adding azimuth rotation

    // BNO055 data pickup
    sensors_event_t event;    //BNo055 loop does not seem to pickup event data from function, this needs to be in the loop
    bno.getEvent(&event);     //BNo055 loop does not seem to pickup event data from function, this needs to be in the loop
    delay(BNO055_SAMPLERATE_DELAY_MS);
    int Bn55 = 90 + (((float)event.orientation.y));
   

   if ((orbElv > Bn55 -1) && (orbElv < Bn55 +1)) {
    delay(8000);
   }
    else if  (orbElv  > Bn55 && orbElv< 179) {          //elevation
      ELforwardStep();
    }

    else if (orbElv < Bn55 && orbElv >1 ) {
      ELbackwardStep();
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
 
}



void motorsMove2() {             //Elevation

  sensors_event_t event;
  bno.getEvent(&event);
 
  delay(BNO055_SAMPLERATE_DELAY_MS);
  

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
  
  delay(BNO055_SAMPLERATE_DELAY_MS);
}



void ELforwardStep() {           //elevation forward
  digitalWrite(dirPinY, HIGH); // Enables the motor to move forward
  // Makes 1 pulse for making one step
  for (int w = 0 ; w < 1 ; w++)  {     //make w < 100 for 100 steps at once, or w<1 for 1 step at a time
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(2500);
  }
}

void ELbackwardStep() {           //elevation backward
  digitalWrite(dirPinY, LOW); // Enables the motor to move reverse
  // Makes 1 pulse for making one step
  for (int z = 0; z < 1 ; z++) {      //make z < 100 for 100 steps at once, or z<1 for 1 step at a time
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(2500);
  }
}

void AZforwardStep() {              //azimuth forward
  digitalWrite(dirPinX, HIGH); // Enables the motor to move forward
  // Makes 1 pulse for making one step
  for (int y = 0; y < 20; y++) {       //make y < 100 for 100 steps at once, or y<1 for 1 step at a time
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(2500);
  }
}

void AZbackwardStep() {               //azimuth backward
  digitalWrite(dirPinX, LOW); // Enables the motor to move reverse
  // Makes 1 pulse for making one step
  for (int x = 0; x < 20; x++) {    //make x < 100 for 100 steps at once, or x<1 for 1 step at a time
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(2500);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(2500);
  }
}
