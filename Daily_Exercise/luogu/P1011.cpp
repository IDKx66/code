// 车站     https://www.luogu.com.cn/problem/P1011
#include <iostream>
using namespace std;

int f[21], sum[21];

int main()
{
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    int ans = a;
    if (x >= 3)
    {
        ans += a;
    }

    if (x >= 4)
    {
        f[1] = f[2] = 1;
        for (int i = 3; i <= n - 4; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        for (int i = 1; i <= n - 4; i++)
        {
            sum[i] = sum[i - 1] + f[i];
        }

        int y = (m - ans - a * sum[n - 5]) / sum[n - 4];

        ans += a * sum[x - 4] + y * sum[x - 3];
    }

    cout << ans << endl;
    return 0;
}