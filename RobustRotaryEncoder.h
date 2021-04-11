/*!
 * @file RobustRotaryEncoder.h
 *
 * Arduino library for robust reading of rotary encoders.
 * 
 * Main logic code for robust reading:
 *   Copyright - John Main - best-microcontroller-projects.com
 * 
 * Library:
 *   Copyright - Juergen Skrotzky (JorgenVikingGod@gmail.com)
 *
 * RobustRotaryEncoder is free software: you can redistribute it and/or
 * modify it under the terms of the MIT License.
 *
 */

#ifndef ROBUSTROTARYENCODER_H
#define ROBUSTROTARYENCODER_H

#include <Arduino.h>

// These table holds the encoder pattern
static const int8_t _rotaryEncoderTable[] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};

/*! 
    @brief  Class that reads rotary encoder position.
*/
class RobustRotaryEncoder {
 public:
  // Constructor: encoder pin A and pin B
  RobustRotaryEncoder(uint8_t pinA, uint8_t pinB);
  RobustRotaryEncoder(void);
  ~RobustRotaryEncoder();

  void              begin(void);
  void              begin(uint8_t pinA, uint8_t pinB);
  int               read(void);
  int               incrementValue(void);
  bool              isChanged(void);
  bool              isCW(void);
  bool              isCCW(void);
  
 protected:
  uint8_t           m_pinA;     ///< encoder pin A
  uint8_t           m_pinB;     ///< encoder pin B
  int               m_val;      ///< current increment value: 1 (CW), -1 (CCW), 0 (invalid)
  uint8_t           m_code;     ///< previous / next code pattern
  uint16_t          m_store;    ///< stored pattern
};

#endif // ROBUSTROTARYENCODER_H
