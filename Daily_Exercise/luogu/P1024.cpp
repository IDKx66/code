// 一元三次方程求解
// 题目描述
// 有形如：ax 
// 3
//  +bx 
// 2
//  +cx+d=0 这样的一个一元三次方程。给出该方程中各项的系数（a,b,c,d 均为实数），并约定该方程存在三个不同实根（根的范围在 −100 至 100 之间），且根与根之差的绝对值 ≥1。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后 2 位。

// 提示：记方程 f(x)=0，若存在 2 个数 x 
// 1
// ​
//   和 x 
// 2
// ​
//  ，且 x 
// 1
// ​
//  <x 
// 2
// ​
//  ，f(x 
// 1
// ​
//  )×f(x 
// 2
// ​
//  )<0，则在 (x 
// 1
// ​
//  ,x 
// 2
// ​
//  ) 之间一定有一个根。
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    for(double i = -100.00; i <= 100.00; i += 0.001)
    {
        double j = i + 0.001;
        double x1 = a * i * i * i + b * i * i + c * i + d;
        double x2 = a * j * j * j + b * j * j + c * j + d;
        
        if (x1 * x2 < 0) 
            printf("%.2lf ", (i + j) / 2);
    }
    return 0;
}