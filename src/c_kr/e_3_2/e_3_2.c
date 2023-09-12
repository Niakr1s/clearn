#include <string.h>

#include "e_3_2.h"

void escape(char *s, const char *t)
{
    for (; *t != '\0'; ++s, ++t)
    {
        switch (*t)
        {
        case '\n':
            *s = '\\';
            *++s = 'n';
            break;
        case '\t':
            *s = '\\';
            *++s = 't';
            break;
        default:
            *s = *t;
            break;
        }
    }
    *s = '\0';
}

void unescape(char *s, const char *t)
{
    for (; *t != '\0'; ++s, ++t)
    {
        switch (*t)
        {
        case '\\':
            switch (*(t + 1))
            {
            case 'n':
                *s = '\n';
                t++;
                break;
            case 't':
                *s = '\t';
                t++;
                break;
            }
            break;
        default:
            *s = *t;
            break;
        }
    }
    *s = '\0';
}