#include "Led.h"

Led::Led(int p) {
    pin = p;
    isOn = false;
    lastToggleTime = 0;
}

void Led::begin() {
    pinMode(pin, OUTPUT);
    turnOff();
}

void Led::turnOn() {
    digitalWrite(pin, HIGH);
    isOn = true;
}

void Led::turnOff() {
    digitalWrite(pin, LOW);
    isOn = false;
}

void Led::blink(int pauseTime) {
    // Get the current time (milliseconds since the ESP32 started).
    unsigned long now = millis();

    // Check if enough time has passed since the last ON/OFF change.
    // If not enough time has passed yet, do nothing and return right away.
    // This is what makes it "non-blocking": no delay() is used here.
    if (now - lastToggleTime >= (unsigned long)pauseTime) {
        // Enough time passed, so flip the state: ON -> OFF or OFF -> ON.
        if (isOn) {
            turnOff();
        } else {
            turnOn();
        }
        lastToggleTime = now;
    }
}