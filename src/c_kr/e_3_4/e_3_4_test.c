#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <limits.h>

#include "e_3_4.h"

int main()
{
    int cases[] = {INT_MIN, -111, -1, 0, 1, 111, INT_MAX};
    char got[64], exp[64];
    int errors = 0, i;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        itoa(cases[i], got);
        sprintf(exp, "%d", cases[i]);

        int fail = strcmp(got, exp) != 0;
        errors += fail;

        printf("[%4s] [TEST #%d] i: %d, got: '%s', exp: '%s'\n",
               fail ? "FAIL" : "OK", i, cases[i], got, exp);
        assert(!fail);
    }
    return errors;
}