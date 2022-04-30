#ifndef utils
#define utils

/**
 * @brief 
 * 
 * @param SR_status 
 * @param bitPos REMEMBER THAT THE change_bit_status BIT COUNTER (OF THE BYTE) START FROM 0 
 * @param set_bit_high 
 * @return int 
 */
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

#endif utils