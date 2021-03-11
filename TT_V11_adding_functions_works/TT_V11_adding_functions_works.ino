
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

// Example 5 - Receive with start- and end-markers combined with parsing

const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

      // variables to hold the parsed data
char messageFromPC[numChars] = {0};
float integerFromPC = 0.0;
float floatFromPC = 0.0;

float val2;      // variable to convert output to motorsteps

boolean newData = false;

//============

void setup() {

 // Sets the 2 pins as Outputs
 pinMode(stepPinX,OUTPUT);    // X Motor  Rotation/ Azimuth
 pinMode(dirPinX,OUTPUT);

 pinMode(stepPinY,OUTPUT);    // Y Motor / Elevation
 pinMode(dirPinY,OUTPUT);
 
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


//============

void loop() {
    sensY();
    recvWithStartEndMarkers();
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
        showParsedData();
        motorsMove();
        motorsMove2();
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

    strtokIndx = strtok(tempChars,",");      // get the first part - the string
    strcpy(messageFromPC, strtokIndx); // copy it to messageFromPC
 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC = atof(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ",");
    floatFromPC = atof(strtokIndx);     // convert this part to a float

}

//============

void showParsedData() {
    Serial.print("Message ");
    Serial.println(messageFromPC);
    Serial.print("Integer ");
    Serial.println(integerFromPC);
    Serial.print("Float ");
    Serial.println(floatFromPC);
}

void motorsMove() {                 //Rotation/ Azimuth
    if (integerFromPC > 1){    
        AZforwardStep();    
    }
}
    
void motorsMove2() {             //Elevation
    
  sensors_event_t event;
  bno.getEvent(&event);
  Serial.print("    y:");
  Serial.println((float)event.orientation.y);
  delay(BNO055_SAMPLERATE_DELAY_MS);
  int Mstop = (floatFromPC == ((float)event.orientation.y));
    
    if(floatFromPC >((float)event.orientation.y)){
        ELforwardStep();
    }
    
    else if(floatFromPC <((float)event.orientation.y)){    
        ELbackwardStep();  
    }
     else { digitalWrite(stepPinY,LOW);
}
}

void ELforwardStep(){
        digitalWrite(dirPinY,HIGH); // Enables the motor to move forward
        // Makes 1 pulse for making one step
        for (int w = 0 ; w < 1 ; w++)  {
        digitalWrite(stepPinY,HIGH);
        delayMicroseconds(1500);
        digitalWrite(stepPinY,LOW);
        delayMicroseconds(1500); }  
}

void ELbackwardStep(){
        digitalWrite(dirPinY,LOW); // Enables the motor to move reverse
        // Makes 1 pulse for making one step
        for(int z = 0; z < 1 ; z++) {
        digitalWrite(stepPinY,HIGH);
        delayMicroseconds(1500);
        digitalWrite(stepPinY,LOW);
        delayMicroseconds(1500); }  
}

void AZforwardStep(){
        digitalWrite(dirPinX,HIGH); // Enables the motor to move forward
        // Makes 1 pulse for making one step
        for(int x = 0; x < 1; x++) {
        digitalWrite(stepPinX,HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPinX,LOW);
        delayMicroseconds(500);}
}

void AZbackwardStep(){
        digitalWrite(dirPinX,LOW); // Enables the motor to move reverse
        // Makes 1 pulse for making one step
        for(int x = 0; x < 1; x++) {
        digitalWrite(stepPinX,HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPinX,LOW);
        delayMicroseconds(500);}
}
