// 装箱问题 https://www.luogu.com.cn/problem/P1049 01背包
#include <iostream>
#include <algorithm>
using namespace std;

int V, n;
int dp[32][20010], v[32];

int main()
{
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (v[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
        }
    }

    cout << V - dp[n][V];
    return 0;
}