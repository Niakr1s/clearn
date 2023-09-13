#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void main()
{
    int i = -123;
    while (i != 0)
    {
        int rem = i % 10;
        i /= 10;
        printf("%%%d, /%d\n", rem, i);
    }
}