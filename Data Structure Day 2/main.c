#include <stdio.h>
#include <stdlib.h>
#include "include/Stack.h"

int main()
{
    Stack stk={.top=NULL};

    Push(&stk, 10);
    Push(&stk, 20);
    Push(&stk, 30);

    int popResult =0;

    if (Pop(&stk, &popResult)==1)
    {
        printf("\npop = %d",popResult);
    }
    else
    {
        printf("\nError");
    }

    int peekResult =0;

    if (Peek(&stk, &peekResult)==1)
    {
        printf("\npeek = %d",peekResult);
    }
    else
    {
        printf("\nError");
    }







    //printf("Hello world!\n");
    return 0;
}
