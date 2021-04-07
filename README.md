# RobustRotaryEncoder Library

Arduino library for robust reading of rotary encoders.

After downloading, rename folder to 'RobustRotaryEncoder' and install in Arduino Libraries folder. Restart Arduino IDE, then open File->Sketchbook->Library->RobustRotaryEncoder->encoder sketch.

---

## Installation

### First Method

Add these lib dependency line to your platformio.ini

```ini
lib_deps =
    https://github.com/Jorgen-VikingGod/RobustRotaryEncoder.git
```

### Second Method

1. Navigate to the [Releases page](https://github.com/Jorgen-VikingGod/RobustRotaryEncoder/releases).
1. Download the latest release.
1. Extract the zip file
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

## Features

- ### Simple to use

  Reading rotary encoder increment value or directon (CW / CCW).

## Functions

- begin()
- read()
- incrementValue()
- isChanged()
- isCW()
- isCCW()

## Examples

There are some examples implemented in this library. One of the examples is below. You can find other examples [here](https://github.com/Jorgen-VikingGod/RobustRotaryEncoder/tree/master/examples)

### Encoder

```Cpp
#include <RobustRotaryEncoder.h>

#define ENCODER_A_PIN 6
#define ENCODER_B_PIN 7

RobustRotaryEncoder encoder;

void setup() {
  // configure encoder
  encoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);
}

void loop() {
  encoderBtn.loop();
  
  if (encoder.read()) {
    // rotary encoder down
    if (encoder.isCCW()) {
      Serial.println("CCW");
    }
    // rotary encoder up
    if (encoder.isCW()) {
      Serial.println("CW");
    }
  }
}
```

## Credits

This library is written by Juergen Skrotzky, but main code of the robust reading is based on code of John Main (best-microcontroller-projects.com).

## License

RobustRotaryEncoder is free software: you can redistribute it and/or modify it under the terms of the MIT license. 

