#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitiBoard(char board[ROW][COL]);

void DisplayBoard(char board[ROW][COL]);

void PlayerMove(char board[ROW][COL]);

void ComputerMove(char board[ROW][COL]);

char WinLoseEnd(char board[ROW][COL]);