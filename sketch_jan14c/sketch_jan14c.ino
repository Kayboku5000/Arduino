
int ledPin1 = 12;
int ledPin2 = 11;
int ledPin3 = 10;
int ledPin4 = 9;


int XPin = A0;
int YPin = A1;
int ZPin = A2;

int valX = 0;
int valY = 0;
int valZ = 0;

int accPin = 8;
int valAcc;

void setup() {
 Serial.begin(9600);
 pinMode(ledPin1, OUTPUT);  
   pinMode(ledPin2, OUTPUT);  
     pinMode(ledPin3, OUTPUT);  
       pinMode(ledPin4, OUTPUT);  
 pinMode(accPin, INPUT);  
}

void loop() {
 valX = analogRead(XPin);
 valY = analogRead(YPin);
 valZ = analogRead(ZPin);
 valAcc = digitalRead(accPin);
 
 Serial.print("  X ->");
 Serial.print(valX);
 Serial.print("  Y ->");
 Serial.print(valY);
 Serial.print("  Z ->");
 Serial.println(valZ);

 Serial.print("########");
 Serial.println(valAcc);  
 delay (150);
 if (valX > 150 or valY > 150 or valZ > 150) {
   digitalWrite(ledPin1, HIGH);  
    digitalWrite(ledPin2, HIGH);  
     digitalWrite(ledPin3, HIGH);  
      digitalWrite(ledPin4, HIGH);  
   delay(50);
  }
 
 else {
 digitalWrite(ledPin1, LOW);
   digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin3, LOW);
       digitalWrite(ledPin4, LOW);
 
 delay(50);
 }
}
