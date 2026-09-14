#include "Led.h"

Led::Led(int p) {
    pin = p;
}

void Led::begin() {
    pinMode(pin, OUTPUT);
    turnOff();
}

void Led::turnOn() {
    digitalWrite(pin, HIGH);
}

void Led::turnOff() {
    digitalWrite(pin, LOW);
}

void Led::blink(int pauseTime) {
    turnOn();
    delay(pauseTime);
    turnOff();
    delay(pauseTime);
}