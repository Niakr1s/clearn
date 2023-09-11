#include <string.h>

#include "e_2_4.h"

// removes each character in str that matches any character in substr
void squeeze(char *str, char *substr)
{
    char buf[strlen(str)];
    int bi = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int found = 0;
        for (int j = 0; substr[j] != '\0'; j++)
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