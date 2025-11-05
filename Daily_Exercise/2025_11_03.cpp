#include <iostream>
using namespace std;

// class Solution
// {
// public:
//     Solution()
//     {
//         cout << "Solution()" << endl;
//     }

//     int Sum_Solution(int n)
//     {
//         cout << "Sum_solution()" << endl;
//         return n;
//     }

//     ~Solution()
//     {
//         cout << "~Solution" << endl;
//     }
// };

// int main()
// {
//     Solution s1;
//     s1.Sum_Solution(10);

//     Solution(); // 匿名对象，生命周期为当前语句，函数结束后立即销毁
//     Solution().Sum_Solution(10);

//     return 0;
// }

// class A
// {
// public:
//     A()
//     {
//         _a = 10;
//         cout << "A()" << endl;
//     }

//     ~A()
//     {
//         cout << "~A()" << endl;
//     }

// private:
//     int _a;
// };

// int main()
// {
//     // C语言        malloc和free是函数
//     int *p1 = (int *)malloc(sizeof(int));
//     int *p3 = (int *)malloc(sizeof(int) * 10);

//     free(p1);
//     free(p3);

//     // C++          new和delete是操作符
//     int *p2 = new int;
//     // int *p2 = new int(5); // 初始化
//     int *p4 = new int[10];

//     delete p2;
//     delete[] p4;

//     // malloc和new的区别：malloc只分配内存，new分配内存并调用构造函数
//     // free和delete的区别：free只释放内存，delete先调用析构函数，再释放内存

//     A *p5 = (A*)malloc(sizeof(A));
//     A *p6 = new A;

//     free(p5);
//     delete p6;

//     return 0;
// }

// struct ListNode_C
// {
//     int _val;
//     ListNode_C *_prev;
//     ListNode_C *_next;
// };

// ListNode_C *BuyListNode_C(int val)
// {
//     ListNode_C *node_c = (ListNode_C *)malloc(sizeof(ListNode_C));
//     node_c->_val = val;
//     node_c->_prev = nullptr;
//     node_c->_next = nullptr;

//     return node_c;
// }

// struct ListNode_CPP // 升级为C++类
// {
//     int _val;
//     struct ListNode_CPP *_prev; // 兼容C
//     ListNode_CPP *_next;

//     ListNode_CPP(int val = 0)
//         : _val(val), _prev(nullptr), _next(nullptr)
//     {
//     }

//     ~ListNode_CPP()
//     {
//         cout << "~ListNode_CPP" << endl;
//     }
// };

// int main()
// {
//     ListNode_C *node1 = BuyListNode_C(2);

//     ListNode_CPP *node2 = new ListNode_CPP;
//     ListNode_CPP *node3 = new ListNode_CPP(3);

//     free(node1);

//     // 析构函数的调用时机：
//     // 栈对象：在离开作用域时自动调用析构函数
//     // 堆对象：只有在使用delete时才会调用析构函数
//     // 程序结束时，操作系统只回收内存，不会调用堆对象的析构函数

//     // delete node2;
//     // delete node3;
//     return 0;
// }

class A
{
public:
    A(int a)
        :_a(a)
    {}

    A()
    {
        cout << "A()" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }

private:
    int _a;
};

int main()
{
    // 函数operator new 和 函数 operator delete

    // malloc
    // operator new -> malloc加失败抛异常
    // new -> operator new + 构造函数

    // operator delete 和 free没区别，因为释放空间失败直接终止进程，是为了与operator new成对才产生

    // A *p1 = (A *)malloc(sizeof(A));
    // A *p2 = new A;
    // A *p3 = (A *)operator new(sizeof(A));

    // size_t size = 1;
    // void *p4 = malloc(size * 1024 * 1024 * 1024 * 100); // 申请100G内存（溢出了）
    // cout << p4 << endl; // 失败返回NULL
    // void *p5 = operator new(size * 1024 * 1024 * 1024 * 100);
    // cout << p5 << endl; // 失败抛异常

    A *p1 = new A(10);
    delete p1;
    
    A *p2 = (A *)operator new(sizeof(A));
    new(p2)A(10); // 定位new/placement new

    p2->~A();
    operator delete(p2);

    return 0;
}