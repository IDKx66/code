// 乒乓球
// 题目描述
// 华华通过以下方式进行分析，首先将比赛每个球的胜负列成一张表，然后分别计算在 11 分制和 21 分制下，双方的比赛结果（截至记录末尾）。

// 比如现在有这么一份记录，（其中 W 表示华华获得一分，L 表示华华对手获得一分）：

// WWWWWWWWWWWWWWWWWWWWWWLW
// 在 11 分制下，此时比赛的结果是华华第一局 11 比 0 获胜，第二局 11 比 0 获胜，正在进行第三局，当前比分 1 比 1。而在 21 分制下，此时比赛结果是华华第一局 21 比 0 获胜，正在进行第二局，比分 2 比 1。如果一局比赛刚开始，则此时比分为 0 比 0。直到分差大于或者等于 2，才一局结束。

// 注意：当一局比赛结束后，下一局立刻开始。

// 你的程序就是要对于一系列比赛信息的输入（WL 形式），输出正确的结果。
#include <cstdio>
#include <cmath>

int main()
{
    int w = 0, l = 0;
    int len = 0;
    char str[62600] = {'0'};
    char c;
    while((scanf("%c", &c) == 1 && c != 'E'))
    {
        str[len++] = c;
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'W')
            w++;
        if (str[i] == 'L')
            l++;
        if ((w >= 11 || l >= 11) && abs(w - l) >= 2)
        {
            printf("%d:%d\n", w, l);
            w = l = 0;
        }
    }

    printf("%d:%d\n", w, l);
    w = l = 0;
    printf("\n");

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'W')
            w++;
        if (str[i] == 'L')
            l++;
        if ((w >= 21 || l >= 21) && abs(w - l) >= 2)
        {
            printf("%d:%d\n", w, l);
            w = l = 0;
        }
    }

    printf("%d:%d\n", w, l);
    w = l = 0;

    return 0;
}