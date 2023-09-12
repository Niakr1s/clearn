#include <string.h>

#include "e_3_3.h"

int expand(const char *s1, char *s2)
{
    enum state
    {
        OUT, // before any ranges
        BEGIN, // in range 'a-z' it's 'a'
        END_PENDING, // in range 'a-z', set after '-'
        END, // in range 'a-z' int's 'z'
    };

    const char DELIM = '-';
    enum state state;

    char *beg = NULL; // for storing the beginning of interval in s2
    int i;
    for (i = 0, state = OUT; s1[i] != '\0'; i++)
    {
        if (s1[i] == DELIM)
        {
            switch (state)
            {
            case OUT:
                *s2++ = DELIM;
                break;
            case BEGIN:
                state = END_PENDING;
                *s2++ = DELIM;
                break;
            case END_PENDING:
                // add delim just in case that it's trailing characters
                *s2++ = DELIM;
                break;
            case END:
                state = END_PENDING;
                break;
            }
        }
        else if ((s1[i] >= 'a' && s1[i] <= 'z') ||
                 (s1[i] >= 'A' && s1[i] <= 'Z') ||
                 (s1[i] >= '0' && s1[i] <= '9'))
        {
            switch (state)
            {
            case OUT:
            case END:
                beg = s2;
                *s2++ = s1[i];
                state = BEGIN;
                break;
            case BEGIN:
                *s2++ = s1[i];
                break;
            case END_PENDING:
                s2 = beg;
                for (int ch = *beg; ch <= s1[i]; ch++)
                    *s2++ = ch;
                beg = s2 - 1;
                state = END;
                break;
            }
        }
        else
        {
            return i;
        }
    }

    *s2 = '\0';
    return -1;
}