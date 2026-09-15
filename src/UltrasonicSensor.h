#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H
#include <Arduino.h>

// Simple driver class for an Ultrasonic Sensor (like the HC-SR04).
// Each UltrasonicSensor object controls exactly one sensor.
class UltrasonicSensor {
  private:
    int triggerPin; // GPIO pin used to send the sound pulse
    int echoPin;    // GPIO pin used to receive the bouncing echo

  public:
    // Constructor: sets which pins are connected to this sensor.
    UltrasonicSensor(int trig, int echo);

    // Set the trigger pin as OUTPUT and the echo pin as INPUT.
    void begin();

    // Measures and returns the distance to an object in centimeters.
    // If no object is nearby, it returns 400.0 (meaning out of range).
    float measureDistance();
};
#endif