int yellowPin=8;
int redPin=7;
int yellowTime=500;
int redTime=500;
int yellowBlink=5;
int redBlink=3;
int j;


void setup() {
  // put your setup code here, to run once:
pinMode (yellowPin, OUTPUT);
pinMode (redPin, OUTPUT);
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
for (j=1;j<=yellowBlink;j=j+1){
  digitalWrite (yellowPin, HIGH);
  delay(yellowTime);
  digitalWrite(yellowPin,LOW);
  delay(yellowTime);

 
}
for (j=1;j<=redBlink;j=j+1){
  digitalWrite (redPin, HIGH);
  delay(redTime);
  digitalWrite(redPin,LOW);
  delay(redTime);

 
}
}
