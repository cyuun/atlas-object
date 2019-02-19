#include "Volume.h"

//speaker is in pin 5
const int slider = A0;
const int spinner = A1;

Volume vol;
int pitch = 0;
int volume = 0;

void setup() {
  // put your setup code here, to run once:
  // vol.begin is necessary for the volume library I'm using
  vol.begin();
  // just good ol serial communication
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  //reading in the analog inputs, I already know theyre potentiometers, so I know the range 
  volume = map(analogRead(slider), 0, 1023, 0, 255);
  pitch = map(analogRead(spinner), 0, 1023, 120, 3500);
  
  //just checking things
  //Serial.println(vol);
  //Serial.println(pitch);
  
  //outputting with the volume library I'm using, no pin is specified, because the library uses pin 5 by default
  vol.tone(pitch, volume);
}
