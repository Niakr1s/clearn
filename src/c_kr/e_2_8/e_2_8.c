#include <string.h>

#include "e_2_8.h"

unsigned rightrot(unsigned x, int n)
{
    int bits = 0; // number of bits in x
    for (unsigned xx = x; xx != 0; bits++)
        xx >>= 1;

    if (bits != 0)
        n %= bits;

    unsigned mask = ~(~0 << n); // 0000000011
    unsigned right = (x & mask) << (bits - n);
    
    return (x >> n) | right;
}