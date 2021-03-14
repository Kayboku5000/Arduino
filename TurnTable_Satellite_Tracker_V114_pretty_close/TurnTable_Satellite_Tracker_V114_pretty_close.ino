// TurnTable Satellite Tracker being recombined
//
// It is currently fully functioning and can track satellites across the sky reading telemetry from Orbitron
//
// It is however still a work in progress, and needs some more refinement
#define BNO055_SAMPLERATE_DELAY_MS (100)
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
int CompStep; // the amount of steps the stepper will take at once
int ElevStep; // the amount of steps the stepper will take at once
int AZstepDelaySpeed;
int ELstepDelaySpeed;



//--------------------------------------------------------------

// averaging filter Compass
//const int CnumReadings = 5;

//int Creadings[CnumReadings];      // the readings from the analog input
//int CreadIndex = 0;              // the index of the current reading
//int Ctotal = 0;                  // the running total
//int Compassaverage;                // the average
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

int g;
int h;


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
  g = orbAzi - headingDegrees;
  h = orbElv - Bn55;
  //  int j;
  //  if (j<5){
  Orbitron_Telem_Recieve();
  Compass();
  Inclinometer();
  lcdDisplay();
  //  }
  //***********************************************************************************





  if  ((g < 5) &&  (g > -5)) {

    if (orbAzi > headingDegrees) {
      AZstepDelaySpeed = 1500;
      CompStep = 3;
      digitalWrite(dirPinX, LOW);
      AZforward();


    }
    else if (orbAzi < headingDegrees) {
      AZstepDelaySpeed = 1500;
      CompStep = 3;
      digitalWrite(dirPinX, HIGH);
      AZforward();

    }
  }

  if ((g > 5) ||  (g < -5)) {

    if (orbAzi > headingDegrees)  {

     
      CompStep = g;
      AZstepDelaySpeed = 500;
      digitalWrite(dirPinX, LOW);
      AZforward();


    }

    else if (orbAzi < headingDegrees) {
     
      CompStep = (g * -1);
      AZstepDelaySpeed = 500;
      digitalWrite(dirPinX, HIGH);
      AZforward();


    }
  }

  //  j = j + 1;




  //***********************************************************************************
  if (orbElv > 170  && orbElv < 10) {
    digitalWrite(stepPinY, LOW);
  }

  else if (orbElv < 169  && orbElv > 11) {


    if ((h < 5) && (h > -5)) {
      if ( Bn55 > orbElv) {
        ELstepDelaySpeed = 1000;
        ElevStep = 1;
        ELbackward();

      }
      else if ( Bn55 < orbElv) {
        ELstepDelaySpeed = 1000;
        ElevStep = 1;
        ELforward();

      }
    }


    if ((h > 5) || (h < -5)) {
      if   ( Bn55 > orbElv) {
        ELstepDelaySpeed = 50;
        ElevStep = 5;
        ELbackward();

      }

      else if ( Bn55 < orbElv) {
        ELstepDelaySpeed = 50;
        ElevStep = 5;
        ELforward();



      }
    }

  }
  newData = false;
}
