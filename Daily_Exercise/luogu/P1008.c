// 三连击
// 题目描述
// 将 1,2,…,9 共 9 个数分成 3 组，分别组成 3 个三位数，且使这 3 个三位数构成 1:2:3 的比例，试求出所有满足条件的 3 个三位数。
#include <stdio.h>
#include <string.h>

int book[10];

// 拆分并检查是否符合条件
int cf(int a, int b, int c)
{
    memset(book, 0, sizeof(book));

    book[a / 100]++;
    book[a % 100 / 10]++;
    book[a % 10]++;
    book[b / 100]++;
    book[b % 100 / 10]++;
    book[b % 10]++;
    book[c / 100]++;
    book[c % 100 / 10]++;
    book[c % 10]++;

    if (book[0] != 0)
        return 0;

    for (int i = 1; i <= 9; i++)
    {
        if (book[i] != 1)
            return 0;
    }

    return 1;
}

int main()
{
    int a, b, c;
    for (a = 123; a <= 329; a++)
    {
        b = 2 * a;
        c = 3 * a;
        if (cf(a, b, c))
            printf("%d %d %d\n", a, b, c);
    }
    return 0;
}