#ifndef __STACK_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
void MakeEmpty(Stack S);
Stack CreateStack(void);
void Push(int element, Stack S);
void Pop(Stack S);
int Top(Stack S);

#endif