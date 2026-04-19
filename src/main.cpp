#include <Arduino.h>

#define J6_FWD_BTN 18
#define J6_RVS_BTN 19
#define G_FWD_BTN 16
#define G_RVS_BTN 17
#define X_FWD_BTN 28
#define X_RVS_BTN 38
#define ENABLE 20
#define J2 27
#define J3 26
#define J4 25
#define PITCH 24

void setup() {
    Joystick.begin();
    pinMode(ENABLE, INPUT);            // Enable
    pinMode(PITCH, INPUT);             // Pitch Encoder
    pinMode(J4, INPUT);                // J4
    pinMode(J3, INPUT);                // J3
    pinMode(J2, INPUT);                // J2
    pinMode(J6_RVS_BTN, INPUT_PULLUP); // J6 Reverse
    pinMode(J6_FWD_BTN, INPUT_PULLUP); // J6 Forward
    pinMode(G_RVS_BTN, INPUT_PULLUP);  // G Reverse
    pinMode(G_FWD_BTN, INPUT_PULLUP);  // G Forward
    pinMode(X_RVS_BTN, INPUT_PULLUP);  // X Reverse
    pinMode(X_FWD_BTN, INPUT_PULLUP);  // X Forward
}

void loop() {
    // Read Encoder Values
    int j2 = analogRead(J2);
    int j3 = analogRead(J3);
    int j4 = analogRead(J4);
    int j5 = analogRead(PITCH);

    // Joystick Encoder Values Sent to Basestation
    Joystick.Y(j2);
    Joystick.Z(j3);
    Joystick.Zrotate(j4);
    Joystick.slider(j5);

    // Joystick Buttons Set to Basestation
    Joystick.button(1, !digitalRead(J6_RVS_BTN)); // J6 Reverse
    Joystick.button(2, !digitalRead(J6_FWD_BTN)); // J6 Forward
    Joystick.button(3, !digitalRead(G_RVS_BTN));  // G Reverse
    Joystick.button(4, !digitalRead(G_FWD_BTN));  // G Forward
    Joystick.button(5, !digitalRead(X_RVS_BTN));  // X Reverse
    Joystick.button(6, !digitalRead(X_FWD_BTN));  // X Forward

    Joystick.button(7, !digitalRead(ENABLE)); // Enable
}
