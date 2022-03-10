#define _CRT_SECURE_NO_WARNINGS
#include "Toschool.h"

void menu(){

	printf("--------学生返校健康管理系统--------\n");
	printf("------------1.添加学生信息----------\n");
	printf("------------2.修改学生信息----------\n");
	printf("------------3.连续三天学生异常信息--\n");
	printf("------------4.查询学生信息----------\n");
	printf("------------5.异常信息查看----------\n");
	printf("------------6.打印学生信息----------\n");
	printf("---------------0.退出---------------\n");

}

int main() {
	int input = 0;
	struct students p;
	InitStudent(&p);
	loadStudent("data1.txt", &p);
	do {
		menu();
		printf("请输入要选择的操作：>");
		scanf("%d", &input);
		switch (input) {
			case ADD:addStudent(&p); saveStudent("data1.txt",&p); break;
			case MODIFY:modifyStudent(&p); saveStudent("data1.txt", &p); break;
			case ADVICE:abnormaladvice("data4.txt",&p); break;
			case SEARCH:searchStudent(&p); break;
			case ABNORMAL:abnormalStudent("data3.txt" ,&p); break;
			case PRINT: printStudent(&p); break;
			case EXIT:destory(&p); exit(0); break;
			default:printf("输入有误，请重新输入\n"); break;
		}
		system("pause");
		system("cls");
	} while (input);
	return 0;
}