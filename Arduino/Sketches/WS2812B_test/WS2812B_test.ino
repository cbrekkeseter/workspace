#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);

}

void loop() {
//
//leds[0] = CRGB::Red;
//delay(1000);
//leds[0] = CRGB::Black;
//delay(1000);

  for(int i = 0; i < NUM_LEDS; i++)  {
    leds[i] = CRGB::Red;
    FastLED.show();
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(50);
  }

}
