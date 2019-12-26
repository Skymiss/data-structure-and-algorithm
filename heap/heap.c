#include "heap.h"

struct Heap
{
    int Capacity;
    int Size;
    int *Elements;
}

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue PQ;

    PQ = malloc(sizeof(struct Heap));
    if(PQ == NULL)
    {
        Error("out of space");
    }

    PQ->Elements = malloc((MaxElements + 1) * sizeof(int));

    if(PQ->Elements == NULL)
    {
        Error("out of space");
    }
    
    PQ->Capacity = MaxElements;
    PQ->Size = 0;
    PQ->Elements[0] = 0;

    return PQ;
}