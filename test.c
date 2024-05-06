#include"game.h"
void menu()
{
    printf("*********************\n");
    printf("****1. play 0.exit***\n");
    printf("*********************\n");
}
void game()
{
    //判断游戏结果的变量
    char ret = 0;
    //定义棋盘
    char board[ROW][COl] = {0};
    //给棋盘赋值为空
    InitBoard(board,ROW,COl);
    //打印初始画的棋盘
    DisplayBoard(board,ROW,COl);
    //然后就是玩家与电脑开始下棋
    while (1)
    {
        //玩家下棋
        PlayerMove(board,ROW,COl);
        //判断游戏的输赢
        ret = IsWin(board,ROW,COl);
        if(ret != 'C')
        {
            break;
        }
        DisplayBoard(board,ROW,COl);
        //电脑下棋
        ComputerMove(board,ROW,COl);
        //判断游戏的输赢
        ret = IsWin(board,ROW,COl);
        if(ret != 'C')
        {
            break;
        }
        DisplayBoard(board,ROW,COl);
    }
    if(ret == '*')
    {
        printf("玩家胜出^_^\n");
    }else if( ret == '#')
    {
        printf("电脑胜出\n");
    }else
    {
        printf("平局\n");
    }
    DisplayBoard(board,ROW,COl);
}
int main(void)
{
    srand((unsigned int )time(NULL));//设置随机数的生成起点

    int input = 0;
    do
    {   menu();
        printf("请输入选项:>");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                // 定义开始游戏的函数
                game();
            break;
            case 0:
                printf("退出游戏\n");
            break;
            default:
                printf("输入的数字非法,请重新输入\n");
            break;
        }
    } while (input);

    return 0;
}
