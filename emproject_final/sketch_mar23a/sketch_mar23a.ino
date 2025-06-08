#include <ShiftRegister74HC595.h>

// create a global shift register object
// parameters: (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (2, 11, 12, 8);

void setup() {
  
}

void loop() {

  // setting all pins at the same time to either HIGH or LOW
  sr.setAllHigh(); // set all pins HIGH
  delay(500);

  sr.setAllLow(); // set all pins LOW
  delay(500);


  // setting single pins
  for (int i = 0; i < 16; i++) {

    sr.set(i, HIGH); // set single pin HIGH
    delay(250);
  }


  // set all pins at once
  uint8_t pinValues[] = { B10101010, B10101010 };
  sr.setAll(pinValues);
  delay(1000);


  // read pin (zero based, i.e. 6th pin)
  uint8_t stateOfPin5 = sr.get(5);


  // set pins without immediate update
  sr.setNoUpdate(0, HIGH);
  sr.setNoUpdate(1, LOW);
  // at this point of time, pin 0 and 1 did not change yet
  sr.updateRegisters(); // update the pins to the set values
}