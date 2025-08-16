// 三子棋
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define ROW 3 // 行
#define COL 3 // 列

void menu();                                               // 打印菜单
void initBoard(char board[ROW][COL], int row, int col);    // 初始化棋盘
void displayBoard(char board[ROW][COL], int row, int col); // 打印棋盘
void playerMove(char board[ROW][COL], int row, int col);   // 玩家下棋
void computerMove(char board[ROW][COL], int row, int col); // 电脑下棋
bool isFull(char board[ROW][COL], int row, int col);       // 判断棋盘是否下满
char isWin(char board[ROW][COL], int row, int col);        // 判断是否有一方获胜
void game();                                               // 游戏主函数
void printGameResult(char result);                         // 打印游戏结果

// 打印菜单
void menu()
{
    printf("**************************\n");
    printf("********  1.play  ********\n");
    printf("********  0.exit  ********\n");
    printf("**************************\n");
}

// 初始化棋盘
void initBoard(char board[ROW][COL], int row, int col)
{
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         board[i][j] = ' ';
    //     }
    // }

    memset(board, ' ', row * col * sizeof(char));
}

// 打印棋盘
void displayBoard(char board[ROW][COL], int row, int col)
{
    // 打印数据
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");

        // 打印分割信息
        if (i < row - 1)
        {
            for (int j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

// 玩家下棋
void playerMove(char board[ROW][COL], int row, int col)
{
    printf("玩家下棋:>\n");

    int x = 0;
    int y = 0;

    while (1)
    {
        printf("请输入坐标:>\n");
        scanf("%d %d", &x, &y);

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("坐标被占用，不能下棋，请选择其他位置:>\n");
            }
        }
        else
        {
            printf("坐标非法，请重新输入:>\n");
        }
    }
}

// 电脑下棋
void computerMove(char board[ROW][COL], int row, int col)
{
    printf("电脑下棋:>\n");

    int x = 0;
    int y = 0;

    while (1)
    {
        x = rand() % row; // 0~2
        y = rand() % col; // 0~2

        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

// 判断棋盘是否下满
bool isFull(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// 判断是否有一方获胜（优化算法，不仅限于3*3）
//*玩家赢  #电脑赢  Q平局  C继续
char isWin(char board[ROW][COL], int row, int col)
{
    // 检查行
    for (int i = 0; i < row; i++)
    {
        bool win = true;

        for (int j = 1; j < col; j++)
        {
            if (board[i][0] != board[i][j] || board[i][0] == ' ')
            {
                win = false;
                break;
            }
        }

        if (win)
        {
            return board[i][0];
        }
    }

    // 检查列
    for (int j = 0; j < col; j++)
    {
        bool win = true;

        for (int i = 1; i < row; i++)
        {
            if (board[0][j] != board[i][j] || board[0][j] == ' ')
            {
                win = false;
                break;
            }
        }

        if (win)
        {
            return board[0][j];
        }
    }

    // 检查主对角线
    bool diag1 = true;

    for (int i = 1; i < row; i++)
    {
        if (board[0][0] != board[i][i] || board[0][0] == ' ')
        {
            diag1 = false;
            break;
        }
    }

    if (diag1)
    {
        return board[0][0];
    }

    // 检查副对角线
    bool diag2 = true;

    for (int i = 1; i < row; i++)
    {
        if (board[0][row - 1] != board[i][row - 1 - i] || board[0][row - 1] == ' ')
        {
            diag2 = false;
            break;
        }
    }
    if (diag2)
    {
        return board[0][row - 1];
    }

    return 'C'; // 游戏继续
}

// 打印游戏结果
void printGameResult(char result)
{
    if (result == '*')
    {
        printf("恭喜你赢了！🎉\n");
    }
    else if (result == '#')
    {
        printf("很遗憾，电脑赢了！💻\n");
    }
    else
    {
        printf("游戏结束，平局！🤝\n");
    }
}

// 游戏主函数
void game()
{
    char result = 0;

    // 初始化棋盘
    char board[ROW][COL] = {0};
    initBoard(board, ROW, COL);
    displayBoard(board, ROW, COL);

    // 下棋
    while (1)
    {
        playerMove(board, ROW, COL);
        displayBoard(board, ROW, COL);
        result = isWin(board, ROW, COL);
        if (result != 'C')
        {
            break;
        }

        computerMove(board, ROW, COL);
        displayBoard(board, ROW, COL);
        result = isWin(board, ROW, COL);
        if (result != 'C')
        {
            break;
        }
    }

    printGameResult(result);
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