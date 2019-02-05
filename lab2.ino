// global variabling the pins
int button1 = 2;
int button2 = 3;
int switch1 = 4;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;
int button1state, button2state, switch1state;

// setup routine to initialize the process  
void setup() {
  // initializing the pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(switch1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  // serial communication
  Serial.begin(9600);
}

// loop routine main body
void loop() {
  
  // acquiring those values
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);
  switch1state = digitalRead(switch1);

  // Serial.println(button1state);
  // Serial.println(button2state);
  // Serial.println(switch1state);
  
  // first the switch is a modifier, meaning 2 options
  if (switch1state) {
    // then you have 3 options for each switch state
    if (button1state && !button2state) {
      // option 1 first button is pressed and second isnt
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    } else if (!button1state && button2state) {
      // option 2 first button not pressed and second is
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, HIGH);
    } else if (button1state && button2state) {
      // option 3 both buttons pressed
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, LOW);
    } else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
  } else {
    // switch is off but you still have the same 3 options just different results
    if (button1state && !button2state) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    } else if (!button1state && button2state) {
      // I might as well take this moment to explain why each statement contains all 5 write statements every time
      // it allows a "seamless" transition when moving from pressing 1 button to pressing both
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
    } else if (button1state && button2state) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
    } else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
  }
}
