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

AvlTree Insert(int X, AvlTree T)
{
    if(T == NULL)
    {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if(T == NULL)
        {
            Error("out of space");
        }
        else
        {
            T->element = X;
            T->Height = 0;
            T->left = T->right = NULL;
        }
    }
    else if(X < T->element)
    {
        T->left = Insert(X, T->left);
        if(Height(T->left) - Height(T->right) == 2)
        {
            if(X < T->left->element)
            {
                T = SingleRotateWithLeft(T);
            }
            else
            {
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    else if(X > T->elemtn)
    {
        T->right = Insert(X, T->right);
        if(Height(T->right) - Height(T->left) == 2)
        {
            if(X > T->right->element)
            {
                T = SingleRotateWithRight(T);
            }
            else
            {
                T = DoubleRotateWithRight(T);
            }
        }
    }

    T->Height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}