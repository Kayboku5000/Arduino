
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


  
    Serial.begin(9600);
    
}

//============

void loop() {
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
        digitalWrite(dirPinX,HIGH); // Enables the motor to move in a particular direction
        // Makes 200 pulses for making one full cycle rotation
        for(int x = 0; x < 200; x++) {
        digitalWrite(stepPinX,HIGH);
        delayMicroseconds(1500);
        digitalWrite(stepPinX,LOW);
        delayMicroseconds(1500);
    }
    }
    }
void motorsMove2() {                //Elevation
    if(floatFromPC > 1 && floatFromPC <179 ) {
        
        val2 = map(floatFromPC, 1, 179, 1, 200); 
        digitalWrite(dirPinY,HIGH); // Enables the motor to move in a particular direction
        // Makes 200 pulses for making one full cycle rotation
        for (int x = 0; x < val2; x++) {
        digitalWrite(stepPinY,HIGH);
        delayMicroseconds(1500);
        digitalWrite(stepPinY,LOW);
        delayMicroseconds(1500);
}      
}
}
