#include <MIDI.h>   // Add Midi Library
 
#define LED 13    // Arduino Board LED is on Pin 13
#define LED2 2
#define LED3 3
unsigned long BAS_channel_1 = 0; // Flags for MIDI-channel 1
unsigned long TREBL_channel_1 = 0;

unsigned long BAS_channel_2 = 0; // Flags for MIDI-channel 2
unsigned long TREBL_channel_2 = 0;

unsigned long BAS_channel_3 = 0; // Flags for MIDI-channel 3
unsigned long TREBL_channel_3 = 0;

#define sub_II_to_I 8
unsigned long BAS_sub_II_to_I = 0;
unsigned long TREBL_sub_II_to_I = 0;
byte sub_II_to_I_monitor = 0;

#define super_II_to_I 9
unsigned long BAS_super_II_to_I = 0;
unsigned long TREBL_super_II_to_I = 0;
byte super_II_to_I_monitor = 0;

#define II_to_I 10
unsigned long BAS_II_to_I = 0;
unsigned long TREBL_II_to_I = 0;
byte II_to_I_monitor = 0;

#define super_I 11
unsigned long BAS_super_I = 0;
unsigned long TREBL_super_I = 0;
byte super_I_monitor = 0;


#define super_II 12
unsigned long BAS_super_II = 0;
unsigned long TREBL_super_II = 0;
byte super_II_monitor = 0;

#define II_to_P 7
unsigned long BAS_II_to_P = 0;
unsigned long TREBL_II_to_P = 0;
byte II_to_P_monitor = 0;

#define I_to_P 6
unsigned long BAS_I_to_P = 0;
unsigned long TREBL_I_to_P = 0;
byte I_to_P_monitor = 0;

#define super_P 5
unsigned long BAS_super_P = 0;
unsigned long TREBL_super_P = 0;
byte super_P_monitor = 0;

#define sub_I 4
unsigned long BAS_sub_I = 0;
unsigned long TREBL_sub_I = 0;
byte sub_I_monitor = 0;

 
//Create an instance of the library with default name, serial port and settings
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  pinMode (LED, OUTPUT); // Set Arduino board pin 13 to output
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);

  pinMode (sub_II_to_I, INPUT_PULLUP); // set board pin ... to intput
  pinMode (super_II_to_I, INPUT_PULLUP);
  pinMode (II_to_I, INPUT_PULLUP);
  pinMode (super_I, INPUT_PULLUP);
  pinMode (super_II, INPUT_PULLUP);
  pinMode (II_to_P, INPUT_PULLUP);
  pinMode (I_to_P, INPUT_PULLUP);
  pinMode (super_P, INPUT_PULLUP);
  pinMode (sub_I, INPUT_PULLUP);
  
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
  // to respond to notes on channel 2 only.
 // MIDI.turnThruOff();
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
   if (pitch == 60) {
    digitalWrite(LED,HIGH);  //Turn LED on for note c1
   }
    if (channel == 1) {
      digitalWrite(LED2,HIGH); //Turn LED2 on for all note channel 1
    }
// ustawianie flag kanałowych    
  if (channel == 1) { //ustawianie flag dla kanału 1
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_channel_1, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_channel_1, pitch - 69);
    }
  }  
  if (channel == 2) { //ustawianie flag dla kanału 2
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_channel_2, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_channel_2, pitch - 69);
    }
  }  
  if (channel == 3) { //ustawianie flag dla kanału 3
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_channel_3, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_channel_3, pitch - 69);
     }
  }      
// obsługa połączeń dla midi_on
// onsługa sub_I
  if (digitalRead(sub_I) == LOW && channel == 1) {
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_sub_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_sub_I, pitch - 69);
    }
    pitch = pitch - 12;
    MIDI.sendNoteOn (pitch, velocity, channel);
    pitch = pitch + 12;
  }
    
  if (digitalRead(super_I) == LOW && channel == 1) {
       digitalWrite(LED3,HIGH); // Turn LED3 on for control superoctawe
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_super_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_super_I, pitch - 69);
    }
     pitch = pitch + 12;
     MIDI.sendNoteOn (pitch, velocity, channel);
     pitch = pitch - 12;
  }

  if (digitalRead(super_II) == LOW && channel == 2) {
       digitalWrite(LED3,HIGH); // //Turn LED3 on for control superoctawe
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_super_II, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_super_II, pitch - 69);
    }
     pitch = pitch + 12;
     MIDI.sendNoteOn (pitch, velocity, channel);
     pitch = pitch - 12;
  }
  
  if (digitalRead(II_to_I) == LOW && channel == 1) {
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel - 1;
  }

  if (digitalRead(super_II_to_I) == LOW && channel == 1){
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_super_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_super_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    pitch = pitch + 12;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel - 1;
    pitch = pitch - 12;
  }

   if (digitalRead(sub_II_to_I) == LOW && channel == 1) {
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_sub_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_sub_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    pitch = pitch - 12;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel - 1;
    pitch = pitch + 12;
  }

    if (digitalRead(II_to_P) == LOW && channel == 3) {
     
    channel = channel - 1;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel + 1;
  }

  if (digitalRead(I_to_P) == LOW && channel == 3) {
    if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_I_to_P, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_I_to_P, pitch - 69);
    }
    channel = channel - 2;
    MIDI.sendNoteOn (pitch, velocity, channel);
    channel = channel + 2;
  }

  
    if (digitalRead(super_P) == LOW && channel == 3) {
     if (pitch >= 36 && pitch <= 68){
      bitSet(BAS_super_P, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitSet(TREBL_super_P, pitch - 69);
    }
    pitch = pitch + 12;
    MIDI.sendNoteOn (pitch, velocity, channel);
    pitch = pitch - 12;
  }

}

 
// MyHandleNoteOFF is the function that will be called by the Midi Library
// when a MIDI NOTE OFF message is received.
// * A NOTE ON message with Velocity = 0 will be treated as a NOTE OFF message *
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) {
 
    digitalWrite(LED,LOW);  //Turn LED off
    digitalWrite(LED2,LOW);  //Turn LED2 off 
    digitalWrite(LED3,LOW);  //Turn LED3 off
    
// **********Obsługa OFF sub_I
    if (digitalRead(sub_I) == LOW && channel == 1) {
       sub_I_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){ // gaszenie flag Bas
      bitClear(BAS_sub_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){ // gaszenie flag Trebll
      bitClear(TREBL_sub_I, pitch - 69);
    }

    pitch = pitch - 12;
      if (pitch >= 36 && pitch <= 68){
      if (bitRead(BAS_channel_1, pitch -36) == LOW)  MIDI.sendNoteOff (pitch, velocity, channel);
      }
      if (pitch >= 69 && pitch <= 101){ 
      if (bitRead(TREBL_channel_1, pitch -69) == LOW) MIDI.sendNoteOff (pitch, velocity, channel);
      }
      if (pitch < 36 && pitch > 101) MIDI.sendNoteOff (pitch, velocity, channel);
      pitch = pitch + 12;
      
   } 
   
// *** Jesli sub_I rozłączony przed puszczeniem klawiszy   

   if (digitalRead(sub_I) == HIGH && channel == 1 &&  sub_I_monitor == 1){ 
    
    int storage_pitch = pitch;
    sub_I_monitor = 0;
    if  (BAS_sub_I != 0){ 
      // tu procedura odczytu bitów i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_sub_I, i - 36) == HIGH){
          pitch =  i - 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     BAS_sub_I = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_sub_I != 0){
      // tu procedura odczytu bitów i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_sub_I, i - 69) == HIGH){
           
          pitch = i  - 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     TREBL_sub_I = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch; 
   }  
 
  
 
// **********Obsługa OFF super_I
  
  if (digitalRead(super_I) == LOW && channel == 1) {
    super_I_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_super_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_super_I, pitch - 69);
    }
    pitch = pitch + 12;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch - 12;
   } 


// *** Jesli super_I rozłączony przed puszczeniem klawiszy  
   
   if (digitalRead(super_I) == HIGH && channel == 1 &&  super_I_monitor == 1){ 
    
    int storage_pitch = pitch;
    super_I_monitor = 0;
    if  (BAS_super_I != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_super_I, i - 36) == HIGH){
          pitch =  i + 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     BAS_super_I = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_super_I != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_super_I, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i  + 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     TREBL_super_I = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch; 
   }
 
// **********Obsługa OFF super_II

if (digitalRead(super_II) == LOW && channel == 2) {
    super_II_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_super_II, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_super_II, pitch - 69);
    }
    pitch = pitch + 12;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch - 12;
   } 

// *** Jesli super_II rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(super_II) == HIGH && channel == 2 &&  super_II_monitor == 1){ 
    
    int storage_pitch = pitch;
    super_II_monitor = 0;
    if  (BAS_super_II != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_super_II, i - 36) == HIGH){
          pitch =  i + 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     BAS_super_II = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_super_II != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_super_II, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i  + 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     TREBL_super_II = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch; 
   }
   

// **********Obsługa OFF II_to_I
    

if (digitalRead(II_to_I) == LOW && channel == 1) {
    II_to_I_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel - 1;
   } 

// *** Jesli II_to_I rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(II_to_I) == HIGH && channel == 1 &&  II_to_I_monitor == 1){ 
    
    int storage_pitch = pitch;
    II_to_I_monitor = 0;
    if  (BAS_II_to_I != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_II_to_I, i - 36) == HIGH){
          pitch =  i;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
           channel = channel - 1;
        }
      }
     BAS_II_to_I = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_II_to_I != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_II_to_I, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
           channel = channel - 1;
        }
      }
     TREBL_II_to_I = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch;
    channel = 1; 
   }

        
    
// **********Obsługa OFF super_II_to_I

if (digitalRead(super_II_to_I) == LOW && channel == 1) {
    super_II_to_I_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_super_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_super_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    pitch = pitch + 12;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel - 1;
    pitch = pitch - 12;
   } 

// *** Jesli super_II_to_I rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(super_II_to_I) == HIGH && channel == 1 &&  super_II_to_I_monitor == 1){ 
    
    int storage_pitch = pitch;
    super_II_to_I_monitor = 0;
    if  (BAS_super_II_to_I != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_super_II_to_I, i - 36) == HIGH){
          pitch =  i + 12;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
           pitch =  i - 12;
          channel = channel - 1;
        }
      }
     BAS_super_II_to_I = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_super_II_to_I != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_super_II_to_I, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i + 12;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
            pitch = i - 12;
          channel = channel - 1;
        }
      }
     TREBL_super_II_to_I = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch;
    channel = 1; 
   }

  
// **********Obsługa OFF sub_II_to_I

    if (digitalRead(sub_II_to_I) == LOW && channel == 1) {
    sub_II_to_I_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_sub_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_sub_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    pitch = pitch - 12;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel  - 1;
    pitch = pitch + 12;
   } 

// *** Jesli sub_II_to_I rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(sub_II_to_I) == HIGH && channel == 1 &&  sub_II_to_I_monitor == 1){ 
    
    int storage_pitch = pitch;
    sub_II_to_I_monitor = 0;
    if  (BAS_sub_II_to_I != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_sub_II_to_I, i - 36) == HIGH){
          pitch =  i - 12;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
           pitch =  i + 12;
          channel = channel - 1;
        }
      }
     BAS_sub_II_to_I = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_sub_II_to_I != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_sub_II_to_I, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i - 12;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
            pitch = i + 12;
          channel = channel - 1;
        }
      }
     TREBL_sub_II_to_I = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch;
    channel = 1; 
   }

// **********Obsługa OFF II_to_P
   
if (digitalRead(II_to_P) == LOW && channel == 3) {
    II_to_P_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_II_to_P, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_II_to_P, pitch - 69);
    }
    channel = channel - 1;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel + 1;
   } 


// *** Jesli II_to_P rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(II_to_P) == HIGH && channel == 3 &&  II_to_P_monitor == 1){ 
    
    int storage_pitch = pitch;
    II_to_P_monitor = 0;
    if  (BAS_II_to_P != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_II_to_P, i - 36) == HIGH){
          pitch =  i;
          channel = channel -1;
           MIDI.sendNoteOff (pitch, velocity, channel);
          channel = channel +1; 
        }
      }
     BAS_II_to_P = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_II_to_P != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_II_to_P, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i;
          channel = channel -1;
           MIDI.sendNoteOff (pitch, velocity, channel);
          channel = channel +1; 
        }
      }
     TREBL_II_to_P = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch;
    channel = 3; 
   }

        
    
// **********Obsługa OFF super_II_to_I

if (digitalRead(super_II_to_I) == LOW && channel == 1) {
    super_II_to_I_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_super_II_to_I, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_super_II_to_I, pitch - 69);
    }
    channel = channel + 1;
    pitch = pitch + 12;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel - 1;
    pitch = pitch - 12;
   } 
// *** Jesli super_II_to_I rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(super_II_to_I) == HIGH && channel == 1 &&  super_II_to_I_monitor == 1){ 
    
    int storage_pitch = pitch;
    super_II_to_I_monitor = 0;
    if  (BAS_super_II_to_I != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_super_II_to_I, i - 36) == HIGH){
          pitch =  i +12;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
            pitch =  i -12;
          channel = channel - 1;
        }
      }
     BAS_super_II_to_I = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_super_II_to_I != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_super_II_to_I, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch =  i +12;
          channel = channel + 1;
           MIDI.sendNoteOff (pitch, velocity, channel);
            pitch =  i -12;
          channel = channel - 1;
        }
      }
     TREBL_super_II_to_I = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch;
    channel = 1; 
   }
    
   

    
// **********Obsługa OFF I_to_P 

if (digitalRead(I_to_P) == LOW && channel == 3) {
    I_to_P_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_I_to_P, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_I_to_P, pitch - 69);
    }
    channel = channel - 2;
    MIDI.sendNoteOff (pitch, velocity, channel);
    channel = channel + 2;
   } 

// *** Jesli I_to_P rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(I_to_P) == HIGH && channel == 3 &&  I_to_P_monitor == 1){ 
    
    int storage_pitch = pitch;
    I_to_P_monitor = 0;
    if  (BAS_I_to_P != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_I_to_P, i - 36) == HIGH){
          pitch =  i;
          channel = 3;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     BAS_I_to_P = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_I_to_P != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_I_to_P, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i;
          channel = 3;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     TREBL_I_to_P = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch;
    channel = 3; 
   }
    

// **********Obsługa OFF super_P   

if (digitalRead(super_P) == LOW && channel == 3) {
    super_P_monitor = 1;
    
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_super_P, pitch -36);
    }
    
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_super_P, pitch - 69);
    }
    pitch = pitch + 12;
    MIDI.sendNoteOff (pitch, velocity, channel);
    pitch = pitch - 12;
   } 

// *** Jesli super_II rozłączony przed puszczeniem klawiszy   
  
   if (digitalRead(super_P) == HIGH && channel == 3 &&  super_P_monitor == 1){ 
    
    int storage_pitch = pitch;
    super_P_monitor = 0;
    if  (BAS_super_P != 0){ 
      // tu procedura odczytu bitów strony basowej i odpowiednie wysłanie komunikaru note off
      for (int i = 36; i <= 68; i++){
        if (bitRead(BAS_super_P, i - 36) == HIGH){
          pitch =  i + 12;
           MIDI.sendNoteOff (pitch, velocity, channel);  
        }
      }
     BAS_super_P = 0; //Wyzerowanie flag dla strony basowej
    }
     if  (TREBL_super_P != 0){
      // tu procedura odczytu bitów strony dyszkantowej i odpowiednie wysłanie komunikaru note off   
      for (int i = 69; i <= 101; i++){
        if (bitRead(TREBL_super_P, i - 69) == HIGH){
          digitalWrite(LED,HIGH); 
          pitch = i  + 12;
           MIDI.sendNoteOff (pitch, velocity, channel);
        }
      }
     TREBL_super_P = 0; //Wyzerowanie flag dla strony dyszkantowej
    }
    
    pitch = storage_pitch; 
   }
   
// gaszenie flag kanalowych

    // for channel 1
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_channel_1, pitch -36);
    }
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_channel_1, pitch - 69);
    }

    // for channel 2
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_channel_2, pitch -36);
    }
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_channel_2, pitch - 69);
    }

    // for channel 3
    if (pitch >= 36 && pitch <= 68){
      bitClear(BAS_channel_3, pitch -36);
    }
     if (pitch >= 69 && pitch <= 101){
      bitClear(TREBL_channel_3, pitch - 69);
    }
}   


      
   
   
