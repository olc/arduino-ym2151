
#include <Arduino.h>
#include "YM2151.h"

// Pins are for an Arduino Mega 2560 
int YM_Datapins[8] = {A0, A1, A2, A3, A4, A5, A6, A7};
const int YM_CS = A8;
const int YM_RD = A9;
const int YM_WR = A10;
const int YM_A0 = A11;
const int YM_IC = A12;
const int YM_IRQ = A13;
YM2151 opm(YM_Datapins, YM_CS, YM_RD, YM_WR, YM_A0, YM_IRQ, YM_IC);

const int LoNote = 0x3A;
const int HiNote = 0x44;

void setup() {
  opm.Reset();
  
  opm.SendDataPins(0x20, 0xC0);
  opm.SendDataPins(0x58, 0x01);
  opm.SendDataPins(0x98, 0x1F);
  opm.SendDataPins(0xB8, 0x0D);
  opm.SendDataPins(0xF8, 0xF6);
}

void loop() {
  // play a two chime sounds
  // port of: https://commander-cx16.fandom.com/wiki/Beep
  opm.SendDataPins(0x28, LoNote);
  opm.SendDataPins(0x08, 0x00);
  opm.SendDataPins(0x08, 0x40);
  delay(1000);
  opm.SendDataPins(0x28, HiNote);
  opm.SendDataPins(0x08, 0x00);
  opm.SendDataPins(0x08, 0x40);
  delay(1000);
}
