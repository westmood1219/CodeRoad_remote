#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 20// 雷的数量用常量表示，方便改动

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);//自定义函数的声明最后应有分号
void DisplayBoard(char board[ROWS][COLS], int row, int col);//可视化棋盘
void SetMine(char board[ROWS][COLS], int row, int col);//埋雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排雷
int get_my_count(char board[ROWS][COLS], int x, int y);