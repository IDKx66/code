#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
// #include <iostream>

// // 枚举类型
// enum Color
// {
//     RED = 2,
//     GREEN = 8,
//     BLUE
// };

// int main()
// {
// enum Color color;
// scanf("%d", &color);
// switch (color)
// {
// case RED:
//     printf("The color is red.\n");
//     break;
// case GREEN:
//     printf("The color is green.\n");
//     break;
// case BLUE:
//     printf("The color is blue.\n");
//     break;
// default:
//     printf("Unknown color.\n");
// }

// printf("%d\n", RED);
// printf("%d\n", GREEN);
// printf("%d\n", BLUE);

// char arr1[] = "abcdef";//7
// printf("%s\n", arr1);
// printf("%s\n", arr1 + 1);

// char arr2[] = {'a', 'b', 'c', 'd', 'e', 'f'};//6   少了个'\0'
// printf("%s\n", arr2);
// printf("%s\n", arr2 + 1);

// printf("strlen(arr1) = %zu\n", strlen(arr1));
// printf("strlen(arr2) = %zu\n", strlen(arr2));//strlen()函数也是要遇到'\0'才会停下

// printf("\\0\n");
// printf("\\n");

// printf("abc\0def");
// printf("??)\n");
// printf("%c\n", '\'');
// printf("\"\n");
// printf("%s\n", "abcdef");
// printf("abc\\0def\n");
// printf("\a");
// printf("%c\n", '\130');//八进制
// printf("%c\n", '\x63');//十六进制

// printf("%zu\n", strlen("c:\test\628\test.c"));

// sizeof是操作符，单目操作符

// int a = 3.14;
// printf("%d\n", a);
// std::cout << a << std::endl;

// typedef   类型重命名
// typedef unsigned int uint_32

//     return 0;
// }

// static
// 修饰局部变量
// 修饰全局变量
// 修饰函数
// #include <stdio.h>

// void test()
// {
//     static int a = 1;
//     a++;
//     printf("%d ", a);
// }

// int main()
// {
//     int i = 0;
//     while (i < 10)
//     {
//         test();
//         i++;
//     }

//     return 0;
// }

// 1.static修饰局部变量时，局部变量出了作用域不销毁。本质上，static修饰
//   局部变量的时候，改变了变量的存储位置。
// 2.static修饰全局变量时，这个全局变量的外部链接属性就变成了内部链接属性，
//   其他源文件(.c)就不能再使用这个全局变量了。
// 3.static修饰函数时，同2

// #include <stdio.h>

// int main()
// {
//     //register
//     //寄存器变量
//     register int num = 3;//建议：3放在寄存器中
//     return 0;
// }

// #define定义标识符常量(define不是关键字，是预处理指令)
// #define MAX 100

// #define定义宏(有参数)
// #define ADD(x, y) ((x) + (y))

// int main()
// {
//     printf("%d\n", ADD(21, 22));
//     printf("%x\n", 255);//16进制
//     return 0;
// }

// int main()
// {
//     // int a = 10;
//     // printf("%p\n", &a);
//     // int *p = &a;

//     // printf("%zu\n", sizeof(char *));
//     // printf("%zu\n", sizeof(short *));
//     // printf("%zu\n", sizeof(int *));
//     // printf("%zu\n", sizeof(double *));
//     // printf("%zu\n", sizeof(float *));

//     int *p1, p2, p3;
//     printf("%zu\n", sizeof(p1));
//     printf("%zu\n", sizeof(p2));
//     printf("%zu\n", sizeof(p3));

//     return 0;
// }

// 结构体
// 学生
// #include <windows.h>
//  struct Stu
//  {   //成员
//      char name[20];
//      int age;
//      char sex[5];
//      char id[20];
//  };

// void print(struct Stu *ps)
// {
//     printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);
//     //->
//     //结构体指针变量->变量名
//     printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->id);

// }
// int main()
// {
//     SetConsoleCP(65001);
//     struct Stu s = {"张三", 18, "男", "123456789"};

//     //结构体对象.成员名
//     // printf("%s %d %s %s\n", s.name, s.age, s.sex, s.id);

//     print(&s);

//     scanf("%s", s.name);//为什么这样输入中文却会乱码？？？
//     print(&s);
//     return 0;
// }
// int main()
// {
//     // system("chcp 65001");
//     char test[100] = "李四";
//     printf("%s\n", test);
//     scanf("%s", test);
//     printf("%s\n", test);
//     return 0;

// }

// int main()
// {
//     int day = 0;
//     scanf("%d", &day);

// switch (day)
// {
// case 1:
//     printf("星期一\n");
//     break;
// case 2:
//     printf("星期二\n");
//     break;
// case 3:
//     printf("星期三\n");
//     break;
// case 4:
//     printf("星期四\n");
//     break;
// case 5:
//     printf("星期五\n");
//     break;
// case 6:
//     printf("星期六\n");
//     break;
// case 7:
//     printf("星期日\n");
//     break;
// default:              //switch语句中的default子句可以放在任意位置
//     printf("输入有误\n");
//     break;
// }

// switch (day)
// {
// case 1:
// case 2:
// case 3:
// case 4:
// case 5:
//     printf("weekday\n");
//     break;
// case 6:
// case 7:
//     printf("weekend\n");
//     break;
// default:
//     printf("输入有误\n");
//     break;
// }

// return 0;
// }

// int main()
// {
//     int i = 1;
//     while (i <= 10)
//     {
//         // if (5 == i)
//         //     break;

//         if (5 == i)
//             continue;//1234死循环(continue在for循环中是跳到调整部分所以不会死循环)

//         printf("%d\n", i);
//         i++;
//     }

//     return 0;
// }

// int main()
// {
//     // int ch = getchar();
//     // printf("%c\n", ch);
//     // putchar(ch);

//     // int ch = 0;
//     // while ((ch = getchar()) != EOF)
//     // {
//     //     putchar(ch);
//     // }

//     // char password[20] = { 0 };
//     // printf("请输入密码:");
//     // scanf("%s", password);
//     // printf("请确认密码(Y/N):");

//     // int ret = getchar();
//     // if ('Y' == ret) printf("YES\n");
//     // else printf("NO");//由于没有清除缓冲区里的\n会直接输出NO

//     // char password[20] = { 0 };
//     // printf("请输入密码:");
//     // scanf("%s", password);
//     // printf("请确认密码(Y/N):");
//     // // getchar();//读取了\n
//     // int ch = 0;
//     // while((ch = getchar()) != '\n')
//     // {
//     //     ;
//     // }
//     // int ret = getchar();
//     // if ('Y' == ret) printf("YES\n");
//     // else printf("NO");

//     printf("printf(\"Hello, World!\\n\")\n");
//     printf("cout << \"Hello, World!\" << endl\n");

//     return 0;
// }

// int main()
// { // for循环的判断部分省略意味着判断恒成立
//     for (;;)
//     {
//         printf("hehe\n");
//     }

//     // do
//     // {
//     //     /* code */
//     // } while (condition);//分号不能忘

// }

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int k = 7;
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int left = 0;
//     int right = sz - 1;

//     while (left <= right)
//     {
//         //int mid = (left + right) / 2;
//         int mid = left + (right - left) / 2;

//         if (arr[mid] < k)
//             left = mid + 1;
//         else if (arr[mid] > k)
//             right = mid - 1;
//         else
//         {

//             printf("找到了, 下标是%d\n", mid);
//             break;
//         }
//     }

//     if (left > right)
//         printf("没找到\n");

//     return 0;
// }

// #include <windows.h>
// #include <stdlib.h>
// int main()
// {
//     char arr1[] = "welcome to China!!!";
//     char arr2[] = "###################";

//     int left = 0;
//     int right = strlen(arr1) - 1;
//     //int right = sizeof(arr1) / sizeof(arr1[0]) - 2;

//     while(left <= right)
//     {
//         arr2[left] = arr1[left];
//         arr2[right] = arr1[right];
//         printf("%s\n", arr2);
//         // printf("\a");
//         Sleep(1000);//单位是毫秒

//         //清空屏幕
//         system("cls");//system是一个库函数，可以执行系统命令//在vs2022用有效果
//         left++;
//         right--;
//     }

//     printf("%s\n", arr2);

//     return 0;
// }

// int main()
// {
//     int i = 0;
//     // 假设密码是abcdef
//     char password[20] = {0};
//     for (i = 0; i < 3; i++)
//     {
//         printf("请输入密码:");
//         scanf("%s", password);
//         // if (password == "abcdef")###错误###，比较两个字符串是否相等不能用==，得用库函数strcmp
//         //                                                    如果返回值是0，表示两个字符串相等
//         if (strcmp(password, "abcdef") == 0)
//         {
//             printf("登陆成功\n");
//             break;
//         }
//         else printf("密码错误\n");
//     }

//     if (3 == i)
//         printf("三次密码均输入错误,退出程序\n");
// }

// void menu()
// {
//     printf("**************************\n");
//     printf("********  1.paly  ********\n");
//     printf("********  0.exit  ********\n");
//     printf("**************************\n");
// }

// void game()
// {
//     int guess = 0;

//     //1.生成随机数(0~RAND_MAX(32767))
//     int ret = rand() % 100 + 1;
//     // printf("%d\n", ret);
//     printf("请猜数字:>");
//     scanf("%d", &guess);

//     while (1)
//     {
//         if (guess > ret)
//         {
//             printf("大了\n");
//             printf("请猜数字:>");
//             scanf("%d", &guess);
//         }
//         else if (guess < ret)
//         {
//             printf("小了\n");
//             printf("请猜数字:>");
//             scanf("%d", &guess);
//         }
//         else
//         {
//             printf("恭喜你猜对了！\n");
//             break;
//         }
//     }
// }

// int main()
// {
//     srand((unsigned int)time(NULL));

//     int input = 0;
//     do
//     {
//         menu();
//         printf("请选择:>");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:
//         game();
//             printf("猜数字\n");
//             break;
//         case 0:
//             printf("退出游戏\n");
//             break;
//         default:
//             printf("选择错误, 重新选择\n");
//             break;
//         }
//     } while (input);

//     return 0;
// }

// int main()
// {
//     char input[20] = {0};
//     system("shutdown -s -t 120");
// again:
//     printf("请注意,你的电脑将在60s内关机。输入我是猪,就取消关机\n");
//     scanf("%s", input);
//     if (strcmp(input, "我是猪") == 0)
//     {
//         system("shutdown -a");
//     }
//     else
//     {
//         goto again;
//     }

//     return 0;
// }

// 形参arr看似是数组，本质是指针变量
//  int test(int arr[])
//  {
//      int sz = sizeof(arr) / sizeof(arr[0]);
//      return sz;
//  }
// 这个错误提示
//'sizeof' on array function parameter 'arr' will return size of 'int*'
// 是因为在 函数参数中使用 sizeof(arr) 时，数组会被隐式转换为指针（即 “数组退
// 化”），导致 sizeof 计算的是指针的大小，而不是数组实际元素个数。

// int main()
// {
// char arr1[20] = {0};
// char arr2[20] = "hello, world";
// strcpy(arr1, arr2);

// printf("%s\n", arr1);

// char arr[20] = "hello world";
// memset(arr, 'x', 6);
// //memset(arr + 1, 'x', 6);
// printf("%s\n", arr);

// 值传递址传递
// 当实参传递给形参时，形参是实参的一份临时拷贝
// 对形参的修改不会影响实参

//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int sz = test(arr);
//     printf("%d\n", sz);

//     printf("%d\n", sizeof(bool));

//     return 0;
// }

// void Add(int *p)
// {
//     (*p)++;
// }

// int main()
// {
//     int num = 0;
//     Add(&num);
//     printf("%d\n", num);
//     Add(&num);
//     printf("%d\n", num);

//     return 0;
// }

// 函数不写返回值时，默认返回类型是int
//  Add(int x, int y)
//  {
//      return x + y;
//  }

// #include "add.h"
// int main()
// {
// 链式访问(把一个函数的返回值作为另一个函数的参数)
// printf("%d\n", strlen("abcdef)"));

// printf的返回值是字符的个数
//     printf("%d", printf("%d", printf("%d", 43)));//打印出4321

//     printf("\n%d\n", Add(10, 20));
//     printf("69\n");
//     return 0;
// }

// main函数有三个参数
// int main(int argc, char *argv[], char *envp[])
// {
//     return 0;
// }

// 递归
//  void print(unsigned int n)//从高到低依次打印
//  {
//      if (n > 9)
//      {
//          print(n / 10);
//      }

//     printf("%u ", n % 10);
// }

// int main()
// {
//     int num = 1000;
//     print(num);

//     return 0;
// }

// 非递归与递归写求字符串长度
// int my_strlen(char *str)
// {
//     int count = 0;
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }

// int my_strlen(char *str)
// {
//     if (*str != '\0')
//     {
//         return 1 + my_strlen(str + 1);
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     char arr[] = "abc d ][]";
//     int len = my_strlen(arr);
//     printf("%d\n", len);

//     return 0;
// }

// 斐波那契数列(迭代)
// int fib(int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 1;

//     while (n > 2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }

//     return c;
// }
// int main()
// {
//     int n = 0;
//     while (1)
//     {
//         scanf("%d", &n);
//         if (0 == n)
//             break;
//         printf("%d\n", fib(n));
//     }
//     return 0;
// }

// 辗转相除法求最大公约数(递归版本)
// int gcd(int a, int b)
// {
//     // 如果b为0，则最大公约数是a
//     if (b == 0)
//         return a;
//     // 否则，递归调用gcd(b, a % b)
//     return gcd(b, a % b);
// }

// 辗转相除法求最大公约数（迭代版本）
// int gcd(int a, int b)
// {
//     int temp;
//     while (b != 0)
//     {
//         temp = a % b;
//         a = b;
//         b = temp;
//     }
//     return a;
// }

// int main()
// {
//     int n = gcd(12,15);
//     printf("%d\n", n);
//     return 0;
// }

// 计算1/1-1/2+1/3-···+1/99-1/100
//  int main()
//  {
//      int i = 0;
//      double sum = 0.0;
//      int flag = 1;
//      for (i = 1; i <= 100; i++)
//      {
//          sum += flag * 1.0 / i;
//          flag = -flag;
//      }
//      printf("%lf\n", sum);
//  }

// 打印九九乘法表
//  int main()
//  {
//      int i = 0;
//      int j = 0;
//      for (i = 1; i <= 9; i++)
//      {
//          for (j = 1; j <= i; j++)
//          {
//              printf("%d*%d=%d\t", j, i, i * j);
//          }
//          printf("\n");
//      }
//      return 0;
//  }

// int main()
// {
// //     //下面的代码只能在支持C99标准的编译器上编译
// //     int n = 0;
// //     scanf("%d", &n);
// //     int arr[n]; //这种数组不能初始化

// //     //在C99标准之前，数组的大小必须是常量或者常量表达式
// //     //在C99标准之后，数组的大小可以是变量，为了支持变长数组
//     return 0;
// }

// 二维数组(可以理解为：一维数组的是数组)
//  int main()
//  {
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6
// int arr[3][4] = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};

// int arr[3][4] = {{1, 2}, {3, 4}, {5, 6}};

// int arr[][4] = {{1, 2, 3, 4}, {2, 3}};
// int arr[][4] = {1, 2, 3, 4, 5, 6};
// 只能省略行不能省略列

// int arr[3][4] = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};

// for (int i = 0; i < 3; i++)
// {
//     for (int j = 0; j < 4; j++)
//     {
//         printf("%d ", arr[i][j]);
//     }
//     printf("\n");
// }

// for (int i = 0; i < 3; i++)
// {
//     for (int j = 0; j < 4; j++)
//     {
//         printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//     }
// }

// printf("%d", arr[3][4]);
// 越界但是不一定报错，需要自己检查
//     return 0;
// }

// 二维数组的越界
//  int main()
//  {
//      int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//      for(int i = 0; i < 3; i++)
//      {
//          for(int j = 0; j <= 4;j++)
//          {
//              printf("%d ", arr[i][j]);
//          }
//      }
//      return 0;
//  }

// 数组传参的时候，形参有2种写法
// 1.数组
// 2.指针
// void bubble_sort(int arr[], int sz)
// void bubble_sort(int *arr, int sz)
// {
// 冒泡排序
//     int i = 0;
//     int j = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         for (j = 0; j < sz - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// int main()
// {
//     int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, sz);
//     for(int i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 数组名确实能表示首元素的地址
// 但是有2个例外：
// 1.sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组
//   的大小，单位是字节
// 2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
// int main()
// {
//     int arr[10] = {0};
//     printf("%p\n", arr);
//     printf("%p\n", arr + 1);
//     printf("---------------\n");
//     printf("%p\n", &arr[0]);
//     printf("%p\n", &arr[0] + 1);
//     printf("---------------\n");
//     printf("%p\n", &arr);
//     printf("%p\n", &arr + 1);

//     return 0;
// }

// 二维数组的数组名的理解
// int main()
// {
//     int arr[3][4] = {0};

//     printf("%d\n", sizeof(arr) / sizeof(arr[0]));       // 行的大小
//     printf("%d\n", sizeof(arr[0]) / sizeof(arr[0][0])); // 列的大小

// int sz = sizeof(arr);
// printf("%d\n", sz);

// printf("%p\n", arr);
// printf("%p\n", arr + 1);

// return 0;
// }

// 递归逆序字符串
// void reverse_string1(char *str)
// {
//     // char temp = str[0];
//     char temp = *str;

//     int len = strlen(str);

//     // str[0] = str[len - 1];
//     // str[len - 1] = '\0';
//     *str = *(str + len - 1);
//     *(str + len - 1) = '\0';

//     if (strlen(str + 1) >= 2)
//     {
//         reverse_string1(str + 1);
//     }

//     str[len - 1] = temp;
// }

// void reverse_string2(char *str, int left, int right)
// {
//     char temp = *(str + left);
//     *(str + left) = *(str + right);
//     *(str + right) = temp;

//     if (left < right)
//     {
//         reverse_string2(str, left + 1, right - 1);
//     }
// }

// int main()
// {
//     char arr[] = "abcdefgh";//{'a', 'b',..., 'h','\0' }
//     int sz = strlen(arr) - 1;
//     printf("%s\n", arr);

//     reverse_string1(arr);
//     printf("%s\n", arr);

//     reverse_string2(arr, 0, sz);
//     printf("%s\n", arr);

//     return 0;
// }

int main()
{
    int num = 0;
    int arr[10] = {0};

    return 0;
}