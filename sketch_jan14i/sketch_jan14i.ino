int RPWM=5;
int LPWM=6;
int L_EN=7;
int R_EN=8;

  void setPWMfrequency(int freq){
   TCCR0B = TCCR0B & 0b11111000 | freq ;
  }

  void MotorActiveStatus(char Side,boolean s){
    boolean state=s;
    if(Side=='R'){
    digitalWrite(R_EN,s);
    }
    if(Side=='L'){
    digitalWrite(L_EN,s);
    }    
  }
  void setMotor(char side,byte pwm){
   if(side=='R'){
    analogWrite(RPWM,pwm);
   }
    if(side=='L'){
    analogWrite(LPWM,pwm);
   }
  }
  void closeMotor(char side){
     if(side=='R'){
    digitalWrite(RPWM,LOW);
     }
     if(side=='L'){
    digitalWrite(LPWM,LOW);
     }

     }
void setup() {
  // put your setup code here, to run once:
  setPWMfrequency(0x02);// timer 0 , 3.92KHz
  for(int i=5;i<9;i++){
   pinMode(i,OUTPUT);
  }
   for(int i=5;i<9;i++){
   digitalWrite(i,LOW);
  }
   delay(1000);
   MotorActiveStatus('R',true);
   MotorActiveStatus('L',true);
    Serial.begin(9600);
  }

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<256;i++){
  setMotor('R',i);
  delay(500);
}
delay(1000);
closeMotor('R');
delay(1000);
  for(int i=0;i<256;i++){
  setMotor('L',i);
  delay(500);
}
delay(1000);
closeMotor('L');
delay(1000);
}
