//队列的链式结构
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct QueueNode{
    ElemType data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue{
    QueueNode *front;
    QueueNode *rear;
} Queue;