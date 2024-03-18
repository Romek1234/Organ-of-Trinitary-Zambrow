//Author Romuald Milewski
//Dekoder Prospekt and Oboe for pipe organ Zambrow, sw. Trojca
//Arduino Mega and Mega2560

#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 13

#define decoder_channel 2 // the selected MIDI channel on which the decoder works
int pins[] = {A14, A15, A12, A13, A10, A11, A8, A9, A6, A7, A4, A5, A2, A3, A0, A1,   46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33,    3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 17, 16,     19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30};
int remaining_pins[] = {48,49,50}; // unused pins

// for I manuału tak:

//int pins[] = {3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12,     19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30,    A14, A15, A12, A13, A10, A11, A8, A9, A6, A7, A4, A5, A2, A3, A0, A1,   46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33};
// 15, 14, 17, 16, // unused pins 
// 

//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  
     // setup pins for output
for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
    pinMode(pins[i], OUTPUT);
    digitalWrite (pins[i], LOW);
    
  }
// setup remaining pinsfor output ( remaining_pins )
  for (int i = 0; i < sizeof(remaining_pins) / sizeof(remaining_pins[0]); ++i) {
    pinMode(remaining_pins[i], OUTPUT);
    digitalWrite (remaining_pins[i], LOW);    
    
  }  

 
      // self-test  jesli potrzebny
//  for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
//    digitalWrite(pins[i], HIGH);
//    delay(300); // Czas trwania stanu wysokiego - 300 ms
//    digitalWrite(piny[i], LOW);
//    delay(50);  // Dodatkowy czas dla lepszego zobaczenia efektu
//  }


  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
  MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}
 
void loop() { // Main loop
  MIDI.read(); // Continuously check if Midi data has been received.
}
 
// MyHandleNoteON is the function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
 if (channel == decoder_channel) {
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins) / sizeof(pins[0] )))){
   for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins[i], HIGH); // Set Arduino board pin 13 to output
     } 
    }
   } 
  }
 } 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
 if (channel == decoder_channel) {  
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins) / sizeof(pins[0] )))){
   for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
    if (pitch == 36+i) {
      digitalWrite (pins[i], LOW); // Set Arduino board pin 13 to output
    } 
   }
  }
 } 
}  
