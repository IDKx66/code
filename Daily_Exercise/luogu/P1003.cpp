// 铺地毯
// 题目描述
// 为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。一共有 n 张地毯，编号从 1 到 n。
// 现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。

// 地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], g[MAXN], k[MAXN];
int main()
{
    int n = 0;
    int x, y;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }

    cin >> x >> y;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + k[i])
        {
            ans = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}