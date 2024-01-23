#include<stdio.h>
#include"game.h"

void menu()
{
	printf("*************************************\n");
	printf("*************************************\n"); 
	printf("*******  1. play  2. exit  **********\n");
	printf("*************************************\n");
	printf("*************************************\n");


}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘的函数
	Initboard(board,ROW,COL);
	Dispalybroad(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		Dispalybroad(board, ROW, COL);
		//判断输赢
		ret=Iswin(board,ROW,COL);
		if (ret != 'C')//除了继续这种情况，其他的就游戏结束
		{
			break;
		}

		//电脑下棋
		ComputerMove(board,ROW,COL);
		//判断输赢
		if (ret != 'C')
		{
			break;
		}
		Dispalybroad(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("恭喜，玩家赢了！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	Dispalybroad(board, ROW, COL);
	 
}
int main() {
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;



		}
	} while (input);


	return 0;
}