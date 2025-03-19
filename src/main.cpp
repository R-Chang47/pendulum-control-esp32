#include <Arduino.h>
#include <SPI.h>
#include <Encoder.h>
#include <chrono>

// Define encoder SPI pins
#define ENC_MISO 12    // Encoder data output (MISO)
#define ENC_CLK  14    // SPI clock (SCK)
#define ENC_CS   15    // Chip Select (active LOW)
#define ENC_MOSI 13    // MOSI pin for encoder communication

Encoder ENC1(ENC_MISO, ENC_CLK, ENC_CS, ENC_MOSI);

unsigned long startTime;

void printBinary16(uint16_t n);
unsigned long getTime(unsigned long startTime);

void setup() {
  Serial.begin(115200);
  ENC1.begin(); // Initializes SPI for ENC

  startTime = millis();
}

void loop() {
  // Read the 14-bit angle
  float angle;
  angle = ENC1.readAngle();
  //Serial.print("Angle: ");
  Serial.println(angle);
  delay(10);
}

void printBinary16(uint16_t n) {
  for (int i = 15; i >= 0; i--) {
    Serial.print((n >> i) & 1);
  }
  Serial.println();
}

unsigned long getTime(unsigned long startTime) {
  unsigned long currentTime = millis();
  unsigned long duration = currentTime - startTime;
  return duration;
}
