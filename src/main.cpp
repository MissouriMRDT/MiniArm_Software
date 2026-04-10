#include <Arduino.h>

void setup() {
    Joystick.begin();
    pinMode(20, INPUT); // Enable
    pinMode(24, INPUT); // Pitch Encoder
    pinMode(25, INPUT); // J4
    pinMode(26, INPUT); // J3
    pinMode(27, INPUT); // J2
    pinMode(38, INPUT); // X-Axis
    pinMode(19, INPUT_PULLUP); // J6 Reverse
    pinMode(18, INPUT_PULLUP); // J6 Forward
    pinMode(17, INPUT_PULLUP); // G Reverse
    pinMode(16, INPUT_PULLUP); // G Forward
}


void loop() {
    // Read Encoder Values
    int x = analogRead(38);
    int j2 = analogRead(27);
    int j3 = analogRead(26);
    int j4 = analogRead(25);
    int j5 = analogRead(24);

    // Joystick Encoder Values Sent to Basestation
    Joystick.X(x);
    Joystick.Y(j2);
    Joystick.Z(j3);
    Joystick.Zrotate(j4);
    Joystick.slider(j5);

    // Joystick Buttons Set to Basestation
    Joystick.button(1, !digitalRead(19)); // J6 Reverse
    Joystick.button(2, !digitalRead(18)); // J6 Forward
    Joystick.button(3, !digitalRead(17)); // G Reverse
    Joystick.button(4, !digitalRead(16)); // G Forward
    Joystick.button(5, !digitalRead(20)); // Enable 
}
