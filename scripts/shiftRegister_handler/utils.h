#ifndef utils
#define utils

int addNewBit(int SR_status, int newBit_pos) {
    int newBit = 1;
    for (int i = 0; i < newBit_pos; i++)
        newBit = newBit << 1;
    return SR_status | newBit;
}

#endif utils