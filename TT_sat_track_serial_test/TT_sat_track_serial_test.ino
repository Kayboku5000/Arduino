
char AZ;
char EL;

const int stepPinX = 2;  //X.Step
const int dirPinX = 5;  //X.Dir

// Y Motor
const int stepPinY = 3;  //Y.Step
const int dirPinY = 6;  //Y.Dir


 
void setup() {
    Serial.begin(9600); 
    delay(2000);  
 
 pinMode(stepPinX,OUTPUT);
 pinMode(dirPinX,OUTPUT);

 pinMode(stepPinY,OUTPUT);
 pinMode(dirPinY,OUTPUT);   
}
 
void loop() {
    if(Serial.available()>0){
        Serial.read();
        digitalWrite(dirPinX,HIGH);
        for(int x = 0; x < 200; x++) {
        digitalWrite(stepPinX,HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPinX,LOW);
        delayMicroseconds(500);

        
}
}    
}
