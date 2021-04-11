/*!
 * @file RobustRotaryEncoder.cpp
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

#include "RobustRotaryEncoder.h"

/*!
  @brief   RobustRotaryEncoder constructor
  @param   pinA   encoder pin A.
  @param   pinB   encoder pin B.
  
  @return  RobustRotaryEncoder object. Call the begin() function before use.
*/
RobustRotaryEncoder::RobustRotaryEncoder(uint8_t pinA, uint8_t pinB) :
  m_pinA(pinA), m_pinB(pinB) { }

/*!
  @brief   "Empty" RobustRotaryEncoder constructor
  @return  RobustRotaryEncoder object. Call the begin(pinA, pinB) function before use.
*/
RobustRotaryEncoder::RobustRotaryEncoder(void) :
  m_pinA(0), m_pinB(0) { }

/*!
  @brief   Deallocate Adafruit_NeoPixel object, set data pin back to INPUT.
*/
RobustRotaryEncoder::~RobustRotaryEncoder() { }

/*!
  @brief   Configure encoder pins for input.
*/
void RobustRotaryEncoder::begin(void) {
  if (m_pinA && m_pinB) {
    // rotary encoder port config
    pinMode(m_pinA, INPUT);
    pinMode(m_pinA, INPUT_PULLUP);
    pinMode(m_pinB, INPUT);
    pinMode(m_pinB, INPUT_PULLUP);
  }
}

/*!
  @brief   Configure encoder pins for input.
  @param   pinA   encoder pin A.
  @param   pinB   encoder pin B.
*/
void RobustRotaryEncoder::begin(uint8_t pinA, uint8_t pinB) {
  m_pinA = pinA;
  m_pinB = pinB;
  begin();
}

/*!
  @brief   Read current encoder value.
  @return  encoder increment value. (1 = CW, -1 = CCW, 0 = invalid).
*/
int RobustRotaryEncoder::read(void) {
  m_code <<= 2;
  if (digitalRead(m_pinA)) {
    m_code |= 0x02;
  }
  if (digitalRead(m_pinB)) {
    m_code |= 0x01;
  }
  m_code &= 0x0f;
  // If valid then store as 16 bit data.
  if (_rotaryEncoderTable[m_code]) {
    m_store <<= 4;
    m_store |= m_code;
    if ((m_store & 0xff) == 0x2b) {
      m_val = -1;
      return m_val;
    }
    if ((m_store & 0xff) == 0x17) {
      m_val = 1;
      return m_val;
    }
  }
  m_val = 0;
  return m_val;
}

/*!
  @brief   get current increment value.
  @return  encoder increment value. (1 = CW, -1 = CCW, 0 = invalid).
*/
int RobustRotaryEncoder::incrementValue(void) {
  return m_val;
}

/*!
  @brief   check if encoder was changed.
  @return  encoder change state. (true = changed, false = unchanged).
*/
bool RobustRotaryEncoder::isChanged(void) {
  return m_val != 0;
}

/*!
  @brief   check if encoder was rotated CW.
  @return  encoder CW direction. (true = CW, false = not CW).
*/
bool RobustRotaryEncoder::isCW(void) {
  return m_code == 0x07;
}

/*!
  @brief   check if encoder was rotated CCW.
  @return  encoder CCW direction. (true = CCW, false = not CCW).
*/
bool RobustRotaryEncoder::isCCW(void) {
  return m_code == 0x0b;
}

