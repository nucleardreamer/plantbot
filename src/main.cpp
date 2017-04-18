
#include "Arduino.h"
#include <math.h>

#include "DHT.h"

#define LEDPIN 13
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(DHTPIN, INPUT);
  dht.begin();
  Serial.begin(115200);
}

void readSerial(){
  String data = Serial.readString();
  if (data.length() > 0) {
    Serial.println(data);
  }
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float f = dht.readTemperature(true); // bool for F not C

  if (isnan(h) || isnan(f)) {
    Serial.println("fucking fail");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print(hif);
  Serial.println(" *F");
}
