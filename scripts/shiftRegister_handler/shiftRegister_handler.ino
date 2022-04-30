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
  int SR_status = 0;
  SR_status = addNewBit(SR_status, 0);
  SR_status = addNewBit(SR_status, 12);
  writeRegister(SR_status);

  //ByteOfChar tmp = ByteOfChar('0','1','1','1','1','1','1','0');
  //ByteOfChar tmp = ByteOfChar('0','1','1','1','1','1','1','1');

}


void writeRegister(unsigned int value){
//byte register_1 = 11000000;   /* x_7..x_0 */
//byte register_2 = 11100000;   /* y_7..y_0 */
  /*
   *        Register 2   Register 1
   * byte:  0000  0000   0000  0000
   * pos:   y_7....y_0   x_7....x_0
   * 
   * MSBFIRST -> La macchina legge (da SX verso DX): y_7..y_0x_7..x_0
   * LSBFIRST -> La macchina legge (da SX verso DX): x_0..x_7y_0..y_7
  */
  digitalWrite(Latch, LOW);                     // Si abilita la scrittura sugli shift register
  shiftOut(Data, Clock, MSBFIRST, value >> 8);
  shiftOut(Data, Clock, MSBFIRST, value);
  digitalWrite(Latch, HIGH);                    // Si disabilita la scrittura sugli shift register
}