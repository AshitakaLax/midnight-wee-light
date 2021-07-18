// Author: Levi Balling
// Application Name: Midnight-Wee
// Description: a light that will slowely come on to

#include "FastLED.h"
#define NUM_LEDS 60
// Max is from 0-255
#define MAX_RED_BRIGHTNESS 25
#define LED_DATA_PIN 6
#define TIME_BETWEEN_INCREMENTS 75
CRGB leds[NUM_LEDS];


bool lightOn;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS); 
  FastLED.clear();
  FastLED.show();
  delay(10);
  FastLED.clear();
  FastLED.show();
  fill_solid( &(leds[0]), NUM_LEDS, CRGB( 0, 0, 0) );
  delay(10);
  lightOn = false;
}

void loop() {
  while(lightOn)
  {
    delay(1000);
  }
  for(int brightness = 0; brightness < MAX_RED_BRIGHTNESS; brightness++) 
  { 
    fill_solid( &(leds[0]), NUM_LEDS, CRGB( brightness, 0, 0) );
    FastLED.show();
    // clear this led for the next time around the loop
    delay(TIME_BETWEEN_INCREMENTS);
  }
   lightOn = true;        
}
