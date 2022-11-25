#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

Node *head = NULL, *tail = NULL;

void AddNode(int data)
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

int GetListCount(Node *head)
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

int GetNodeByIndex(Node *head, int index, Node *result)//give index to return
{
    int i=0;
    Node *current = head;

    while(current != NULL)
    {
        if (index<i)
    {
        return 0;
    }
        else if (index==i){
        result = current;
        return 1;
        }

        i++;
        current = current->Next;
    }

}

void Swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void BubbleSort(Node *head, Node *tail)
{
    int counter, index;
    int sorted = 0;

    Node *store, *currentnode, *nextnode;

    int size = GetListCount(head);

    for(counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;

        for(index = 0; index < size - 1 - counter; index++)
        {
            if (GetNodeByIndex(head, index, store))
            {
                currentnode = store;
            }
            if (GetNodeByIndex(head, index + 1, store))
            {
                nextnode = store;
            }
            if(currentnode->Data > nextnode->Data)
            {
                Swap(currentnode, nextnode);
                sorted = 0;
            }
        }
    }
}

/*
void SelectionSort(int *data, int size)
{
    int counter;

    for(counter = 0; counter < size - 1; counter++)
    {
        int minIndex = counter, index;

        for(index = minIndex + 1; index < size; index++)
        {
            if(data[index] < data[minIndex])
                minIndex = index;
        }

        Swap(&data[counter], &data[minIndex]);
    }
}

void InsertionSort(int *data, int size)
{
    int counter, key, index;

    for(counter = 1; counter < size; counter++)
    {
        key = data[counter];
        index = counter - 1;

        while(index >= 0 && data[index] > key)
        {
            data[index + 1] = data[index];
            index--;
        }
        data[index+1] = key;
    }
}
*/

int BinarySearch(Node *head, Node *tail, int item)
{

    BubbleSort(head, tail);
    int size = GetListCount(head);
    Node *current;
    int nodeData;

    int minIndex = 0, maxIndex = size - 1, midIndex;

    while(minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if(GetNodeByIndex(head,midIndex,current))
        {
            nodeData = current->Data;
        }

        if(nodeData == item)
            return midIndex;

        if(item > nodeData)
            minIndex = midIndex + 1;
        else
            maxIndex = midIndex - 1;
    }

    return -1;
}

/*
void Display(int *data, int size)
{
    int index;

    for(index = 0; index < size; index++)
    {
        printf("%d  ", data[index]);
    }
}
*/

int main()
{
    AddNode(5);
    AddNode(3);
    AddNode(4);
    AddNode(7);
    AddNode(2);

    Display();

    Node *result;

    if(GetNodeByIndex(head,1,result))
    {
        printf("%d",result->Data);
    }

    //Display();

    return 0;
}
