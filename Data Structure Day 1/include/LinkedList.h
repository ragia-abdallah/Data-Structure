#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

typedef struct LinkedList
{
    Node *head, *tail;

}LinkedList;

//Node *head = NULL, *tail = NULL;

/*void Add(LinkedList *L, int data)
{
    L->head
}*/

void Add(LinkedList *L, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(L->head == NULL)
    {
        L->head = L->tail = newNode;
    }
    else
    {
        L->tail->Next = newNode;
        newNode->Prev = L->tail;
        L->tail = newNode;
    }
}

void Display(LinkedList *L)
{
    Node *current = L->head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(LinkedList *L, int data)
{
    Node *current = L->head;

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
    Node *node = GetNodeByData(L, data);

    if(node == NULL)
        return;

    if(node == L->head)
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
    else if(node == L->tail)
    {
        L->tail = L->tail->Prev;
        L->tail->Next = NULL;
    }
    else
    {
        /*Node *A = node->Prev;
        Node *B = node->Next;

        A->Next = B;
        B->Prev = A;*/

        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
}


void InsertAfter(LinkedList *L, int data, int newData) // V2
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->Next = newNode->Prev = NULL;

    Node *current = GetNodeByData(L, data);
    if (current == NULL)
    {
        L->head = newNode;
    }
    else if (current == L->tail)
    {
        newNode->Prev = L->tail;
        L->tail->Next = newNode;
        L->tail = newNode;
    }
    else
    {
        newNode->Prev = current;
        newNode->Next = current->Next;
        current->Next->Prev = newNode;
        current->Next = newNode;
    }
}

int GetCount(LinkedList *L)//count of nodes in linked list
{
    Node *current = L->head;
    int counter=0;

    while(current != NULL)
    {
        counter++;
        current = current->Next;
    }
    return counter;
}

int GetNodeByIndex(LinkedList *L, int *data, int index) // V2
{
    int i=0, check=0;
    Node *current = L->head;

    for (i=1; i<index; i++)
    {
        if (current == NULL)
            return 0;

        current = current->Next;
    }

    *data = current->Data;
    return 1;

}
#endif // LINKEDLIST_H
