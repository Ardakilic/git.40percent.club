/* Buttons to USB Keyboard Example - Special Media Player Keys
   You must select Keyboard from the "Tools > USB Type" menu
   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce MX01 = Bounce(4, 10);
Bounce MX02 = Bounce(5, 10);  // 10 ms debounce time is appropriate
Bounce MX03 = Bounce(6, 10);  // for most mechanical pushbuttons
Bounce MX04 = Bounce(7, 10);
Bounce MX05 = Bounce(9, 10);  // if a button is too "sensitive"
Bounce MX06 = Bounce(10, 10);  // you can increase this time.
Bounce MX07 = Bounce(21, 10);
Bounce MX08 = Bounce(20, 10);
Bounce MX09 = Bounce(19, 10);
Bounce MX10 = Bounce(18, 10);
Bounce MX11 = Bounce(16, 10);
Bounce MX12 = Bounce(15, 10);

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

  pinMode(8, OUTPUT); // The virtual Ground Pin
  digitalWrite(8, LOW);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  MX01.update();
  MX02.update();
  MX03.update();
  MX04.update();
  MX05.update();
  MX06.update();
  MX07.update();
  MX08.update();
  MX09.update();
  MX10.update();
  MX11.update();
  MX12.update();

  // Check each button for "falling" edge.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (MX01.fallingEdge()) {
    Keyboard.press(KEY_HOME);
    Keyboard.release(KEY_HOME);
  }
  if (MX02.fallingEdge()) {
    Keyboard.press(KEY_UP);
    Keyboard.release(KEY_UP);
  }
  if (MX03.fallingEdge()) {
    Keyboard.press(KEY_PAGE_UP);
    Keyboard.release(KEY_PAGE_UP);
  }
  if (MX04.fallingEdge()) {
    Keyboard.press(KEY_LEFT);
    Keyboard.release(KEY_LEFT);
  }
  if (MX05.fallingEdge()) {
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
  }
  if (MX06.fallingEdge()) {
    Keyboard.press(KEY_RIGHT);
    Keyboard.release(KEY_RIGHT);
  }
  if (MX07.fallingEdge()) {
    Keyboard.press(KEY_END);
    Keyboard.release(KEY_END);
  }
  if (MX08.fallingEdge()) {
    Keyboard.press(KEY_DOWN);
    Keyboard.release(KEY_DOWN);
  }
  if (MX09.fallingEdge()) {
    Keyboard.press(KEY_PAGE_DOWN);
    Keyboard.release(KEY_PAGE_DOWN);
  }
  if (MX10.fallingEdge()) {
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.release(KEY_BACKSPACE);
  }
  if (MX11.fallingEdge()) {
    Keyboard.press(KEY_SPACE);
    Keyboard.release(KEY_SPACE);
  }
  if (MX12.fallingEdge()) {
    Keyboard.press(KEY_ENTER);
    Keyboard.release(KEY_ENTER);
  }
}
