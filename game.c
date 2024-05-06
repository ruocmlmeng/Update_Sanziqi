/**
  ******************************************************************************
  * @file           : game.c
  * @author         : wj
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/6
  ******************************************************************************
  */

#include "game.h"

#include <stdlib.h>

//给棋盘赋值
void InitBoard(char board[ROW][COl],int row,int col)
{
  int i = 0;
  for (i = 0 ; i < row ;i++)
  {
    int j = 0;
    for (j = 0; j < col ;j++)
    {
      board[i][j] = ' ';
    }
  }
}
//打印初始化的棋盘
void DisplayBoard(char board[ROW][COl],int row,int col)
{
  int i = 0;
  int j = 0;
  for (i = 0 ; i < row; i++)
  {
    //排版放子的格子
    for (j = 0; j < col ;j++)
    {
      printf(" %c ",board[i][j]);
      if(j < col - 1)
        printf("|");

    }
    printf("\n");

    //排版格子下的挡板
    if(i < row - 1)
    {
      for (j = 0; j < col ; j++)
      {
        printf("---");
        if (j < col -1 )
          printf("|");
      }
      printf("\n");
    }
  }
}

//玩家下棋
void PlayerMove(char board[ROW][COl],int row,int col)
{
  int x = 0;
  int y = 0;
  printf("请玩家开始下棋:>");

  while (1)
  {
    printf("请输入坐标:");
    scanf("%d %d",&x,&y);
    if(x >= 1 && x <= row && y >=1 &&y <=col)
    {
      if(board[x - 1][y - 1] == ' ')
      {
        board[x - 1][y - 1] = '*';
        break;
      }else
      {
        printf("坐标被占用,不能在该处下棋,请重新输入\n");
      }
    }else
    {
      printf("输入错误请重新输入!\n");
    }
  }
}
//电脑下棋
void ComputerMove(char board[ROW][COl],int row,int col)
{
  printf("电脑开始下棋\n");

  int x, y;

  // 检查是否有电脑即将获胜的位置
  for (x = 0; x < row; x++)
  {
    for (y = 0; y < col; y++)
    {
      if (board[x][y] == ' ')
      {
        board[x][y] = '#'; // 电脑下在这个位置
        if (IsWin(board, row, col) == '#')
          return; // 电脑获胜
        board[x][y] = ' '; // 恢复棋盘状态
      }
    }
  }

  // 检查是否有玩家即将获胜的位置，若有则阻止
  for (x = 0; x < row; x++)
  {
    for (y = 0; y < col; y++)
    {
      if (board[x][y] == ' ')
      {
        board[x][y] = '*'; // 假设玩家下在这个位置
        if (IsWin(board, row, col) == '*')
        {
          board[x][y] = '#'; // 阻止玩家获胜
          return;
        }
        board[x][y] = ' '; // 恢复棋盘状态
      }
    }
  }

  // 如果以上两种情况都不满足，则随机选择一个空位置下棋
  do {
    x = rand() % row;
    y = rand() % col;
  } while (board[x][y] != ' '); // 继续选择直到找到空位置
  board[x][y] = '#'; // 电脑随机下棋
}


//判断棋盘有没有满,是不是平局
int IsFull(char board[ROW][COl],int row,int col)
{
  int i = 0;
  int j = 0;
  for (i = 0; i < row ; i++)
  {
    for (j = 0; j < col; j++)
    {
      if(board[i][j] == ' ')
        return 1;
    }
  }
  return 0;
}
//判断n*n阶游戏输赢
//玩家赢 *
//电脑赢 #
//满了平局 Q
//没有分出胜负 C
char IsWin(char board[ROW][COl],int row,int col)
{
  int i = 0;
  int j = 0;
  //判断行和列
  for (i = 0; i < row ;i++)
  {
    //初始值为第一个格子的值
    char row_w = board[i][0];
    char col_w = board[0][i];
    int row_same = 1;
    int col_same = 1;
    for (j = 1 ; j < col ; j++)
    {
      //检查行
      if(board[i][j] != row_w || row_w == ' ')
        row_same = 0;

      //检查列
      if(board[j][i] != col_w || col_w == ' ')
        col_same = 0;
    }
    //如果一行或一列的格子都相同且都不为空,则胜利
    if(row_same && row_w != ' ')
      return row_w;
    if(col_same && row_w != ' ')
      return col_w;
  }

  // 检查对角线
  char diag1_winner = board[0][0];
  char diag2_winner = board[0][col - 1];
  int diag1_same = 1;
  int diag2_same = 1;

  for (i = 1; i < row; i++)
  {
    // 检查主对角线
    if (board[i][i] != diag1_winner || diag1_winner == ' ')
      diag1_same = 0;

    // 检查副对角线
    if (board[i][col - 1 - i] != diag2_winner || diag2_winner == ' ')
      diag2_same = 0;
  }

  // 如果对角线的格子都相同且不为空，则有玩家获胜
  if (diag1_same && diag1_winner != ' ')
    return diag1_winner;
  if (diag2_same && diag2_winner != ' ')
    return diag2_winner;

  //判断是不是平局
  if(IsFull(board,row,col) == 0)
  {
    return 'Q';//平局了
  }
  //如果上述条件都不满足就是还没有分出胜负,也没有平局,那么继续
  return 'C';
}

//三子棋判断输赢逻辑
// int i = 0;
// int j = 0;
// //判断列是否都一样
// for (i = 0 ; i < row ;i++)
// {
//   if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] !=' ')
//   {
//     return board[i][1];
//   }
// }
//
// for (j = 0 ; j < col ;j++)
// {
//   if(board[0][j] ==board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
//   {
//     return board[1][j];
//   }
// }
//
// //判断对角线
// if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
// {
//   return board[1][1];
// }
//
// if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
// {
//   return board[1][1];
// }