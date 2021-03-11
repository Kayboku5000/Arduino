#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include "BTS7960.h"
Adafruit_MCP23017 mcp;


#define RPWM mcp.pinMode(4, OUTPUT);
#define LPWM mcp.pinMode(5, OUTPUT);
#define L_EN mcp.pinMode(6, OUTPUT);
#define R_EN mcp.pinMode(7, OUTPUT);



void setup() {

  mcp.begin();
  //mcp.pinMode(RPWM, OUTPUT);
  //mcp.pinMode(LPWM, OUTPUT);
  //mcp.pinMode(L_EN, OUTPUT);
  //mcp.pinMode(R_EN, OUTPUT);
  mcp.digitalWrite(4,LOW);
  mcp.digitalWrite(5,LOW);
  mcp.digitalWrite(6,LOW);
  mcp.digitalWrite(7,LOW);
  delay(100);
  Serial.begin(9600);

  
}

void loop() {
  Serial.println("EN High");
  mcp.digitalWrite(R_EN,HIGH);
  mcp.digitalWrite(L_EN,HIGH);
  delay(100);
  
  Serial.println("forwards_V1");
  for(int i=0;i<200;i++){  
  analogWrite(RPWM,i);

  delay(100);
  } 
  
  Serial.println("backwards_V1");
 for(int i=0;i<200;i++){  
  analogWrite(LPWM,200-i);
  delay(100);
  } 
}
