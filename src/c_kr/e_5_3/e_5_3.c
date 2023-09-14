#include <string.h>

#include "e_5_3.h"

void my_strcat(char *s, const char *t)
{
    for (s += strlen(s); *s = *t; s++, t++)
        ;
}