/**
 * for ATmega1284p or Arduino mega
 * @brief   This example demonstrates the use of push buttons that send note 
 *          events.
 * 
 * ### Connections
 * 
 *  - 2:  momentary push button (to ground)
 *  - 3:  momentary push button (to ground)
 * 
 * The internal pull-up resistors for the buttons will be enabled automatically.
 * 
 * ### Behavior
 * 
 * Pressing the first button will send note on/off events on middle C.
 * Pressing the second button will send note on/off events for middle C sharp.
 * 
 * Written by PieterP, 28-01-2019  
 * https://github.com/tttapa/Control-Surface
 */

// Include the Control Surface library
#include <Control_Surface.h>

// Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midi;

MIDI_PipeFactory<1> pipes;

using namespace MIDI_Notes;

// Instantiate the momentary push buttons that send out MIDI Note events.
NoteButton buttons[] = {
    //{2, note(C, 4)}, // digital input pin, note number
    //{3, note(Db, 4)},
    
    // If you want to set the channel specifically, you can use:
    // for UNO , nano , mega // czwarta taśma 10 tonów
  /*  {2, {note(C, 6), CHANNEL_2}},
    {3, {note(Db, 6), CHANNEL_2}},
    {4, {note(D, 6), CHANNEL_2}},
    {5, {note(Eb, 6), CHANNEL_2}},
    {6, {note(E, 6), CHANNEL_2}},
    {7, {note(F_, 6), CHANNEL_2}},
    {8, {note(Gb, 6), CHANNEL_2}},
    {9, {note(G, 6), CHANNEL_2}},
    {10, {note(Ab, 6), CHANNEL_2}},
    {11, {note(A, 6), CHANNEL_2}},
   
   // {12, {note(Bb, 2), CHANNEL_2}},
   // {13, {note(B, 2), CHANNEL_2}},
    //{13, {note(C, 3), CHANNEL_2}},
    //{14, {note(Db, 3), CHANNEL_2}},
   // {15, {note(D, 3), CHANNEL_2}},
    //{16, {note(Eb, 3), CHANNEL_2}},
   // {17, {note(E, 3), CHANNEL_2}},
  //  {18, {note(F, 3), CHANNEL_2}},
   // {19, {note(Gb, 3), CHANNEL_2}},
   //// {20, {note(G, 3), CHANNEL_2}},
   // {21, {note(Ab, 3), CHANNEL_2}},
   // {22, {note(A, 3), CHANNEL_2}},
  //  {23, {note(Bb, 3), CHANNEL_2}},
  //  {A0, {note(B, 3), CHANNEL_2}},  
  // {A0, {note(Ab, 4), CHANNEL_2}},
    {A1, {note(A, 4), CHANNEL_2}},
    {A2, {note(Bb, 4), CHANNEL_2}},
    {A3, {note(B, 4), CHANNEL_2}},
    {A4, {note(C, 5), CHANNEL_2}},
    {A5, {note(Db, 5), CHANNEL_2}},
    {A6, {note(D, 5), CHANNEL_2}},
    {A7, {note(Eb, 5), CHANNEL_2}},
    {A8, {note(E, 5), CHANNEL_2}},
    {A9, {note(F_, 5), CHANNEL_2}},
    {A10, {note(Gb, 5), CHANNEL_2}},
    {A11, {note(G, 5), CHANNEL_2}},
    {A12, {note(Ab, 5), CHANNEL_2}},
    {A13, {note(A, 5), CHANNEL_2}},
    {A14, {note(Bb, 5), CHANNEL_2}},
    {A15, {note(B, 5), CHANNEL_2}},
    */
                                    
    

                                    // pierwsza taśma 3 albo 32 tonów
    {A1, {note(C, 2), CHANNEL_4}},
    {A0, {note(Db, 2), CHANNEL_4}},
    {A3, {note(D, 2), CHANNEL_4}},
    {A2, {note(Eb, 2), CHANNEL_4}},
    {A5, {note(E, 2), CHANNEL_4}},
    {A4, {note(F_, 2), CHANNEL_4}},
    {A7, {note(Gb, 2), CHANNEL_4}},
    {A6, {note(G, 2), CHANNEL_4}},
    {A9, {note(Ab, 2), CHANNEL_4}},
    {A8, {note(A, 2), CHANNEL_4}},
    {A11, {note(Bb, 2), CHANNEL_4}},
    {A10, {note(B, 2), CHANNEL_4}},
    {A13, {note(C, 3), CHANNEL_4}},
    {A12, {note(Db, 3), CHANNEL_4}},
    {A15, {note(D, 3), CHANNEL_4}},
    {A14, {note(Eb, 3), CHANNEL_4}},
    {33, {note(E, 3), CHANNEL_4}},
    {32, {note(F_, 3), CHANNEL_4}},
    {35, {note(Gb, 3), CHANNEL_4}},
    {34, {note(G, 3), CHANNEL_4}},
    {37, {note(Ab, 3), CHANNEL_4}},
    {36, {note(A, 3), CHANNEL_4}},
    {39, {note(Bb, 3), CHANNEL_4}},
    {38, {note(B, 3), CHANNEL_4}},
    {41, {note(C, 4), CHANNEL_4}},
    {40, {note(Db, 4), CHANNEL_4}},
    {43, {note(D, 4), CHANNEL_4}},
    {42, {note(Eb, 4), CHANNEL_4}},
    {45, {note(E, 4), CHANNEL_4}},
    {44, {note(F_, 4), CHANNEL_4}},
    {47, {note(Gb, 4), CHANNEL_4}},
    {46, {note(G, 4), CHANNEL_4}},

    
    
};

void setup() {
    // Initialize everything
    Control_Surface.begin();
    midiser >> pipes >> midiser; //all incoming midi from Serial is looped back
     midiser.begin();

    // for (auto &b : buttons) //pętla dla ptzycisków normalnie zwartych
   //  b.invert();

   delay(2000); // czeka na inicjacje odbiorników
}

void loop() {
    // Update the control surface
    Control_Surface.loop();
    midiser.update();
}
