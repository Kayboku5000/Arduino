int j=1;
int x=2;
int y=3;
int delaytime=500;
String mystring="j = ";
float area;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(j) ;
j=j+1*x+y;



delay(delaytime);
}
