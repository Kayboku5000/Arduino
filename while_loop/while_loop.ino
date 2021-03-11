int j;
int delayTime=500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
j=10;
while (j>=1) {
  Serial.println(j);
  delay(delayTime);
  j=j-1;
}
}
