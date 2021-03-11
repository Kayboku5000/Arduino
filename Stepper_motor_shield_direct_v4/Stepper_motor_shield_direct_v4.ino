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
const int stepPinA = 0;  //A.Step
const int dirPinA = 1;  //A.Dir



void setup() {
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
digitalWrite(dirPinX,HIGH);
digitalWrite(dirPinY,HIGH);
digitalWrite(dirPinZ,HIGH);
digitalWrite(dirPinA,HIGH);


for(int x = 0; x < 200; x++) {
digitalWrite(stepPinX,HIGH);
digitalWrite(stepPinY,HIGH);
digitalWrite(stepPinZ,HIGH);
digitalWrite(stepPinA,HIGH);

delayMicroseconds(500);

digitalWrite(stepPinX,LOW);
digitalWrite(stepPinY,LOW);
digitalWrite(stepPinZ,LOW);
digitalWrite(stepPinA,LOW);

delayMicroseconds(500);
}

digitalWrite(dirPinX,LOW); 
digitalWrite(dirPinY,LOW); 
digitalWrite(dirPinZ,LOW); 
digitalWrite(dirPinA,LOW); 

for(int x = 0; x < 400; x++) {
digitalWrite(stepPinX,HIGH);
digitalWrite(stepPinY,HIGH);
digitalWrite(stepPinZ,HIGH);
digitalWrite(stepPinA,HIGH);

delayMicroseconds(500);

digitalWrite(stepPinX,LOW);
digitalWrite(stepPinY,LOW);
digitalWrite(stepPinZ,LOW);
digitalWrite(stepPinA,LOW);

delayMicroseconds(500);
}
delay(10);

}
