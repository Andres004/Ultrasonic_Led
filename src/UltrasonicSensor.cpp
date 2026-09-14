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
    // Generar pulso de 10 microsegundos
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Leer el rebote. El "30000" garantiza que el sistema responda en menos de 1 segundo (evita bloqueos)
    long duration = pulseIn(echoPin, HIGH, 30000); 
    
    // Si no hay objeto cerca, devuelve 400 (fuera de rango)
    if (duration == 0) {
        return 400.0; 
    }

    return (duration * 0.0343) / 2.0; 
}