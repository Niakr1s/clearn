#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dcl.h"

void skip_spaces(const char **s)
{
    while (isspace(**s))
        *(*s)++;
}

int name_len(const char *s)
{
    int i;
    for (i = 0; isalnum(s[i]); i++)
        ;
    return i;
}

int brackets_len(const char *s, char start_bracket, char end_bracket)
{
    if (s[0] != start_bracket)
        return 0;

    int depth, i;
    for (i = 1, depth = 1; s[i] && depth > 0; i++)
    {
        if (s[i] == start_bracket)
            depth++;
        else if (s[i] == end_bracket)
            depth--;
    }
    return i;
}

struct token
{
    enum
    {
        NONE,
        NAME,
        POINTER,
        BRACKETS,
        ARRAY,
    } type;
    void *data;
};

struct name_data
{
    const char *p;
    int len;
};

struct brackets_data
{
    const char *p;
    int len;
};

struct array_data
{
    int sz;
};

void free_token(struct token *token)
{
    switch (token->type)
    {
    case NAME:
        struct name_data *nd = (struct name_data *)token->data;
        free(nd);
        break;
    case POINTER:
        break;
    case BRACKETS:
        struct brackets_data *bd = (struct brackets_data *)token->data;
        free(bd);
        break;
    case ARRAY:
        struct array_data *ad = (struct array_data *)token->data;
        free(ad);
        break;
    }
    free(token);
}

void print_token(const struct token *token)
{

    char buf[256];

    switch (token->type)
    {
    case NONE:
        printf("NONE");
        break;
    case NAME:
        struct name_data *nd = (struct name_data *)token->data;
        strncpy(buf, nd->p, nd->len);
        printf("NAME: '%s'", buf);
        break;
    case POINTER:
        printf("POINTER");
        break;
    case BRACKETS:
        struct brackets_data *bd = (struct brackets_data *)token->data;
        strncpy(buf, bd->p, bd->len);
        printf("BRACKETS: '%s'", buf);
        break;
    case ARRAY:
        struct array_data *ad = (struct array_data *)token->data;
        printf("ARRAY: [%d]", ad->sz);
        break;
    }
}

struct token_getter
{
    const char *s; // pointer to first char of next token
};

struct token_getter new_token_getter(const char *s)
{
    return (struct token_getter){s};
}

struct token nexttoken(struct token_getter *getter)
{
    skip_spaces(&getter->s);

    int len;
    if (*getter->s == '\0')
        return (struct token){NONE, NULL};
    else if (*getter->s == '*')
    {
        getter->s++;
        return (struct token){POINTER, NULL};
    }
    else if ((len = name_len(getter->s)))
    {
        struct name_data *data = (struct name_data *)malloc(sizeof(struct name_data));
        data->p = getter->s;
        data->len = len;
        getter->s += len;
        return (struct token){NAME, (void *)data};
    }
    else if ((len = brackets_len(getter->s, '(', ')')))
    {
        struct brackets_data *data = (struct brackets_data *)malloc(sizeof(struct brackets_data));
        data->p = getter->s;
        data->len = len;
        getter->s += len;
        return (struct token){BRACKETS, (void *)data};
    }
    else if ((len = brackets_len(getter->s, '[', ']')))
    {
        struct array_data *data = (struct array_data *)malloc(sizeof(struct array_data));
        if (sscanf(getter->s, "[%d]", &data->sz) == 0)
        {
            data->sz = 0;
        }
        getter->s += len;
        return (struct token){ARRAY, (void *)data};
    }
    else
    {
        return (struct token){NONE, NULL};
    }
}

void dcl_parse(const char *s)
{
    struct token_getter getter = new_token_getter(s);
    struct token out;
    for (out = nexttoken(&getter); out.type != NONE; out = nexttoken(&getter))
    {
        print_token(&out);
        printf("\n");
    }
}
