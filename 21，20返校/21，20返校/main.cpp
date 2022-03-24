#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"option.h"
int main() {
	int input = 0;
	init();
	struct Node* list;
	list = createList();
	readStudentInfoFromFile("data1.txt", list);//读取文件中的信息
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1:addStudent(list); break;
			case 2:modifyStudent(list); break;
			case 3:searchStudent(list); break;
			case 4:abnormalStudent(list); break;
			case 5:printf("模块5\n"); break;
			case 6:printInfoByTable(list); break;
			case 0:printf("退出系统\n"); destory(list); exit(0); break;
			default:printMidInfo("输入有误，请重新输入\n");  break;
		}
		system("pause");
		system("cls");
	} while (input);
	
}