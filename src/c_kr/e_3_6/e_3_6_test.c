#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <limits.h>

#include "e_3_6.h"

int main()
{
    struct test_case
    {
        int n;
        int w;
        char exp[64];
    };
    struct test_case cases[] = {
        {-111, 0, "-111"},
        {-111, 1, "-111"},
        {-111, 2, "-111"},
        {-111, 3, "-111"},
        {-111, 4, "-111"},
        {-111, 5, " -111"},
        {-111, 6, "  -111"},

        {-1, 0, "-1"},
        {-1, 1, "-1"},
        {-1, 2, "-1"},
        {-1, 3, " -1"},

        {0, 0, "0"},
        {0, 1, "0"},
        {0, 2, " 0"},
        {0, 3, "  0"},

        {1, 0, "1"},
        {1, 1, "1"},
        {1, 2, " 1"},
        {1, 3, "  1"},

        {111, 0, "111"},
        {111, 1, "111"},
        {111, 2, "111"},
        {111, 3, "111"},
        {111, 4, " 111"},
        {111, 5, "  111"},
    };
    char got[64];
    int errors = 0, i;
    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    {
        struct test_case *test = &cases[i];
        itoa_padl(test->n, got, test->w);

        int fail = strcmp(got, test->exp) != 0;
        errors += fail;

        printf("[%4s] [TEST #%d] n: %d, w: %d, got: '%s', exp: '%s'\n",
               fail ? "FAIL" : "OK", i, test->n, test->w, got, test->exp);
        assert(!fail);
    }
    return errors;
}