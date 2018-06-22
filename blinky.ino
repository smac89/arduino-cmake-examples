#include <Arduino.h>

const static uint8_t ledPin = 10;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, LOW);
//    delay(2000);
//    digitalWrite(ledPin, HIGH);
//    delay(1300);
}
