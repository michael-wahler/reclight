/*
   This program continuosly reads from the MIDI port and checks for the Mackie command for "record".
   Depending on "record" being on or off, it triggers an LED on the Arduino.

   Required libraries
   ------------------
   MIDIUSB (https://www.arduino.cc/en/Reference/MIDIUSB)
   - turns the Arduino into USB Slave mode and is then detected as a MIDI device

   What's missing
   --------------
   Trigger another LED or relais

*/

#include "MIDIUSB.h"

#include "config.h"

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
      // check for Mackie command 95d/5Fh "record"
      // for Mackie commands, see https://www.native-instruments.com/forum/threads/mackie-control-mcu-parameter-id-codes-template.266581/
      if (ENABLE_RECORDING_LIGHT) {
        if (rx.byte1 == 0x90 && rx.byte2 == 0x5F) {
          digitalWrite(LED_BUILTIN, rx.byte3 == 0x7F ? HIGH : LOW);
        }
      }

    }
  } while (rx.header != 0);
}
