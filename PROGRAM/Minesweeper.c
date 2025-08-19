// 扫雷
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_COUNT 10

int book[ROWS][COLS]; // 标记数组

// 函数声明

void menu();                                                                   // 打印菜单
void initBoard(char board[ROWS][COLS], int rows, int cols, char set);          // 初始化数组
void displayBoard(char board[ROWS][COLS], int row, int col);                   // 打印数组
void setMine(char mine[ROWS][COLS], int row, int col);                         // 布置雷
int get_mine_count(char mine[ROWS][COLS], int x, int y);                       // 获取周围雷的数量
void spreadMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);   // 展开一片
void isWin(char show, int row, int col);                                       // 判断是否胜利
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col); // 排查雷
void game();                                                                   // 游戏主函数

// 打印菜单
void menu()
{
    printf("**************************\n");
    printf("********  1.play  ********\n");
    printf("********  0.exit  ********\n");
    printf("**************************\n");
}

// 初始化数组
void initBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    memset(board, set, rows * cols * sizeof(char));
}

// 打印数组
void displayBoard(char board[ROWS][COLS], int row, int col)
{
    printf("-----扫雷游戏-----\n");

    printf("  ");
    for (int j = 1; j <= col; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("-----扫雷游戏-----\n");
}

// 布置雷
void setMine(char mine[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;

    while (count--)
    {
        int x = rand() % row + 1; // 1~row
        int y = rand() % col + 1; // 1~col

        if (mine[x][y] == '0')
        {
            mine[x][y] = '1';
        }
    }
}

// 获取周围雷的数量
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y - 1] +
           mine[x - 1][y] +
           mine[x - 1][y + 1] +
           mine[x][y - 1] +
           mine[x][y + 1] +
           mine[x + 1][y - 1] +
           mine[x + 1][y] +
           mine[x + 1][y + 1] - 8 * '0';
}

// 展开一片
void spreadMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    if (x < 1 || x > ROW || y < 1 || y > COL)
    {
        return;
    }

    book[x][y] = 1;

    int count = get_mine_count(mine, x, y);

    if (count > 0)
    {
        show[x][y] = count + '0';
        return;
    }

    show[x][y] = ' ';

    if (book[x - 1][y - 1] == 0)
        spreadMine(mine, show, x - 1, y - 1);
    if (book[x - 1][y] == 0)
        spreadMine(mine, show, x - 1, y);
    if (book[x - 1][y + 1] == 0)
        spreadMine(mine, show, x - 1, y + 1);
    if (book[x][y - 1] == 0)
        spreadMine(mine, show, x, y - 1);
    if (book[x][y + 1] == 0)
        spreadMine(mine, show, x, y + 1);
    if (book[x + 1][y - 1] == 0)
        spreadMine(mine, show, x + 1, y - 1);
    if (book[x + 1][y] == 0)
        spreadMine(mine, show, x + 1, y);
    if (book[x + 1][y + 1] == 0)
        spreadMine(mine, show, x + 1, y + 1);
}

// 判断是否胜利
bool isWin(char show[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (show[i][j] == '*')
            {
                count++;
            }
        }
    }

    if (count == EASY_COUNT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 排查雷
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;

    int win = 0; // 找到非雷的个数
    while (1)
    {
        printf("请输入要排查的坐标:>\n");
        scanf("%d %d", &x, &y);

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (show[x][y] != '*')
            {
                printf("该坐标已被排查,不能重复排查\n");
            }

            else
            {
                if (mine[x][y] == '1')
                {
                    printf("很遗憾，你被炸死了\n");
                    displayBoard(mine, ROW, COL);
                    break;
                }

                else
                {
                    int count = get_mine_count(mine, x, y);

                    if (count == 0)
                    {
                        show[x][y] = ' ';
                        spreadMine(mine, show, x, y);
                        displayBoard(show, ROW, COL);
                    }

                    else
                    {
                        show[x][y] = count + '0';
                        displayBoard(show, ROW, COL);
                    }

                    if (isWin(show, ROW, COL))
                    {
                        printf("恭喜你,排雷成功\n");
                        break;
                    }
                }
            }
        }

        else
        {
            printf("输入的坐标非法，请重新输入:>\n");
        }
    }
}

// 游戏主函数
void game()
{
    char mine[ROWS][COLS] = {0}; // 存放布置好的雷的信息
    char show[ROWS][COLS] = {0}; // 存放排查出的雷的信息

    memset(book, 0, sizeof(book));

    initBoard(mine, ROWS, COLS, '0'); // mine数组在没有布置雷时都是'0'，雷用'1'表示
    initBoard(show, ROWS, COLS, '*'); // show数组在没有排查雷时都是'*'

    setMine(mine, ROW, COL);
    displayBoard(mine, ROW, COL);
    displayBoard(show, ROW, COL);

    findMine(mine, show, ROW, COL);
}

int main()
{
    srand((unsigned int)time(NULL)); // 设置随机数种子

    int input = 0;
    do
    {
        menu();
        printf("请选择:>:\n");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
        }
    } while (input != 0);

    return 0;
}