//栈的链式结构实现
#include<iostream>
using namespace std;
//压栈相当于头插
typedef int ElemType;

typedef struct stack{
    ElemType data;
    stack *next;
} Stack;

//初始化
Stack* initStack(){
    Stack *s = new Stack;
    s->data = 0;
    s->next = nullptr;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if(s->next == nullptr){
        cout << "栈为空" << endl;
        return 1;
    }
    else return 0;
}

//进栈（压栈）
int push(Stack *s, ElemType e){
    Stack *p = new Stack;
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1; 
}

//出栈
int pop(Stack *s, ElemType *e){
    if(s->next == nullptr){
        cout << "栈为空" << endl;
        return 0;
    }
    *e = s->next->data;
    Stack *q = s->next;
    s->next = q->next;
    delete q;
    //free(q);
    return 1;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e){
    if(s->next == 0){
        cout << "栈为空" << endl;
        return 0;
    }
    *e = s->next->data;
    return 1;
}