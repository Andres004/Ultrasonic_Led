#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trig, int echo) {
    triggerPin = trig;
    echoPin = echo;
}

void UltrasonicSensor::begin() {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float UltrasonicSensor::measureDistance() {
    // Generate a clean 10-microsecond sound pulse to start the measurement.
    // First, ensure the trigger pin is LOW, then send the HIGH pulse.
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Read the bouncing sound wave (the echo). 
    // The "30000" timeout (in microseconds) ensures the system responds quickly.
    // This prevents the program from freezing if the sound wave never comes back.
    long duration = pulseIn(echoPin, HIGH, 30000); 
    
    // If the duration is 0, no object is close enough to bounce the sound back.
    // We return 400.0 cm to indicate "out of range".
    if (duration == 0) {
        return 400.0; 
    }

    // Convert the time (duration) into distance in centimeters.
    // The speed of sound is roughly 0.0343 cm per microsecond.
    // We divide by 2.0 because the sound travels to the object AND back to the sensor.
    return (duration * 0.0343) / 2.0; 
}