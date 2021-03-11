#define ip1 9   // input pin 9 receiver on pin 9
#define spd 11  // from pin 11 to pwm of hbridge
#define op1 12  // pin 1 of hbridge on pin 12
#define op2 13  // pin 2 of hbridge on pin 13
int ch1;        // Value of channel 1 of the receiver
int val1;       // motor speed


void setup() {
 pinMode (ip1, INPUT);
 pinMode (spd, OUTPUT);
 pinMode (op1, OUTPUT);
 pinMode (op2, OUTPUT);
 digitalWrite(op1, LOW);
 digitalWrite(op2, LOW);
 Serial.begin(9600);

}

void loop() {
  ch1 = pulseIn(ip1, HIGH);
  Serial.print("ch1");
  Serial.print(ch1);
  if (ch1 < 1450)     // for reverse

{
  val1=map(ch1, 1450, 1900, 255, 25);
  analogWrite(spd, val1);
  digitalWrite(op1, HIGH);
  digitalWrite(op2, LOW);
}
else if (ch1 > 1550)     // for forward
{

  val1=map(ch1, 1550, 1100, 255, 25);
  analogWrite(spd, val1);
  digitalWrite(op1, LOW);
  digitalWrite(op2, HIGH);
}

else if (ch1 ==0)
{
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
}
delay(100);

  
}
