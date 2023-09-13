#include <string.h>

#include "e_2_4.h"

void squeeze(char *str, const char *substr)
{
    char buf[strlen(str) + 1];
    int bi = 0, i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        int found = 0, j = 0;
        for (j = 0; substr[j] != '\0'; j++)
        {
            if (str[i] == substr[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            buf[bi++] = str[i];
        }
    }
    buf[bi] = '\0';
    memcpy(str, buf, bi + 1);
}