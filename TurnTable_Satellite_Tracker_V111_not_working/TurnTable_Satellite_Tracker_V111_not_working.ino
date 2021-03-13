// TurnTable Satellite Tracker being recombined
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

float ComPa;
float ComPb;

//--------------------------------------------------------------

const int stepPinX = 22;  //X.Step
const int dirPinX = 23;  //X.Dir
const int stepPinY = 24;  //Y.Step
const int dirPinY = 25;  //Y.Dir
int CompStep; // the amount of steps the stepper will take at once
int ElevStep; // the amount of steps the stepper will take at once
int AZstepDelaySpeed = 500;
int ELstepDelaySpeed = 500;

//--------------------------------------------------------------

// averaging filter Compass
const int CnumReadings = 5;

//int Creadings[CnumReadings];      // the readings from the analog input
//int CreadIndex = 0;              // the index of the current reading
//int Ctotal = 0;                  // the running total
int Compassaverage;                // the average
//--------------------------------------------------------------

// Receive with start- and end-markers combined with parsing
const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing
// variables to hold the parsed data
char messageFromPC[numChars] = {0};
float orbAzi;
float orbElv;
boolean newData = false;

//----------------------------------------------------------------

void setup() {
  delay(3000); //10second startup
  Serial.begin(9600);
  mag.begin();
  bno.begin();
  bno.setExtCrystalUse(true);
  delay(4000);
  pinMode(stepPinX, OUTPUT);   // X Motor / Azimuth
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);
  delay(1000);
  // Setup the LCD display
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // Print message on first line
  lcd.print("startup");
  delay(2000);
  //  for (int CthisReading = 0; CthisReading < CnumReadings; CthisReading++) { //compass filter
  //    Creadings[CthisReading] = 0;
  //  }
}
//***********************************************************************************

void loop() {

  Orbitron_Telem_Recieve();
  Compass();
  Inclinometer();
  lcdDisplay();

  //***********************************************************************************

  int a = orbAzi;
  int b = Compassaverage;

// between zero and 90*******************************************************************
  if (a > 0 && a < 90) {
          if (b > 90 && b < 245) {
          CompStep = 100;
          AZforward();
          }
          else if (b < 360 && b > 245) {
          CompStep = 100;
          AZbackward();
          
          }
          else if (b > 0 && b < 90) {
          CompStep = 10;
              
              if (a > b) {
                CompStep = 10;
              AZforward();
              
              }
              else if (a < b) {
                CompStep = 10;
              AZbackward();
              
          }
          }
      else if (a == b) {
        CompStep = 1;
        
              if (a > b) {
                 CompStep = 1;
              AZforward();
              }

              else if (a < b) {
                 CompStep = 1;
              AZbackward();
              
              }
      }

    }



// between 90 and 180****************************************************************

 if (a > 90 && a < 180) {
      if (b > 180 && b < 335) {
      CompStep = 100;
      AZforward();
      }
          else if (b < 90 && b > 335) {
          CompStep = 100;
          AZbackward();
          
      }
          else if (b > 90 && b < 180) {
          CompStep = 10;
              
              if (a > b) {
                CompStep = 10;
              AZforward();
              }
              
              else if (a < b) {
                CompStep = 10;
              AZbackward();
              
              }
          }
      else if (a == b) {
        CompStep = 1;
        
              if (a > b) {
                CompStep = 1;
              AZforward();
              }

              else if (a < b) {
                CompStep = 1;
              AZbackward();
              
              }
      }

    }

// between 180 and 270****************************************************************

 if (a > 180 && a < 270) {
      if (b > 270 && b < 45) {
      CompStep = 100;
      AZforward();
      }
          else if (b < 180 && b > 45) {
          CompStep = 100;
          AZbackward();
          
      }
          else if (b > 180 && b < 270) {
          CompStep = 10;
              
              if (a > b) {
                CompStep = 10;
              AZforward();
              }
              
              else if (a < b) {
                CompStep = 10;
              AZbackward();
              
              }
          }
      else if (a == b) {
        CompStep = 1;
        
              if (a > b) {
                CompStep = 1;
              AZforward();
              }

              else if (a < b) {
                CompStep = 1;
              AZbackward();
              
              }
      }

    }

// between 270 and 360****************************************************************

 if (a > 270 && a < 360) {
      if (b > 360 && b < 135) {
      CompStep = 100;
      AZforward();
      }
          else if (b < 270 && b > 135) {
          CompStep = 100;
          AZbackward();
          
      }
          else if (b > 270 && b < 360) {
          CompStep = 10;
              
              if (a > b) {
                CompStep = 10;
              AZforward();
              }
              
              else if (a < b) {
                CompStep = 10;
              AZbackward();
              
              }
          }
      else if (a == b) {
        CompStep = 1;
        
              if (a > b) {
                 CompStep = 1;
              AZforward();
              }

              else if (a < b) {
                 CompStep = 1;
              AZbackward();
              
              }
      }

    }





    //***********************************************************************************
    if (orbElv > 170  && orbElv < 10) {
      digitalWrite(stepPinY, LOW);
    }

    else if (orbElv < 169  && orbElv > 11) {

      if   ( Bn55 > orbElv) {
        ELbackward();
      }

      else if ( Bn55 < orbElv) {
        ELforward();
      }
    }
    newData = false;

  }
