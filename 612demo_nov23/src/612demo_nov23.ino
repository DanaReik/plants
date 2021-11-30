/*
 * Project blink-led
 * Description: Learning how to make an LED respond to a sensor
 * Author:
 * Date: September 20, 2021
 */

#include "neopixel.h"
#define PIXEL_PIN D3
#define PIXEL_COUNT 16 //if your neopixel has 16 lights, use 16 here instead
#define PIXEL_TYPE WS2812
Adafruit_NeoPixel ring(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint8_t  offset = 0; // Position of spinny eyes
uint32_t color  = 0x0000FF; // Start blue

int LED = D0;
int FED = D1;
int GED = D2;


// setup() runs once, when the device is first turned on.
// void setup() {
//   // Put initialization like pinMode and begin functions here.
// pinMode(LED, OUTPUT);
// pinMode(FED, OUTPUT);
// pinMode(GED, OUTPUT);
// // LEDgreenfull(); //use these to test, but remove when function is called with html example
// // LEDgreenmedium();
// // LEDgreenempty();
// }


void LEDsetup() {
 digitalWrite(LED, HIGH);
 digitalWrite(FED, HIGH);
 digitalWrite(GED, HIGH);
 delay(1000);
 digitalWrite(LED, LOW);
 digitalWrite(FED, LOW);
 digitalWrite(GED, LOW);
 delay(1000);
}

//
void LEDgreenfull() { // call HTML/javascript files from Wizard of Oz workshop
  for (int i=0; i<5; i++) {
    digitalWrite(LED, HIGH);
    delay(1000);
    // digitalWrite(LED, LOW);
    // delay(1000);
  }
}

void LEDgreenmedium() { // call HTML/javascript files from Wizard of Oz workshop
  for (int i=0; i<10; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
}

void LEDgreenempty() { // call HTML/javascript files from Wizard of Oz workshop
  for (int i=0; i<20; i++) {
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  }
}

void LEDblue() { // call HTML/javascript files from Wizard of Oz workshop
  for (int i=0; i<10; i++) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
}

void LEDyellow() { // call HTML/javascript files from Wizard of Oz workshop
  for (int i=0; i<10; i++) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
}


//Neopixel Ring
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
void setup() { //USE AS SETUP FOR ALL
  Serial.begin(9600);
  ring.begin();
  ring.setBrightness(95);
  pinMode(LED, OUTPUT);
  pinMode(FED, OUTPUT);
  pinMode(GED, OUTPUT);
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
  } else if (function == "green") {
    LEDgreenempty();
  }

}





// loop() runs over and over again, as quickly as it can execute.
// void loop() {
//   // The core of your code will likely live here.
// digitalWrite(LED, HIGH);
// digitalWrite(FED, HIGH);
// digitalWrite(GED, HIGH);
// delay(1000);
// digitalWrite(LED, LOW);
// digitalWrite(FED, LOW);
// digitalWrite(GED, LOW);
// delay(1000);
// }

//



//have a different function at the bottom or multiple if statements () for lights to behave differently
//week 9 (like 3rd workshop) for wizard of oz movies
//serial monitor, arduino (or html/java from 3rd workshop and make html buttons to push) 

//NeoPixel

// #include <Adafruit_NeoPixel.h>
// #include "hsv.h"

// // data pin
// #define PIN 6
// // led count
// #define CNT 24
// // max Hue
// #define MAXHUE 256*6

// int position = 0;

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(CNT, PIN, NEO_GRB + NEO_KHZ800);

// void setup() {
//   strip.begin();
// }


// //one set up, one loop, as many custom functions
// //neopixel on class, flashes color of rainbow (Florarainbow.ino)

// void loop() {
//   // hue - red
//   // saturation - max
//   // value - 0-255
//   for (int i = 0; i < CNT; i++)
//     strip.setPixelColor((i + position) % CNT, getPixelColorHsv(i, 0, 255, strip.gamma8(i * (255 / CNT))));
//   strip.show();
//   position++;
//   position %= CNT;
//   delay(50);
// }