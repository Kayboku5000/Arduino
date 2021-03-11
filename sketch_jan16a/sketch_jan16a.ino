#define STEPPER_PIN_1 0
#define STEPPER_PIN_2 1
#define STEPPER_PIN_3 2
#define STEPPER_PIN_4 4


void setup() {
  // put your setup code here, to run once:
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  delay(2);
}
