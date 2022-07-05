#include <SPI.h>
#include <Wire.h>
#include "SH1106Wire.h"
#include <BH1750.h>
#include <Wire.h>

BH1750 lightMeter(0x23); //lightmeter instance with address
SH1106Wire display(0x3c, 21, 22); //oled instance with address and SDA and SCL pins
 
void printDisplay();
void drawProgressBarDemo();

void setup() {
  Serial.begin(115200);
  Wire.begin();
  lightMeter.begin();
  display.init();
  display.setFont(ArialMT_Plain_10);
}

void loop() {
  printDisplay();
  delay(60);
}
void drawProgressBarDemo() {
  float h = lightMeter.readLightLevel();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 0, "LIGHT INTENSITY METER");
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 14, "LUX : " + String(h));
  display.drawProgressBar(0, 32, 126, 10, h/2);
  
}

void printDisplay(){
  display.clear();
  drawProgressBarDemo();
  display.display();
}
