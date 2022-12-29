#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main()
{
    LinkedList myList = {.head = NULL, .tail = NULL};
    Add(&myList, 3);
    Add(&myList, 5);
    Add(&myList, 7);
    Add(&myList, 9);

    Display(&myList);

    return 0;
}
