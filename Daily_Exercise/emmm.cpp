#include <iostream>
using namespace std;
// 判断是否为回文数（反转数字方法）
bool isPalindrome(int num)
{
    if (num < 0 || (num % 10 == 0 && num / 10 != 0))
        return 0;
    int original = num;
    int reversed = 0;

    while (num > reversed)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return num == reversed || num == reversed / 10;
}

int main()
{
    int num;
    cout << "请输入一个整数: ";
    cin >> num;

    if (isPalindrome(num))
    {
        cout << num << ' ' << "是回文数" << endl;
    }
    else
    {
        cout << num << ' ' << "不是回文数" << endl;
    }

    return 0;
}
