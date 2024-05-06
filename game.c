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

//�����̸�ֵ
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
//��ӡ��ʼ��������
void DisplayBoard(char board[ROW][COl],int row,int col)
{
  int i = 0;
  int j = 0;
  for (i = 0 ; i < row; i++)
  {
    //�Ű���ӵĸ���
    for (j = 0; j < col ;j++)
    {
      printf(" %c ",board[i][j]);
      if(j < col - 1)
        printf("|");

    }
    printf("\n");

    //�Ű�����µĵ���
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

//�������
void PlayerMove(char board[ROW][COl],int row,int col)
{
  int x = 0;
  int y = 0;
  printf("����ҿ�ʼ����:>");

  while (1)
  {
    printf("����������:");
    scanf("%d %d",&x,&y);
    if(x >= 1 && x <= row && y >=1 &&y <=col)
    {
      if(board[x - 1][y - 1] == ' ')
      {
        board[x - 1][y - 1] = '*';
        break;
      }else
      {
        printf("���걻ռ��,�����ڸô�����,����������\n");
      }
    }else
    {
      printf("�����������������!\n");
    }
  }
}
//��������
void ComputerMove(char board[ROW][COl],int row,int col)
{
  printf("���Կ�ʼ����\n");

  int x, y;

  // ����Ƿ��е��Լ�����ʤ��λ��
  for (x = 0; x < row; x++)
  {
    for (y = 0; y < col; y++)
    {
      if (board[x][y] == ' ')
      {
        board[x][y] = '#'; // �����������λ��
        if (IsWin(board, row, col) == '#')
          return; // ���Ի�ʤ
        board[x][y] = ' '; // �ָ�����״̬
      }
    }
  }

  // ����Ƿ�����Ҽ�����ʤ��λ�ã���������ֹ
  for (x = 0; x < row; x++)
  {
    for (y = 0; y < col; y++)
    {
      if (board[x][y] == ' ')
      {
        board[x][y] = '*'; // ��������������λ��
        if (IsWin(board, row, col) == '*')
        {
          board[x][y] = '#'; // ��ֹ��һ�ʤ
          return;
        }
        board[x][y] = ' '; // �ָ�����״̬
      }
    }
  }

  // ���������������������㣬�����ѡ��һ����λ������
  do {
    x = rand() % row;
    y = rand() % col;
  } while (board[x][y] != ' '); // ����ѡ��ֱ���ҵ���λ��
  board[x][y] = '#'; // �����������
}


//�ж�������û����,�ǲ���ƽ��
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
//�ж�n*n����Ϸ��Ӯ
//���Ӯ *
//����Ӯ #
//����ƽ�� Q
//û�зֳ�ʤ�� C
char IsWin(char board[ROW][COl],int row,int col)
{
  int i = 0;
  int j = 0;
  //�ж��к���
  for (i = 0; i < row ;i++)
  {
    //��ʼֵΪ��һ�����ӵ�ֵ
    char row_w = board[i][0];
    char col_w = board[0][i];
    int row_same = 1;
    int col_same = 1;
    for (j = 1 ; j < col ; j++)
    {
      //�����
      if(board[i][j] != row_w || row_w == ' ')
        row_same = 0;

      //�����
      if(board[j][i] != col_w || col_w == ' ')
        col_same = 0;
    }
    //���һ�л�һ�еĸ��Ӷ���ͬ�Ҷ���Ϊ��,��ʤ��
    if(row_same && row_w != ' ')
      return row_w;
    if(col_same && row_w != ' ')
      return col_w;
  }

  // ���Խ���
  char diag1_winner = board[0][0];
  char diag2_winner = board[0][col - 1];
  int diag1_same = 1;
  int diag2_same = 1;

  for (i = 1; i < row; i++)
  {
    // ������Խ���
    if (board[i][i] != diag1_winner || diag1_winner == ' ')
      diag1_same = 0;

    // ��鸱�Խ���
    if (board[i][col - 1 - i] != diag2_winner || diag2_winner == ' ')
      diag2_same = 0;
  }

  // ����Խ��ߵĸ��Ӷ���ͬ�Ҳ�Ϊ�գ�������һ�ʤ
  if (diag1_same && diag1_winner != ' ')
    return diag1_winner;
  if (diag2_same && diag2_winner != ' ')
    return diag2_winner;

  //�ж��ǲ���ƽ��
  if(IsFull(board,row,col) == 0)
  {
    return 'Q';//ƽ����
  }
  //���������������������ǻ�û�зֳ�ʤ��,Ҳû��ƽ��,��ô����
  return 'C';
}

//�������ж���Ӯ�߼�
// int i = 0;
// int j = 0;
// //�ж����Ƿ�һ��
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
// //�ж϶Խ���
// if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
// {
//   return board[1][1];
// }
//
// if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
// {
//   return board[1][1];
// }