#include "queue.h"

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    int *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Capacity == 0;
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int value, Queue Q)
{
    if(++value == Q->Capacity)
    {
        value = 0;
    }
    
    return value;
}

void Enqueue(int element, Queue Q)
{
    if(IsFull(Q))
    {
        Error("Queue is full");
    }
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = element;
    }
    
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
    {
        Error("Queue is empty");
    }
    else
    {
        Q->Size--;
        Q->front = Succ(Q->front, Q);
    }
}

int Front(Queue Q)
{
    if(IsEmpty(Q))
    {
        Error("Queue is empty");
    }
    else
    {
        return Q->array[Q->front];
    }
}