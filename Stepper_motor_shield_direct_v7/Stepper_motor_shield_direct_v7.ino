// Stepper motor Shield Direct control

// X Motor
const int stepPinX = 2;  //X.Step
const int dirPinX = 5;  //X.Dir

// Y Motor
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir

// Z Motor
const int stepPinZ = 4;  //Z.Step
const int dirPinZ = 7;  //Z.Dir

// A Motor
const int stepPinA = 0;
const int dirPinA = 1;
 int x;
 int y;

void setup() {
  
 x = stepPinX,stepPinY,stepPinZ,stepPinA;
 y = dirPinX,dirPinY,dirPinZ,dirPinA;
  
  // Sets the 2 pins as Outputs
 pinMode(stepPinX,OUTPUT);
 pinMode(dirPinX,OUTPUT);

 pinMode(stepPinY,OUTPUT);
 pinMode(dirPinY,OUTPUT);

 pinMode(stepPinZ,OUTPUT);
 pinMode(dirPinZ,OUTPUT);

 pinMode(stepPinA,OUTPUT);
 pinMode(dirPinA,OUTPUT);
 
}

void loop() { 
  
  // X AND ALL MOTOR
digitalWrite(y,HIGH);

for(int x = 0; x < 200; x++) {
digitalWrite(x,HIGH);

delayMicroseconds(500);

digitalWrite(x,LOW);

delayMicroseconds(500);
}

digitalWrite(y,LOW); 

for(int x = 0; x < 400; x++) {
digitalWrite(x,HIGH);

delayMicroseconds(500);

digitalWrite(x,LOW);

delayMicroseconds(500);
}
delay(10);

}
