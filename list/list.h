#ifndef __LIST_H__

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L, Position P);
Position Find(int element, List L);
void Delete(int element, List L);
Position FindPrevious(int element, List L);
void Insert(int element, Position P, List L);
void DeleteList(List L);
void PrintList(List L);

#endif
