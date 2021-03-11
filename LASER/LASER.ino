int x=12;
int dt=1500;

void setup() {
  // put your setup code here, to run once:
pinMode (x,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (x,HIGH);
delay (dt);
digitalWrite (x,LOW);
delay (dt);


}
