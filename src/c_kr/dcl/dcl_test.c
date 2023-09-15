#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "dcl.h"

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
    };

    int errors = 0, i;
    // for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++)
    // {
    //     // struct test_case *test = cases + i;
    //     // int got = strend(test->s, test->t);

    //     // int fail = got != test->exp;
    //     // errors += fail;

    //     // printf("[%4s] [TEST #%d] s: '%s', t: '%s', got: %d, exp: %d\n",
    //     //        fail ? "FAIL" : "OK", i, test->s, test->t, got, test->exp);
    //     // assert(!fail);
    // }
    const char *s = "  char (   *(*x[3])())   [5]";
    printf("%s -> \n", s);
    dcl_parse(s);
    return errors;
}