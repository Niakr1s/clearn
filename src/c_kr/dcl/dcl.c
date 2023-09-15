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
        NAME,
        POINTER,
        BRACKETS,
        ARRAY,
    } type;
    void *data;
};

struct name_data
{
    char *s;
};

struct brackets_data
{
    char *s;
};

struct array_data
{
    int sz;
};

void free_token(struct token *token)
{
    if (!token)
        return;
    switch (token->type)
    {
    case NAME:
        struct name_data *nd = (struct name_data *)token->data;
        free(nd->s);
        free(nd);
        break;
    case POINTER:
        break;
    case BRACKETS:
        struct brackets_data *bd = (struct brackets_data *)token->data;
        free(bd->s);
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
    switch (token->type)
    {
    case NAME:
        struct name_data *nd = (struct name_data *)token->data;
        printf("%s", nd->s);
        break;
    case POINTER:
        printf("*");
        break;
    case BRACKETS:
        struct brackets_data *bd = (struct brackets_data *)token->data;
        printf("(%s)", bd->s);
        break;
    case ARRAY:
        struct array_data *ad = (struct array_data *)token->data;
        printf("[%d]", ad->sz);
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

struct token *nexttoken(struct token_getter *getter)
{
    skip_spaces(&getter->s);

    struct token *token = NULL;
    int len;
    if (*getter->s == '*')
    {
        getter->s++;
        token = (struct token *)malloc(sizeof(struct token));
        token->type = POINTER;
    }
    else if ((len = name_len(getter->s)))
    {
        struct name_data *data = (struct name_data *)malloc(sizeof(struct name_data));
        data->s = (char *)malloc(len + 1);
        strncpy(data->s, getter->s, len);
        data->s[len] = 0;

        getter->s += len;

        token = (struct token *)malloc(sizeof(struct token));
        token->type = NAME;
        token->data = (void *)data;
    }
    else if ((len = brackets_len(getter->s, '(', ')')))
    {
        struct brackets_data *data = (struct brackets_data *)malloc(sizeof(struct brackets_data));
        data->s = (char *)malloc(len - 1);
        strncpy(data->s, getter->s + 1, len - 2);
        data->s[len - 2] = 0;

        getter->s += len;

        token = (struct token *)malloc(sizeof(struct token));
        token->type = BRACKETS;
        token->data = (void *)data;
    }
    else if ((len = brackets_len(getter->s, '[', ']')))
    {
        struct array_data *data = (struct array_data *)malloc(sizeof(struct array_data));
        if (!sscanf(getter->s, "[%d]", &data->sz))
        {
            data->sz = 0;
        }
        getter->s += len;
        token = (struct token *)malloc(sizeof(struct token));
        token->type = ARRAY;
        token->data = (void *)data;
    }
    return token;
}

void dcl_parse(const char *s)
{
    struct token_getter getter = new_token_getter(s);
    struct token *out;
    for (out = nexttoken(&getter); out; out = nexttoken(&getter))
    {
        if (out->type == BRACKETS)
        {
            printf("(");
            dcl_parse(((struct brackets_data *)out->data)->s);
            printf(") ");
        }
        else
        {
            print_token(out);
            printf(" ");
        }
    }
    free_token(out);
}
