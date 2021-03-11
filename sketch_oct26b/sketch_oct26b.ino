// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;


//rc connections
double channel[4];
void setup() {
 //rc connections
 pinMode(14, INPUT);
 pinMode(15, INPUT);
 pinMode(16, INPUT);
 pinMode(17, INPUT);
 Serial.begin(9600);

 // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

 
}

void loop() {
  //rc code
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

  //motor code 
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
  
}
