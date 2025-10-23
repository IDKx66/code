#include <iostream>

// 类
// 成员变量和成员函数
// c++中class和struct都可以用来定义类，class的默认访问限定符是private，struct默认是public

// 类的六个默认成员函数
// 1. 构造函数->在对象构造时调用的函数，完成初始化工作
//    特征：函数名与类名相同，无返回值，自动调用，可以重载
//    如果没有显式定义构造函数，编译器默认生成无参构造函数，  ps:默认构造函数是指不需要参数就能被调用的构造函数
//    一旦用户显示定义，编译器不再生成                         自己写的无参、全缺省和编译器默认生成的
//    1、针对内置类型的成员变量没有做处理
//    2、针对自定义类型的成员变量，调用它的构造函数初始化
// 2. 析构函数->对象生命周期到了后自动调动，完成对象里面的资源清理工作，不是销毁
//    特征：函数名就是类名前加~， 无返回值，一个类只有一个析构函数，不写默认生成，生命周期结束自动调用
// 3. 拷贝构造函数
// 4. 赋值运算符重载
// 5. 取地址运算符重载
// 6. const成员函数

class Student
{
public:
    int _age;
    int _score;
    // void show()
    // {
    //     std::cout << "_age:" << _age << std::endl;
    //     std::cout << "_score:" << _score << std::endl;
    // }
    void show();
};

void Student::show()
{
    std::cout << "_age:" << _age << std::endl;
    std::cout << "_score:" << _score << std::endl;
}

class A
{
public:
    void PrintA()
    {
        std::cout << _a << std::endl;
    }

    void Print()
    {
        std::cout << "Print()" << std::endl;
    }

private:
    int _a;
};

// class Time
// {
// public:
//     Time()
//     {
//         _hour = 0;
//         _minute = 0;
//         _second = 0;
//     }

// private:
//     int _hour;
//     int _minute;
//     int _second;
// };

// class Date
// {
// public:
//     // 隐含的this指针(存在栈上)
//     // this指针指向调用成员函数的对象
//     void Init(int year, int month, int day) // void Init(Date* this, int year, int month, int day)
//     {
//         _year = year;   // this->_year = year;
//         _month = month; // this->_month = month;
//         _day = day;     // this->_day = day;
//     }

//     // Date(int year, int month, int day) // 构造函数
//     // {
//     //     _year = year;
//     //     _month = month;
//     //     _day = day;
//     // }

//     // Date()
//     // {
//     //     _year = 0;
//     //     _month = 1;
//     //     _day = 1;
//     // }

//     // 更好的方式->全缺省
//     Date(int year = 0, int month = 1, int day = 1)
//     {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

//     void Print()
//     {
//         std::cout << _year << "-" << _month << "-" << _day << std::endl;
//     }
//     // void Print(Date *this)
//     // {
//     //     std::cout << this->_year << "-" << this->_month << "-" << this->_day << std::endl;
//     // }

// private:
//     // 基本类型（内置类型）
//     int _year;
//     int _month;
//     int _day;

//     // 自定义类型
//     // Time _t;
// };

class Date
{
public:
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // 析构函数
    ~Date()
    {
        std::cout << "~Date()" << std::endl;
    }

    void Print()
    {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

class Stack
{
public:
    Stack(int n = 10)
    {
        _a = new int[n];
        // _a = (int *)malloc(sizeof(int) * n);
        std::cout << "new:" << _a << std::endl;
        _size = 0;
        _capacity = n;
    }

    ~Stack()
    {
        delete[] _a;
        // free(_a);
        _a = nullptr;
        std::cout << "delete:" << _a << std::endl;
    }

private:
    int *_a;
    int _size;
    int _capacity;
};
int main()
{
    // 类实例化对象
    // Student s1;
    // s1._age = 18;
    // s1._score = 100;
    // s1.show();

    // Date d1;
    // d1.Init(2025, 10, 22); // d1.Init(&d1, 2025, 10, 22);
    // d1.Print(); // d1.Print(&d1);

    // A* p = nullptr; // p->PrintA(p)
    // // p->PrintA(); // 崩溃
    // p->Print(); // 正常运行

    // A a;
    // a.PrintA(); // a.PrintA(&a)

    // 对象实例化时自动调用
    // Date d1(2025, 10, 22);
    // d1.Print();

    // Date d2; // 不能加括号
    // d2.Print();

    Stack s1;
    Stack s2;
    return 0;
}