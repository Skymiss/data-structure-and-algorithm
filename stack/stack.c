#include "stack.h"

struct Node
{
    int element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
    {
        Error("must use CreateStack first");
    }
    else
    {
        while(!IsEmpty(S))
        {
            Pop(S);
        }
    }
}

Stack CreateStack(void)
{
    Stack S;

    S = malloc(sizeof(struct Node));
    if(S == NULL)
    {
        Error("Create Stack Error ");
    }

    S->Next = NULL;
    MakeEmpty(S);
    return S;
    
}

void Push(int element, Stack S)
{
    PtrToNode P;

    P = malloc(sizeof(struct Node));
    if(P == NULL)
    {
        Error("fatal error");
    }
    else
    {
        P->element = element;
        P->Next = S->Next;
        S->Next = P;
    }
}

int Pop(Stack S)
{
    PtrToNode P;

    if(IsEmpty(S))
    {
        Error("Empty Stack");
    }
    else
    {
        P = S->Next;
        S->Next = P->Next;
        free(P);
    }
}

int Top(Stack S)
{
    if(!IsEmpty(S))
    {
        return S->Next->element;
    }
    
    Error("empty stack");
    return 0;
}