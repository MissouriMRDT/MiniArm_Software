#include <Arduino.h>

void setup() {
    Joystick.begin();
    pinMode(20, INPUT); // Enable
    pinMode(21, INPUT); // X-AxisA
    pinMode(22, INPUT); // X-AxisB
    pinMode(24, INPUT); // Pitch Encoder
    pinMode(25, INPUT); // J4
    pinMode(26, INPUT); // J3
    pinMode(27, INPUT); // J2
}

void loop() {
    int enable = digitalRead(20);
    // Read Encoder Values
    int j2 = analogRead(27);
    int j3 = 0.0;
    int j4 = 0.0;
    int pitch = 0.0;

    // Joystick Values Sent to Basestation
    Joystick.X(enable * 1024);
    Joystick.Y(j2);
    Joystick.Z(j3);
    Joystick.Zrotate(j4);
    Joystick.slider(pitch);
}
