//Author Romuald Milewski
// Dekoder Registry  manuał I Zambrów Trójca
//UNO &  midiuino

#include <MIDI.h>   // Add Midi Library
 


#define decoder_channel 1 // the selected MIDI channel on which the decoder works
int pins[] = {11, 12, 13, A0, A1, 9, 10, A2, A3};   //inne możliwości 2, 3, 9, 10, 4, 6, 5, 7, 8   i odwrotnoie 8, 7, 5, 6, 4, 10, 9, 3, 2
//
int remaining_pins[] = {2, 3, 4, 5, 6, 7, 8, A4, A5};



//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  
     // setup pins for output
for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
    pinMode(pins[i], OUTPUT);
    digitalWrite (pins[i], LOW);
    
  }
     // setup remaining_pins for output ( pozostałe )
  for (int i = 0; i < sizeof(remaining_pins) / sizeof(remaining_pins[0]); ++i) {
    pinMode(remaining_pins[i], OUTPUT);
    digitalWrite (remaining_pins[i], LOW);    
    
  }


 
      // self-test  jesli potrzebny
//  for (int i = 0; i < sizeof(piny) / sizeof(piny[0]); ++i) {
//    digitalWrite(piny[i], HIGH);
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
  if (pitch >= 44 && pitch <= (44 + ( sizeof(pins) / sizeof(pins[0] )))){
  for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
   if (pitch == 44+i) {
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
  if (pitch >= 44 && pitch <= (44 + ( sizeof(pins) / sizeof(pins[0] )))){
     for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
   if (pitch == 44+i) {
digitalWrite (pins[i], LOW); // Set Arduino board pin 13 to output
 } 
}
} 
} 
} 
