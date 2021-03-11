#define RPWM 5
#define LPWM 6
#define L_EN 7
#define R_EN 8



void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  delay(100);
  Serial.begin(9600);

  
}

void loop() {
  Serial.println("EN High");
  digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
  delay(100);
  
  Serial.println("forwards_V1");
  for(int i=0;i<200;i++){  
  analogWrite(RPWM,i);

  delay(100);
  } 
  
  Serial.println("backwards_V1");
 for(int i=0;i<200;i++){  
  analogWrite(LPWM,200-i);
  delay(100);
  } 
}
