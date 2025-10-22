#include <iostream>
#include <ctime>
using namespace std;

// 引用

// void Swap(int& a, int& b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// int& add(int a, int b)
// {
//     static int c = 0;
//     c = a + b;
//     return c;
// }

// struct A
// {
//     int a[10000];
// };

// void test1(A a) {}

// void test2(A &a) {}

// // 内联函数(加inline)
// int main()
// {
//     // int x = 1, y = 2;
//     // Swap(x, y);

//     // int& ret = add(2, 4);
//     // cout << ret;
//     // printf("\n");
//     // cout << ret << endl;
//     // add(1, 3);
//     // cout << ret << endl;

//     A a;
//     size_t begin1 = clock();
//     for (int i = 0; i < 1000000; ++i)
//         test1(a); // 以值作为函数参数
//     size_t end1 = clock();
//     cout << "test1:" << end1 - begin1 << endl;

//     size_t begin2 = clock();
//     for (int i = 0; i < 1000000; ++i)
//         test2(a); // 以引用作为函数参数
//     size_t end2 = clock();
//     cout << "test2:" << end2 - begin2 << endl;

//     return 0;
// }

// auto不能推导的场景
//  1.auto不能作为函数的参数
//  2.auto不能直接用来声明数组
//  int main()
//  {
//      int a = 0;
//      auto b = a; // b是根据a的类型自动推导出来的
//      auto &c = a;
//      auto *d = &a;
//      auto e = &a;

//     cout << typeid(a).name() << endl;
//     cout << typeid(b).name() << endl;
//     cout << typeid(c).name() << endl;
//     cout << typeid(d).name() << endl;
//     cout << typeid(e).name() << endl;

//     return 0;
// }

// 范围for(语法糖)
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    for (auto &e : a) // 要加引用
    {
        e *= 2;
    }
    for (auto e : a)
    {
        cout << e << " ";
    }
    return 0;
}