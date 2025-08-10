// #include <stdio.h>
// #include <string.h>
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

#include <stdio.h>

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

int main()
{
    // int a = 10;
    // printf("%p\n", &a);
    // int *p = &a;

    // printf("%zu\n", sizeof(char *));
    // printf("%zu\n", sizeof(short *));
    // printf("%zu\n", sizeof(int *));
    // printf("%zu\n", sizeof(double *));
    // printf("%zu\n", sizeof(float *));

    int *p1, p2, p3;
    printf("%zu\n", sizeof(p1));
    printf("%zu\n", sizeof(p2));
    printf("%zu\n", sizeof(p3));
    
    return 0;
}
