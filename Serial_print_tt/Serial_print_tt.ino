float myNumber;
char x;
char y;

void setup() {

  Serial.begin(9600);
  

}

void loop() {
while (Serial.available()==0){
}  
myNumber = Serial.parseFloat();

Serial.println(myNumber);




}
