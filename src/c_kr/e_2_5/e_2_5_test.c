#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_2_5.h"

int main()
{
    struct test_case
    {
        char str[20];
        char substr[20];
        int expected;
    };

    struct test_case cases[] = {
        {"", "", 0},
        {"hello", "", 0},
        {"hello", "el", 1},
        {"hello", "ll", 2},
        {"hello", "le", -1},
        {"hello", "helo", -1},
        {"hello", "o", 4},
    };

    int errors = 0;
    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];
        int got = strfind(test->str, test->substr);
        int fail = got != test->expected;
        errors += fail;

        printf("[%4s] [TEST #%d] str: %s, substr: %s, got: %d, expected: %d\n",
               fail ? "FAIL" : "OK", i, test->str, test->substr, got, test->expected);
        assert(!fail);
    }
    return errors;
}