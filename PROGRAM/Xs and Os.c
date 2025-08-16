// 三子棋
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROW 3 // 行
#define COL 3 // 列

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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
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

// 判断棋盘是否已满
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

// 判断输赢（该函数只能用于3 * 3的棋盘）
//*玩家赢  #电脑赢  Q平局  C继续
char isWin(char board[ROW][COL], int row, int col)
{   
    // 行
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }

    // 列
    for (int j = 0; j < col; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return board[0][j];
        }
    }

    // 主对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }

    // 副对角线
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[1][1];
    }

    if (isFull(board, row, col))
    {
        return 'Q'; // 平局
    }

    return 'C'; // 游戏继续
}

void game()
{
    char ret = 0;

    // 初始化棋盘
    char board[ROW][COL] = {0};
    initBoard(board, ROW, COL);
    displayBoard(board, ROW, COL);

    // 下棋
    while (1)
    {
        playerMove(board, ROW, COL);
        displayBoard(board, ROW, COL);
        ret = isWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }

        computerMove(board, ROW, COL);
        displayBoard(board, ROW, COL);
        ret = isWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
    }

    if (ret == '*')
    {
        printf("恭喜你赢了！🎉\n");
    }
    else if (ret == '#')
    {
        printf("很遗憾，电脑赢了！💻\n");
    }
    else
    {
        printf("游戏结束，平局！🤝\n");
    }
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