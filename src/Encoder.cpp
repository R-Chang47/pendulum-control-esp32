#include "Encoder.h"
#include <Arduino.h>
#include <SPI.h>

Encoder::Encoder(int miso, int clk, int cs, int mosi)
    : miso(miso), clk(clk), cs(cs), mosi(mosi),
      firstReading(true), prevAngle(0), rotationCount(0)
{}

void Encoder::begin() {  
  // Configure encoder
  pinMode(cs, OUTPUT);
  digitalWrite(cs, HIGH);  // Deselect encoder by default
  SPI.begin(clk, miso, mosi, cs);
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  Serial.println("AS5147 SPI Encoder Initialized");
}

float Encoder::readAngle() {
<<<<<<< HEAD
  // Reads encoder angle and outputs in degrees
  //uint16_t response;

  digitalWrite(CS, LOW);
  u_int16_t response = SPI.transfer16(0x3FFF);
  digitalWrite(CS, HIGH);
  float angle = float(response & 0x3FFF) / 16384.00 * 360.00;
=======
  // Reads encoder angle and converts to degrees (0-360)
  uint16_t response;
  digitalWrite(cs, LOW);
  response = SPI.transfer16(0x3FFF);
  digitalWrite(cs, HIGH);
  
  // Calculate the current angle between 0 and 360
  float angle = float(response & 0x3FFF) / 16384.0 * 360.0;

  if (firstReading) {
    prevAngle = angle;
    firstReading = false;
  } else {
    float diff = angle - prevAngle;

    // Adjust for multiple rollovers/rollbacks
    while (diff > 180) {
      rotationCount--;  // A negative diff means we've rolled back past 0
      diff -= 360;
    }
    while (diff < -180) {
      rotationCount++;  // A large negative difference indicates a rollover
      diff += 360;
    }
    
    prevAngle = angle;
  }

>>>>>>> 9c2bdea604a431e0541d3c0d60e3ec8de074af9a
  return angle;
}

float Encoder::getTotalAngle() {
  // Total angle is the number of rotations times 360 plus the current angle
  return rotationCount * 360.0 + prevAngle;
}