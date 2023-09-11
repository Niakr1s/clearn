#include <string.h>
#include <assert.h>

#include "e_2_4.h"

int main()
{
    struct test_case {
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
    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        squeeze(cases[i].str, cases[i].substr);
        int fail = strcmp(cases[i].str, cases[i].expected) != 0;
        errors += fail;
        assert(!fail);
    }
    return errors;
}