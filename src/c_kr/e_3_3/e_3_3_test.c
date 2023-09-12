#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "e_3_3.h"

int main()
{
    struct test_case
    {
        char s1[20];
        char expected_s2[100]; // expected s2
        int expected_res;      // expected result
    };

    struct test_case cases[] = {
        {"", "", -1},
        {"-", "-", -1},
        {"--", "--", -1},

        {"a", "a", -1},
        {"abc", "abc", -1},
        {"-a", "-a", -1},
        {"a-", "a-", -1},
        {"-a-", "-a-", -1},

        {"a-c", "abc", -1},
        {"A-C", "ABC", -1},
        {"x-z", "xyz", -1},
        {"X-Z", "XYZ", -1},

        {"a-b-c", "abc", -1},
        {"a-bb-c", "abbc", -1},
        {"a-bb-c-e", "abbcde", -1},
        {"a-bb-c-", "abbc-", -1},
        {"a-bb-c-e--", "abbcde--", -1},
        {"---a-bb-c-e--", "---abbcde--", -1},
    };

    int errors = 0;

#define GOT_S2_SZ 100
    char got_s2[GOT_S2_SZ];

    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]);
         i++, memset(got_s2, '\0', GOT_S2_SZ))
    {
        struct test_case *test = &cases[i];

        int got_res = expand(test->s1, got_s2);

        int fail;
        if (got_res == -1 && test->expected_res == -1)
            fail = strcmp(got_s2, test->expected_s2) != 0;
        else
            fail = got_res != test->expected_res;

        errors += fail;

        printf("[%4s] [TEST #%d] s1: '%s', s2: '%s'\n",
               fail ? "FAIL" : "OK", i, test->s1, got_s2);
        assert(!fail);
    }
    return errors;
}