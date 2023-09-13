#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_2_4.h"

int main()
{
    struct test_case
    {
        char str[20];
        char substr[20];
        char expected[20];
    };

    struct test_case cases[] = {
        {"", "", ""},
        {"hello", "", "hello"},
        {"hello", "el", "ho"},
        {"hello", "le", "ho"},
        {"hello", "helo", ""},
    };

    int errors = 0;
    int i;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        squeeze(cases[i].str, cases[i].substr);
        int fail = strcmp(cases[i].str, cases[i].expected) != 0;
        printf("[%4s] [TEST #%d] str: '%s', substr: '%s', expected: '%s'\n",
               fail ? "FAIL" : "OK", i, cases[i].str, cases[i].substr, cases[i].expected);
        errors += fail;
        assert(!fail);
    }
    return errors;
}