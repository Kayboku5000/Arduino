#define ip1 5   // input pin 5 receiver on pin 1
#define spd1 6  // from pin 6 to pwm of hbridge
#define op1 7  // pin 1 of hbridge on pin 7
#define op2 8  // pin 2 of hbridge on pin 8
int ch1;        // Value of channel 1 of the receiver
int val1;       // motor1 speed


#define ip2 9   // input pin 9 receiver on pin 9
#define spd2 10  // from pin 10 to pwm of hbridge
#define op3 11  // pin 1 of hbridge on pin 11
#define op4 12  // pin 2 of hbridge on pin 12
int ch2;        // Value of channel 2 of the receiver
int val2;       // motor2 speed


void setup() {
 pinMode (ip1, INPUT);
 pinMode (spd1, OUTPUT);
 pinMode (op1, OUTPUT);
 pinMode (op2, OUTPUT);
 digitalWrite(op1, LOW);
 digitalWrite(op2, LOW);
 
 pinMode (ip2, INPUT);
 pinMode (spd2, OUTPUT);
 pinMode (op3, OUTPUT);
 pinMode (op4, OUTPUT);
 digitalWrite(op3, LOW);
 digitalWrite(op4, LOW);
 Serial.begin(9600);
}

void loop() {
  ch1 = pulseIn(ip1, HIGH);    // Left Motor
  Serial.print("ch1");
  Serial.print(ch1);

  ch2 = pulseIn(ip2, HIGH);    // Right Motor
  Serial.print("ch2");
  Serial.print(ch2);

  if (ch1 < 1450)     // for reverse
{
  val1=map(ch1, 1450, 1900, 255, 25);
  analogWrite(spd1, val1);
  digitalWrite(op1, HIGH);
  digitalWrite(op2, LOW);
}
  
else if (ch1 > 1550)     // for forward
{

  val1=map(ch1, 1550, 1100, 255, 25);
  analogWrite(spd1, val1);
  digitalWrite(op1, LOW);
  digitalWrite(op2, HIGH);
}

else if (ch1 ==0)
{
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
}

  if (ch2 < 1450)     // for reverse
{
  val2=map(ch2, 1450, 1900, 255, 25);
  analogWrite(spd2, val1);
  digitalWrite(op3, HIGH);
  digitalWrite(op4, LOW);
}
  
else if (ch1 > 1550)     // for forward
{

  val1=map(ch2, 1550, 1100, 255, 25);
  analogWrite(spd2, val1);
  digitalWrite(op3, LOW);
  digitalWrite(op4, HIGH);
}

else if (ch2 ==0)
{
  digitalWrite(op1, LOW);
  digitalWrite(op2, LOW);
}

delay(100);
 
}
