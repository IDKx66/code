// 青蛙跳台阶
#include <stdio.h>

int book[100];

int f(int n)
{
    if (book[n] != -1)
    {
        return book[n];
    }

    book[n] = f(n - 2) + f(n - 1); // 记忆化

    return book[n];
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        book[i] = -1;
    }

    book[0] = 0;
    book[1] = 1;
    book[2] = 2;

    int n = 0;
    scanf("%d", &n);
    int steps = f(n);
    printf("青蛙跳到第 %d 级台阶共有 %d 种跳法\n", n, steps);

    return 0;
}