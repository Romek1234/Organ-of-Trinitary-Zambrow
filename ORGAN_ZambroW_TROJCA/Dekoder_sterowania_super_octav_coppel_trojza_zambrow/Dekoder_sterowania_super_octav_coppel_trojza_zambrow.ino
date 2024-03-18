//Author Romuald Milewski
//Dodatkowy Dekoder Man. II for pipe organ Zambrow, sw. Trojca
//Arduino Nano or Uno

#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 13

#define decoder_channel 1 // the selected MIDI channel on which the decoder works
int pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
int remaining_pins[] = {12, 13, 10, 11, A1, A2, A3, A4, A5, A0};
// 15, 14, 17, 16, 
// 29, 28, 31, 30,

//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  
     // setup pins for output
for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
    pinMode(pins[i], OUTPUT);
    digitalWrite (pins[i], HIGH);
    //delay(200);
    //digitalWrite (pins[i], LOW);
    //delay(200);
    
  }
// setup remaining pinsfor output ( remaining_pins )
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
    if (pitch == 42){ 
      digitalWrite (2, LOW);
    }
    
    if (pitch ==43){
      digitalWrite (pins[1], LOW);
    }
    if (pitch == 53){
      digitalWrite (pins[2], LOW);
    }
    if (pitch == 54){
      digitalWrite (pins[3], LOW);
    }
    if (pitch == 55){
      digitalWrite (pins[4], LOW);
    }
    if (pitch == 56){
      digitalWrite (pins[5], LOW);
    }
    if (pitch == 70){
      digitalWrite (pins[6], LOW);
    }
    

    
  } 
}
 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
  if (channel == decoder_channel) {  
    if (pitch == 42){
      digitalWrite (2, HIGH);
    }
    
    if (pitch == 43){
      digitalWrite (pins[1], HIGH);
    }
    if (pitch == 53){
      digitalWrite (pins[2], HIGH);
    }
    if (pitch == 54){
      digitalWrite (pins[3], HIGH);
    }
    if (pitch == 55){
      digitalWrite (pins[4], HIGH);
    }
    if (pitch ==56){
      digitalWrite (pins[5], HIGH);
    }
    if (pitch == 70){
      digitalWrite (pins[6], HIGH);
    }
    

    
  } 
}
 
