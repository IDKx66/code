#include<iostream>
using namespace std;

#define MAXSIZE 100

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE]; //  定义一个数组，用于存储栈中的元素
    int top; //  定义一个整型变量，用于表示栈顶的位置
} Stack;

// 初始化栈
void initStack(Stack *s){
    s->top = -1; // 将栈顶指针置为-1，表示栈为空
}

//检查栈是否为空
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
        cout << "空的" << endl;
        return 0;
    }

    *e = s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e){
    if(s->top == -1){
        cout << "空的" << endl;
        return 0;
    }

    *e = s->data[s->top];
    return 1;
}


int main(){
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    ElemType e;
    pop(&s, &e);
    cout << e << endl;
    getTop(&s, &e);
    cout << e << endl;

    return 0;
}