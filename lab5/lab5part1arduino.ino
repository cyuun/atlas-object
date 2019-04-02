double potent1 = 0;
double potent2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potent1 = 10-(float)(map(analogRead(A0), 0, 1023, 0, 1000))/100;
  potent2 = 10-(float)(map(analogRead(A1), 0, 1023, 0, 1000))/100;

  Serial.print(potent1);
  Serial.print(',');
  Serial.println(potent2);
}
