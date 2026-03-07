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
    Joystick.button(1, digitalRead(20));
    // Read Encoder Values
    int x = 0;
    int j2 = analogRead(27);
    int j3 = analogRead(26);
    int j4 = analogRead(25);
    int j5 = analogRead(24);

    // Joystick Values Sent to Basestation
    Joystick.button(2, millis() % 1000 < 500); // Toggle a button every second so the browser detects it.
    Joystick.X(0);
    Joystick.Y(j2);
    Joystick.Z(j3);
    Joystick.Zrotate(j4);
    Joystick.slider(j5);
}
