// TurnTable Satellite Tracker with extra tabs

//
// It is currently fully functioning and can track satellites across the sky reading telemetry from Orbitron
//
// It is however still a work in progress, and needs some more refinement


#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
int ADXLAddress = 0x1E;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

float headingDegrees;
float Bn55;

//--------------------------------------------------------------



const int stepPinX = 22;  //X.Step
const int dirPinX = 23;  //X.Dir
const int stepPinY = 24;  //Y.Step
const int dirPinY = 25;  //Y.Dir
int CompStep = 1;
int ElevStep = 1;
int AZstepDelaySpeed = 500;
int ELstepDelaySpeed = 500;

// averaging filter Compass
const int CnumReadings = 20;

int Creadings[CnumReadings];      // the readings from the analog input
int CreadIndex = 0;              // the index of the current reading
int Ctotal = 0;                  // the running total
int Compassaverage = 0;                // the average
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

//----------------------------------------------------------------

void setup() {

  Serial.begin(9600);
  mag.begin();
  bno.begin();
  bno.setExtCrystalUse(true);


  pinMode(stepPinX, OUTPUT);   // X Motor / Azimuth
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);



  // Setup the LCD display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // Print message on first line
  lcd.print("startup");

  for (int CthisReading = 0; CthisReading < CnumReadings; CthisReading++) { //compass filter
    Creadings[CthisReading] = 0;
  }


  // StartupProgram();


}


//***********************************************************************************


void loop() {


  Compass();
  Inclinometer();
  lcdDisplay();


  recvWithStartEndMarkers();
  if (newData == true) {
    strcpy(tempChars, receivedChars);
    parseData();          //send to strtok to split data

    Compass();
    Inclinometer();
    lcdDisplay();


    if (orbElv > 170  && orbElv < 10) {
      delay(6000);
      Compass();
      Inclinometer();
      lcdDisplay();

    }

    else if (orbElv < 169  && orbElv > 11) {
      Compass();
      Inclinometer();
      lcdDisplay();



      while  (Compassaverage > orbAzi) {
        AZforward();
        Compass();
        
        

      }
      while (Compassaverage < orbAzi) {

        AZbackward();
        Compass();
        
        

      }


      while ( Bn55 > orbElv) {
        ELbackward();
        
        Inclinometer();
        lcdDisplay();


      }

      while ( Bn55 < orbElv) {

        ELforward();
        
        Inclinometer();
        lcdDisplay();


      }

    }

    newData = false;
  }



}
