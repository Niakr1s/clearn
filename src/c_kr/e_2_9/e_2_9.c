#include <string.h>

#include "e_2_9.h"

int bitcount(unsigned x)
{
    int count = 0;
    for (; x != 0; x &= (x - 1))
    {
        count++;
    }
    return count;
}