//Last updated by Nelson on 5/7/19

// Simple example application that shows how to read four Arduino
// digital pins and map them to the USB Joystick library.
//
// Ground digital pins 9, 10, 11, and 12 to press the joystick 
// buttons 0, 1, 2, and 3.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2015-11-20
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  
  pinMode(A0, INPUT_PULLUP);
  //pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);  

  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.

// Last state of the button
int const button_count = 15;
int lastButtonState[button_count] = {0,0,0,0};
// +4 for the 4 proxy directions

void loop() {

/*
  Original buttons:
  Joy5 Up 
  Joy12 Down
  Joy9 Right
  Joy4 Left 

  Send to:
  Joy17 Up
  Joy18 Down
  Joy19 Left
  Joy20 Right
  
 */

  
  int buttons[button_count] = {
    0, 
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    
    A0,
    
    A2,
    A3,
    A4,
    A5};
  // Read pin values
  int index = 0;
  while(index < button_count)
  {
    //Faceplate Button 13
    //Array element 12
    //Pin A0
    //Assign to Joy17
    //Set to Up
    int currentButtonState = !digitalRead(buttons[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
    index++;
  }
}
