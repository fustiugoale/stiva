#include <stdio.h>
#include "stiva.h"


int main()
{
    printf("Introduceti un text\n");

    char text[100];

    while(1)
    {
        gets(text); if (!strlen(text)) break;

        int i = 0;
        while (text[i] && !isit_full())
            push(text[i++]);

        while (!isit_empty())
            printf("%c", pop());
        printf("\n\n");
    }

    return 0;
}
