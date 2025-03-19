#include <Arduino.h>
#include <SPI.h>
<<<<<<< HEAD
#include <Encoder.h>
#include <chrono>
=======
#include "Encoder.h"
#include "Move.h"
#include "Driver.h"
>>>>>>> 9c2bdea604a431e0541d3c0d60e3ec8de074af9a

// Define encoder SPI pins
// #define ENC_MISO 12    // Encoder data output (MISO)
// #define ENC_CLK  14    // SPI clock (SCK)
// #define ENC_CS   15    // Chip Select (active LOW)
// #define ENC_MOSI 13    // MOSI pin for encoder communication

#define PWM1 4
#define DIR1 2
#define PWM2 15
#define DIR2 13
#define SPEED 10
// Encoder ENC1(ENC_MISO, ENC_CLK, ENC_CS, ENC_MOSI);
Driver DVR1(PWM1, DIR1);
Driver DVR2(PWM2, DIR2);
Move move(DVR1, DVR2);

unsigned long startTime;

void printBinary16(uint16_t n);
unsigned long getTime(unsigned long startTime);

void setup() {
<<<<<<< HEAD
  Serial.begin(115200);
  ENC1.begin(); // Initializes SPI for ENC

  startTime = millis();
=======
  DVR1.begin();
  DVR2.begin();
>>>>>>> 9c2bdea604a431e0541d3c0d60e3ec8de074af9a
}

void loop() {
  // Read the 14-bit angle
<<<<<<< HEAD
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
=======

  move.moveX(SPEED, 1);
  delay(500);
  move.stop();
  delay(1000);
  move.moveX(SPEED, 0);
  delay(500);
  move.stop();
  delay(1000);
  move.moveY(SPEED, 1);
  delay(500);
  move.stop();
  delay(1000);
  move.moveY(SPEED, 0);
  delay(500);
  move.stop();
  delay(1000);
}

// void printBinary16(uint16_t n) {
//   for (int i = 15; i >= 0; i--) {
//     Serial.print((n >> i) & 1);
//   }
//   Serial.println();
// }
>>>>>>> 9c2bdea604a431e0541d3c0d60e3ec8de074af9a
