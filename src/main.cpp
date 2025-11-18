#include <Arduino.h>

void setup() { Joystick.begin(); }

unsigned int floatToJoystick(float j) {
  float k = (j + 1.0) / 2.0 * 1024.0;
  return k < 0 ? 0 : k > 1024 ? 1024 : (unsigned int)k;
}

void loop() {
  float x = -0.95;
  float j2 = -0.5;
  float j3 = 0;
  float j4 = 0.5;
  float pitch = 0.95;
  Joystick.X(floatToJoystick(x));
  Joystick.Y(floatToJoystick(j2));
  Joystick.Z(floatToJoystick(j3));
  Joystick.Zrotate(floatToJoystick(j4));
  Joystick.slider(floatToJoystick(pitch));
  delay(50);
}
