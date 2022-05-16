#include "utils.h"
#include "class_ByteOfChar.h"

#define DATA  11    /* 74HC595 pin: ds   */
#define LATCH 12    /* 74HC595 pin: STCP */
#define CLOCK 13    /* 74HC595 pin: SHCP */

void setup() {
  Serial.begin(9600);  
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop() {

  int SR_status = 7;
  
  SR_status = change_bit_status(SR_status, 3, 1);
  
  writeRegister(SR_status);
  
}

void writeRegister(unsigned int value) {
  digitalWrite(LATCH, LOW);                     // Si abilita la scrittura sugli shift register
  shiftOut(DATA, CLOCK, MSBFIRST, value >> 8);
  shiftOut(DATA, CLOCK, MSBFIRST, value);
  digitalWrite(LATCH, HIGH);                    // Si disabilita la scrittura sugli shift register
}
