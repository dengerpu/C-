#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"

void menu(){

	printf("--------学生返校健康管理系统--------\n");
	printf("------------1.添加学生信息----------\n");
	printf("------------2.修改学生信息----------\n");
	printf("------------3.删除学生信息----------\n");
	printf("------------4.查询学生信息----------\n");
	printf("------------5.异常信息查看----------\n");
	printf("------------6.打印学生信息----------\n");
	printf("---------------0.退出---------------\n");

}

int main() {
	int input = 0;
	struct students p;
	InitStudent(&p);
	do {
		menu();
		printf("请输入要选择的操作：>");
		scanf("%d", &input);
		switch (input) {
		case ADD:addStudent(&p); saveStudent("data1.txt",&p); break;
		case MODIFY:modifyStudent(&p); saveStudent("data1.txt", &p); break;
		case DELETE:printf("删除学生模块\n"); break;
		case SEARCH:searchStudent(&p); break;
		case ABNORMAL:printf("异常信息模块\n"); break;
		case PRINT:printStudent(&p); break;
		case EXIT:exit(0); printf("退出\n"); break;
		}
		system("pause");
		system("cls");
	} while (input);
	return 0;
}