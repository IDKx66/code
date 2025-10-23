// 数楼梯😑😑😑😑😑(这题要用高精度)
// 题目描述
// 楼梯有 N 阶，上楼可以一步上一阶，也可以一步上二阶。

// 编一个程序，计算共有多少种不同的走法。
#include <iostream>
using namespace std;

long long a[5005];

long long f(long long n)
{
    if (a[n])
        return a[n];
    else
    {
        a[n] = f(n - 1) + f(n - 2);
        return a[n];
    }
}

int main()
{
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;

    long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}