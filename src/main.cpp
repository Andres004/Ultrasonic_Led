#include <Arduino.h>
#include "Led.h"
#include "UltrasonicSensor.h"

// FR1: Sensor and actuator initialization
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
    // FR1: Distance measurement
    float distance = mySensor.measureDistance();
    
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // FR2 & FR3: 3 ranges with completely distinct behaviors
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
        delay(100); // Small pause for stability
    }
}