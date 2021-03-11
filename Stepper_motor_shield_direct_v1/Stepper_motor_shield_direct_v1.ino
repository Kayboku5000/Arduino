const int stepPin = 2;  //X.Step
const int dirPin = 5;  //X.Dir

int Compass = 600;

void AZforward() {
digitalWrite(dirPin,HIGH); 
for(int x = 0; x < Compass; x++) {
digitalWrite(stepPin,HIGH);
delayMicroseconds(500);
digitalWrite(stepPin,LOW);
delayMicroseconds(500);  
}
}

void AZbackward() {
digitalWrite(dirPin,LOW); 
for(int x = 0; x < Compass; x++) {
digitalWrite(stepPin,HIGH);
delayMicroseconds(500);
digitalWrite(stepPin,LOW);
delayMicroseconds(500);  
}
}

void setup() {
 pinMode(stepPin,OUTPUT);
 pinMode(dirPin,OUTPUT);
}

void loop() {
AZforward();
delay(1000); 
AZbackward();
delay(1000);
}
