#ifndef QUEUE_H
#define QUEUE_H

#define MaxQSize 5

struct Node
{
    int Data;
    Node *Next;
};

typedef struct Queue
{
    Node *item;
    int *head, *tail;//need to be initiated as NULL

}Queue;

void EnQueue(Queue *q, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;

    if(q->head == NULL)
    {
        Queue->head = newNode;
    }

        newNode->Next = Queue->tail;
        Queue->tail = newNode;
}

int DeQueue(Queue *q, int *data)
{
    //q->head;

    if(q->head == NULL)
    {
        return 0;
    }
    else
    {
        Node *temp = q->head
        *data = temp->Data;
        q->head=temp->Next;

        return 1;
    }
}

#endif // QUEUE_H
