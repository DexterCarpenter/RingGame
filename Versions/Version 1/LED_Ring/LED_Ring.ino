#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 24
#define SELECT_PIN 3
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Define Variables
int wins = 0;
int losses = 0;
int score = 0;
int ButtonState = 0;
uint32_t StartUpColor = strip.Color(0, 0, 255);
uint32_t RunnerColor = strip.Color(255, 0, 0);
uint32_t SelectorColor = strip.Color(0, 0, 255);
uint32_t Green = strip.Color(0, 64, 0, 64);
bool Running = true;
int RunnerSpeed = 100;

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  pinMode(SELECT_PIN, INPUT); // initialize pin for button
  
  StartUp(StartUpColor, 25); //Red
  StartUp(strip.Color(0,   0,   0), 25); //No Color
}

void loop() {
  for (int a=23; Running == true; a++) {
    if (a > 23) { a = 0; }
    strip.setPixelColor(a, RunnerColor);
    strip.setPixelColor(a-1, 0);
    strip.setPixelColor(23, SelectorColor);
    strip.show();
    delay(RunnerSpeed);
    
    ButtonState = digitalRead(SELECT_PIN);
    if (ButtonState == HIGH) {
      if (a == 23) {
        //score++;
        //wins++;
        RunnerSpeed *= 0.7;
        for (int b=0; b < 23; b++) {
          strip.setPixelColor(b, Green);
          strip.show();
        }
        delay(200);
        for (int b=0; b < 23; b++) {
          strip.setPixelColor(b, strip.Color(0, 0, 0));
          strip.show();
        }
      } else {
        //score--;
        //losses++;
        RunnerSpeed = 100;
        StartUp(StartUpColor, 25); //Red
        StartUp(strip.Color(0,   0,   0), 25); //No Color
        a = 23;
      } 
    }
  }
}

void StartUp(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

