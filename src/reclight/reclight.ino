/*
 * 
 * Required libraries
 * ------------------
 * MIDIUSB (https://www.arduino.cc/en/Reference/MIDIUSB)  
 * - turns the Arduino into USB Slave mode and is then detected as a MIDI device
 * 
 * What's missing
 * --------------
 * Trigger another LED or relais
 * 
 */

#include "MIDIUSB.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      if (rx.byte1 == 0x90 && rx.byte2 == 0x5F) {
        digitalWrite(LED_BUILTIN, rx.byte3 == 0x7F ? HIGH : LOW);
      }
      
    }
  } while (rx.header != 0); 
}
