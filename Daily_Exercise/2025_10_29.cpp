#include <iostream>
using namespace std;

// 有几类必须用初始化列表
// 1. 没有默认构造函数的类类型成员变量
// 2. 引用成员变量
// 3. const成员变量

// class Date
// {
// public:
//     // 函数体内赋值
//     // Date(int year = 0, int month = 0, int day = 1)
//     // {
//     //     _year = year;
//     //     _month = month;
//     //     _day = day;
//     // }

//     // 初始化列表
//     // Date(int year, int month, int day) : _year(year), _month(month), _day(day) {}

//     // explicit Date(int year = 0, int month = 1, int day = 1) // 禁止隐式类型转换
//     Date(int year = 0, int month = 1, int day = 1)
//         : _year(year), _month(month), _day(day)
//     {
//         cout << "Date(int year, int month, int day)" << endl;
//     }

//     Date(const Date &d)
//     {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//         cout << "Date(const Date& d)" << endl;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// class A
// {
// public:
//     A(int a)
//     {
//         _a = a;
//     }

// private:
//     int _a;
// };

// class B
// {
// public:
//     B(int a, int ref, const int nn)
//         : _aobj(a), _ref(ref), _n(nn)
//     {
//         _x = 10;
//     }

// private:
//     A _aobj;
//     int &_ref;
//     const int _n;
//     int _x;

//     // 成员变量在类中声明次序，就是初始化列表中的初始化次序，与其在初始化列表中的次序无关
// };

// class C
// {
// public:
//     C()
//     {
//         ++n;
//     }

//     C(const C &c)
//     {
//         ++n;
//     }

//     static int GetN() // 静态成员函数没有this指针
//     {
//         return n;
//     }

//     // static成员
//     // 1.static成员变量不存在对象中，存在静态区，属于这个类的所有对象，也属于这个类
//     // 2.static成员函数没有this指针，不使用对象就可以调用。 类名::func();
//     // 3. static成员函数只能访问静态成员变量和静态成员函数，，不能访问非静态成员变量和非静态成员函数

// private:
//     static int n;
// };

// int C::n = 0;

// // C f1(C c)
// // C &f1(C c)
// // C f1(C& c)
// C &f1(C &c)
// {
//     return c;
// }

// class D
// {
// public:
//     D(int d = 0)
//         :_d(d)
//     {

//     }

//     int _d;
// };

// class E
// {
// public:
//     void Print()
//     {
//         cout << a << endl;
//         cout << d._d << endl;
//         cout << p << endl;
//     }
// private:
//     //非静态成员变量，可以在成员声明时给缺省值
//     int a = 10;
//     D d = 20;
//     int* p = (int*)malloc(4);

//     static int n;
// };

// int E::n = 0;
// int main()
// {
//     // B b(1, 2, 9);

//     // Date d1(2); // 直接构造函数
//     // Date d2 = 2; // 涉及隐式类型转换，构造出tmp(2),再用tmp拷贝构造d2(tmp),最后优化成直接构造
//     // // const Date& d2 = 3;
//     // Date d3 = d1; // 拷贝构造函数
//     // Date d4(d1); // 拷贝构造函数
//     // Date d5 = {1, 2, 3}; // 隐式类型转换，c++11开始支持

//     // int i = 1;
//     // const double& k = i;

//     C c1;
//     C c2;
//     f1(c1);
//     cout << C::GetN() << endl;
//     cout << c1.GetN() << endl;
//     cout << c2.GetN() << endl;

//     return 0;
// }

// 友元函数
// 1. 友元函数不是类的成员函数，但是可以访问类的私有成员
// 2. 友元函数不能用const修饰
// 3. 友元函数可以在类定义的任何地方声明，不受成员函数的访问权限的限制
// 4.一个函数可以是多个类的友元函数
// 5.友元函数的调用和普通函数的调用和原理相同
class Date
{
public:
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);

    Date(int year = 0, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day)
    {
    }

private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << "/" << d._month << "/" << d._day;
    return out;
}

istream& operator>>(istream& in, Date& d) // 不能加const，因为要修改对象
{
    in >> d._year >> d._month >> d._day;
    return in;
}

int main()
{
    Date d;
    cin >> d;
    cout << d << endl;
}

//友元类
// 1. 友元类的所有成员函数都可以访问对方类的私有成员
// 2. 友元关系是单向的，不具有交换性
// 3. 友元关系不具有传递性
// ...