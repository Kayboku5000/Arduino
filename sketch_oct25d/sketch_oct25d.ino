#include <AFMotor.h>
AF_DCMotor motor(1); // DC motor on M1
AF_Stepper stepper(48, 2); // Stepper, Port M3+M4, 48 Steps.
// servo is not managed by AFMotor.h
// Use traditional Servo library in Arduino IDE.
int i = 0;
bool goForward = true;
void setup() {
  motor.setSpeed(50);
  motor.run(RELEASE);
}
void loop() {
  motor.run(goForward ? FORWARD : BACKWARD );
  for (i = 0; i < 255; i++) {
    motor.setSpeed(i);
    stepper.step(1, FORWARD, INTERLEAVE);
  }
  stepper.step(255, BACKWARD, INTERLEAVE);
  for (i = 255; i > 0; i--) {
    motor.setSpeed(i);
    stepper.step(1, FORWARD, DOUBLE);
  }
  goForward = !goForward;
}
