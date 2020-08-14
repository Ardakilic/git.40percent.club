#include "Adafruit_Keypad.h"
#include <IRremote.h>

const byte ROWS = 6; // rows
const byte COLS = 5; // columns

//define weird Gherkin key layout
byte keys[ROWS][COLS] = {
  {30, 12, 23, 5, 16},
  {27, 9, 20, 2, 13},
  {24, 6, 17, 28, 10},
  {21, 3, 14, 25, 7},
  {18, 29, 11, 22, 4},
  {15, 26, 8, 19, 1}
};

// Physical Gherkin layout
//  1  2  3
//  4  5  6
//  7  8  9
// 10 11 12
// 13 14 15
// 16 17 18
// 19 20 21
// 22 23 24
// 25 26 27
// 28 29 30

byte rowPins[ROWS] = {3, 4, 5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 16, 14, 15, 18}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

IRsend irsend;

void setup() {
//  Serial.begin(9600);
  customKeypad.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();
  
  //Codes for the Visio TV
  //Power   A        Input      20DF10EF  20DF4AB5  20DFF40B
  //Home    Up       Menu       20DFB44B  20DFA25D  20DFF20D
  //Left    OK       Right      20DFE21D  20DF22DD  20DF12ED
  //Back    Down     Star       20DF52AD  20DF629D  20DFD827
  //Vol +   Mute     Channel +  20DF40BF  20DF906F  20DF00FF
  //Vol -   Previous Channel -  20DFC03F  20DF58A7  20DF807F
  //1       2        3          20DF8877  20DF48B7  20DFC837
  //4       5        6          20DF28D7  20DFA857  20DF6897
  //7       8        9          20DFE817  20DF18E7  20DF9867
  //.       0        Enter      20DFFF00  20DF08F7  20DF5CA3

  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    if ((e.bit.KEY == 1) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF10EF, 32);
    if ((e.bit.KEY == 2) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF4AB5, 32);
    if ((e.bit.KEY == 3) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFF40B, 32);
    if ((e.bit.KEY == 4) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFB44B, 32);
    if ((e.bit.KEY == 5) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFA25D, 32);
    if ((e.bit.KEY == 6) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFF20D, 32);
    if ((e.bit.KEY == 7) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFE21D, 32);
    if ((e.bit.KEY == 8) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF22DD, 32);
    if ((e.bit.KEY == 9) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF12ED, 32);
    if ((e.bit.KEY == 10) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF52AD, 32);
    if ((e.bit.KEY == 11) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF629D, 32);
    if ((e.bit.KEY == 12) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFD827, 32);
    if ((e.bit.KEY == 13) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF40BF, 32);
    if ((e.bit.KEY == 14) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF906F, 32);
    if ((e.bit.KEY == 15) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF00FF, 32);
    if ((e.bit.KEY == 16) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFC03F, 32);
    if ((e.bit.KEY == 17) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF58A7, 32);
    if ((e.bit.KEY == 18) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF807F, 32);
    if ((e.bit.KEY == 19) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF8877, 32);
    if ((e.bit.KEY == 20) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF48B7, 32);
    if ((e.bit.KEY == 21) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFC837, 32);
    if ((e.bit.KEY == 22) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF28D7, 32);
    if ((e.bit.KEY == 23) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFA857, 32);
    if ((e.bit.KEY == 24) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF6897, 32);
    if ((e.bit.KEY == 25) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFE817, 32);
    if ((e.bit.KEY == 26) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF18E7, 32);
    if ((e.bit.KEY == 27) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF9867, 32);
    if ((e.bit.KEY == 28) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DFFF00, 32);
    if ((e.bit.KEY == 29) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF08F7, 32);
    if ((e.bit.KEY == 30) && (e.bit.EVENT == KEY_JUST_PRESSED)) irsend.sendNEC(0x20DF5CA3, 32);
  }
  delay(10);
}
