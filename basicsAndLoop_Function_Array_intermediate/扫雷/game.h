#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 20// �׵������ó�����ʾ������Ķ�

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);//�Զ��庯�����������Ӧ�зֺ�
void DisplayBoard(char board[ROWS][COLS], int row, int col);//���ӻ�����
void SetMine(char board[ROWS][COLS], int row, int col);//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//����
int get_my_count(char board[ROWS][COLS], int x, int y);