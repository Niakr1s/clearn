#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "e_5_4.h"

int main()
{
    struct test_case
    {
        char s[8];
        char t[8];
        int exp;
    };
    struct test_case cases[] = {
        {"", "", 1},
        {"", "a", 0},
        {"a", "", 1},
        {"a", "a", 1},
        {"a", "b", 0},
        {"aa", "a", 1},
        {"aa", "aa", 1},
        {"aa", "aaa", 0},
        {"a", "aa", 0},
    };

    int errors = 0, i;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = cases + i;
        int got = strend(test->s, test->t);

        int fail = got != test->exp;
        errors += fail;

        printf("[%4s] [TEST #%d] s: '%s', t: '%s', got: %d, exp: %d\n",
               fail ? "FAIL" : "OK", i, test->s, test->t, got, test->exp);
        assert(!fail);
    }
    return errors;
}