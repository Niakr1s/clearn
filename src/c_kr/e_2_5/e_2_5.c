#include <string.h>

#include "e_2_5.h"

int strfind(char *s, char *substr)
{
    if (s[0] == '\0' && substr[0] == '\0')
        return 0;

    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (memcmp(s + i, substr, strlen(substr)) == 0)
        {
            return i;
        }
    }
    return -1;
}