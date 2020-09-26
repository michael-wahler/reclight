# reclight
This project turns an Arduino board with a native USB port into a multi-purpose MIDI device.

# Features
## Recording Light
When starting to record in your DAW, an LED is lit to show everybody in your place that you are recording.
In the current version, only the onboard LED is supported.

# Future Features
## Recording Light
Trigger an external LED or relais for a more impressive recording indicator that can be mounted far away from the Arduino.

## Recording Footswitch
- use a footswitch to start/stop recording in your DAW
- use a footswitch to fast forward/rewind

# Configuration
## Compiling the code and uploading it onto the Arduino board
to be done

## Configuring your DAW
In your DAW, add a new Mackie control device and choose the Arduino to receive MIDI data from and to send MIDI data to.
![Studio One Screenshot](https://github.com/michael-wahler/reclight/blob/master/doc/Studio%20One%20Arduino%201.png "Screenshot from Presonus Studio One")

# Compatibility
- Tested with Arduino Due version 1.6.12. Should work with Arduino Micro because it has native USB capabilities.
- Tested with version 1.0.4. of [MIDIUSB](https://www.arduino.cc/en/Reference/MIDIUSB).	
- Tested with Windows 10 and Presonus Studio One.