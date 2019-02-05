// setup routine to initialize the process
  
// variabling the pins
int button1 = 2;
int button2 = 3;
int switch1 = 2;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;
int button1state, button2state, switch1state;

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
  
  button1state = digitalRead(button1);
  button2state = digitalRead(button2);
  switch1state = digitalRead(switch1);

  Serial.println(button1state);
  Serial.println(button2state);
  Serial.println(switch1state);  
  
  
}
