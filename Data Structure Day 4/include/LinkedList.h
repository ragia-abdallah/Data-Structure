#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LNode LNode;

struct LNode
{
    int Data;
    LNode *Prev, *Next;
};

typedef struct LinkedList
{
    LNode *head, *tail;

}LinkedList;

//LNode *head = NULL, *tail = NULL;

/*void Add(LinkedList *L, int data)
{
    L->head
}*/

void Add(LinkedList *L, int data)
{
    LNode *newLNode = malloc(sizeof(LNode));
    newLNode->Data = data;
    newLNode->Prev = newLNode->Next = NULL;

    if(L->head == NULL)
    {
        L->head = L->tail = newLNode;
    }
    else
    {
        L->tail->Next = newLNode;
        newLNode->Prev = L->tail;
        L->tail = newLNode;
    }
}

void Display(LinkedList *L)
{
    LNode *current = L->head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}

LNode* GetLNodeByData(LinkedList *L, int data)
{
    LNode *current = L->head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(LinkedList *L, int data)
{
    LNode *LNode = GetLNodeByData(L, data);

    if(LNode == NULL)
        return;

    if(LNode == L->head)
    {
        if(L->head == L->tail)
        {
            L->head = L->tail = NULL;
        }
        else
        {
            L->head = L->head->Next;
            L->head->Prev = NULL;
        }
    }
    else if(LNode == L->tail)
    {
        L->tail = L->tail->Prev;
        L->tail->Next = NULL;
    }
    else
    {
        /*LNode *A = LNode->Prev;
        LNode *B = LNode->Next;

        A->Next = B;
        B->Prev = A;*/

        LNode->Prev->Next = LNode->Next;
        LNode->Next->Prev = LNode->Prev;
    }

    free(LNode);
}


void InsertAfter(LinkedList *L, int data, int newData) // V2
{
    LNode *newLNode = malloc(sizeof(LNode));
    newLNode->Data = newData;
    newLNode->Next = newLNode->Prev = NULL;

    LNode *current = GetLNodeByData(L, data);
    if (current == NULL)
    {
        L->head = newLNode;
    }
    else if (current == L->tail)
    {
        newLNode->Prev = L->tail;
        L->tail->Next = newLNode;
        L->tail = newLNode;
    }
    else
    {
        newLNode->Prev = current;
        newLNode->Next = current->Next;
        current->Next->Prev = newLNode;
        current->Next = newLNode;
    }
}

int GetCount(LinkedList *L)//count of LNodes in linked list
{
    LNode *current = L->head;
    int counter=0;

    while(current != NULL)
    {
        counter++;
        current = current->Next;
    }
    return counter;
}

int GetLNodeByIndex(LinkedList *L, int *data, int index) // V2
{
    int i=0, check=0;
    LNode *current = L->head;

    for (i=1; i<index; i++)
    {
        if (current == NULL)
            return 0;

        current = current->Next;
    }

    *data = current->Data;
    return 1;

}

int GetMax(LinkedList *L)
{
    int Max=0;

    LNode *current = L->head;

    while(!current)
    {
        if(current->Data > Max)
            Max = current->Data;
        current = current->Next;
    }
    return Max;

}
#endif // LINKEDLIST_H
