/*
 * Project Rainbow
 * Description:
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.
#include "neopixel.h"
#define PIXEL_PIN D2
#define PIXEL_COUNT 12 //if your neopixel has 16 lights, use 16 here instead
#define PIXEL_TYPE WS2812
Adafruit_NeoPixel ring(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint8_t  offset = 0; // Position of spinny eyes
uint32_t color  = 0x0000FF; // Start blue

void searching() {

  for(int i=0; i<16; i++) {
      uint32_t c = 0;
      if(((offset + i) & 7) < 2) c = color;
      ring.setPixelColor( i, c); // First eye
    }
    ring.show();
    offset++;
    delay(90);
}

void found() {
  for(int i=0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, color);
  }
  ring.show();
}

void stopring () {
  ring.clear();
  ring.show();
}
void setup() {
  Serial.begin(9600);
  ring.begin();
  ring.setBrightness(95);
}

void  loop() {
  String function = "";
  while(Serial.available() > 0) {
    char c = Serial.read();
    if ( c == '\n') {
      break;
    }
    function.concat(c);
  }

  if (function == "searching") {
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    searching();
    found();
    delay(500);
    stopring();
    delay(500);
    found();
    delay(500);
    stopring();
    delay(500);
    found();
    delay(500);
    stopring();
    delay(500);
    found();
  } else if (function == "found") {
    found();
  } else if (function == "stopring") {
    stopring();
  }
}
/* void setup() {
  ring.begin();
  ring.setBrightness(95); // 1/3 brightness
}

void loop() {
 
    for(int i=0; i<16; i++) {
      uint32_t c = 0;
      if(((offset + i) & 7) < 2) c = color;
      ring.setPixelColor( i, c); // First eye
    }
    ring.show();
    offset++;
    delay(90);


} */


/* void setup() {
  ring.begin();
  for(int i=0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, 255, 0, 255);
  }
  ring.show();
}
void loop() {
  rainbow(30); //extra for rainbow
  delay(5); //extra for rainbow
}
//extra for rainbow
void rainbow(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i<ring.numPixels(); i++) {
      ring.setPixelColor(i, Wheel((i*1+j) & 255));
    }
    ring.show();
    delay(wait);
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return ring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return ring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else {
    WheelPos -= 170;
    return ring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
} */