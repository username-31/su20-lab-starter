#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg)
{
    /* YOUR CODE HERE */
    int bit0 = *reg & 1;
    int bit2 = (*reg >> 2) & 1;
    int bit3 = (*reg >> 3) & 1;
    int bit5 = (*reg >> 5) & 1;
    int bit15 = ((bit0 ^ bit2) ^ bit3) ^ bit5;
    *reg = *reg >> 1;
    // Set the new bit15
    int mask = *reg & (1 << 15);
    *reg = (*reg ^ mask) | (bit15 << 15);
}
