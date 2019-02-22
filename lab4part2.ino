const int switchPin = 2;
const int motor1Pin = 3;
const int motor2Pin = 4;
const int enablePin = 9;

int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin) == HIGH) {
    switchState = !switchState;
    delay(350);
  }
  Serial.println(switchState);
  if (switchState) {
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
  } else {
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
  }
  
}
