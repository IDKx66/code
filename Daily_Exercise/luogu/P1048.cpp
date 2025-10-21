// 采药 https://www.luogu.com.cn/problem/P1048 01背包
#include <iostream>
#include <algorithm>
using namespace std;

int dp[105][1005], t[105], v[105];
int T, m;

int main()
{   
    cin >> T >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> t[i] >> v[i];
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= T; j++)
        {
            if(t[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-t[i]]);
        }
    }

    cout << dp[m][T];
    return 0;
}