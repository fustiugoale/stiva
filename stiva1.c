#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"

enum {Stack_Size = 100};

static int stiva[Stack_Size];
static int top = 0;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    top = 0;
}

int isit_empty(void)
{
    return top == 0;
}

int isit_full(void)
{
    return top == Stack_Size;
}

void push(int i)
{
    if (isit_full())
        terminate("Error in push: stack is full.\n");

    stiva[top++] = i;
}

int pop(void)
{
    if (isit_empty())
        terminate("Error in pop: stack is empty.\n");

    return stiva[--top];
}
