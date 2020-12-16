# RingGame

Made by Dexter Carpenter

## Overview
An Arduino-based arcade style game. Press the button when the lights line up to proceed to a faster level. 

This was a one-day project. Using a Adafruit Neopixel ring (24), an Arduinio Uno, and a button I created a game where the objective is to press the button when the "runner" and the "selector" are aligned. If you are successful, you get a green flash and the runner gets faster. This proceeds until you miss, in which an animation plays and restarts the runner's speed.

My goal was to make this as simple as possible, using just the NeoPixel and a button as the UI.

Below is my documentation on the project.

## Documentation

### GIF

![GIF](https://github.com/DexterCarpenter/RingGame/blob/master/Documentation/RingGame.gif)

### List of Materials

| Item            | Quantity | Source                                                   |
|-----------------|----------|----------------------------------------------------------|
| NeoPixel 24     | 1        | [Adafruit](https://www.adafruit.com/product/1586)        |
| Push Button     | 1        | N/A                                                      |
| Resistor (1000ohm) | 1        | N/A                                                      |
| Resistor (680ohm) | 1        | N/A                                                      |
| Arduino Uno     | 1        | [Arduino](https://store.arduino.cc/usa/arduino-uno-rev3) |
| Jumper Wires    | 5        | N/A                                                      |
| Breadboard      | 1        | N/A                                                      |

### Wiring Diagram

![Wiring Diagram](https://github.com/DexterCarpenter/RingGame/blob/master/Documentation/RingGameWDiagram.PNG)

## References

Thanks to [Colin Hale-Brown](https://github.com/colinhalebrown) for his help making the custom circuit

Thanks to [Adafruit](https://www.adafruit.com/) for their documentation on their product

The NeoPixel Library by [Adafruit](https://www.adafruit.com/) (Adafruit_NeoPixel.h) can be found [here](https://github.com/adafruit/Adafruit_NeoPixel)

Thanks to [Tinkercad](https://www.tinkercad.com) for help making the wiring diagram


