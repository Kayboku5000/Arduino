// Watch video here: https://www.youtube.com/watch?v=BtTQGpMpq0E

/*
Arduino     Knock/Shock Sensor KY-031
 GND               -
 5V               +5V
 D3                S
*/

int Led = 13;// LED pin
int Shock = 3;
int val;

void setup () {
 Serial.begin(9600);
 pinMode(Led, OUTPUT);
 pinMode(Shock, INPUT);
}

void loop () {
 val = digitalRead (Shock);// read digital interface is assigned a value of 3 val
 Serial.println(val);
 if (val == HIGH) {// When the percussion when the sensor detects a signal, LED flashes
  digitalWrite(Led, LOW);
 }
 else {
  digitalWrite(Led, HIGH);
 }
}
