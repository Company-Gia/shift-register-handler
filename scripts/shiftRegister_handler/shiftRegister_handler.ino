#include "utils.h"
#include "class_ByteOfChar.h"

#define DATA  11    /* 74HC595 pin: ds   */
#define LATCH 12    /* 74HC595 pin: STCP */
#define CLOCK 13    /* 74HC595 pin: SHCP */

void setup(){
  Serial.begin(9600);  
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop(){

}

void writeRegister(unsigned int value) {
  digitalWrite(Latch, LOW);                     // Si abilita la scrittura sugli shift register
  shiftOut(Data, Clock, MSBFIRST, value >> 8);
  shiftOut(Data, Clock, MSBFIRST, value);
  digitalWrite(Latch, HIGH);                    // Si disabilita la scrittura sugli shift register
}