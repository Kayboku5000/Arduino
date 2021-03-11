

#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include "BTS7960.h"
Adafruit_MCP23017 mcp;

#define ledYes 6

void setup() {
  mcp.begin();
  mcp.pinMode(ledYes, OUTPUT);


  
}

void loop() {
  mcp.digitalWrite(ledYes, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  mcp.digitalWrite(ledYes, LOW);    // turn the LED off by making the voltage LOW
  delay(400);                       // wait for a second

}
