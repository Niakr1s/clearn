#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "e_5_3.h"

int main()
{
    struct test_case
    {
        char s[8];
        char t[8];
        char exp[16];
    };
    struct test_case cases[] = {
        {"", "", ""},
        {"", "a", "a"},
        {"a", "", "a"},
        {"a", "b", "ab"},
        {"ab", "c", "abc"},
        {"a", "bc", "abc"},
    };

    int errors = 0, i;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = cases + i;
        my_strcat(test->s, test->t);

        int fail = strcmp(test->s, test->exp) != 0;
        errors += fail;

        printf("[%4s] [TEST #%d] got: '%s', exp: '%s'\n",
               fail ? "FAIL" : "OK", i, test->s, test->exp);
        assert(!fail);
    }
    return errors;
}