#define _CRT_SECURE_NO_WARNINGS
#include "ToSchool.h"

int main() {
	int input = 0;
	students p;  //创建学生信息表
	Login();
	Init(&p);
	do {
		menu();
		printf("请输入您需要的操作（按5请求帮助）：\n");
		scanf("%d", &input);
		switch (input) {
		case ADD:AddStudent(&p); break;
		case SEARCH:break;
		case MODIFY:break;
		case SORT:break;
		case SHOW:ShowStudent(&p); break;
		case EXIT:printf("退出系统\n"); break;
		default:printf("输入有误，请重新输入\n");
		}
	} while (input);

	return 0;
}