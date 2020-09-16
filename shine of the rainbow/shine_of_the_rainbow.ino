#include <CommonBusEncoders.h>
#include <Adafruit_NeoPixel.h>
#include <HID-Project.h>

#define LED_PIN    4
#define LED_COUNT 12

#define DIMDELAY  1000
#define DIMMAX    50
#define DIMMIN    10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);
long RGBpos = 0;
int delay_count = 0;
byte LEDbrightness = 50;
int dimdelay_count = 0;

CommonBusEncoders encoders(1, 2, 3, 1);

void setup() {
  //Setup APA106 LEDs
  strip.begin();
  strip.show();
  strip.setBrightness(LEDbrightness);

  //Setup encoder
  encoders.setDebounce(16);
  encoders.resetChronoAfter(10000);
  encoders.addEncoder(1, 4, 5, 1, 100, 199);

  //Start Consumer keyboard
  Consumer.begin();

  //Serial debugging
  //Serial.begin(9600);
}

void loop() {
  dimled();
  if (delay_count > 20) {
    strip.setBrightness(LEDbrightness);
    rainbow(RGBpos);
    RGBpos = (RGBpos += 256);
    if (RGBpos > 5 * 65536) RGBpos = 0;
    delay_count = 0;
  }

  int code = encoders.readAll();
  if (code != 0) {
    //Serial.println(code);
    LEDbrightness = DIMMAX;
    strip.setBrightness(LEDbrightness);
    strip.show();
  }
  if (code == 101) Consumer.write(MEDIA_VOLUME_DOWN);
  if (code == 100) Consumer.write(MEDIA_VOLUME_UP);
  if (code == 199) Consumer.write(MEDIA_VOLUME_MUTE);
  delay(1);
  delay_count++;
}

void dimled() {
  dimdelay_count++;
  if (dimdelay_count > DIMDELAY)  {
    dimdelay_count = 0;
    LEDbrightness--;
    if (LEDbrightness <= DIMMIN) {
      LEDbrightness = DIMMIN;
    }
    //Serial.println(LEDbrightness);
    strip.setBrightness(LEDbrightness);
    strip.show();
  }
}

void rainbow(long firstPixelHue) {
  for (int i = 0; i < strip.numPixels(); i++) {
    int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
    strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
  }
  strip.show();
}
