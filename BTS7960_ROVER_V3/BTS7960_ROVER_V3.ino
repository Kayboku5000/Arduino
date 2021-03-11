
// PINS FOR MOTOR 1
#define RPWM_1 3 // define pin 3 for RPWM pin (output)
#define R_EN_1 14 // define pin 14 for R_EN pin (input)
#define R_IS_1 15 // define pin 15 for R_IS pin (output)

#define LPWM_1 5 // define pin 5 for LPWM pin (output)
#define L_EN_1 16 // define pin 16 for L_EN pin (input)
#define L_IS_1 17 // define pin 17 for L_IS pin (output)


// PINS FOR MOTOR 2
#define RPWM_2 6 // define pin 6 for RPWM pin (output)
#define R_EN_2 7 // define pin 7 for R_EN pin (input)
#define R_IS_2 8 // define pin 8 for R_IS pin (output)

#define LPWM_2 10 // define pin 10 for LPWM pin (output)
#define L_EN_2 11 // define pin 11 for L_EN pin (input)
#define L_IS_2 12 // define pin 12 for L_IS pin (output)

// Inputs from pixhawk ch 1 and 3
#define ip1 13 // input to pin13 from pixhawk output 1
#define ip2 9  // input to pin9  from pixhawk output 3

int ch1;  // Value of channel 1 of the receiver
int val1; // motor1 speed

int ch2;  // Value of channel 2 of the receiver
int val2; // motor2 speed


#define CW 1 //do not change
#define CCW 0 //do not change
#define debug 1 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view

// ultrasonic sensor
int trigPin = 9;
int echoPin = 10;


#include <RobojaxBTS7960.h>
RobojaxBTS7960 motor1(R_EN_1,RPWM_1,R_IS_1, L_EN_1,LPWM_1,L_IS_1,debug);//define motor 1 object
RobojaxBTS7960 motor2(R_EN_2,RPWM_2,R_IS_2, L_EN_2,LPWM_2,L_IS_2,debug);//define motor 2 object and the same way for other motors

void setup() {

pinMode (ip1, INPUT);  //pixhawk pwm O/P ch1
pinMode (ip2, INPUT);  //pixhawk pwm O/P ch3

  // BTS7960 Motor Control Code by Robojax.com 20190622
  Serial.begin(9600);// setup Serial Monitor to display information

   motor1.begin();
   motor2.begin();  

}


void loop() {

  ch1 = pulseIn(ip1, HIGH);    // Left Motor
  Serial.print(" ch1 ");
  Serial.print(ch1);

  ch2 = pulseIn(ip2, HIGH);    // Right Motor
  Serial.print(" ch2 ");
  Serial.println(ch2);



//######### motor 1+2 LEFT SIDE *** motor1  #########



  if (ch1 < 1450 && ch1  > 950 )   // for reverse
  {
    val1 = map(ch1, 1450, 950, 5, 100);
    motor1.rotate(val1,CCW);
   
  }

  else if (ch1 < 2200 && ch1 > 1550 )   // for forward
  {

    val1 = map(ch1, 1550, 2000, 5, 100);
    motor1.rotate(val1,CW);


  }

  else if (ch1 < 1550 && ch1 > 1450  ) //stop motor
  {
    motor1.stop();


  }

  else if  (ch1 == 0)  //failsafe
  {
    motor1.stop();
  }


  //######### motor 3+4 RIGHT SIDE **** motor2 #########


  if  (ch2 < 1450 && ch2  > 950 )  // for reverse
  {
    val2 = map(ch2, 1450, 950, 5, 100);
   motor2.rotate(val2,CCW);
  }

  else if  (ch2 < 2200 && ch2 > 1550 )  // for forward
  {

    val2 = map(ch2, 1550, 2000, 5, 100);
   motor2.rotate(val2,CW);
  }

  else if (ch2 > 1450 && ch2 < 1550)   //stop motor
  {
    motor2.stop();

  }

  else if  (ch2 == 0)  //failsafe
  {
    motor2.stop();


  }


  delay(10);


}
