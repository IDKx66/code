// https://www.luogu.com.cn/problem/P1015  (高精度，进制)
#include <iostream>
using namespace std;
   
// 判断是不是回文数
bool isPalindrome(int num)  
{
    if (num < 0 || (num != 0 && num / 10 == 0))
        return false;
    // int original = num;
    int reversed = 0;

    while (num > reversed)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return num == reversed || num == reversed / 10;
}

//处理
int deal(int num)
{
    int original = num;
    int reversed = 0;
    while(num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original + reversed;
}

int main()
{
    int steps = 0;
    int n, m;
    cin >> n >> m;
    int i = 0;

    for(i = 0; i < 30; i++)
    {
        m = deal(m);
        steps++;
        if(isPalindrome(m))
        {
            cout << "STEP=" << steps << endl;
            break;
        }
    }

    if(i == 30) cout << "Impossible!" << endl;

    return 0;
}