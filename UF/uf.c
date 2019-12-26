#include "uf.h"

void Initialize(DisjSet S)
{
    int i;

    for(i = NumSets; i > 0; i--)
    {
        S[i] = 0;
    }
}

void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    if(S[Root2] < S[Root1])
    {
        S[Root1] = Root2;
    }
    else
    {
        if(S[Root2] == S[Root1])
        {
            S[Root1]--;
        }
        S[Root2] = Root1;
    }
}

SetType Find(ElementType X, DisjSet S)
{
    if(X <= 0)
    {
        return X;
    }

    return S[X] = Find(S[X], S);
}