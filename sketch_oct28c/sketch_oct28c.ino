#define ip1 A0   // input pin 14 receiver on pin 1
int ch1;        // Value of channel 1 of the receiver

#define ip2 A1   // input pin 15 receiver on pin 9
int ch2;        // Value of channel 2 of the receiver

void setup() {
  // put your setup code here, to run once:
  pinMode (ip1, INPUT);
  pinMode (ip2, INPUT);
  Serial.begin(115200);


}

void loop() {
  // put your main code here, to run repeatedly:

 ch1 = pulseIn(ip1, HIGH);    // Left Motor
  Serial.print(" ch1 ");
  Serial.print(ch1);

 ch2 = pulseIn(ip2, HIGH);    // Right Motor
  Serial.print(" ch2 ");
  Serial.println(ch2);


}
