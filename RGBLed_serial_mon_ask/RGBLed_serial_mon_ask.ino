
int RedPin=7;
int GreenPin=8;
int RedPinn=9;
int DelayTime=500;

String msg="which LED would you like? 1, 2 or 3?";
String myColour;

 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(RedPin,OUTPUT);
pinMode(GreenPin,OUTPUT);
pinMode(RedPinn,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(msg);
while (Serial.available()==0){
}
myColour=Serial.readString();

if (myColour=="1"){
  digitalWrite(RedPin,HIGH);
  digitalWrite(GreenPin,LOW);
  digitalWrite(RedPinn,LOW);

}
if (myColour=="2"){
  digitalWrite(RedPin,LOW);
  digitalWrite(GreenPin,HIGH);
  digitalWrite(RedPinn,LOW);

}
if (myColour=="3"){
  digitalWrite(RedPin,LOW);
  digitalWrite(GreenPin,LOW);
  digitalWrite(RedPinn,HIGH);

}
}
