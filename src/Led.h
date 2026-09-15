#ifndef LED_H
#define LED_H
#include <Arduino.h>

// Simple driver class for one LED.
// Each Led object controls exactly one pin.
// blink() does NOT use delay(), so it never freezes the program.
class Led {
  private:
    int pin;                      // GPIO pin connected to this LED
    bool isOn;                    // current state: true = ON, false = OFF
    unsigned long lastToggleTime; // last time (in ms) the LED changed state

  public:
    Led(int p);

    // Set the pin as OUTPUT and start with the LED OFF.
    void begin();

    // Turn the LED fully ON (solid light).
    void turnOn();

    // Turn the LED fully OFF.
    void turnOff();

    // Make the LED blink, WITHOUT blocking the program.
    // "pauseTime" is how long (in ms) the LED stays ON, then OFF.
    // IMPORTANT: call this function again on every loop() while this
    // LED's zone is active. It only changes the LED state when enough
    // time has passed; the rest of the time it just returns immediately.
    void blink(int pauseTime);
};
#endif