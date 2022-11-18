#ifndef STACK_H
#define STACK_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev;
};

typedef struct Stack
{
    Node *item;
    int *top;//need to be initiated as NULL
}Stack;

void Push(Stack *stk, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = stk->top;
    stk->top = &newNode;
}

int Pop(Stack *stk, int *data)
{
    if(stk->top == NULL)
    {
        return 0;
    }

    Node *item = stk->top;

    *data = item->Data;
    stk->top--;

    return 1;
}

int Peek(Stack *stk, int *data)
{
    if(stk->top == NULL)
    {
        return 0;
    }

    *data = stk->top;

    return 1;
}
#endif // STACK_H
