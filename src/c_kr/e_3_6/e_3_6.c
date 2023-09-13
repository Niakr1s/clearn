#include <string.h>

#include "e_3_6.h"
#include "../e_3_4/e_3_4.h"

void itoa_padl(int n, char s[], int width)
{
    itoa(n, s);

    int len = strlen(s);
    int pad = width - len;
    if (pad <= 0)
        return;

    int i;
    for (i = len; i >= 0; i--)
    {
        s[i + pad] = s[i];
    }
    memset(s, ' ', pad);
}