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

void loop() { // X MOTOR
digitalWrite(dirPinX,HIGH); // Enables the motor to move in a particular direction
// Makes 200 pulses for making one full cycle rotation
for(int x = 0; x < 200; x++) {
digitalWrite(stepPinX,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinX,LOW);
delayMicroseconds(500);
}
delay(1000); // One second delay

digitalWrite(dirPinX,LOW); //Changes the Rotations Direction
// Makes 400 pulses for making 2 full cycle rotation
for(int x = 0; x < 400; x++) {
digitalWrite(stepPinX,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinX,LOW);
delayMicroseconds(500);
}

  //   Y MOTOR
digitalWrite(dirPinY,HIGH); // Enables the motor to move in a particular direction
// Makes 200 pulses for making one full cycle rotation
for(int x = 0; x < 200; x++) {
digitalWrite(stepPinY,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinY,LOW);
delayMicroseconds(500);
}
delay(1000); // One second delay

digitalWrite(dirPinY,LOW); //Changes the Rotations Direction
// Makes 400 pulses for making 2 full cycle rotation
for(int x = 0; x < 400; x++) {
digitalWrite(stepPinY,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinY,LOW);
delayMicroseconds(500);
}


  //  Z MOTOR
digitalWrite(dirPinZ,HIGH); // Enables the motor to move in a particular direction
// Makes 200 pulses for making one full cycle rotation
for(int x = 0; x < 200; x++) {
digitalWrite(stepPinZ,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinZ,LOW);
delayMicroseconds(500);
}
delay(1000); // One second delay

digitalWrite(dirPinZ,LOW); //Changes the Rotations Direction
// Makes 400 pulses for making 2 full cycle rotation
for(int x = 0; x < 400; x++) {
digitalWrite(stepPinZ,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinZ,LOW);
delayMicroseconds(500);
}

 //  A MOTOR
digitalWrite(dirPinA,HIGH); // Enables the motor to move in a particular direction
// Makes 200 pulses for making one full cycle rotation
for(int x = 0; x < 200; x++) {
digitalWrite(stepPinA,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinA,LOW);
delayMicroseconds(500);
}
delay(1000); // One second delay

digitalWrite(dirPinA,LOW); //Changes the Rotations Direction
// Makes 400 pulses for making 2 full cycle rotation
for(int x = 0; x < 400; x++) {
digitalWrite(stepPinA,HIGH);
delayMicroseconds(500);
digitalWrite(stepPinA,LOW);
delayMicroseconds(500);
}




delay(1000);

}
