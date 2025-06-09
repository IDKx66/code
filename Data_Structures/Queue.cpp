#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} Queue; 

//初始化
void initQueue(Queue *Q){
    Q->front = 0;
    Q->rear = 0; 
}

//判断队列是否为空
int isEmpty(Queue *Q){
    if(Q->front == Q->rear){
        cout << "空的" << endl;
        return 1;
    }
    else return 0; 
}

//调整队列
int queueFull(Queue *Q){
    if(Q->front > 0){
        int step = Q->front;
        for(int i = Q->front; i <= Q->rear; i++){
            Q->data[i-step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else {
        cout << "真的满了" << endl;
        return 0;
    }
}

//入队
int enqueue(Queue *Q, ElemType e){
    if(Q->rear >= MAXSIZE){
        if(queueFull(Q) == 0){
        return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
}

//出队
ElemType dequeue(Queue *Q){
    if(Q->front == Q->rear){
        cout << "空的" << endl; 
        return 0;
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}

//获取队头
int getHead(Queue *Q, ElemType *e){
    if(Q->front == Q->rear){
        cout << "空的" << endl;
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}
int main(){ 
    Queue Q;
    initQueue(&Q);

    enqueue(&Q, 10);
    enqueue(&Q, 20);
    enqueue(&Q, 30);
    enqueue(&Q, 40);
    enqueue(&Q, 50);

    cout << dequeue(&Q) << endl;    
    cout << dequeue(&Q) << endl;

    ElemType e;
    getHead(&Q, &e);
    cout << e << endl;
    return 0;
}
