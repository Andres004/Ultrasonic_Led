#ifndef LED_H
#define LED_H
#include <Arduino.h>

class Led {
  private:
    int pin;

  public:
    Led(int p);
    void begin();
    void turnOn();
    void turnOff();
    void blink(int pauseTime);
};
#endif