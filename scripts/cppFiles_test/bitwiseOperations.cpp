#include <iostream>

using namespace std;

int addNewBit(int newBit_pos, int SR_status) {
    int newBit = 1;
    newBit_pos--;                           /* decrements cuz newBis is already := ...0001 */
    for (int i = 0; i < newBit_pos; i++)
        newBit = newBit << 1;
    return SR_status | newBit;
}

int main () {

    printf("%c%d%c", '\n', addNewBit(5,15), '\n');  /* print: 31 -> ..00011111*/

    return 0;
}