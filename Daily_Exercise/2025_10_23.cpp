#include <iostream>
using namespace std;

// // 类的六个默认成员函数
// // 1. 构造函数->在对象构造时调用的函数，完成初始化工作
// //    特征：函数名与类名相同，无返回值，自动调用，可以重载
// //    如果没有显式定义构造函数，编译器默认生成无参构造函数，  ps:默认构造函数是指不需要参数就能被调用的构造函数
// //    一旦用户显示定义，编译器不再生成                         自己写的无参、全缺省和编译器默认生成的
// //    1、针对内置类型的成员变量没有做处理
// //    2、针对自定义类型的成员变量，调用它的构造函数初始化
// // 2. 析构函数->对象生命周期到了后自动调动，完成对象里面的资源清理工作，不是销毁
// //    特征：函数名就是类名前加~， 无返回值，一个类只有一个析构函数，不写默认生成，生命周期结束自动调用
// // 3. 拷贝构造函数
// // 4. 赋值运算符重载
// //       运算符重载：
// //       作为类成员的重载函数时，其形参看起来比操作数数目少1，因为成员函数的操作符有一个默认的形参this，限定为第一个形参
// //       有5个运算符不能重载：
// //       .*、::、sizeof、?:、.   ps:sizeof是运算符，不是函数
// // 5. 取地址运算符重载
// // 6. const成员函数

// class Stack
// {
// public:
//     Stack(int n = 10)
//     {
//         _a = new int[n];
//         // _a = (int *)malloc(sizeof(int) * n);
//         std::cout << "new:" << _a << std::endl;
//         _size = 0;
//         _capacity = n;
//     }

//     ~Stack()
//     {
//         delete[] _a;
//         // free(_a);
//         _a = nullptr;
//         _size = _capacity = 0;
//         std::cout << "delete:" << _a << std::endl;
//     }

// private:
//     int *_a;
//     int _size;
//     int _capacity;
// };

// class Date
// {
// public:
//     Date(int year = 0, int month = 1, int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

//     // 拷贝构造
//     Date(const Date &d)
//     {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }

//     void Print()
//     {
//         cout << _year << "-" << _month << "-" << _day << endl;
//     }

//     // d1 == d2
//     // operator(&d1, d2)  这里&是取地址
//     // d1.operator==(d2)
//     bool operator==(const Date &d) // bool operator==(Date* this, const Date& d)
//     {
//         return _year == d._year      // this->_year == d._year
//                && _month == d._month // this->_month == d._month
//                && _day == d._day;    // this->_day == d._day
//     }

//     bool operator>(const Date &d)
//     {
//         if (_year > d._year)
//             return true;
//         else if (_year == d._year && _month > d._month)
//             return true;
//         else if (_year == d._year && _month == d._month && _day > d._day)
//             return true;

//         return false;
//     }

//     bool operator<(const Date& d)
//     {
//         return !(*this == d) && !(*this > d);
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// // 赋值运算符重载
// // bool operator==(const Date &d1, const Date &d2)
// // {
// //     return d1._year == d2._year
// //         && d1._month == d2._month
// //         && d1._day == d2._day;
// // }

// int main()
// {
//     Date d1(2025, 10, 23);
//     d1.Print();

//     // 这两个写法都是调用拷贝构造
//     Date d2(d1);
//     d2.Print();
//     Date d3 = d1;
//     d3.Print();

//     // d1 == d2; // 这里编译器会转换成operator==(d1, d2) ps:写在全局
//     // 但不这样写，因为可读性不好

//     d1 == d2;

//     Date d4(2025, 10, 22);
//     if (d2<d1) cout << "yes" << endl;
//     return 0;
// }

// 实现一个完整的日期类
class Date
{
public:
    int GetMonthDay(int year, int month)
    {
        static int monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
            return 29;

        return monthdays[month];
    }

    Date(int year = 0, int month = 1, int day = 1)
    {
        if (year >= 0 && month >= 1 && day >= 1 && day <= GetMonthDay(year, month))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout << "非法日期" << endl;
            _year = 0;
            _month = 1;
            _day = 1;
        }
    }

    // 拷贝构造
    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        cout << "Date(const Date &d)" << endl;
    }

    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    // 析构
    ~Date()
    {
        // Date类不涉及动态内存分配，无需特殊清理工作
    }

    bool operator<(const Date &d)
    {
        if (_year < d._year)
            return true;
        else if (_year == d._year && _month < d._month)
            return true;
        else if (_year == d._year && _month == d._month && _day < d._day)
            return true;

        return false;
    }

    bool operator==(const Date &d)
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator>(const Date &d)
    {
        return !(*this < d) && !(*this == d);

        // 建议优化，避免多次函数调用
        // if (_year > d._year)
        //     return true;
        // else if (_year == d._year && _month > d._month)
        //     return true;
        // else if (_year == d._year && _month == d._month && _day > d._day)
        //     return true;
        // return false;
    }

    bool operator!=(const Date &d)
    {
        return !(*this == d);
    }

    bool operator<=(const Date &d)
    {
        return *this < d || *this == d;
    }

    bool operator>=(const Date &d)
    {
        return *this > d || *this == d;
    }

    Date operator+(int day)
    {
        Date ret(*this); // 这里要拷贝构造，因为要返回一个对象

        if (day < 0)
        {
            return *this - (-day); // 如果是负数，转换为减法
        }
        // Date ret = *this;

        // ret._day += day;
        // while (ret._day > GetMonthDay(ret._year, ret._month))
        // {
        //     ret._day -= GetMonthDay(ret._year, ret._month);
        //     ret._month++;

        //     if (ret._month == 13)
        //     {
        //         ret._year++;
        //         ret._month = 1;
        //     }
        // }

        ret += day;

        return ret;
    }

    Date &operator+=(int day)
    {
        if (day < 0)
        {
            return *this -= (-day); // 如果是负数，转换为减法
        }

        _day += day;

        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month++;

            if (_month == 13)
            {
                _year++;
                _month = 1;
            }
        }

        return *this;
    }

    Date operator-(int day)
    {
        Date ret(*this);

        if (day < 0)
        {
            return ret + (-day); // 如果是负数，转换为加法
        }

        // ret._day -= day;
        // while (ret._day <= 0)
        // {
        //     ret._month--;
        //     if (ret._month == 0)
        //     {
        //         ret._year--;
        //         ret._month = 12;
        //     }

        //     ret._day += GetMonthDay(ret._year, ret._month);
        // }

        ret -= day;

        return ret;
    }

    Date &operator-=(int day)
    {
        if (day < 0)
        {
            return *this += (-day); // 如果是负数，转换为加法
        }

        _day -= day;

        while (_day <= 0)
        {
            _month--;
            if (_month == 0)
            {
                _year--;
                _month = 12;
            }

            _day += GetMonthDay(_year, _month);
        }

        return *this;
    }

    Date &operator=(const Date &d) // 用引用提高效率
    {
        if (this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        return *this;
    }

    // 前置++
    Date &operator++()
    {
        *this += 1;
        return *this;
    }

    // 后置++
    Date operator++(int) // 这里要传int参数，因为要区分前置++和后置++
    {
        Date tmp(*this);
        *this += 1;
        return tmp;
    }

    // 前置--
    Date &operator--()
    {
        *this -= 1;
        return *this;
    }

    // 后置--
    Date operator--(int) // 这里要传int参数，因为要区分前置++和后置++
    {
        Date tmp(*this);
        *this -= 1;
        return tmp;
    }

    int operator-(const Date& d)
    {
        Date max(*this);
        Date min(d);
        int flag = 1;

        if(max < d)
        {
            max = d;
            min = *this;
            flag = -1;
        }

        int n = 0;
        while(min != max)
        {
            ++min;
            ++n;
        }

        return n * flag;
    }

private:
    int _year;
    int _month;
    int _day;
};

// Date f1()
// {
//     static Date d;
//     cout << &d << endl;
//     return d;
// }

// Date& f2()
// {
//     static Date d;
//     cout << &d << endl;
//     return d;
// }

int main()
{
    // 自定义类型传参数和返回值时，在可以的情况下，尽量使用引用，减少拷贝
    // f1();
    // f2();
    // f1();
    // f2();

    Date d1(12313, 2, 30); // 由于日期非法，输入的日期被赋值为0，1，1
    Date d2(2025, 10, 23);
    Date d3(2025, 10, 24);

    // cout << (d3 < d2) << endl;
    // cout << (d3 > d2) << endl;
    // cout << (d3 == d2) << endl;
    // cout << (d3 != d2) << endl;
    // cout << (d3 <= d2) << endl;
    // cout << (d3 >= d2) << endl;

    Date d4 = d3 - 100000;
    d4.Print();
    d3 -= 100000;
    d3.Print();
    Date d5;
    d5 = d4;
    d5.Print();
    Date d6 = d4--;
    d4.Print();
    d6.Print();
    ++d5;
    d5.Print();

    cout << d5 - d4 << endl;
    // 浅拷贝
    // ...
    // 导致异常

    return 0;
}