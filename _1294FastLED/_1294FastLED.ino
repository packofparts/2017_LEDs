#include <FastLED.h>
#define COLOR_ORDER GRB
#define MAX_BRIGHTNESS 255
#define NUM_LEDS 150
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
const int inputRedPin = 2;
const int inputBluePin = 3;
//pin numbers are placeholders until real numbers are recieved
int inputRed = 0;
int inputBlue = 0;
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  pinMode(inputRedPin, INPUT_PULLUP);
  pinMode(inputBluePin, INPUT_PULLUP);
}

void loop() {
  inputRed = digitalRead(inputRedPin);
  inputBlue = digitalRead(inputBluePin);
  if(inputRed == LOW && inputBlue == HIGH){
    fill_solid( leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
  }
  else if(inputBlue == LOW && inputRed == HIGH){
    fill_solid( leds, NUM_LEDS, CRGB::Blue);
    FastLED.show();
  }
  else if(inputBlue == HIGH && inputRed == HIGH){
    while(inputBlue == HIGH && inputRed == HIGH){
      cylon(CRGB::Red, 1, 1);
      cylon(CRGB::Blue, 1, 1);
      cylon(CRGB::Green, 1, 1);
      cylon(CRGB::Cyan, 1, 1);
      cylon(CRGB::Yellow, 1, 1);
    }
  }
}
void cylon(CRGB color, uint16_t wait, uint8_t number_of_cycles){
 FastLED.setBrightness(MAX_BRIGHTNESS);
 for (uint8_t times = 0; times<=number_of_cycles; times++){
   for(int led_number = 0; led_number < NUM_LEDS; led_number++){
     leds[led_number] = color;
     leds[led_number + 1] = color;
     leds[led_number + 2] = color;
     leds[led_number + 3] = color;
     leds[led_number + 4] = color;
     leds[led_number + 5] = color;
     FastLED.show();
     leds[led_number] = CRGB::Black;
     delay(wait);
   }
   // Now "move" the LED the other direction
   for(int led_number = NUM_LEDS-1; led_number >= 0; led_number--){
     leds[led_number] = color;
     leds[led_number - 1] = color;
     leds[led_number - 2] = color;
     leds[led_number - 3] = color;
     leds[led_number - 4] = color;
     leds[led_number - 5] = color;
     FastLED.show();
     leds[led_number] = CRGB::Black;
     delay(wait);
   }
 }
 return;
}
