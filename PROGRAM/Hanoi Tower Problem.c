// 汉诺塔问题
#include <stdio.h>

int hanoi(int n, char a, char b, char c) // A柱  B柱  C柱
{
    int steps = 0;

    if (1 == n)
    {
        printf("将盘子 %d 从 %c 移到 %c\n", n, a, c);
        return 1;
    }

    // 步骤1：将n-1个盘子从a移到b，累加步数
    steps += hanoi(n - 1, a, c, b);

    // 步骤2：移动第n个盘子，计1步
    printf("将盘子 %d 从 %c 移到 %c\n", n, a, c);
    steps++;

    // 步骤3：将n-1个盘子从b移到c，累加步数
    steps += hanoi(n - 1, b, a, c);

    return steps;
}

int main()
{
    int n = 0;
    printf("请输入汉诺塔的盘子数量:");
    scanf("%d", &n);

    printf("移动步骤：\n");
    int count = hanoi(n, 'A', 'B', 'C'); // A是源柱，B是辅助柱，C是目标柱

    // 汉诺塔的最少移动次数为 2^n - 1
    // printf("最少需要 %d 步\n", (1 << n) - 1);  // 1<<n 等价于 2^n
    printf("%d\n", count);
    return 0;
}