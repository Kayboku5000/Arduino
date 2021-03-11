String my_name;
 
void setup() {
    Serial.begin(9600);
 
    delay(2000);
 
    Serial.println("What is your name?");
}
 
 
 
void loop() {
    if(Serial.available()){
        my_name = Serial.readStringUntil('\n');
 
        Serial.println("Nice to meet you, " + my_name + "!");
    }
}
