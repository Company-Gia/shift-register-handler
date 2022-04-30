/**
 * @file class_ByteOfChar.h
 * @author sapore_di_Marte_63
 * @brief A handler (for newbie) for n shif-registers connected in cascade.
 * This handler use an obejct data (ByteOfChar) that is essential an array of char with useful 
 * methods to manipulate it easiest as possible.
 * Ideally, the array of char rappresent a byte, so the elements should be '0' or '1'.
 * The use of this class should be the easiest way to manage shift registers.
 * @version 0.1
 * @date 2022-04-26
 */

#ifndef class_ByteOfChar
#define class_ByteOfChar

#define BYTE_SIZE 8

class ByteOfChar {
  /**
    * Functions return true if there're no errors.
    * Functions return false if an error occurred.
    */
  private:

    char byteArray[BYTE_SIZE];    /* A byte (of char) written FROM RIGHT to LEFT -> MSB-?-?-?-?-?-?-LSB = byteArray[7]-?-?-?-?-?-?-byteArray[0] */
    unsigned int n;

    bool check_pos (int pos);

    bool check_value (char value);

    int myPow (int base, int exponent);

    int evaluate ();

  protected:

  public:
    ByteOfChar ();

    ByteOfChar (char bit8, char bit7, char bit6, char bit5, char bit4, char bit3, char bit2, char bit1, char bit0);

    unsigned int get_n ();

    bool set_value (int pos, char value);

    bool negate_value (int pos);

};

/* Private methods */
bool ByteOfChar::check_pos (int pos) {
  if (pos <= BYTE_SIZE && pos >= 0)
    return true;
  else
    return false;
}

bool ByteOfChar::check_value (char value) {
  if (value == '0' || value == '1')
    return true;
  else
    return false;
}

int ByteOfChar::myPow (int base, int exponent) {
  int res = 1;
  while (exponent > 0) {
    res *= base;
    exponent--;
  }
  return res;
}

int ByteOfChar::evaluate () {
  /**
    * PSEUDOCODE:
    * int evaluate
    *   pos = 7, upL = lowL = 0           // Algoritm can be generalaized to n bits by setting pos = n
    *   *from MSB to LSB*
    *   while byte[pos] != 1 && pos >= 0
    *     pos--
    *   if pos < 0    // case: 00000000
    *     return 0
    *   else
    *     upL = 2^(pos+1) - 1
    *     lowL = 2^pos
    *     pos--
    *   while pos >= 0
    *     if byte[pos] == 0
    *       upL -= 2^pos
    *     else
    *       lowL += 2^pos
    *     pos--
    *   if upL == lowL
    *     return upL
    *   else
    *     return ERR
    * end
  */

  int pos = BYTE_SIZE, upperLimit = 0, lowerLimit = 0;

  while (this->byteArray[pos] != '1' && pos >= 0)           /* Scroll the byte (from MSB to LSB) yo the first bit == 1 */
    pos--;
  if (pos < 0)                                              /* case: byte := 00000000 */
    return 0;

  upperLimit = myPow (2, pos + 1) - 1;
  lowerLimit = myPow (2, pos);
  pos--;

  while (pos >= 0) {
    //Serial.println("pos=" + pos );
    //Serial.println("up=" + upperLimit);
    //Serial.println("lw=" + lowerLimit);
    //Serial.println("bitPos=" + this->byteArray[pos]);
    if (this->byteArray[pos] == '0')
      upperLimit -= myPow (2,pos);
    else
      lowerLimit += myPow (2,pos);
    pos--;
  }
  if (upperLimit == lowerLimit)
    return upperLimit;
  else
    return 0;
}

/* Protected methods */


/* Public methods */
ByteOfChar::ByteOfChar () {
  for (int pos = 0; pos < 8; pos++)
    this->byteArray[pos] = '0';
  this->n = 0;
}

ByteOfChar::ByteOfChar (char bit8, char bit7, char bit6, char bit5, char bit4, char bit3, char bit2, char bit1, char bit0) {
  if (check_value(bit0) && check_value(bit1) && check_value(bit2) && check_value(bit3) &&
      check_value(bit4) && check_value(bit5) && check_value(bit6) && check_value(bit7) &&
      check_value(bit8)) {
    this->byteArray[0] = bit0;
    this->byteArray[1] = bit1;
    this->byteArray[2] = bit2;
    this->byteArray[3] = bit3;
    this->byteArray[4] = bit4;
    this->byteArray[5] = bit5;
    this->byteArray[6] = bit6;
    this->byteArray[7] = bit7;
    this->byteArray[8] = bit8;
    this->n = evaluate();
  } else
    ByteOfChar();
}

unsigned int ByteOfChar::get_n () { return this->n; }

bool ByteOfChar::set_value (int pos, char value) {
  if (check_pos(pos) && check_value(value)) {
    this->byteArray[pos] = value;
    this->n = evaluate();
    return true;
  } else
    return false;
}

bool ByteOfChar::negate_value (int pos) {
  if (check_pos(pos)) {
    if (this->byteArray[pos] == '0')
      this->byteArray[pos] = '1';
    else if (this->byteArray[pos] == '1')
      this->byteArray[pos] = '0';
    else
      return false;
    this->n = evaluate();
    return true;
  } else
    return false;
}

#endif