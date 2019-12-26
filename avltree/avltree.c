#include "avltree.h"

struct AvlNode
{
    int element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height(Position P)
{
    if(P == NULL)
    {
        return -1;
    }
    else
    {
        return P->Height;
    }
}