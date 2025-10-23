// #include <iostream>
// using namespace  std;

// namespace A
// {
//     int a = 10;
//     int b = 20;
//     int c = 30;
// }

// // 全缺省
// // void fun(int a = 10, int b = 20, int c = 30)
// // {
// //     cout << a << " " << b << " " << c << endl;
// // }

// // 半缺省（从右往左缺省）
// void fun(int a, int b = 20, int c = 30)
// {
//     cout << a << " " << b << " " << c << endl;
// }
// int main()
// {
//     // fun();
//     fun(1);
//     fun(1, 2);
//     fun(1, 2, 3);

//     return 0;
// }
// #include <iostream>
// #include "./add"
// int main()
// {
//     std::cout << Add(10, 20) << std::endl;
//     int a = Add(18, 29);
//     std::cout << Add(10.0, 20.0) << std::endl;
//     // std::cout << Add('a','b') << std::endl;
//     // std::cout << Add(10, 20) << std::endl;//     std::cout << Add(10.0, 20.0) << std::endl;
//     return 0;
// }
#include <iostream>
void Test(int a = 2, int b = 9)
{
    std::cout << a + b;
}
#include "./add"
int main()
{
    // test();

    Test();
    return 0;
}