#include <Servo.h>
int Xpin=A0;
int Ypin=A1;
int Spin=2;
int Xval;
int Yval;
int Sval;
int dt=50;
int servoPin=9;
int servoPos=0;
Servo myServo;
int WVx;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (Xpin,INPUT);
pinMode (Ypin, INPUT);
pinMode (Spin,INPUT);
digitalWrite(Spin,HIGH); 
myServo.attach(servoPin);
pinMode (servoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Xval=analogRead(Xpin);
Yval=analogRead(Ypin);
Sval=digitalRead(Spin);
delay(dt);
Serial.print("X Value = ");
Serial.print( Xval);
Serial.print( " Y Value = " );
Serial.print( Yval);
Serial.print( " Swith State is " );
Serial.println( Sval );
myServo.write(servoPos);

Xval=analogRead(Xpin);
WVx=(180./1023.)*Xval;
myServo.write(WVx);
}
