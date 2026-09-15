#include <Arduino.h>
#include "Led.h"
#include "UltrasonicSensor.h"

// RF1: Sensor and actuator initialization
UltrasonicSensor mySensor(27, 26);
Led redLed(25);
Led yellowLed(33);
Led whiteLed(32);

void setup() {
    Serial.begin(115200);

    mySensor.begin();
    redLed.begin();
    yellowLed.begin();
    whiteLed.begin();
}

void loop() {
    // RF1: Distance measurement
    float distance = mySensor.measureDistance();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // RF2 & RF3: 3 ranges with completely distinct behaviors.
    // Note: blink() no longer blocks the program, so measureDistance()
    // above still runs at a steady rate in ALL 3 zones, not just in
    // the "Clear" zone like before.
    if (distance < 20.0) {
        // Zone 1 (< 20 cm): Danger -> Fast blink
        yellowLed.turnOff();
        whiteLed.turnOff();
        redLed.blink(100);
    }
    else if (distance >= 20.0 && distance < 40.0) {
        // Zone 2 (20 to 39.9 cm): Warning -> Slow blink
        redLed.turnOff();
        whiteLed.turnOff();
        yellowLed.blink(500);
    }
    else {
        // Zone 3 (>= 40 cm): Clear -> Solid ON
        redLed.turnOff();
        yellowLed.turnOff();
        whiteLed.turnOn();
    }

    // Small pause so the HC-SR04 has time to "rest" before the next
    // trigger pulse (the datasheet recommends waiting a bit between
    // measurements so echoes from the previous pulse don't interfere).
    // This delay is short and always the same, no matter which zone is
    // active, so it does NOT create the uneven sampling rate problem
    // that the old delay()-based blink() had.
    delay(60);
}