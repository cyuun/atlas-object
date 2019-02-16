
//the pins
const int flex = A0;
const int pot = A1;
const int led1 = 11;
const int led2 = 10;

//the values
int flexvalue, potvalue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  //read in the flex sensor
  flexvalue = analogRead(flex);
  //read in the potentiometer
  potvalue = analogRead(pot);
  //print things out for calibration
  //Serial.println(flexvalue); the range seems to be 40-300
  //Serial.println(potvalue); the rang is 0-1023 as expected
  //adjusting the values
  flexvalue = map(flexvalue, 40, 300, 0, 255);
  potvalue = map(potvalue, 0, 1023, 0, 255);
  //outputing to the leds
  //flex sensor goes to led1
  analogWrite(led1, flexvalue);
  //potentiometer goes to led2
  analogWrite(led2, potvalue);
}
