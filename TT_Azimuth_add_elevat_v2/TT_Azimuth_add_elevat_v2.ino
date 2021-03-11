const int stepPinX = 2;  //X.Step
const int dirPinX = 5;  //X.Dir
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir



int Compass = 600;
int Elevation = 400;

void AZforward() {
  digitalWrite(dirPinX, HIGH);
  for (int x = 0; x < Compass; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(500);
  }
}

void AZbackward() {
  digitalWrite(dirPinX, LOW);
  for (int x = 0; x < Compass; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(500);
  }
}

void ELforward() {
  digitalWrite(dirPinY, HIGH);
  for (int x = 0; x < Elevation; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(500);
  }
}

void ELbackward() {
  digitalWrite(dirPinY, LOW);
  for (int x = 0; x < Elevation; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(500);
  }
}


void setup() {
  pinMode(stepPinX, OUTPUT);   // X Motor / Azimuth
  pinMode(dirPinX, OUTPUT);
  pinMode(stepPinY, OUTPUT);   // Y Motor / Elevation
  pinMode(dirPinY, OUTPUT);

}

void loop() {
  AZforward();
  delay(1000);
  AZbackward();
  delay(1000);
  
}
