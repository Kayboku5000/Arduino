// TT SATELLITE TRACKER

// X Motor
const int stepPinX = 2;  //X.Step
const int dirPinX = 5;  //X.Dir

// Y Motor
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir


void setup() {
  // Sets the 2 pins as Outputs
 pinMode(stepPinX,OUTPUT);
 pinMode(dirPinX,OUTPUT);

 pinMode(stepPinY,OUTPUT);
 pinMode(dirPinY,OUTPUT);

Serial.begin(9600);

}

void loop() {

if (Serial.available()) {
  Serial.println;
}


}
