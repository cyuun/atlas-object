int brightness = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int brightness = Serial.read();
    Serial.write(brightness);
    analogWrite(5, brightness);
  }
}
