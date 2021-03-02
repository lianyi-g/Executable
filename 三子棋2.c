#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"
//游戏的整个算法实现
void game()
{
	char ret = 0;//输赢判断标志
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisPlayBoard(board, ROW, COL);
	while(1)
	{
		//玩家移动
		PlayerMOve(board, ROW, COL);
		//移动后打印
		DisPlayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if(ret!='C')
		{
			break;
		}		

		//电脑移动
		CompterMOve(board, ROW, COL);
		//移动后打印
		DisPlayBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if(ret!='C')
		{
			break;
		}

		
	}
	if('#'==ret)
	{
		printf("电脑赢！\n");
	}
	else if('*'==ret)
	{
		printf("玩家赢！\n");
	}
	else
	{
		printf("平局！\n");
	}		
}

void menu()
{
	printf("****************************\n");
	printf("*****1.play     0.exit******\n");
	printf("  请输入数字选择开始游戏！  \n");
}
void test()
{
	int n = 0;//合理设置变量范围
	//只调用一次srand（）,传入时间戳为参数
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	}while(n);
}
int main()
{
	test();
	return 0;
}