int trigPin=2;
int trigPin2=7;
int trigPin3=8;
int echoPin=3;
int echoPin2=4;
int echoPin3=5;
int pingTravelTime;
int pingTravelTime2;
int pingTravelTime3;
float pingTravelDistance;
float pingTravelDistance2;
float pingTravelDistance3;
float distanceToTarget;
float distanceToTarget2;
float distanceToTarget3;

int dt=5000;
void setup() {

pinMode(trigPin,OUTPUT);
pinMode(trigPin2,OUTPUT);
pinMode(trigPin3,OUTPUT);

pinMode(echoPin,INPUT);
pinMode(echoPin2,INPUT);
pinMode(echoPin3,INPUT);
Serial.begin(9600);
}

void loop() {
  
digitalWrite(trigPin,LOW);
digitalWrite(trigPin2,LOW);
digitalWrite(trigPin3,LOW);
delayMicroseconds(10);

digitalWrite(trigPin,HIGH);
digitalWrite(trigPin2,HIGH);
digitalWrite(trigPin3,HIGH);
delayMicroseconds(10);

digitalWrite(trigPin,LOW);
digitalWrite(trigPin2,LOW);
digitalWrite(trigPin3,LOW);

pingTravelTime=pulseIn(echoPin,HIGH);
pingTravelTime2=pulseIn(echoPin2,HIGH);
pingTravelTime3=pulseIn(echoPin3,HIGH);
delay(25);

pingTravelDistance=(pingTravelTime*765.*5280.*12)/(3600.*1000000);
distanceToTarget=pingTravelDistance/2;
Serial.print("Dist1:    ");
Serial.print(distanceToTarget);


pingTravelDistance2=(pingTravelTime2*765.*5280.*12)/(3600.*1000000);
distanceToTarget2=pingTravelDistance2/2;
Serial.print("   Dist2:    ");
Serial.print(distanceToTarget2);

pingTravelDistance3=(pingTravelTime3*765.*5280.*12)/(3600.*1000000);
distanceToTarget3=pingTravelDistance3/2;
Serial.print("   Dist3:    ");
Serial.print(distanceToTarget3);

Serial.println(" in.");

delay(dt);

}
