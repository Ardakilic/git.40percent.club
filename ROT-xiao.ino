#include <CommonBusEncoders.h>
#include <HID-Project.h>

CommonBusEncoders encoders(8, 10, 3, 1);

void setup() {

  //Setup encoder
  encoders.setDebounce(16);
  encoders.resetChronoAfter(10000);
  encoders.addEncoder(1, 2, 9, 1, 100, 199);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);

  //Start Consumer keyboard
  Consumer.begin();

  //Serial debugging
  //Serial.begin(9600);
}

void loop() {

  int code = encoders.readAll();
  if (code != 0) {
    //Serial.println(code);
  }
  if (code == 101) Consumer.write(MEDIA_VOLUME_DOWN);
  if (code == 100) Consumer.write(MEDIA_VOLUME_UP);
  if (code == 199) Consumer.write(MEDIA_VOLUME_MUTE);
}
