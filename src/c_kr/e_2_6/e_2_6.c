#include <string.h>

#include "e_2_6.h"

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int bits = 0; // number of bits in x
    unsigned xx;
    for (xx = x; xx != 0; bits++)
        xx >>= 1;

    unsigned clear_mask = ~(~(~0 << n) << (bits - p - n));
    unsigned apply_mask = (y & ~(~0 << n)) << (bits - p - n);

    return (x & clear_mask) | apply_mask;
}