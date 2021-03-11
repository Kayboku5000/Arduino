/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include "BTS7960.h"
Adafruit_MCP23017 mcp;

// PINOUT
// L_EN -> 8
// R_EN -> 8
// L_PWM -> 9
// R_PWM -> 10
 


const uint8_t EN = 0;
const uint8_t L_PWM = 1;
const uint8_t R_PWM = 2;

BTS7960 motorController(EN, L_PWM, R_PWM);

void setup() 
{
mcp.begin();      // Default device address 0
mcp.pinMode(EN, OUTPUT);  // 
mcp.pinMode(L_PWM, OUTPUT);  // 
mcp.pinMode(R_PWM, OUTPUT);  // 

  
}

void loop() 
{
  motorController.Enable();

  for(int speed = 0 ; speed < 255; speed+=10)
  {
  motorController.TurnLeft(speed);
  delay(100);
  }  

  motorController.Stop();
  
  for(int speed = 255 ; speed > 0; speed-=10)
  {
  motorController.TurnLeft(speed);
  delay(100);
  }  
  motorController.Stop();

  motorController.Disable();
  
  delay(5000);
}
