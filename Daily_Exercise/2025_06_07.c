//计算后缀表达式的值
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int top;
} Stack;

typedef enum
{
    LEFT_PARE,  //  左括号
    RIGHT_PAER, // 右括号
    ADD,        //  加法
    SUB,        //  减法
    MUL,        //  乘法
    DIV,        //  除法
    MOD,        // 取余
    EOS,        // 结束符(\0)
    NUM         // 数字
} contentType;  // 符号类型

char expr[] = "82/2+56*-"; // 表达式

// 初始化
Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    s->top = -1;
    return s;
}

// 判断栈是否为空
int isEmpty(Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// 判断栈是否已满
int isFull(Stack *s)
{
    if (s->top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

// 进栈
int push(Stack *s, ElemType e)
{
    if (s->top == MAXSIZE - 1)
    {
        printf("Stack is full!\n");
        return 0;
    }
    s->data[++s->top] = e;
    return 1;
}

// 出栈
int pop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    *e = s->data[s->top--];
    return 1;
}

// 获取栈顶元素
int getTop(Stack *s, ElemType *e)
{
    if (s->top == -1)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

contentType getContentType(char *symbol, int *index)
{
    *symbol = expr[*index];
    *index += 1;
    switch (*symbol)
    {
    case '(':
        return LEFT_PARE;
    case ')':
        return RIGHT_PAER;
    case '+':
        return ADD;
    case '-':
        return SUB;
    case '*':
        return MUL;
    case '/':
        return DIV;
    case '%':
        return MOD;
    case '\0':
        return EOS;
    default:
        return NUM;
    }
}

// 计算表达式
int eval(Stack *s)
{
    char symbol;
    int op1, op2;
    int index = 0;
    contentType token;
    token = getContentType(&symbol, &index);
    ElemType result;
    while (token != EOS)
    {
        if (token == NUM)
        {
            push(s, symbol - '0');
        }
        else
        {
            pop(s, &op2);
            pop(s, &op1);
            switch (token)
            {
            case ADD:
                push(s, op1 + op2);
                break;
            case SUB:
                push(s, op1 - op2);
                break;
            case MUL:
                push(s, op1 * op2);
                break;
            case DIV:
                push(s, op1 / op2);
                break;
            case MOD:
                push(s, op1 % op2);
                break;
            default:
                break;
            }
        }
        token = getContentType(&symbol, &index);
    }
    pop(s, &result);
    printf("result = %d\n", result);
    return result;
}

int main()
{
    Stack *s = initStack();

    eval(s);

    return 0;
}