#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"

struct node {
    int data;
    struct node *next;
};

static struct node *top = NULL;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while (!isit_empty())
        pop();
}

int isit_full(void)
{
    return 0;
}

int isit_empty(void)
{
    return top == NULL;
}

void push(int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.\n");

    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

int pop(void)
{
    struct node *old_top;
    int i;

    if(isit_empty())
        terminate("Error in pop: stack is empty. \n");

    old_top = top;
    i = top->data;
    top = top->next;
    free(old_top);
    return i;
}
