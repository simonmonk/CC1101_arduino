#include <ELECHOUSE_CC1101.h>

// These examples are from the Electronics Cookbook by Simon Monk
// Connections (for an Arduino Uno)
// Arduino          CC1101
// GND              GND
// 3.3V             VCC
// 10               CSN/SS   **** Must be level shifted to 3.3V
// 11               SI/MOSI  **** Must be level shifted to 3.3V
// 12               SO/MISO
// 13               SCK      **** Must be level shifted to 3.3V
// 2                GD0

const int n = 61;

void setup()
{
  Serial.begin(9600);
  Serial.println("Rx");
  ELECHOUSE_cc1101.Init(F_433);  // set frequency - F_433, F_868, F_965 MHz
  ELECHOUSE_cc1101.SetReceive();
}

byte buffer[61] = {0};

void loop()
{
  if (ELECHOUSE_cc1101.CheckReceiveFlag())
  {
    int len = ELECHOUSE_cc1101.ReceiveData(buffer);
    buffer[len] = '\0';
    Serial.println((char *) buffer);
    ELECHOUSE_cc1101.SetReceive();
  }
}
