#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    // 构造
    string s1;
    string s2("hello, world!");
    string s3(s2);
    string s4(6, '6');

    string s5 = "hello, world!";
    string s6 = s5;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;

    s1 = s2;
    cout << s1 << endl;
}

void test2()
{
    string s("1234");
    s.push_back('5'); // 在末尾添加一个字符
    s.append("6");    // 在末尾添加一个字符串
    s += '1';
    s += "222";
    s += "六百六十六";
    cout << s << endl;
}

// 实现字符串转成整型
void test3()
{
    string s("123045");
    int val = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        val *= 10;
        val += s[i] - '0';
    }
    cout << val << endl;
}

void test4()
{
    string s1("hello, world!");

    // string s2(const string& str, size_t pos, size_t len = npos)
    string s2(s1, 6);               // 从下标6开始，拷贝到末尾（缺省）
    string s3(s1, 3, 12);           // 从下标3开始，拷贝12个字符（不够12个，则拷贝到末尾）
    string s4(s1, 2, string::npos); // 从下标2开始，拷贝到末尾

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

// 遍历
void test5()
{
    string s("hello,world!");

    //[]+下标
    // 写
    for (size_t i = 0; i < s.size(); i++)
    {
        s[i] += 1;
    }
    // 读
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    // 迭代器
    // 写
    string::iterator it = s.begin();
    while (it != s.end())
    {
        *it -= 1;
        ++it;
    }
    // 读
    it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // 范围for
    for (auto &ch : s)
    {
        cout << ch << " ";
    }
    cout << endl;
}

int string2int(const string &str) // string to int
{
    // const迭代器，只能读不能写
    string::const_iterator it = str.begin(); // 记得加const
    // auto it = str.begin();

    int val = 0;
    while (it != str.end())
    {
        val *= 10;
        val += (*it++) - '0';
    }

    return val;
}

// 其他迭代器
void test6()
{
    string s("hello,world");

    // 倒着遍历
    string::reverse_iterator rit = s.rbegin(); // 反向迭代器
    // auto rit = s.rbegin();

    while (rit != s.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;

    string s2("001203000");
    cout << string2int(s2) << endl;
}

void test7()
{
    string s1 = "hello, world!";
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1.empty() << endl;
    cout << s1.capacity() << endl;
    s1 += "hello, world!";
    cout << s1.capacity() << endl;

    cout << s1 << endl; // 以C++风格字符串输出(遇到'\0'也继续输出)
    cout << s1.c_str() << endl; // 以C风格字符串输出(遇到'\0'结束)

    string s2;
    s2.reserve(100); // reserve(n) 用于预先分配至少能容纳 n 个字符的内存空间
    cout << s2.capacity() << endl;

    string s3 = "hello";
    cout << "原始字符串：" << s3 << "，长度：" << s3.size() << endl; // hello，长度：5
    // 1. 缩短字符串（n < 当前长度）
    s3.resize(3);
    cout << "缩短后：" << s3 << "，长度：" << s3.size() << endl; // hel，长度：3
    // 2. 延长字符串（默认填充 '\0'，但输出时可能不显示）
    s3.resize(6);
    cout << "延长后（默认填充）：" << s3 << "，长度：" << s3.size() << endl; // hel（后面3个'\0'不显示），长度：6
    // 3. 延长字符串（指定填充字符）
    s3.resize(8, '!');
    cout << "延长后（指定填充）：" << s3 << "，长度：" << s3.size() << endl; // hel!!，长度：8（注意：原延长的'\0'被覆盖后再新增'!'）
}

void test8()
{
    // 插入
    // string& insert (size_t pos, const string& str);
    // string& insert (size_t pos, const char* s, size_t n);
    // 在下标 pos 位置插入字符串 str 或 字符串 s
    // string& insert (size_t pos, size_t n, char c);
    string s1 = "123456789";
    s1.insert(3, "hello");
    cout << s1 << endl; // 123hello456789

    // 删除
    s1.erase(3, 5); // 从下标3开始，删除5个字符
    cout << s1 << endl; // 123456789
}

void split_url(const string &url)
{
    size_t pos1 = url.find("://");
    if (pos1 != string::npos)
    {
        cout << "协议：" << url.substr(0, pos1) << endl;
        size_t pos2 = url.find("/", pos1 + 3);
        if (pos2 != string::npos)
        {
            cout << "域名：" << url.substr(pos1 + 3, pos2 - (pos1 + 3)) << endl;
            cout << "路径：" << url.substr(pos2) << endl;
        }
    }
}

void test9()
{
    string url("https://cplusplus.com/reference/string/");
    // 查找
    // size_t pos1 = url.find("://");
    // if (pos1 != string::npos)
    // {
    //     cout << "协议：" << url.substr(0, pos1) << endl;
    //     size_t pos2 = url.find("/", pos1 + 3);
    //     if (pos2 != string::npos)
    //     {
    //         cout << "域名：" << url.substr(pos1 + 3, pos2 - (pos1 + 3)) << endl;
    //         cout << "路径：" << url.substr(pos2) << endl;
    //     }
    // }
    split_url(url);
    // find的用法
    // size_t find (const string& str, size_t pos = 0) const noexcept;
    // size_t find (const char* s, size_t pos, size_t n) const; 
    // size_t find (const char* s, size_t pos = 0) const noexcept;
    // size_t find (char c, size_t pos = 0) const noexcept;

    // substr的用法
    // string substr (size_t pos = 0, size_t n = npos) const;
    // 从下标 pos 开始，拷贝 n 个字符（缺省拷贝到末尾）
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    test9();

    return 0;
}