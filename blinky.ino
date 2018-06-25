#include <Arduino.h>

typedef void (*callback)();
typedef unsigned long ulong;

static void tempo(ulong currentTime);
static void main_beat(ulong currentTime);
static unsigned long get_interval(int ledState, ulong low, ulong high);

const static uint8_t ledPin = LED_BUILTIN;
const static uint8_t ledOther = 9;

int ledState = LOW;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(ledOther, OUTPUT);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledOther, HIGH);
}

void loop() {
    ulong currentMillis = millis();
    main_beat(currentMillis);
    tempo(currentMillis);
}

void main_beat(ulong currentMillis) {
    static ulong previousMillis = 0;
    static unsigned interval_high = 820;
    static int ledState = LOW;

    if (currentMillis - previousMillis >= interval_high) {
        previousMillis = currentMillis;

        if (ledState == LOW) {
            ledState = HIGH;
        } else {
            ledState = LOW;
        }
        digitalWrite(ledOther, ledState);
    }
}

void tempo(unsigned long currentMillis) {
    static unsigned long previousMillis = 0;
    const static unsigned interval_high = 600;
    const static unsigned interval_low = 220;
    if (currentMillis - previousMillis >= get_interval(ledState, interval_low, interval_high)) {
        previousMillis = currentMillis;

        if (ledState == LOW) {
            ledState = HIGH;
        } else {
            ledState = LOW;
        }
        digitalWrite(ledPin, ledState);
    }
}

ulong get_interval(int ledState, ulong low, ulong high) {
    if (ledState == LOW) {
        return low;
    }
    return high;
}
