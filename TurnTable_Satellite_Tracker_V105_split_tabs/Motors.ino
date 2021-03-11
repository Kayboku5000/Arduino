void AZforward() {
  digitalWrite(dirPinX, HIGH);
  for (int x = 0; x < CompStep; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(AZstepDelaySpeed);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(AZstepDelaySpeed);
  }
}





//---------------------------------------------------

void AZbackward() {
  digitalWrite(dirPinX, LOW);
  for (int x = 0; x < CompStep; x++) {
    digitalWrite(stepPinX, HIGH);
    delayMicroseconds(AZstepDelaySpeed);
    digitalWrite(stepPinX, LOW);
    delayMicroseconds(AZstepDelaySpeed);
  }
}


//****************************************************


void ELforward() {
  digitalWrite(dirPinY, HIGH);
  for (int x = 0; x < ElevStep; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(ELstepDelaySpeed);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(ELstepDelaySpeed);
  }
}

//------------------------------------------------------

void ELbackward() {
  digitalWrite(dirPinY, LOW);
  for (int x = 0; x < ElevStep; x++) {
    digitalWrite(stepPinY, HIGH);
    delayMicroseconds(ELstepDelaySpeed);
    digitalWrite(stepPinY, LOW);
    delayMicroseconds(ELstepDelaySpeed);
  }
}
