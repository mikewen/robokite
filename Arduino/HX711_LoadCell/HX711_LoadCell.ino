/*
 Inspired from code HX711 demo from Nathan Seidle, SparkFun Electronics

 This example code uses bogde's excellent library: https://github.com/bogde/HX711
 bogde's library is released under a GNU GENERAL PUBLIC LICENSE
 
 The HX711 does one thing well: read load cells. T

 The HX711 board can be powered from 2.7V to 5V so the Arduino 5V power should be fine.
 
*/

#include "HX711.h"

#define HX711_DOUT  12 // or DAT
#define HX711_CLK   11
#define HX711_GND   13

#define OFFSET 8177300 // From raw value when no load
#define SCALE  -146.7  // From calibration
HX711 scale(HX711_DOUT, HX711_CLK);
long raw_value;

void setup() {
  Serial.begin(57600);
  
  setupHX711();
}
void loop() {
  loopHX711();
}

void setupHX711() {
  // Ground connection
  pinMode(HX711_GND, OUTPUT);
  Serial.print("HX711_DOUT -> D");
  Serial.println(HX711_DOUT);
  Serial.print("HX711_CLK -> D");
  Serial.println(HX711_CLK);
  Serial.print("HX711_GND -> D");
  Serial.println(HX711_GND);
  Serial.println("HX711_VCC -> 3V3");

   // No calibration, read the raw value
  scale.set_offset(0);
  scale.set_scale(1);
}
void loopHX711() {
  raw_value = scale.get_units();
  Serial.print("Reading: ");
  Serial.print(raw_value, 1); //raw value
  Serial.print(" ");
  Serial.print((raw_value-OFFSET)/SCALE, 1); //scaled and offset after calibration
  Serial.print(" g"); 
  Serial.println();
}


