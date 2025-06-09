// 队列的顺序结构-动态内存分配
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *data;//存储队列元素的数组
    int front;//front指向队列的第一个元素
    int rear;//rear指向队列的最后一个元素的后一个位置
} Queue;

// 初始化队列
Queue *initQueue(Queue *Q)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));                // Queue *q = new Queue;
    q->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType)); // q->data = new ElemType[MAXSIZE];
    q->front = q->rear = 0;
    return q;
}

// 入队
void enQueue(Queue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        cout << "队列为空!" << endl;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
}

// 出队
void deQueue(Queue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        cout << "队列为空!" << endl;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
}


//获取队头元素
ElemType getHead(Queue *Q){
    if(Q->front == Q->rear){
        cout << "队列为空!" << endl;
    }
    return Q->data[Q->front];
}

//获取队列长度
int getLength(Queue *Q){
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

int main(){
    Queue *Q = initQueue(Q);
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    cout << getHead(Q) << endl;
    ElemType e;
    deQueue(Q, &e);
    cout << e << endl;
    cout << getLength(Q) << endl;
    return 0;
}