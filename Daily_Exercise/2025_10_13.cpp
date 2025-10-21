// 高精度加法
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     int a1[210] = {0}, a2[210] = {0}, a3[210] = {0};
//     string s1, s2;
//     cin >> s1 >> s2;

//     int len = max(s1.size(), s2.size());

//     for (int i = 0; i < (int)s1.size(); i++)
//     {
//         a1[i] = s1[s1.size() - i - 1] - '0';
//     }

//     for (int i = 0; i < (int)s2.size(); i++)
//     {
//         a2[i] = s2[s2.size() - i - 1] - '0';
//     }

//     for (int i = 0; i < len; i++)
//     {
//         a3[i] = a1[i] + a2[i];
//     }

//     for (int i = 0; i < len; i++)
//     {
//         if (a3[i] > 9)
//         {
//             a3[i + 1] += a3[i] / 10;
//             a3[i] %= 10;
//         }
//     }

//     if (a3[len] != 0)
//         len++;

//     for (int i = len - 1; i >= 0; i--)
//     {
//         cout << a3[i];
//     }

//     return 0;
// }

// 高精度减法
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     int a1[210] = {0}, a2[210] = {0}, a3[210] = {0};
//     string s1, s2;
//     cin >> s1 >> s2;
//     char flag = '+';

//     if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2))
//     {
//         swap(s1, s2);
//         flag = '-';
//     }

//     for (int i = 0; i < (int)s1.size(); i++)
//     {
//         a1[i] = s1[s1.size() - i - 1] - '0';
//     }

//     for (int i = 0; i < (int)s2.size(); i++)
//     {
//         a2[i] = s2[s2.size() - i - 1] - '0';
//     }

//     for (int i = 0; i < (int)s1.size(); i++)
//     {
//         if (a1[i] < a2[i])
//         {
//             a1[i] += 10;
//             a1[i + 1]--;
//         }

//         a3[i] = a1[i] - a2[i];
//     }

//     int index = 0;

//     for (int i = s1.size() - 1; i >= 0; i--)
//     {
//         if (a3[i] != 0)
//         {
//             index = i;
//             break;
//         }
//     }

//     if (flag == '-')
//         cout << '-';

//     for (int i = index; i >= 0; i--)
//     {
//         cout << a3[i];
//     }

//     return 0;
// }

// 高精度乘法
// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     int a1[210] = {0}, a2[210] = {0}, a3[210] = {0};
//     string s1, s2;
//     cin >> s1 >> s2;

//     for(int i = 0; i < (int)s1.size(); i++)
//     {
//         a1[i] = s1[s1.size() - i - 1] - '0';
//     }

//     for(int i = 0; i < (int)s2.size(); i++)
//     {
//         a2[i] = s2[s2.size() - i - 1] - '0';
//     }

//     for(int i = 0; i < (int)s1.size(); i++)
//     {
//         for(int j = 0; j < (int)s2.size(); j++)
//         {
//             a3[i + j] += a1[i] * a2[j];
//         }
//     }

//     for(int i = 0; i < (int)s1.size() + (int)s2.size(); i++)
//     {
//         if(a3[i] > 9)
//         {
//             a3[i + 1] += a3[i] / 10;
//             a3[i] %= 10;
//         }
//     }

//     int index = 0;
//     for(int i = (int)s1.size() + (int)s2.size() - 1; i >= 0; i--)
//     {
//         if(a3[i] != 0)
//         {
//             index = i;
//             break;
//         }
//     }

//     for(int i = index; i >= 0; i--)
//     {
//         cout << a3[i];
//     }

//     return 0;
// }

// 高精度除法
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a, b, n; // a是被除数， b是除数
    cin >> a >> b >> n;

    cout << a / b << ".";

    int tmp = a % b;

    for (int i = 0; i < n; i++)
    {
        tmp *= 10;
        cout << tmp / b;
        tmp %= b;
    }

    return 0;
}