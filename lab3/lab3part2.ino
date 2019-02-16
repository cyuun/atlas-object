const int speaker = 8;
const int photo = A0;

int speaker_out, photo_in;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // reading the photocells
  photo_in = analogRead(photo);
  //and finding the range of values
  Serial.println(photo_in);
  //im getting a range of 220-1020
  speaker_out = map(photo_in, 220, 1020, 100, 1000);
  //playing the sound
  tone(speaker, speaker_out, 10);

}
