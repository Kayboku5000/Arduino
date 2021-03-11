int potpin=A3;
int rPin=9;
int potVal;
float LEDVal;


void setup() {
  // put your setup code here, to run once:
pinMode (potpin,INPUT);
pinMode (rPin,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
potVal=analogRead(potpin);
LEDVal=(255./1023.)*potVal;
analogWrite(rPin,LEDVal);
Serial.println (LEDVal); 
}
