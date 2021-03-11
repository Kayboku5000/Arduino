#include <Servo.h> 

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int servoPos = 0;


void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
 for(servoPos = 0; servoPos < 180; servoPos++)
 {
  servo1.write(servoPos);
  servo2.write(servoPos);
  servo3.write(servoPos);
  servo4.write(servoPos);
  delay(15);
  
 }
for(servoPos = 180; servoPos > 0; servoPos--)
{
servo1.write(servoPos);
servo2.write(servoPos);
servo3.write(servoPos);
servo4.write(servoPos);
delay(15);
 
}

}
