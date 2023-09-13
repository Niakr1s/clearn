#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_2_8.h"

int main()
{
    struct test_case
    {
        unsigned x;
        int n;
        unsigned expected;
    };

    unsigned x = 0b1011;

    struct test_case cases[] = {
        {0U, 0, 0U},

        {x, 0, 0b1011},
        {x, 1, 0b1101},
        {x, 2, 0b1110},
        {x, 3, 0b0111},
        {x, 4, 0b1011},
        {x, 5, 0b1101},
    };

    int errors, i = 0;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];
        int got = rightrot(test->x, test->n);
        int fail = got != test->expected;
        errors += fail;

        printf("[%4s] [TEST #%d] x: %b, n: %d, got: %b, expected: %b\n",
               fail ? "FAIL" : "OK", i, test->x, test->n, got, test->expected);
        assert(!fail);
    }
    return errors;
}