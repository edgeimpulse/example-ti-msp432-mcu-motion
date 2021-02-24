#include "SPI.h"

#define FREQUENCY_HZ        50
#define INTERVAL_MS         (1000 / (FREQUENCY_HZ + 1))

const int xpin = 23; // x-axis of the accelerometer
const int ypin = 24; // y-axis
const int zpin = 25; // z-axis

void setup() {
  // By default MSP432 has analogRead() set to 10 bits.
  // This Sketch assumes 12 bits. Uncomment to line below to set analogRead()
  // to 12 bit resolution for MSP432.
  //analogReadResolution(12);
  Serial.begin(115200);
  Serial.println("Started");
}

void loop() {
  static unsigned long last_interval_ms = 0;

  if (millis() > last_interval_ms + INTERVAL_MS) {
    last_interval_ms = millis();

    Serial.print(analogRead(xpin));
    Serial.print("\t");
    Serial.print(analogRead(ypin));
    Serial.print("\t");
    Serial.println(analogRead(zpin));
  }
}
