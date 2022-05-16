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

  writeRegister(SR_status);           /* ..0111 -> SF q0, q1 and q2 are high */
  
  delay(500);  
  
  SR_status = change_bit_status(SR_status, 3, 1);   /* SR_status = 15 */ 
  
  writeRegister(SR_status);           /* ..01111 -> SF q0, q1, q2 and q3 are high */

}

void writeRegister(unsigned int value) {
  digitalWrite(LATCH, LOW);                     /* Enable writing to SF */
  shiftOut(DATA, CLOCK, MSBFIRST, value >> 8);
  shiftOut(DATA, CLOCK, MSBFIRST, value);
  digitalWrite(LATCH, HIGH);                    /* Disable writing to SF */
}
