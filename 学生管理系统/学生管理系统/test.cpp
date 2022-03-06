#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

struct Node* list = NULL;
void keydown() {
	int input = 0;
	struct student tempData;
	scanf("%d", &input);
	switch (input) {
	case 0:
		printf("\t\t【退出系统】\n");
		exit(0);
		break;
	case 1:
		printf("\t\t【插入信息】\n");
		printf("请输入要插入的学生信息:>\n");
		printf("请输入姓名、学号、年龄、电话、地址：>");
		scanf("%s%s%d%s%s", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr);
		insertNoByHead(list, tempData);
		saveInfoToFile("student.txt", list);
		break;
	case 2:
		printf("\t\t【浏览信息】\n");
		printList(list);
		break;
	case 3:
		printf("\t\t【删除信息】\n"); 
		printf("请输入要删除的学生信息（姓名）:>");
		scanf("%s", tempData.name);
		deleteNodeByStudent_Name(list, tempData.name);
		saveInfoToFile("student.txt", list);
		break;
	case 4:
		printf("\t\t【修改信息】\n"); 
		printf("请输入要修改的学号:>");
		scanf("%s", &tempData.num);
		if (searchNodeBynum(list, tempData.num) == NULL) {
			printf("未查找到相关信息\n");
		}
		else {
			struct Node* modifyNode = searchNodeBynum(list, tempData.num);
			printf("请输入姓名、学号、年龄、电话、地址：>");
			scanf("%s%s%d%s%s", modifyNode->data.name, modifyNode->data.num, &(modifyNode->data.age), modifyNode->data.tel, modifyNode->data.addr);
			saveInfoToFile("student.txt", list);
		}
		break;
	case 5:
		printf("\t\t【查找信息】\n");
		printf("请输入要查找的学号:>");
		scanf("%s", &tempData.num);
		if (searchNodeBynum(list, tempData.num) == NULL) {
			printf("表为空或查找不到\n");
		}
		else {
			printNode(searchNodeBynum(list, tempData.num));
		}
		break;
	default:printf("输入有误，请重新输入\n"); break;

	}
}



int main() {
	list = createList();
	readInfofromfile("student.txt", list);
	while (1) {
		menu();
		keydown();
		system("pause");
		system("cls");
	}
	
	return 0;
}