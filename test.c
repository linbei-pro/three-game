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
	//��ʼ�����̵ĺ���
	Initboard(board,ROW,COL);
	Dispalybroad(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		Dispalybroad(board, ROW, COL);
		//�ж���Ӯ
		ret=Iswin(board,ROW,COL);
		if (ret != 'C')//���˼�����������������ľ���Ϸ����
		{
			break;
		}

		//��������
		ComputerMove(board,ROW,COL);
		//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		Dispalybroad(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("��ϲ�����Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	Dispalybroad(board, ROW, COL);
	 
}
int main() {
	srand((unsigned int)time(NULL));//������������������
	int input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;



		}
	} while (input);


	return 0;
}