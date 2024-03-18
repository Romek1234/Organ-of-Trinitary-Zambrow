//Author Romuald Milewski
//Dekoder Prospektu for pipe organ Zambrow, sw. Trojca
//Arduino Mega and Mega2560

#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 
#define decoder_channel_Reg 1  // the selected MIDI channel on which the decoder works
#define decoder_channel_I 2
#define decoder_channel_II 3
#define decoder_channel_P 4 

#define pitch_PED_PR_16 36
#define pitch_PED_OCTVBAS_8 38
#define pitch_M_I_PR_8 44
#define pitch_M_II_PR_8 58 


int pins_PED_PR_16[] = {19, 18, 21, 20, 23, 14, 25, 24, 27, 26, 29, 28};
int pins_PED_OCTVBAS_8[] = {3, 2, 5, 4, 7, 6, 9, 8, A1, A0, A3, A2};
int pins_M_I_PR_8[] = {A14, A15, A12, A13, A10, A11, A8, A9, A6, A7, A4, A5};
int pins_M_II_PR_8[] = {31, 30, 11, 10, 13, 12};

int remaining_pins[] = {41, 47, 44, 45, 42, 43, 40, 38, 39, 36, 37, 34, 35, 32, 33, 31, 30,  22, 15, 17, 16}; // unused pins
// 
// for man II :
// int pins[] = {3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12,     19, 18, 21, 20, 23, 22, 25, 24, 27, 26,     A14, A15, A12, A13, A10, A11, A8, A9, A6, A7, A4, A5, A2, A3, A0, A1,   46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33};
// 15, 14, 17, 16, // unused pins
// 29, 28, 31, 30,// unused pins
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();

bool state_Reg_PED_PR_16 = false;
bool state_Reg_PED_OCTVBAS_8 = false;
bool state_Reg_M_I_PR_8 = false;
bool state_Reg_M_II_PR_8 = false;
unsigned long BAS_channel_4 = 0; // Flags for MIDI-channel 4 - Ped.
unsigned long BAS_PED_OCTVBAS_8 = 0; //Flags for MIDI-channel 4 - octavbas
unsigned long BAS_M_I_PR_8 = 0; // Flags for MIDI-channel 2
unsigned long BAS_M_II_PR_8 = 0; // Flags for MIDI-channel 3


void setup() {
  
     // setup pins for output Pedał Pryncypał 16
for (int i = 0; i < sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0]); ++i) {
    pinMode(pins_PED_PR_16[i], OUTPUT);
    digitalWrite (pins_PED_PR_16[i], LOW);
    
  }
 // setup pins for output Pedał Oktavbas 8
for (int i = 0; i < sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0]); ++i) {
    pinMode(pins_PED_OCTVBAS_8[i], OUTPUT);
    digitalWrite (pins_PED_OCTVBAS_8[i], LOW);
    
  }
  // setup pins for output Man. I Pryncypał 8
for (int i = 0; i < sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0]); ++i) {
    pinMode(pins_M_I_PR_8[i], OUTPUT);
    digitalWrite (pins_M_I_PR_8[i], LOW);
    
  } 
 // setup pins for output Man. II Pryncypał Fl. 8
for (int i = 0; i < sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0]); ++i) {
    pinMode(pins_M_II_PR_8[i], OUTPUT);
    digitalWrite (pins_M_II_PR_8[i], LOW);
    
  }   
// setup remaining pinsfor output ( remaining_pins )
  for (int i = 0; i < sizeof(remaining_pins) / sizeof(remaining_pins[0]); ++i) {
    pinMode(remaining_pins[i], OUTPUT);
    digitalWrite (remaining_pins[i], LOW);    
    
  }
 




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
  
 if (channel == decoder_channel_Reg){
  
 if (pitch == pitch_PED_PR_16){
    state_Reg_PED_PR_16 = true;
    pinsOn_in_flags();
   //  digitalWrite (30, HIGH);
  }
  if (pitch == pitch_PED_OCTVBAS_8){
    state_Reg_PED_OCTVBAS_8 = true;
    pinsOn_in_flags_OCT();
   // digitalWrite (30, HIGH);
  }
  if (pitch == pitch_M_I_PR_8){
    state_Reg_M_I_PR_8 = true;
    pinsOn_in_flags_M_I();
  }
  if (pitch == pitch_M_II_PR_8){
    state_Reg_M_II_PR_8 = true;
    pinsOn_in_flags_M_II();
  } 
 }
  
 if (channel == decoder_channel_P) {
  
// aktualizacja flag kanałowych dla Pryncypału 16 w Pedale
    if (pitch >= 40 && pitch <= (40 + ( sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0] )))){ 
      bitSet(BAS_channel_4, pitch - 40);
       }     
          
 // aktualizacja flag kanałowych dla Oktavbasu 8 w Pedale
    if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0] )))){ 
      bitSet(BAS_PED_OCTVBAS_8, pitch - 36);
       }  
 }    
   if (channel == decoder_channel_I) {     
 // aktualizacja flag kanałowych dla Pryncypału 8 w Man. I
    if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0] )))){ 
      bitSet(BAS_M_I_PR_8, pitch - 36);
       }           
   }
   if (channel == decoder_channel_II){
 // aktualizacja flag kanałowych dla Pryncypału FL. 8 w Man. II
    if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0] )))){ 
      bitSet(BAS_M_II_PR_8, pitch - 36);
       } 
   }
  if (channel == decoder_channel_P){            
 // ---- jesli wlączony pryncypał 16        
  if(state_Reg_PED_PR_16 == true){
  if (pitch >= 40 && pitch <= (40 + ( sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0] )))){
   for (int i = 0; i < sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0]); ++i) {
    if (pitch == 40+i) {
     digitalWrite (pins_PED_PR_16[i], HIGH); // Set Arduino board pin 13 to output
     } 
    }
   } 
  }

// ----- jesli wlaczony Octavbas 8
   if(state_Reg_PED_OCTVBAS_8 == true){
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0] )))){
   for (int i = 0; i < sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins_PED_OCTVBAS_8[i], HIGH); 
     } 
    }
   } 
  }
  }
  if (channel == decoder_channel_I){
// ----- jesli wlaczony pryncypał 8 w man. I
   if(state_Reg_M_I_PR_8 == true){
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0] )))){
   for (int i = 0; i < sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins_M_I_PR_8[i], HIGH); 
     } 
    }
   } 
  }
  }
  if (channel == decoder_channel_II){
  // ----- jesli wlaczony pryncypał 8 w man. II
   if(state_Reg_M_II_PR_8 == true){
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0] )))){
   for (int i = 0; i < sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins_M_II_PR_8[i], HIGH); 
     } 
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
  if (channel == decoder_channel_Reg){
    
  if (pitch == pitch_PED_PR_16){
  state_Reg_PED_PR_16 = false;
  pinsOff_in_flags();
  // digitalWrite (30, LOW);
  }
  
  if (pitch == pitch_PED_OCTVBAS_8) { 
  state_Reg_PED_OCTVBAS_8 = false;
  pinsOff_in_flags_OCT();
  // digitalWrite (30, LOW);
  }
  
  if (pitch == pitch_M_I_PR_8){ 
  state_Reg_M_I_PR_8 = false;
  pinsOff_in_flags_M_I();
  }
  
  if (pitch == pitch_M_II_PR_8){ 
  state_Reg_M_II_PR_8 = false;
  pinsOff_in_flags_M_II();
 }
 }
  
 if (channel == decoder_channel_P) { 
  
  // aktualizacja flag kanałowych dla Pryncypału 16 w Pedale
      if (pitch >= 40 && pitch <= (40 + ( sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0] )))){ 
      bitClear(BAS_channel_4, pitch - 40);
      }
  // aktualizacja flag kanałowych dla Oktavbasu 8 w Pedale
    if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0] )))){ 
      bitClear(BAS_PED_OCTVBAS_8, pitch - 36);
       }  
 }
 if (channel == decoder_channel_I){ 
 // aktualizacja flag kanałowych dla Pryncypału 8 w Man. I
    if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0] )))){ 
      bitClear(BAS_M_I_PR_8, pitch - 36);
       }           
 }
 if (channel == decoder_channel_II){
 // aktualizacja flag kanałowych dla Pryncypału FL. 8 w Man. II
    if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0] )))){ 
      bitClear(BAS_M_II_PR_8, pitch - 36);
       }       
 }
 if (channel == decoder_channel_P){
 // ---- jesli wlączony pryncypał 16   
  if(state_Reg_PED_PR_16 == true) { 
  if (pitch >= 40 && pitch <= (40 + ( sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0] )))){
   for (int i = 0; i < sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0]); ++i) {
    if (pitch == 40+i) {
      digitalWrite (pins_PED_PR_16[i], LOW); 
    } 
   }
  }
  }
// ----- jesli wlaczony Octavbas 8
   if(state_Reg_PED_OCTVBAS_8 == true){
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0] )))){
   for (int i = 0; i < sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins_PED_OCTVBAS_8[i], LOW); // Set Arduino board pin 13 to output
     } 
    }
   } 
  }
 }
 if (channel == decoder_channel_I){
// ----- jesli wlaczony pryncypał 8 w man. I
   if(state_Reg_M_I_PR_8 == true){
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0] )))){
   for (int i = 0; i < sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins_M_I_PR_8[i], LOW); 
     } 
    }
   } 
  }
 }
 if (channel == decoder_channel_II){
  // ----- jesli wlaczony pryncypał 8 w man. II
   if(state_Reg_M_II_PR_8 == true){
  if (pitch >= 36 && pitch <= (36 + ( sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0] )))){
   for (int i = 0; i < sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0]); ++i) {
    if (pitch == 36+i) {
     digitalWrite (pins_M_II_PR_8[i], LOW); 
     } 
    }
   } 
  } 
  
}
}  


// ************* Funkcje właczenia registrem ON ****************

void pinsOn_in_flags(){
  for (int i = 0; i < sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0]); ++i) {
  
      digitalWrite (pins_PED_PR_16[i], bitRead(BAS_channel_4, i)); 
  
   }

}
void pinsOn_in_flags_OCT(){
  for (int i = 0; i < sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0]); ++i) {
  
      digitalWrite (pins_PED_OCTVBAS_8[i], bitRead(BAS_PED_OCTVBAS_8, i));   
   }

}

void pinsOn_in_flags_M_I(){
  for (int i = 0; i < sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0]); ++i) {
  
      digitalWrite (pins_M_I_PR_8[i], bitRead(BAS_M_I_PR_8, i));       
   }

}

void pinsOn_in_flags_M_II(){
  for (int i = 0; i < sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0]); ++i) {
  
      digitalWrite (pins_M_II_PR_8[i], bitRead(BAS_M_II_PR_8, i)); // Set Arduino board pin 13 to output
  
   }

}

// *********************  Funkcje wyłączenia registrem OFF *******************

void pinsOff_in_flags(){
for (int i = 0; i < sizeof(pins_PED_PR_16) / sizeof(pins_PED_PR_16[0]); ++i) {
  
        digitalWrite (pins_PED_PR_16[i], LOW); 
   }
}

void pinsOff_in_flags_OCT(){
for (int i = 0; i < sizeof(pins_PED_OCTVBAS_8) / sizeof(pins_PED_OCTVBAS_8[0]); ++i) {
  
        digitalWrite (pins_PED_OCTVBAS_8[i], LOW); 
   }
}

void pinsOff_in_flags_M_I(){
for (int i = 0; i < sizeof(pins_M_I_PR_8) / sizeof(pins_M_I_PR_8[0]); ++i) {
  
        digitalWrite (pins_M_I_PR_8[i], LOW); 
   }
}

void pinsOff_in_flags_M_II(){
for (int i = 0; i < sizeof(pins_M_II_PR_8) / sizeof(pins_M_II_PR_8[0]); ++i) {
  
        digitalWrite (pins_M_II_PR_8[i], LOW); 
   }
}
