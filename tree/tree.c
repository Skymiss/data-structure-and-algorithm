#include "tree.h"

struct TreeNode
{
    int element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(int element, SearchTree T)
{
    if(T == NULL)
    {
        return NULL;
    }

    if(element < T->element)
    {
        return Find(element, T->Left);
    }
    else if(element > T->element)
    {
        return Find(element, T->Right);
    }
    else
    {
        return T;
    }
}

Position FindMin(SearchTree T)
{
    if(T == NULL)
    {
        return NULL;
    }
    else if(T->Left == NULL)
    {
        return T;
    }
    else
    {
        return FindMin(T->Left);
    }
}

Position FindMax(SearchTree T)
{
    if(T != NULL)
    {
        while(T->Right != NULL)
        {
            T = T->Right;
        }
    }
    
    return T;
}

SearchTree Insert(int element, SearchTree T)
{
    if(T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
        {
            Error("out of space");
        }
        else
        {
            T->element = element;
            T->Left = T->Right = NULL;
        }
    }
    else if(element < T->element)
    {
        T->Left = Insert(element, T->Left);
    }
    else if(element > T->element)
    {
        T->Right = Insert(element, T->Right);
    }
    
    return T;
}

SearchTree Delete(int element, SearchTree T)
{
    Position tmpceil;

    if(T == NULL)
    {
        Error("element not found");
    }
    else if(element < T->element)
    {
        T->Left = Delete(element, T->Left);
    }
    else if(element > T->element)
    {
        T->Right = Delete(element, T->Right);
    }
    else if(T->Left && T->Right)
    {
        tmpceil = FindMin(T->Right);
        T->element = tmpceil->element;
        T->Right = Delete(T->element, T->Right);
    }
    else 
    {
        tmpceil = T;
        if (T->Left == NULL)
        {
            T = T->Right;
        }
        else if (T->Right = NULL)
        {
            T = T->Left;
        }
        free(tmpceil);
    }
    
    return T;
}