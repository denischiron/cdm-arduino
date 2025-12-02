/*
  Angular sensor + XInput (Gamepad)
  Language: Wiring/Arduino
  Board: Leonardo
  Author : Lou Aimé
*/

#include <XInput.h>

float clamp01(float v) {
  if (v < 0.0f) return 0.0f;
  if (v > 1.0f) return 1.0f;
  return v;
}

int clamp(int v, int mini, int maxi) {
  if (v < mini) return mini;
  if (v > maxi) return maxi;
  return v;
}

int16_t remap01ToInt16(float x) {
  x = clamp01(x);
  int32_t v = (int32_t)(x * 65535.0f - 32768.0f);
  v = clamp(v, -32768, 32767);
  return (int16_t)v;
}

float normalizeADC(int raw, int inMin, int inMax) {
  float t = (float)(raw - inMin) / (float)(inMax - inMin);
  t = clamp01(t);
  return t;
}

int readADC12bit(int pin) {
  uint32_t sum = 0;
  for (int i = 0; i < 16; i++)
    sum += analogRead(pin);
  return sum >> 2; // 0–4095
}


void setup() {
  XInput.setAutoSend(false);
  XInput.begin();
}

void loop() {
  /* without oversampling
  int raw = analogRead(A1);
  float t = normalizeADC(raw, 99, 920);
  //*/

  //* with oversampling
  int raw = readADC12bit(A1);
  float t = normalizeADC(raw, 99 * 4, 920 * 4); // 10bit to 12bit -> *4
  //*/

  XInput.setJoystick(JOY_RIGHT, remap01ToInt16(t), 0);

  XInput.send();
}