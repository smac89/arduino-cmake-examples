#include <Arduino.h>

typedef void (*callback)();
typedef unsigned long ulong;

static void tempo(ulong currentTime);
static void main_beat(ulong currentTime);

static unsigned long get_interval(int ledState, ulong low, ulong high);

const static uint8_t ledPin = LED_BUILTIN;
const static uint8_t ledOther = 6;
const static long tempo_interval = 820;

const static unsigned interval_high = 600;
const static unsigned interval_low = tempo_interval - interval_high;

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

void main_beat(unsigned long currentMillis) {
    static unsigned long previousMillis = 415;
    static unsigned interval_high = 300;
    static unsigned interval_low = tempo_interval - interval_high;
    static int ledState = HIGH;

    if (currentMillis - previousMillis >= get_interval(ledState, interval_low, interval_high)) {
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
