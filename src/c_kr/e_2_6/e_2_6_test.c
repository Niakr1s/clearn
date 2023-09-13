#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_2_6.h"

int main()
{
    struct test_case
    {
        unsigned x;
        int p;
        int n;
        unsigned y;
        unsigned expected;
    };

    unsigned x = 0b101101100011;
    unsigned y = 0b1010101101101;

    struct test_case cases[] = {
        {0U, 0, 0, 0U, 0U},
        {x, 4, 4, y, 0b101111010011},
        {x, 4, 8, y, 0b101101101101},
    };

    int errors, i = 0;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];
        int got = setbits(test->x, test->p, test->n, test->y);
        int fail = got != test->expected;
        errors += fail;

        printf("[%4s] [TEST #%d] x: %b, p: %d, n: %d, y: %b, got: %b, expected: %b\n",
               fail ? "FAIL" : "OK", i, test->x, test->p, test->n, test->y, got, test->expected);
        assert(!fail);
    }
    return errors;
}