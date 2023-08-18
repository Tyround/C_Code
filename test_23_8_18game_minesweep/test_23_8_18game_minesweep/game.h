#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void menu();
void InitiBoard(char arr[ROWS][COLS]);
void DisplayBoard(char board[ROWS][COLS]);
void create_mine(char arr[ROWS][COLS], int ran);
char scan_num(char mine[ROWS][COLS],int x,int y);
int End(char mine[ROWS][COLS]);

