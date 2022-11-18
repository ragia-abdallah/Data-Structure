#ifndef QUEUE_H
#define QUEUE_H

#define MaxQSize 5

struct Node
{
    int Data;
    Node *Prev;
};

typedef struct Stack
{
    Node *item;
    int *Prev, *Next;
}Stack;

typedef struct Queue
{
    Node *item;
    int *head, *tail;//need to be initiated as NULL

}Queue;

void EnQueue(Queue *q, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = Queue->head;
    newNode->Next = Queue->tail;
    stk->top = newNode;

    if(q->head == NULL)
        q->head++;

    q->rear++;
    q->arr[q->rear] = data;
}

int DeQueue(Queue *q, int *data)
{
    q->front++;

    if(q->front == -1)
    {
        return 0;
    }
    else
    {
        *data = q->arr[q->front];
        q->front++;

        return 1;
    }
}

#endif // QUEUE_H
