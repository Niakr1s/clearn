#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_2_9.h"

int main()
{
    struct test_case
    {
        unsigned x;
        int expected;
    };

    struct test_case cases[] = {
        {0b0, 0},
        {0b1, 1},
        {0b10, 1},
        {0b11, 2},
        {0b110, 2},
        {0b101, 2},
        {0b111, 3},
    };

    int errors = 0;
    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];
        int got = bitcount(test->x);
        int fail = got != test->expected;
        errors += fail;

        printf("[%4s] [TEST #%d] x: %b, got: %d, expected: %d\n",
               fail ? "FAIL" : "OK", i, test->x, got, test->expected);
        assert(!fail);
    }
    return errors;
}