/*
  Copyright (c) 2014-2015 NicoHood
  See the readme for credit to other people.
*/

#include "HID-Project.h"

const int pinLed = LED_BUILTIN;
const int MX01 = 2;
const int MX02 = 3;
const int MX03 = 4;
const int MX04 = 5;
const int MX05 = 7;
const int MX06 = 8;
const int MX07 = 21;
const int MX08 = 20;
const int MX09 = 19;
const int MX10 = 18;
const int MX11 = 14;
const int MX12 = 16;
const int VGround = 6;

void setup() {
  // Prepare led + buttons
  pinMode(pinLed, OUTPUT);
  pinMode(MX01, INPUT_PULLUP);
  pinMode(MX02, INPUT_PULLUP);
  pinMode(MX03, INPUT_PULLUP);
  pinMode(MX04, INPUT_PULLUP);
  pinMode(MX05, INPUT_PULLUP);
  pinMode(MX06, INPUT_PULLUP);
  pinMode(MX07, INPUT_PULLUP);
  pinMode(MX08, INPUT_PULLUP);
  pinMode(MX09, INPUT_PULLUP);
  pinMode(MX10, INPUT_PULLUP);
  pinMode(MX11, INPUT_PULLUP);
  pinMode(MX12, INPUT_PULLUP);
  pinMode(VGround, OUTPUT);
  digitalWrite(VGround, LOW);

  // Sends a clean report to the host. This is important on any Arduino type.
  Keyboard.begin();
}

void loop() {
  if (!digitalRead(MX01)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_HOME);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX02)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_UP);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX03)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_PAGE_UP);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX04)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_LEFT);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX05)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_ESC);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX06)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_RIGHT);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX07)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_END);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX08)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_DOWN);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX09)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_PAGE_DOWN);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX10)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_BACKSPACE);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX11)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_SPACE);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
  if (!digitalRead(MX12)) {
    digitalWrite(pinLed, HIGH);
    Keyboard.write(KEY_ENTER);
    // Simple debounce
    delay(300);
    digitalWrite(pinLed, LOW);
  }
}
