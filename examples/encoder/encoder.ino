// RobustRotaryEncoder simple test program.

#include <RobustRotaryEncoder.h>

// Encoder pin mapping
#define ENCODER_A_PIN     6
#define ENCODER_B_PIN     7

// Declare our RobustRotaryEncoder object:
RobustRotaryEncoder encoder;

void setup() {
  // init serial interface
  Serial.begin(9600);
  
  // init RobustRotaryEncoder object (REQUIRED)
  encoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);
}

void loop() {
  if (encoder.read()) {
    // rotary encoder down
    if (encoder.isCCW()) {
      Serial.println("Encoder rotation: CCW");
    }
    // rotary encoder up
    if (encoder.isCW()) {
      Serial.println("Encoder rotation: CW");
    }
  }
}

