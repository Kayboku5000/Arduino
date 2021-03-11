
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <RobojaxBTS7960.h>
Adafruit_MCP23017 mcp;


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


#define CW 1 //do not change
#define CCW 0 //do not change
#define debug 1 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view


RobojaxBTS7960 motor1(R_EN_1,RPWM_1,R_IS_1, L_EN_1,LPWM_1,L_IS_1,debug);//define motor 1 object
RobojaxBTS7960 motor2(R_EN_2,RPWM_2,R_IS_2, L_EN_2,LPWM_2,L_IS_2,debug);//define motor 2 object and the same way for other motors

void setup() {

  //mcp.begin();
  
 // mcp.pinMode(RPWM_1, OUTPUT);
 // mcp.pinMode(R_EN_1, OUTPUT);
 // mcp.pinMode(R_IS_1, OUTPUT);
 // mcp.pinMode(LPWM_1, OUTPUT);
 // mcp.pinMode(L_EN_1, OUTPUT);
 // mcp.pinMode(L_IS_1, OUTPUT);


  // BTS7960 Motor Control Code by Robojax.com 20190622
  Serial.begin(9600);// setup Serial Monitor to display information

   motor1.begin();
   motor2.begin();  

}


void loop() {
  
// BTS7960 Motor Control Code by Robojax.com 20190622 
    motor1.rotate(20,CW);// run motor 1 with 100% speed in CW direction
    delay(5000);//run for 5 seconds
    motor1.stop();// stop the motor 1
    delay(300);// stop for 3 seconds
    motor1.rotate(20,CCW);// run motor 1 at 100% speed in CCW direction
    delay(5000);// run for 5 seconds
    motor1.stop();// stop the motor 1
    delay(300);  // stop for 3 seconds

    

    
 
    
   


}
