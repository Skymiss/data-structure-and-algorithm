#ifndef __QUEUE_H__

struct QueueRecord;
typedef struct QueueRecord *Queue;
int IsEmpty(Queue Q);
int IsFull(Queue Q);
void MakeEmpty(Queue Q);
static int Succ(int value, Queue Q);
void Enqueue(int element, Queue Q);

#endif