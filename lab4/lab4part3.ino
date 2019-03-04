#include <Stepper.h>

//figuring out how many steps are in my motor
const int stepsPerRevolution = 513;

//initializing the stepper
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // put your setup code here, to run once:
  //setting the stepper speed
  myStepper.setSpeed(25);
  //captain crunch cereal communication
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //turning the motor
  myStepper.step(stepsPerRevolution);
  //doing the delay
  delay(3000);
}
