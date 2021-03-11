#include "Wire.h"

void setup() {

Wire.begin(); // wake up I2C bus
Wire.beginTransmission(0x20);
Wire.write(0x00); // IODIRA register
Wire.write(0x00); // set all of port A to outputs
Wire.endTransmission();

}

void loop() {

Wire.beginTransmission(0x20);
Wire.write(0x12); // address port A
Wire.write(15);  // value to send
Wire.endTransmission();

}
