// RobustRotaryEncoder simple test program.

#include <RobustRotaryEncoder.h>
// we use the awesome Button2 library to handle encoder button clicks
#include <Button2.h> 

// Encoder pin mapping
#define ENCODER_A_PIN     6
#define ENCODER_B_PIN     7
#define ENCODER_SW_PIN    8

// Declare our RobustRotaryEncoder object:
RobustRotaryEncoder encoder;
// ESP32Encoder encoder;
Button2 encoderBtn(ENCODER_SW_PIN);

void setup() {
  // init serial interface
  Serial.begin(9600);
  
  // init RobustRotaryEncoder object (REQUIRED)
  encoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);
  
  // init rorary encoder switch button
  encoderBtn.setPressedHandler([](Button2& b) {
    Serial.println("Encoder clicked");
  });
}

void loop() {
  encoderBtn.loop();

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

