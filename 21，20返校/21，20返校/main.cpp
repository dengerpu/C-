#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"option.h"
int main() {
	int input = 0;
	init();
	struct Node* list;
	list = createList();
	readStudentInfoFromFile("data1.txt", list);//��ȡ�ļ��е���Ϣ
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1:addStudent(list); break;
			case 2:modifyStudent(list); break;
			case 3:searchStudent(list); break;
			case 4:abnormalStudent(list); break;
			case 5:printf("ģ��5\n"); break;
			case 6:printInfoByTable(list); break;
			case 0:printf("�˳�ϵͳ\n"); destory(list); exit(0); break;
			default:printMidInfo("������������������\n");  break;
		}
		system("pause");
		system("cls");
	} while (input);
	
}