double channel[4];
void setup() {
 pinMode(14, INPUT);
 pinMode(15, INPUT);
 pinMode(16, INPUT);
 pinMode(17, INPUT);
 Serial.begin(9600);
}

void loop() {
  channel[0] = pulseIn(14, HIGH);
  channel[1] = pulseIn(15, HIGH);
  channel[2] = pulseIn(16, HIGH);
  channel[3] = pulseIn(17, HIGH);
  Serial.print(channel[0]);
  Serial.print(" - ");
  Serial.print(channel[1]);
  Serial.print(" - "); 
  Serial.print(channel[2]);
  Serial.print(" - ");
  Serial.print(channel[3]);
  Serial.println(" - ");
  
}
