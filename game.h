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
//全局定义棋盘的行与列
#define ROW 3
#define COl 3
//给棋盘赋值
void InitBoard(char board[ROW][COl],int row,int col);

//打印初始画的棋盘
void DisplayBoard(char board[ROW][COl],int row,int col);

//玩家下棋
void PlayerMove(char board[ROW][COl],int row,int col);

//电脑下棋
void ComputerMove(char board[ROW][COl],int row,int col);

//判断游戏输赢
char IsWin(char board[ROW][COl],int row,int col);

#endif //GAME_H
