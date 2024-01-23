#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3
//��ʼ������
void Initboard(char board[ROW][COL],int row,int col);

//��ӡ����
void Dispalybroad(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL],int row,int col);

//��������
//��û������ĵط��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
//���Ӯ - '*'
//����Ӯ - '#'
//ƽ�� - 'Q'
//���� - 'C'
char Iswin(char board[ROW][COL], int row, int col);
