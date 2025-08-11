#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
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
// default:
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

