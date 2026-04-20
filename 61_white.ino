// 61_white.ino - Arduino sketch emulating the QMK 61_white keyboard underglow behavior
// This sketch assumes a WS2812-compatible LED strip on pin 29 with 36 LEDs
// and basic layer switching via a button (for demonstration only)

#include <Adafruit_NeoPixel.h>

#define RGB_DI_PIN 29
#define RGBLED_NUM 36
#define BRIGHTNESS 160

Adafruit_NeoPixel strip(RGBLED_NUM, RGB_DI_PIN, NEO_GRB + NEO_KHZ800);

// Default color settings (QMK-like)
uint8_t hue = 128;
uint8_t sat = 255;
uint8_t val = 96;

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();
  // Start with a rainbow effect
  rainbow_mood();
}

void loop() {
  // For demonstration, cycle through effects every 10 seconds
  static uint32_t lastSwitch = 0;
  static int mode = 0;
  if (millis() - lastSwitch > 10000) {
    mode = (mode + 1) % 5;
    lastSwitch = millis();
    switch (mode) {
      case 0: rainbow_mood(); break;
      case 1: breathing(); break;
      case 2: static_gradient(); break;
      case 3: rgb_test(); break;
      case 4: alternating(); break;
    }
  }
}

void rainbow_mood() {
  for (int i = 0; i < RGBLED_NUM; i++) {
    uint32_t color = strip.ColorHSV((hue * 256) + (i * 65536L / RGBLED_NUM), sat, val);
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void breathing() {
  for (int b = 0; b < 255; b += 5) {
    for (int i = 0; i < RGBLED_NUM; i++) {
      uint32_t color = strip.ColorHSV(hue * 256, sat, b);
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(10);
  }
  for (int b = 255; b > 0; b -= 5) {
    for (int i = 0; i < RGBLED_NUM; i++) {
      uint32_t color = strip.ColorHSV(hue * 256, sat, b);
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(10);
  }
}

void static_gradient() {
  for (int i = 0; i < RGBLED_NUM; i++) {
    uint32_t color = strip.ColorHSV((hue * 256) + (i * 65536L / RGBLED_NUM), sat, val);
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void rgb_test() {
  for (int i = 0; i < RGBLED_NUM; i++) strip.setPixelColor(i, strip.Color(255,0,0));
  strip.show();
  delay(500);
  for (int i = 0; i < RGBLED_NUM; i++) strip.setPixelColor(i, strip.Color(0,255,0));
  strip.show();
  delay(500);
  for (int i = 0; i < RGBLED_NUM; i++) strip.setPixelColor(i, strip.Color(0,0,255));
  strip.show();
  delay(500);
}

void alternating() {
  for (int i = 0; i < RGBLED_NUM; i++) {
    if (i % 2 == 0) strip.setPixelColor(i, strip.ColorHSV(hue * 256, sat, val));
    else strip.setPixelColor(i, strip.ColorHSV((hue + 128) * 256, sat, val));
  }
  strip.show();
}
