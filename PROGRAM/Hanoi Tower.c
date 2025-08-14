//汉诺塔问题
#include <stdio.h>

int hanoi(int n, char a, char b, char c)//A柱  B柱  C柱
{
    int steps = 0;

    if(1 == n)
    {
        printf("将盘子 %d 从 %c 移到 %c\n", n, a, c);
        return 1;
    }

    steps += hanoi(n - 1, a, c, b);
    printf("将盘子 %d 从 %c 移到 %c\n", n, a, c);
    steps++;
    steps += hanoi(n - 1, b, a, c);

    return steps;
}

int main()
{
    int n;
    printf("请输入汉诺塔的盘子数量：");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("请输入正整数！\n");
        return 1;
    }
    
    printf("移动步骤：\n");
    int count =hanoi(n, 'A', 'B', 'C');  // A是源柱，B是辅助柱，C是目标柱
    
    // 汉诺塔的最少移动次数为 2^n - 1
    // printf("最少需要 %d 步\n", (1 << n) - 1);  // 1<<n 等价于 2^n
    printf("%d\n", count);
    return 0;
}