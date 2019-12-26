#include "hashtable.h"

struct ListNode
{
    int element;
    Position Next;
};

struct HashTbl
{
    int TableSize;
    List *TheLists;
};

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;

    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
    {
        Error("out of space");
    }

    H->TableSize = TableSize;

    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if(H->TheLists == NULL)
    {
        Error("out of space");
    }
    
    for(i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists == NULL)
        {
            Error("out of space");
        }
        else
        {
            H->TheLists[i]->Next = NULL;
        }
    }
    
    return H;
}

Index Hash(unsigned int key, int TableSize)
{
    return key % TableSize;
}

Position Find(unsigned int key, HashTable H)
{
    Position P;
    List L;

    L = H->TheLists[Hash(key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->element != key)
    {
        P = P->Next;
    }
    
    return P;
}

void Insert(unsigned int key, HashTable H)
{
    Position P, NewNode;
    List L;

    P = Find(key, H);
    if(P == NULL)
    {
        NewNode = malloc(sizeof(struct ListNode));
        if (NewNode == NULL)
        {
            Error("out of space");
        }
        else
        {
            L  = H->TheLists[Hash(key, H->TableSize)];
            NewNode->Next = L->Next;
            NewNode->element = key;
            L->Next = NewNode;
        }
    }
}