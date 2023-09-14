#include <string.h>

#include "e_5_4.h"

int strend(const char *s, const char *t)
{
    const char *ps = s + strlen(s), *pt = t + strlen(t);
    if ((pt - t) > (ps - s))
        return 0;
    for (; (ps - s) >= 0 && (pt - t) >= 0; ps--, pt--)
        if (*ps != *pt)
            return 0;
    return 1;
}