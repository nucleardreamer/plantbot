#include "Arduino.h"
#include <math.h>
#include "Adafruit_Sensor.h"
#include <DHT.h>
#include <DHT_U.h>

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void readSerial(){
  String data = Serial.readString();
  if (data.length() > 0) {
    Serial.println(data);
  }
}

void loop() {
  digitalWrite(ledPin, HIGH);
  if (Serial.available() > 0) {
    readSerial();
  }
  delay(1);
}
