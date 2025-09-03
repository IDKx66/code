#include <stdio.h>
// 判断一个数的二进制中有多少个1，其中负数用补码表示

// int count_num_of_1(int n)
// int count_num_of_1(unsigned int n)

// {
//     int count = 0;
//     while (n)
//     {
//         if (n % 2 == 1)
//         {
//             count++;
//         }
//         n /= 2;
//     }
//     return count;
// }

// int count_num_of_1(int n)
// {
//     int count = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         if (((n >> i) & 1) == 1)
//         {
//             count++;
//         }
//     }
//     return count;
// }

int count_num_of_1(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);  // 这个操作会消除n中最右边的1
        count++;
    }
    return count;
}

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     printf("%d\n", count_num_of_1(n));
//     return 0;
// }

// 两个数的二进制表达中有多少个位（bit）不同
int count_diff__bit(int m, int n)
{
    int count = 0;
    int ret = m ^ n;
    while(ret)
    {
        ret = ret & (ret-1);
        count++;
    }
    return count;
}

int main()
{
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    printf("%d\n", count_diff__bit(m, n));
    return 0;
}