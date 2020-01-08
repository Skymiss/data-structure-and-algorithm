#ifndef __HASHTABLE_H__

typedef unsigned int Index;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef Position List;

HashTable InitializeTable(int TableSize);
Index Hash(unsigned int key, int TableSize);
Position Find(unsigned int key, HashTable H);
void Insert(unsigned int key, HashTable H);
void Delete(unsigned int key, HashTable H);

#endif