 #include <Wire.h>
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
const int pumpPin = 8;
bool pumpOn = false;
bool goodtogo = true;

void setup() {
    Serial.begin(115200);

  while (!Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  Wire.begin();
  if (!lox.begin()) {
    Serial.println(F("Failed to initialize VL53L0X"));
    while (1);
  }
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);

  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));
  lox.startRangeContinuous();

}

void loop() {

  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);

  int distance = measure.RangeMilliMeter;


  Serial.print("Distance in mm: ");
  Serial.println(lox.readRange());

  // Check if the distance is within the specified range for pump control

  if (distance <= 30 && goodtogo) {
    if (!pumpOn) {
      pumpOn = true;
      digitalWrite(pumpPin, HIGH);
      goodtogo = false;
    } else {
      pumpOn = false;
      digitalWrite(pumpPin, LOW);
      goodtogo = false;
    }
  } else if (distance > 60) {
    goodtogo = true;
  }


  delay(50);  // Add a small delay to avoid excessive readings
}