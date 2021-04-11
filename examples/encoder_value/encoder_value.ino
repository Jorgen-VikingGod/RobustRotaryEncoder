// RobustRotaryEncoder simple test program.

#include <RobustRotaryEncoder.h>

// Encoder pin mapping
#define ENCODER_A_PIN     6
#define ENCODER_B_PIN     7

// Declare our RobustRotaryEncoder object:
RobustRotaryEncoder encoder;

int value = 0;

void setup() {
  // init serial interface
  Serial.begin(9600);
  
  // init RobustRotaryEncoder object (REQUIRED)
  encoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);
}

void loop() {
  int incValue = encoder.read();
  if (encoder.isChanged()) {
    value += incValue;
    Serial.print("Encoder (increment: ");
    Serial.print(incValue);
    Serial.print(", value: ");
    Serial.print(value);
    Serial.print(", rotation: "); 
    // rotary encoder down
    if (encoder.isCCW()) {
      Serial.print("CCW");
    }
    // rotary encoder up
    if (encoder.isCW()) {
      Serial.print("CW");
    }
    Serial.println(")");
  }
}

