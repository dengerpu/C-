#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"option.h"
int main() {
	int input = 0;
	init();
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:printf("模块1\n"); break;
		case 2:printf("模块2\n"); break;
		case 3:printf("模块3\n"); break;
		case 4:printf("模块4\n"); break;
		case 5:printf("模块5\n"); break;
		case 6:printInfoByTable(); break;
		case 0:printf("退出系统\n"); exit(0); break;
		default:printMidInfo("输入有误，请重新输入\n");  break;
		}
		system("pause");
		system("cls");
	} while (input);

}