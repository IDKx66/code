#include <iostream>
using namespace std;

// 泛型编程
// 函数模板
template <class T> // 基本没区别，这个用的多，其中T是类型参数
// template<typename T>

void Swap(T &x1, T &x2)
{
    T x = x1;
    x1 = x2;
    x2 = x;
}

// 类模板
template <class T>
class Stack
{
public:
    Stack()
    {
        _a = new T[10];
        _size = 0;
    }
    
private:
    T *_a;
    int _size;
    int _capacity;
};

int main()
{
    char a = 'a', b = 'b';
    Swap(a, b); //调用的是Swap实例化后的函数

    Stack<int> s1;
    Stack<double> s2;

    return 0;
}