#include <iostream>

using namespace std;

class ByteOfChar {
  /**
    * Functions return true if there're no errors.
    * Functions return false if an error occurred.
    */
  private:

    char byteArray[7];    /* A byte (of char) written FROM RIGHT to LEFT -> MSB-?-?-?-?-?-?-LSB = byteArray[7]-?-?-?-?-?-?-byteArray[0] */
    unsigned int n;

    bool check_pos (int pos) {
      if (pos <= 7 && pos >= 0)
        return true;
      else
        return false;
    }

    bool check_value (char value) {
      if (value == '0' || value == '1')
        return true;
      else
        return false;
    }

    int pow (int base, int exponent) {
      int res = 1;
      while (exponent > 0) {
        res *= base;
        exponent--;
      }
      return res;
    }

    int evaluate () {
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

      int pos = 7, upperLimit = 0, lowerLimit = 0;

      while (this->byteArray[pos] != '1' && pos >= 0)           /* Scroll the byte (from MSB to LSB) yo the first bit == 1 */
        pos--;
      if (pos < 0)                                              /* case: byte := 00000000 */
        return 0;

      upperLimit = pow (2, pos + 1) - 1;
      lowerLimit = pow (2, pos);
      pos--;

      while (pos >= 0) {
        //cout << endl << "pos=" << pos << " ; up="<< upperLimit << " ; lw=" << lowerLimit << " ; bitPos=" << this->byteArray[pos];
        if (this->byteArray[pos] == '0')
          upperLimit -= pow (2,pos);
        else 
          lowerLimit += pow (2,pos);
        pos--;
      }
      if (upperLimit == lowerLimit)
        return upperLimit;
      else
        return 0;
    }

  protected:
  
  public:
    ByteOfChar () {
      for (int pos = 0; pos < 8; pos++)
        this->byteArray[pos] = '0';
      this->n = 0;
    }

    ByteOfChar (char bit7, char bit6, char bit5, char bit4, char bit3, char bit2, char bit1, char bit0) {
      if (check_value(bit0) && check_value(bit1) && check_value(bit2) && check_value(bit3) && 
          check_value(bit4) && check_value(bit5) && check_value(bit6) && check_value(bit7)) {
        this->byteArray[0] = bit0;
        this->byteArray[1] = bit1;
        this->byteArray[2] = bit2;
        this->byteArray[3] = bit3;
        this->byteArray[4] = bit4;
        this->byteArray[5] = bit5;
        this->byteArray[6] = bit6;
        this->byteArray[7] = bit7;
        this->n = evaluate();
      } else
        ByteOfChar(); 
    }

    unsigned int get_n () { return this->n; }

    bool set_value (int pos, char value) {
      if (check_pos(pos) && check_value(value)) {
        this->byteArray[pos] = value;
        this->n = evaluate();
        return true;
      } else
        return false;
    }

    bool negate_value (int pos) {
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
};

int main () {

  ByteOfChar tmp;
  tmp = ByteOfChar('0','1','1','1','1','1','1','1');  // 127
  cout << tmp.get_n() << endl;

  tmp = ByteOfChar('0','1','1','1','1','1','1','0');  // 126
  cout << tmp.get_n() << endl;

  tmp = ByteOfChar('0','1','0','0','1','0','1','1');  // 75
  cout << tmp.get_n() << endl;


  return 0;
}