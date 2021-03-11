#include <AFMotor.h>

#define ip1 A0   // input pin A0 from RC receiver 
int ch1;        // Value of channel 1 of the receiver
int val1;       // motor1 speed

#define ip2 A1   // input pin A1 from RC receiver 
int ch2;        // Value of channel 2 of the receiver
int val2;       // motor2 speed

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);



void setup() {

  delay(5000);

  pinMode (ip1, INPUT);
  pinMode (ip2, INPUT);
  Serial.begin(115200);


  motor1.setSpeed(100); //this sets the maximum speed the motor can run
  motor2.setSpeed(100); // 0 being the minimum, 255 being the maximum
  motor3.setSpeed(100);
  motor4.setSpeed(100);


  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

}

void loop() {


  ch1 = pulseIn(ip1, HIGH);    // Left Motor
  Serial.print(" ch1 ");
  Serial.print(ch1);

  ch2 = pulseIn(ip2, HIGH);    // Right Motor
  Serial.print(" ch2 ");
  Serial.println(ch2);

   if (ch1 > 1500)     // for forward
  {

    val1 = map(ch1, 1500, 2000, 25, 200);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor1.setSpeed(val1);
    motor2.setSpeed(val1);

  }

 else if (ch1 < 1499)  //stop motor
  {
    motor1.setSpeed(0);
    motor2.setSpeed(0);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }




   if (ch2 > 1500)     // for forward
  {

    val2 = map(ch2, 1499, 2000, 25, 200);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    motor3.setSpeed(val2);
    motor4.setSpeed(val2);


  }



  else if (ch2 < 1499)  //stop motor
  {
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }


  delay(10);



}
