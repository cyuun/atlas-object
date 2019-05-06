#include <MIDI.h>
#include <CapacitiveSensor.h>

MIDI_CREATE_DEFAULT_INSTANCE();

//Variable Definitions
//capacitive sensors
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);
//strings
const int str1 = A0;
const int str2 = A1;
const int str3 = A2;
const int str4 = A3;
//arrays used for calculating derivatives
int str1array[3];
int str2array[3];
int str3array[3];
int str4array[3];
//count and off variables used for MIDI interactions
int str1count = 0;
int str2count = 0;
int str3count = 0;
int str4count = 0;
bool str1off = 1;
bool str2off = 1;
bool str3off = 1;
bool str4off = 1;
//add variables used for the note change with capacitive sensors
int str1add = 0;
int str2add = 0;
int str3add = 0;
int str4add = 0;
//variables used for the octave rotation
int octArr[3];
int octIndex = 0;
const int button = 12;
int buttoncount = 0;

void setup()                    
{
   MIDI.begin(MIDI_CHANNEL_OMNI); //setting up MIDI communication
   for (int i = 0; i < 3; i++) { //initializing the arrays for derivatives
    str1array[i] = 0;
    str2array[i] = 0;
    str3array[i] = 0;
    str4array[i] = 0;
  }
  //initializind the octave array
  octArr[0] = -12;
  octArr[1] = 0;
  octArr[2] = 12;
  pinMode(button, INPUT);
}

void loop()                    
{
    // SECTION 1: Octave Cylcing
    if (digitalRead(button) && !buttoncount) { //if the button is pressed, cycle once through the octaves
      octIndex = (octIndex +1)%3;
      buttoncount = 50; //"cooldown" for the button so it doesn't read multiple presses from a single press
    }
    if (buttoncount) buttoncount -=1;



    // SECTION 2: Derivative Calculating
    for (int i = 0; i < 2; i++) { //move back each entry in the array by 1
      str1array[i] = str1array[i+1];
      str2array[i] = str2array[i+1];
      str3array[i] = str3array[i+1];
      str4array[i] = str4array[i+1];
    }
    //fill the end of the array with the new value
    str1array[2] = analogRead(str1);
    str2array[2] = analogRead(str2);
    str3array[2] = analogRead(str3);
    str4array[2] = analogRead(str4);
    //finite differences approximation for the derivative of the voltage read accross the strings
    int str1deriv = abs((3*str1array[0] - 4*str1array[1] + str1array[2]));
    int str2deriv = abs((3*str2array[0] - 4*str2array[1] + str2array[2]));
    int str3deriv = abs((3*str3array[0] - 4*str3array[1] + str3array[2]));
    int str4deriv = abs((3*str4array[0] - 4*str4array[1] + str4array[2]));


  
    // SECTION 3: Capacitive Touch Note Adding
    //reading the capacitive sensors
    long total1 =  cs_2_4.capacitiveSensor(30);
    long total2 =  cs_2_5.capacitiveSensor(30);
    long total3 =  cs_2_6.capacitiveSensor(30);
    long total4 =  cs_2_7.capacitiveSensor(30);
    //adding on to the respective MIDI data if the capacitive sensor is read
    if (total1 >=60) {
      str1add = 2;
    }
    if (total1 <60) {
      str1add = 0;
    }
    if (total2 >=60) {
      str2add = 1;
    }
    if (total2 <60) {
      str2add = 0;
    }if (total3 >=60) {
      str3add = 2;
    }
    if (total3 <60) {
      str3add = 0;
    }if (total4 >=60) {
      str4add = 1;
    }
    if (total4 <60) {
      str4add = 0;
    }



    // SECTION 4: Sending the MIDI data
    //the sending part
    if (str1deriv > 8) { //string 1 is plucked, send the MIDI note
      MIDI.sendNoteOn(60+str1add+octArr[octIndex], 127, 1);
      str1count = (str1deriv*10); //the note will last for a length relative to how hard the string was plucked
    } 
    if (str2deriv > 8) { //string 2 is plucked
      MIDI.sendNoteOn(64+str2add+octArr[octIndex], 127, 1);
      str2count = (str2deriv*10);
    } 
    if (str3deriv > 8) { //string 3 is plucked
      MIDI.sendNoteOn(67+str3add+octArr[octIndex], 127, 1);
      str3count = (str3deriv*10);
      str3off = 0;
    } 
    if (str4deriv > 8) { //string 4 is plucked
      MIDI.sendNoteOn(71+str4add+octArr[octIndex], 127, 1);
      str4count = (str4deriv*10);
      str4off = 0;
    }
    //the waiting part
    if (str1count > 0) {
      str1count-=1;
    } 
    if (str2count > 0) {
      str2count-=1;
    } 
    if (str3count > 0) {
      str3count-=1;
    } 
    if (str4count > 0) {
      str4count-=1;
    } 
    //sending the off data once the wait is over, so the note ends
    if (str1count == 0 && str1off == 0) { //the "off" boolean is used so that the MIDI stop data is only sent once per note, and isn't constantly sending while the device isn't in use
      MIDI.sendNoteOff(60+str1add+octArr[octIndex], 0, 1);
      str1off = 1;
    } 
    if (str2count == 0 && str2off == 0) {
      MIDI.sendNoteOff(64+str2add+octArr[octIndex], 0, 1);
      str2off = 1;
    } 
    if (str3count == 0 && str3off == 0) {
      MIDI.sendNoteOff(67+str3add+octArr[octIndex], 0, 1);
      str3off = 1;
    } 
    if (str4count == 0 && str4off == 0) {
      MIDI.sendNoteOff(71+str4add+octArr[octIndex], 0, 1);
      str4off = 1;
    } 
    delay(10);                             // arbitrary delay to limit data to serial port 
}
