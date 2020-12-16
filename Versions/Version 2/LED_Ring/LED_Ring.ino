// Ring Game by Dexter Carpenter
// Updated 12/15/2020

// https://github.com/adafruit/Adafruit_NeoPixel
#include <Adafruit_NeoPixel.h>

// Using 24 LED ring from pin 6 and 3
#define LED_PIN    6
#define LED_COUNT  24
#define SELECT_PIN 3
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Define Variables
//int wins = 0;     // To keep track of wins
//int losses = 0;   // To keep track of losses
//int score = 0;    // To keep track of score
int RunnerSpeed = 100;  // Start running at ~100 millisecond delay

uint32_t StartUpColor = strip.Color(0, 0, 255);  // startup animation is blue
uint32_t RunnerColor = strip.Color(255, 0, 0);   // Runner color is red
uint32_t SelectorColor = strip.Color(0, 0, 255); // The selector is blue
uint32_t Green = strip.Color(0, 64, 0, 64);      // Green when user scores

bool ButtonState = 0; // Is the button pressed
bool Running = true;  // Is the runner running

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels
  strip.setBrightness(50); // Set BRIGHTNESS to about 20% (max = 255)

  pinMode(SELECT_PIN, INPUT); // Initialize pin for button
  
  StartUp(StartUpColor, 25); // Run startup sequence
  StartUp(strip.Color(0,   0,   0), 25); // No Color or off
}

void loop() {
  // Loop through all LEDs
  for (int a=23; Running == true; a++) {
    if (a > 23) { a = 0; } // Once runner reaches end of circle, start back at beginning
    
    strip.setPixelColor(a, RunnerColor);    // Set current LED to runner color
    strip.setPixelColor(a-1, 0);            // Set previous LED off
    strip.setPixelColor(23, SelectorColor); // Keep the selector in place
    strip.show();                           // Update NeoPixel
    delay(RunnerSpeed);                     // Wait according to the runner's speed
    
    ButtonState = digitalRead(SELECT_PIN);  // Read the button state
    
    if (ButtonState == HIGH) {
      if (a == 23) {  // If user and runner are on the same LED
        //score++;
        //wins++;
        
        RunnerSpeed *= 0.7;  // increase the runner's speed by decreasing delay time

        // Flash all LED's Green to signifiy user was correct
        for (int b=0; b < 23; b++) {
          strip.setPixelColor(b, Green);
          strip.show();
        }
        
        delay(200); // Wait a second

        // Then turn all LED's off
        for (int b=0; b < 23; b++) {
          strip.setPixelColor(b, strip.Color(0, 0, 0));
          strip.show();
        }
      } else {  // Else user pressed at the wrong time
        //score--;
        //losses++;
        RunnerSpeed = 100;                     // Reset the runner's speed
        StartUp(StartUpColor, 25);             // Run startup sequence
        StartUp(strip.Color(0,   0,   0), 25); // No Color or off
        a = 23;                                // Set the runner back tp the start
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
