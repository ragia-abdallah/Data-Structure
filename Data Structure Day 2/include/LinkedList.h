#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

/*typedef struct LinkedList
{
    Node *head, *tail;

}LinkedList;*/

Node *head = NULL, *tail = NULL;

/*void Add(LinkedList *L, int data)
{
    L->head
}*/

void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(int data)
{
    Node *node = GetNodeByData(data);

    if(node == NULL)
        return;

    if(node == head)
    {
        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->Next;
            head->Prev = NULL;
        }
    }
    else if(node == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
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

void InsertAfter(int data, int afterData)//add item data after item afterData
{

    Node* checkpoint = GetNodeByData(afterData);
    if (checkpoint == NULL){
        printf("Error. AfterData not found.");
        return;
    }

    Node*newNode = malloc(sizeof(Node));

    newNode->Data = data;

    if (checkpoint == tail){
        tail = newNode;
        newNode->Next = NULL;
        newNode->Prev = checkpoint;
        checkpoint->Next = newNode;

    }
    else {
        checkpoint->Next->Prev = newNode;
        newNode->Next = checkpoint->Next;
        newNode->Prev = checkpoint;
        checkpoint->Next = newNode;
    }

}

int GetCount()//count of nodes in linked list
{
    Node *current = head;
    int counter=0;

    while(current != NULL)
    {
        counter++;
        current = current->Next;
    }
    return counter;
}




int GetDataByIndex(int index)//give index to return
{
    int i=1;
    int output=0;
    Node *current = head;

    while(current != NULL)
    {
        if (index==i){
        output=current->Data;
        return output;
        }

        i++;
        current = current->Next;
    }
    printf("Error. Index not in List.");
    return NULL;




}

#endif // LINKEDLIST_H
