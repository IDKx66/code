#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("**************************\n");
    printf("********  1.paly  ********\n");
    printf("********  0.exit  ********\n");
    printf("**************************\n");
}

void game()
{   
    int guess = 0;

    //1.生成随机数(0~RAND_MAX(32767))
    int ret = rand() % 100 + 1;
    // printf("%d\n", ret);
    printf("请猜数字:>");
    scanf("%d", &guess);

    while (1)
    {
        if (guess > ret) 
        {
            printf("大了\n");
            printf("请猜数字:>");
            scanf("%d", &guess);
        }
        else if (guess < ret) 
        {
            printf("小了\n");
            printf("请猜数字:>");
            scanf("%d", &guess);
        }
        else
        {
            printf("恭喜你猜对了！\n");
            break;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    int input = 0;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        game(); 
            printf("猜数字\n");
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误, 重新选择\n");
            break;
        }
    } while (input);

    return 0;
}
