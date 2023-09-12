/*
Expands short notation in s1 (like 'a-z') into complete string ('abc...xyz').
Allowed: letters of any case and digits.
Handles cases like 'a-b-c', 'a-z0-9', '-a-z', 'a-z-'.
Leading and trailing spaces are taken literally.

Returns -1 on success, otherwise position of first error.
*/
int expand(const char *s1, char *s2);