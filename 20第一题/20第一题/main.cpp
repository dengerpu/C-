#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"option.h"
int main() {
	int input = 0;
	init();
	if (login() == 1) {
		system("pause");
		system("cls");
		struct Node* list;
		list = createList();
		readStudentInfoFromFile("data.txt", list);
		do {
			menu();
			scanf("%d", &input);
			switch (input)
			{
			case 1:addStudent(list); break;
			case 2:sortStudent(list); break;
			case 3:printf("ģ��3\n"); break;
			case 4:searchStudent(list); break;
			case 5:modifyStudent(); break;
			case 6:printStudent(list); break;
			case 0:printf("�˳�ϵͳ\n"); exit(0); break;
			default:printMidInfo("������������������\n");  break;
			}
			system("pause");
			system("cls");
		} while (input);
	}
	else {
		exit(0);
	}
	

}