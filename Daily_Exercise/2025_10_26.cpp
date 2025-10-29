#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    void Print() const // -> void Print(const Date* this)
    {
        cout << _year << "-" << _month << "-" << _day << endl;
        // 不能修改对象成员，因为被const保护
    }

    void f1()
    {
        f2();
    }

    void f2() const
    {
    }

    void f3()
    {
    }

    void f4()
    {
        f3();
    }
    // f1能调用f2, f4不能调用f3

    // 取地址运算符重载    一般不写
    Date *operator&() // 普通对象
    {
        cout << "operator&()" << endl;
        return this;
    }

    const Date *operator&() const // const对象
    {
        cout << "operator&() const" << endl;
        return this;
    }

private:
    int _year;
    int _month;
    int _day;
};

void f(const Date &d)
{
    d.Print();
}

int main()
{
    // Date d1;
    // f(d1);
    // d1.Print();

    // d1.f1();
    // d1.f4();

    Date d1;
    Date d2;
    const Date d3;

    cout << &d1 << endl;
    cout << &d2 << endl;
    cout << &d3 << endl;

    return 0;
}