#include <SoftwareSerial.h>
// software serial #2: RX = digital pin 8, TX = digital pin 9
SoftwareSerial portTwo(8, 9);



void setup() {
  // put your setup code here, to run once:
 Serial.begin(300);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
portTwo.begin(300);

}

void loop() {
  // put your main code here, to run repeatedly:
portTwo.println("Pottatatatataata");
delay(1000);
}
