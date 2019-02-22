#include <Servo.h>

Servo spinBoiz;
const int servoPin = 10;
const int potPin = A0;

int angle = 0;

void setup() {
  // put your setup code here, to run once:
  spinBoiz.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  angle = analogRead(A0);
  //Serial.println(angle);
  angle = map(angle, 0, 1023, 0, 179);
  //Serial.println(angle);
  spinBoiz.write(angle);
  delay(20);
}
