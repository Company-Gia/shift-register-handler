#include <iostream>

using namespace std;

int change_bit_status(int SR_status, int bitPos, int set_bit_high) {
    if (set_bit_high == 0 || set_bit_high == 1) {
        int iter = 1;
        for (int i = 0; i < bitPos; i++)
            iter = iter << 1;
        if (set_bit_high == 1)
            return SR_status | iter;
        else
            return SR_status ^ iter;
    } else
        return 0;
}

int main () {

    printf("%d%c", change_bit_status(0,4,1), '\n');  /* from: ...00000000 to: ...00010000 */

    printf("%d%c", change_bit_status(3,3,1), '\n');  /* from: ...00000111 to: ...00001111 */

    printf("%d%c", change_bit_status(31,0,0), '\n');

    return 0;
}