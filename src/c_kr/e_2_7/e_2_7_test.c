#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_2_7.h"

int main()
{
    struct test_case
    {
        unsigned x;
        int p;
        int n;
        unsigned expected;
    };

    unsigned x = 0b101101100011;

    struct test_case cases[] = {
        {0U, 0, 0, 0U},
        
        {x, 4, 4, 0b101110010011},
        {x, 4, 8, 0b101110011100},
        {x, 0, 8, 0b010010010011},
        {x, 0, 12, 0b010010011100},

        {x, 0, 0, 0b101101100011},
        {x, 4, 0, 0b101101100011},
        {x, 8, 0, 0b101101100011},
        {x, 12, 0, 0b101101100011},
    };

    int errors = 0;
    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];
        int got = invert(test->x, test->p, test->n);
        int fail = got != test->expected;
        errors += fail;

        printf("[%4s] [TEST #%d] x: %b, p: %d, n: %d, got: %b, expected: %b\n",
               fail ? "FAIL" : "OK", i, test->x, test->p, test->n, got, test->expected);
        assert(!fail);
    }
    return errors;
}