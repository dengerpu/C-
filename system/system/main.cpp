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
		case 1:printf("ģ��1\n"); break;
		case 2:printf("ģ��2\n"); break;
		case 3:printf("ģ��3\n"); break;
		case 4:printf("ģ��4\n"); break;
		case 5:printf("ģ��5\n"); break;
		case 6:printInfoByTable(); break;
		case 0:printf("�˳�ϵͳ\n"); exit(0); break;
		default:printMidInfo("������������������\n");  break;
		}
		system("pause");
		system("cls");
	} while (input);

}