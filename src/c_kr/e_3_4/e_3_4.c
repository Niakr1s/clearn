#include <string.h>

#include "e_3_4.h"

void reverse(char s[])
{
    int len = strlen(s);
    if (!len)
        return;

    char tmp[len + 1];
    int i;
    char *tmp_p = &tmp;
    for (i = len - 1; i >= 0; i--)
    {
        *tmp_p++ = s[i];
    }
    *tmp_p = '\0';
    strcpy(s, tmp);
}

int abs(int i)
{
    return i < 0 ? -i : i;
}

void itoa(int n, char s[])
{
    int minus = n < 0;

    int i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (minus)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}