#include"game.h"

void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//1.0�汾 ���̲��ܱ��
//void Dispalybroad(char board[ROW][COL], int row, int col)
//{
//	int i=0;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡ����
//		printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
//		//��ӡ�ָ���
//		if(i<row-1)
//		printf("---|---|---\n");
//
//	}
//
//
//}
void Dispalybroad(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ����
		int j;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < col - 1)
		{
			int j=0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���������(����:>1 1)\n");

	printf("����������:>");
	scanf_s("%d %d", &x, &y);
	//���귶Χ�Ϸ����ж�
	while (1)
	{
		if (x >= 1 && x <= row && y >= 1 && y <=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����Ա�ռ�ã������ڴ�����,����������\n");
				break;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
			break;
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������:>\n");

	int x = 0;
	int y = 0;
	
	while (1)
	{
		x = rand() % row;//�����ֻ����0~2������ȡģrow
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//������˾ͷ���1�������ͷ���0
int Isfull(char board[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	//���ж���
	int i;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];//��return board[i][0] ֱ�����ж� ��룡�룡
		}
	}
	//�ж���
	int j;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//û����Ӯ ����ƽ��
	//Ҫ�ж�һ�������ǲ����Ѿ�����
	if (Isfull(board,row,col))
	{
		return 'Q';
	}
	//û���� ��Ϸ����
	return 'C';
}
