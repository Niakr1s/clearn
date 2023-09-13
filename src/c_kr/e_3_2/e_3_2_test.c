#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_3_2.h"

int main()
{
    struct test_case
    {
        char u[10]; // unescaped
        char e[20]; // escaped
    };

    struct test_case cases[] = {
        {"", ""},
        {"hello", "hello"},

        {"\nhello", "\\nhello"},
        {"hel\nlo", "hel\\nlo"},
        {"hello\n", "hello\\n"},

        {"\thello", "\\thello"},
        {"hel\tlo", "hel\\tlo"},
        {"hello\t", "hello\\t"},

        {"\th\nel\tlo\n", "\\th\\nel\\tlo\\n"},
    };

    int errors, i = 0;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];

        char got_e[16], got_u[16];
        escape(got_e, test->u);
        unescape(got_u, test->e);

        int fail_e = strcmp(got_e, test->e) != 0;
        int fail_u = strcmp(got_u, test->u) != 0;
        errors += fail_e;

        printf("[%4s] [TEST #%d] [escape] '%s'\n",
               fail_e ? "FAIL" : "OK", i, test->e);
        assert(!fail_e);

        printf("[%4s] [TEST #%d] [unescape] '%s'\n",
               fail_u ? "FAIL" : "OK", i, test->e);
        assert(!fail_u);
    }
    return errors;
}