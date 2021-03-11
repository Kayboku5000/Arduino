#include<Servo.h>
int servoPin=9;
int servoPos=0;
Servo myServo;
int inputPot=A0;
float potVal;
float potValtwo;
int readVal;
float V2=0;
int delayTime=500;
int delayTwo=1500;
int pos=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (inputPot,INPUT);
pinMode (servoPin,OUTPUT);


myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:

readVal=analogRead(inputPot);
V2=(5./1023.)*readVal; 
Serial.println(V2); 
delay(delayTime);

  if (V2<2.0)  { 
    myServo.write(0);  
              
  }
if (V2>2.0 && V2<4.0) {
  myServo.write(45); 
              
  }

                       
  if (V2>4.0) { 
    myServo.write(90);              
                          
  }

}
