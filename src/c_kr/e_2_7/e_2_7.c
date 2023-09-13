#include <string.h>

#include "e_2_7.h"

unsigned invert(unsigned x, int p, int n)
{
    int bits = 0; // number of bits in x
    unsigned xx;
    for (xx = x; xx != 0; bits++)
        xx >>= 1;

    unsigned mask = ~(~0 << n) << (bits - p - n); // 00001110000

    unsigned inner = x & mask;
    unsigned outer = x & ~mask;

    return (~inner & mask) | outer;
}