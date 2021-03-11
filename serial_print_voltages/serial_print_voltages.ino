int redPin=9;
int greenPin=8;
int redPin2=7;
int bright=255;
int dull=55;
int offzero=0;
int readPin=A3; 
float V2=0;
int delayTime=500; 
int readVal;


void setup() {
  // put your setup code here, to run once:

pinMode (readPin,INPUT);
pinMode (redPin,OUTPUT);
pinMode (greenPin,OUTPUT);
pinMode (redPin2,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

readVal=analogRead(readPin);
V2=(5./1023.)*readVal; 
Serial.println(V2); 
delay(delayTime);
if (V2>4.0) {
  digitalWrite(redPin,HIGH);
}
if (V2<4.0) {
  digitalWrite(redPin, LOW); 
}

if (V2>2.0 && V2<4.0) {
  digitalWrite (greenPin, HIGH);
}

if (V2<2.0 || V2>4.0) {
  digitalWrite (greenPin, LOW);
}



if (V2<2.0) {
  digitalWrite (redPin2,HIGH);
  
}
if (V2>2.0) {
  digitalWrite (redPin2,LOW);
  
}

}
