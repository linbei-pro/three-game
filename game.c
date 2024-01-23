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
//1.0版本 棋盘不能变宽，
//void Dispalybroad(char board[ROW][COL], int row, int col)
//{
//	int i=0;
//	for (i = 0; i < row; i++)
//	{
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
//		//打印分割行
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
		//打印数据
		int j;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
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
	printf("玩家请输入(例如:>1 1)\n");

	printf("请输入坐标:>");
	scanf_s("%d %d", &x, &y);
	//坐标范围合法的判断
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
				printf("坐标以被占用，不能在此下棋,请重新输入\n");
				break;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			break;
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");

	int x = 0;
	int y = 0;
	
	while (1)
	{
		x = rand() % row;//随机数只能是0~2，所以取模row
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//如果满了就返回1，不满就返回0
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
	//先判断行
	int i;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];//用return board[i][0] 直接来判断 妙！秒！秒！
		}
	}
	//判断列
	int j;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//没有人赢 就是平局
	//要判断一下棋盘是不是已经满了
	if (Isfull(board,row,col))
	{
		return 'Q';
	}
	//没有满 游戏继续
	return 'C';
}
