#define _CRT_SECURE_NO_WARNINGS
#include "ToSchool.h"

int main() {
	int input = 0;
	students p;  //创建学生信息表
	Login();
	Init(&p);
	do {
		menu();
		printf("请输入您需要的操作：\n");
		scanf("%d", &input);
		switch (input) {
		case ADD:AddStudent(&p); break;
		case SEARCH:SearchStudent(&p); break;
		case MODIFY: ModifyStudent(&p); break;
		case SORT:SortStudent(&p); break;
		case SHOW:ShowStudent(&p); break;
		case SAVE:SaveStudent(&p); break;
		case EXIT:printf("退出系统\n"); SaveStudent(&p); DsetoryStudent(&p); break;
		default:printf("输入有误，请重新输入\n");
		}
	} while (input);

	return 0;
}