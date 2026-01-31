#include <Arduino.h>

void setup() {
    // Joystick.begin();
    Serial.begin(115200);
    pinMode(20, INPUT); // Enable
    pinMode(21, INPUT); // X-AxisA
    pinMode(22, INPUT); // X-AxisB
    pinMode(24, INPUT); // Pitch Encoder
    pinMode(25, INPUT); // J4
    pinMode(26, INPUT); // J3
    pinMode(27, INPUT); // J2
}

float floatToJoystick(float eNum) {
    float jNum = (eNum - 512) / 512;
    return jNum;
}

void loop() {
    int enable = digitalRead(20);
    if (enable > 0) {
        float x = 0.0;
        float j2 = analogRead(27);
        float j3 = analogRead(26);
        float j4 = analogRead(25);
        float pitch = analogRead(24);
        // Joystick.X(floatToJoystick(x));
        // Joystick.Y(floatToJoystick(j2));
        // Joystick.Z(floatToJoystick(j3));
        // Joystick.Zrotate(floatToJoystick(j4));
        // Joystick.slider(floatToJoystick(pitch));
        Serial.println(floatToJoystick(pitch));
    } else {
        Serial.println("DISABLED");
    }
    delay(100);
}
