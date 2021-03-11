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
