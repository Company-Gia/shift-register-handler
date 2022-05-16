#ifndef utils
#define utils

/**
 * @brief Given a SR_status, change the value of the (bitPos=)n-th bit to 0 if set_bit_high == 0,
 * 1 otherwise. After that return the updated SR_status.
 * 
 * @param SR_status The (4 byte) integer that rapresent the status of the SR-chain.
 * @param bitPos Position of the bit to change the state of.
 * REMEMBER THAT THE change_bit_status's BIT COUNTER (OF THE BYTE) STARTS COUNTING FROM 0 
 * @param set_bit_high if (set_bit_high == 1) then: SR_status[bitPos] = 1; else: SR_status[bitPos] = 0
 * @return int 
 */

int change_bit_status(int SR_status, int bitPos, int set_bit_high) {
    if (set_bit_high == 0 || set_bit_high == 1) {
        int iter = 1;                               /* iter := ..0001 */
        for (int i = 0; i < bitPos; i++)            /* The only High bit is moved to bitPos position */
            iter = iter << 1;                           /* (Obviously) shift to the left because the LSB is on the left */
        if (set_bit_high == 1)
            return SR_status | iter;
        else
            return SR_status ^ iter;
    } else
        return 0;
}

#endif utils