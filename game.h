/**
  ******************************************************************************
  * @file           : game.h
  * @author         : wj
  * @brief          : None
  * @attention      : None
  * @date           : 2024/5/6
  ******************************************************************************
  */

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ȫ�ֶ������̵�������
#define ROW 3
#define COl 3
//�����̸�ֵ
void InitBoard(char board[ROW][COl],int row,int col);

//��ӡ��ʼ��������
void DisplayBoard(char board[ROW][COl],int row,int col);

//�������
void PlayerMove(char board[ROW][COl],int row,int col);

//��������
void ComputerMove(char board[ROW][COl],int row,int col);

//�ж���Ϸ��Ӯ
char IsWin(char board[ROW][COl],int row,int col);

#endif //GAME_H
