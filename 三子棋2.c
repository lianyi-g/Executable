#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"
//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;//��Ӯ�жϱ�־
	//����-����߳���������Ϣ
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisPlayBoard(board, ROW, COL);
	while(1)
	{
		//����ƶ�
		PlayerMOve(board, ROW, COL);
		//�ƶ����ӡ
		DisPlayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if(ret!='C')
		{
			break;
		}		

		//�����ƶ�
		CompterMOve(board, ROW, COL);
		//�ƶ����ӡ
		DisPlayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if(ret!='C')
		{
			break;
		}

		
	}
	if('#'==ret)
	{
		printf("����Ӯ��\n");
	}
	else if('*'==ret)
	{
		printf("���Ӯ��\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}		
}

void menu()
{
	printf("****************************\n");
	printf("*****1.play     0.exit******\n");
	printf("  ����������ѡ��ʼ��Ϸ��  \n");
}
void test()
{
	int n = 0;//�������ñ�����Χ
	//ֻ����һ��srand����,����ʱ���Ϊ����
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	}while(n);
}
int main()
{
	test();
	return 0;
}