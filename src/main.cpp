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

float floatToJoystick(float encoderNum) {
    float joystickNum = (encoderNum - 512) / 512;
    return joystickNum;
}

void loop() {
    int enable = digitalRead(20);
    if (enable > 0) {

        // Read Encoder Values
        float x = 0.0;
        float j2 = analogRead(27);
        float j3 = analogRead(26);
        float j4 = analogRead(25);
        float pitch = analogRead(24); 

        // Converted Joystick Values Sent to Basestation
        Joystick.X(x);
        Joystick.Y(j2);
        Joystick.Z(j3);
        Joystick.Zrotate(j4);
        Joystick.slider(pitch);
    }
}
