//Author Romuald Milewski
// przyciski pod lkawiaturą  Zambrów Trójca
// podłączone od 0 do 8 plus Cresc zaczynając od D2 w arduino NANO
// wyzwalane stanem niskim (plus przez rezystor na stałe na LED

#include <MIDI.h>   // Add Midi Library
 
//#define LED 13 
//#define LED2 12// Arduino Board LED is on Pin 13

#define decoder_channel 1 // the selected MIDI channel on which the decoder works
int pins[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};     
// 19, 18, 21, 20, 23, 22, 25, 24, 27, 26,     A14, A15, A12, A13, A10, A11, A8, A9, A6, A7, A4, A5, A2, A3, A0, A1,   46, 47, 44, 45, 42, 43, 40, 41, 38, 39, 36, 37, 34, 35, 32, 33};
// 15, 14, 17, 16, 
// 29, 28, 31, 30,

int pitch_store = 84;
int end_pin = 0;

//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  
     // setup pins for output
for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
    pinMode(pins[i], OUTPUT);
    digitalWrite (pins[i], HIGH); // Ustawienie wszystkich pin na stan wysoki
  //  delay(200);
   // digitalWrite (pins[i], LOW);
  //  delay(200);
    
  }
digitalWrite (pins[0], LOW); // Ustawienie pierwszegi pina (D2) na stan LOW, by podswietoić piston 0 czyli kasownik 
 
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
/*
// obsługa pistonow 1 do 8

   if (pitch >= 76 && pitch <= 83){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej pistony  od 1 do 8 
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
          if (pitch == 76+i) {
          digitalWrite (pins[i+1], LOW); // włącza wlasciwą lampkę 
          } 
       }
   } 
*/
// obsługa kasownik (0)
   
   if (pitch == 84){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[0], LOW); // zapala lampkę 0
           
       
   } 
// obsługa 1
   
   if (pitch == 76){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[1], LOW); // zapala lampkę 0
           
       
   }      
// obsługa 2
   
   if (pitch == 77){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[2], LOW); // zapala lampkę 0
           
       
   } 
 // obsługa 3
   
   if (pitch == 78){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[3], LOW); // zapala lampkę 0
           
       
   } 
// obsługa 4
      if (pitch == 79){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[4], LOW); // zapala lampkę 0
           
       
   }
// obsługa 5
         if (pitch == 80){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[5], LOW); // zapala lampkę 0
           
       
   }
// obsługa 6
      if (pitch == 81){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[6], LOW); // zapala lampkę 0
           
       
   }
// obsługa 7
   
      if (pitch == 82){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[7], LOW); // zapala lampkę 0
           
       
   }
// obsługa 8
    if (pitch == 83){
       pitch_store = pitch;
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       digitalWrite (pins[8], LOW); // zapala lampkę 0
           
       
   }
// obsługa Crescendo (C)
   
   if (pitch == 88){ 
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       // zapalenie włąsciwej lampki podświetlającej dla pistonu 0 (kasownik) 
       end_pin = sizeof(pins) / sizeof(pins[0]) - 1;
       digitalWrite (pins[end_pin], LOW); // zapala ostatnią  lampkę (C) 
           
       
   }      

// obsługa Anuluj Crescendo (A)
   
   if (pitch == 89){ 
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       
       // zapalenie na powrót włąsciwej lampki podświetlającej pistony  od 1 do 8 lub (0)
       if (pitch_store >= 76 && pitch_store <= 83){
         for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
            if (pitch_store == 76+i) {
              digitalWrite (pins[i+1], LOW); // włącza wlasciwą lampkę (1 do 8)
            } 
         }
       }
       
       if (pitch_store == 84){
           digitalWrite (pins[0], LOW); // włącza wlasciwą lampkę (0)
       }
   }      
 

// obsługa Next (>)
   
   if (pitch == 85){ 

       pitch_store++;
       if (pitch_store > 83){
        pitch_store = 76;
       }
     
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       
       // zapalenie na powrót włąsciwej lampki podświetlającej pistony  od 1 do 8 lub (0)
       if (pitch_store >= 76 && pitch_store <= 83){
         for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
            if (pitch_store == 76+i) {
              digitalWrite (pins[i+1], LOW); // włącza wlasciwą lampkę (1 do 8)
            } 
         }
       }
       
       if (pitch_store == 84){
           digitalWrite (pins[0], LOW); // włącza wlasciwą lampkę (0)
       }
   }  

// obsługa Prew (<) (-)
   
   if (pitch == 86){ 

       pitch_store--;
       if (pitch_store < 76){
        pitch_store = 83;
       }
     
       // gaszenie wszystkich lampek podświetlenia
       for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i){ 
          digitalWrite (pins[i], HIGH); 
       }
       
       // zapalenie na powrót włąsciwej lampki podświetlającej pistony  od 1 do 8 lub (0)
       if (pitch_store >= 76 && pitch_store <= 83){
         for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
            if (pitch_store == 76+i) {
              digitalWrite (pins[i+1], LOW); // włącza wlasciwą lampkę (1 do 8)
            } 
         }
       }
       
       if (pitch_store == 84){
           digitalWrite (pins[0], LOW); // włącza wlasciwą lampkę (0)
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
     // for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); ++i) {
     // if (pitch == 76+i) {
     // digitalWrite (pins[i], LOW); // Set Arduino board pin 13 to output
     //   }     

  } 
}  
