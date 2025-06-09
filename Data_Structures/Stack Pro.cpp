//动态内存分配
#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType *data;
    int top;
} Stack;

//初始化
Stack* initStack(){
    Stack *s = new Stack;
    //Stack *s = (Stack*)malloc(sizeof(Sack));
    s->data = new ElemType[MAXSIZE];
    //s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if(s->top == -1){
        cout << "空的" << endl;
        return 1;
    }
    else return 0;
}

//进栈（压栈）
int push(Stack *s, ElemType e){
    if(s->top >= MAXSIZE - 1){
        cout << "栈满了" << endl;
        return 0;
    }

    s->top++;
    s->data[s->top] = e;
    return 1;
}

//出栈???????
int pop(Stack *s, ElemType *e){
    if(s->top == -1){
        cout << "栈为空" << endl;
        return 0;
    }

    *e = s->data[s->top];
    s->top--;
    return 1;
}


//获取栈顶元素
ElemType getTop(Stack *s, ElemType *e){
    if(s->top == -1){
        cout << "栈为空" << endl;
        return 0;
    }

    *e = s->data[s->top];
    s->top--;
    return 1;
}


int main(){
    Stack *s = initStack();
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    ElemType e;
    pop(s, &e);
    cout << e << endl;
    getTop(s, &e);
    cout << e << endl;

    return 0;
}