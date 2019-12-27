#include "list.h"
#include "stdlib.h"

struct Node
{
    int Element;
    Position Next;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(List L, Position P)
{
    return P->Next == NULL;
}

Position Find(int element, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != element)
    {
        P = P->Next;
    }
    
    return P;
}

Position FindPrevious(int element, List L)
{
    Position P;

    P = L;

    while (P->Next != NULL && P->Next->Element != element)
    {
        P = P->Next;
    }
        
    return P;
}

void Delete(int element, List L)
{
    Position P, TempCeil;

    P = L->Next;
    P = FindPrevious(element, L);

    if(!IsLast(L, P))
    {
        TempCeil = P->Next;
        P->Next = TempCeil->Next;
        free(TempCeil);
    }

}

void Insert(int element, Position P, List L)
{
    Position P, TempCeil;

    TempCeil = (PtrToNode)malloc(sizeof(struct node));

    if(TempCeil == NULL)
    {
        printf("out of space");
    }

    TempCeil->Element = element;
    TempCeil->Next = P->Next;
    P->Next = TempCeil;
    
}

void DeleteList(List L)
{
    Position P, tmp;

    P = L->Next;
    L->Next = NULL;

    while(P != NULL)
    {
        tmp = P->Next;
        free(P);
        P = P->Next;
    }
    
}

void PrintList(List L)
{
    Position P;

    P = L->Next;
    while(P != NULL)
    {
        printf("%d,", P->Element);
        P = P->Next;
    }
}