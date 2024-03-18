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
    {2, {note(C, 6), CHANNEL_3}},
    {3, {note(Db, 6), CHANNEL_3}},
    {4, {note(D, 6), CHANNEL_3}},
    {5, {note(Eb, 6), CHANNEL_3}},
    {6, {note(E, 6), CHANNEL_3}},
    {7, {note(F_, 6), CHANNEL_3}},
    {8, {note(Gb, 6), CHANNEL_3}},
    {9, {note(G, 6), CHANNEL_3}},
    {10, {note(Ab, 6), CHANNEL_3}},
    {11, {note(A, 6), CHANNEL_3}},
   // {12, {note(Bb, 2), CHANNEL_3}},
   // {13, {note(B, 2), CHANNEL_3}},
    //{13, {note(C, 3), CHANNEL_3}},
    //{14, {note(Db, 3), CHANNEL_3}},
   // {15, {note(D, 3), CHANNEL_3}},
    //{16, {note(Eb, 3), CHANNEL_3}},
   // {17, {note(E, 3), CHANNEL_3}},
  //  {18, {note(F, 3), CHANNEL_3}},
   // {19, {note(Gb, 3), CHANNEL_3}},
   //// {20, {note(G, 3), CHANNEL_3}},
   // {21, {note(Ab, 3), CHANNEL_3}},
   // {22, {note(A, 3), CHANNEL_3}},
  //  {23, {note(Bb, 3), CHANNEL_3}},
  //  {A0, {note(B, 3), CHANNEL_3}},  // trzecia taśma 16 tonów
    {A0, {note(Ab, 4), CHANNEL_3}},
    {A1, {note(A, 4), CHANNEL_3}},
    {A2, {note(Bb, 4), CHANNEL_3}},
    {A3, {note(B, 4), CHANNEL_3}},
    {A4, {note(C, 5), CHANNEL_3}},
    {A5, {note(Db, 5), CHANNEL_3}},
    {A6, {note(D, 5), CHANNEL_3}},
    {A7, {note(Eb, 5), CHANNEL_3}},
    {A8, {note(E, 5), CHANNEL_3}},
    {A9, {note(F_, 5), CHANNEL_3}},
    {A10, {note(Gb, 5), CHANNEL_3}},
    {A11, {note(G, 5), CHANNEL_3}},
    {A12, {note(Ab, 5), CHANNEL_3}},
    {A13, {note(A, 5), CHANNEL_3}},
    {A14, {note(Bb, 5), CHANNEL_3}},
    {A15, {note(B, 5), CHANNEL_3}},
                                    // druga taśma 16 tonów
    {33, {note(E, 3), CHANNEL_3}},
    {32, {note(F_, 3), CHANNEL_3}},
    {35, {note(Gb, 3), CHANNEL_3}},
    {34, {note(G, 3), CHANNEL_3}},
    {37, {note(Ab, 3), CHANNEL_3}},
    {36, {note(A, 3), CHANNEL_3}},
    {39, {note(Bb, 3), CHANNEL_3}},
    {38, {note(B, 3), CHANNEL_3}},
    {41, {note(C, 4), CHANNEL_3}},
    {40, {note(Db, 4), CHANNEL_3}},
    {43, {note(D, 4), CHANNEL_3}},
    {42, {note(Eb, 4), CHANNEL_3}},
    {45, {note(E, 4), CHANNEL_3}},
    {44, {note(F_, 4), CHANNEL_3}},
    {47, {note(Gb, 4), CHANNEL_3}},
    {46, {note(G, 4), CHANNEL_3}},

    

                                    // pierwsza taśma 16 tonów
    {17, {note(C, 2), CHANNEL_3}},
    {16, {note(Db, 2), CHANNEL_3}},
    {19, {note(D, 2), CHANNEL_3}},
    {18, {note(Eb, 2), CHANNEL_3}},
    {21, {note(E, 2), CHANNEL_3}},
    {20, {note(F_, 2), CHANNEL_3}},
    {23, {note(Gb, 2), CHANNEL_3}},
    {22, {note(G, 2), CHANNEL_3}},
    {25, {note(Ab, 2), CHANNEL_3}},
    {24, {note(A, 2), CHANNEL_3}},
    {27, {note(Bb, 2), CHANNEL_3}},
    {26, {note(B, 2), CHANNEL_3}},
    {29, {note(C, 3), CHANNEL_3}},
    {28, {note(Db, 3), CHANNEL_3}},
    {31, {note(D, 3), CHANNEL_3}},
    {30, {note(Eb, 3), CHANNEL_3}},
    
    
};

void setup() {
    // Initialize everything
    Control_Surface.begin();
    midiser >> pipes >> midiser; //all incoming midi from Serial is looped back
     midiser.begin();

    // for (auto &b : buttons) //pętla dla ptzycisków normalnie zwartych
   //  b.invert();
}

void loop() {
    // Update the control surface
    Control_Surface.loop();
    midiser.update();
}
