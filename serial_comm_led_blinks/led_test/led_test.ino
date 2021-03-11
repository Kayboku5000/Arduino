String myColour;
int RedPin=7;
int GreenPin=8;
int RedPinn=9;
int DelayTime=500;
String red;
String msg="which LED would you like?";


 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(RedPin,OUTPUT);
pinMode(GreenPin,OUTPUT);
pinMode(RedPinn,OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:



  digitalWrite(RedPin,LOW);
  digitalWrite(GreenPin,LOW);
  digitalWrite(RedPinn,HIGH);

}
