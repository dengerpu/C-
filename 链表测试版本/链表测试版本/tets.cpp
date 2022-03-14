#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

//菜单
void menu() {
	printf("----------------学生管理系统----------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.插入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.删除信息\n");
	printf("\t\t4.修改信息\n");
	printf("\t\t5.查找信息\n");
	printf("--------------------------------------------\n");
	printf("请选择操作:>");
}

int main() {
	int input = 0;
	struct Node* list = createList();
	readInfoFromFile("student.txt", list);
	struct student tempData;
	//char name[20];  //姓名
	//char num[10];	//学号
	//int age;		//年龄
	//char tel[20];	//电话
	//char addr[20];	//地址
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\t\t【插入信息】\n");
			printf("请输入要插入的学生信息:>\n");
			printf("请输入姓名、学号、年龄、电话、地址：>");
			scanf("%s%s%d%s%s", tempData.name, tempData.num, &(tempData.age), tempData.tel, tempData.addr);
			insertNodeNyHead(list, tempData);
			//list = insertNodeByTail(list, tempData);
			break;
		case 2:
			printf("\t\t【浏览信息】\n");
			printList(list);
			break;
		case 3:
			printf("\t\t【删除信息】\n");
			printf("请输入要删除的学生信息（姓名）:>");
			scanf("%s", tempData.name);
			deleteNodeByquery(list, tempData.name);
			break;
		case 4:
			printf("\t\t【修改信息】\n");
			printf("请输入要修改的学号:>");
			scanf("%s", &tempData.num);
			if (findNodeByquery(list, tempData.num) == NULL) {
				printf("未查找到相关信息\n");
			}
			else {
				struct Node* modifyNode = findNodeByquery(list, tempData.num);
				printf("请输入姓名、学号、年龄、电话、地址：>");
				scanf("%s%s%d%s%s", modifyNode->data.name, modifyNode->data.num, &(modifyNode->data.age), modifyNode->data.tel, modifyNode->data.addr);
				
			}
			break;
		case 5:printf("\t\t【查找信息】\n");
			printf("请输入要查找的学号:>");
			scanf("%s", &tempData.num);
			if (findNodeByquery(list, tempData.num) == NULL) {
				printf("表为空或查找不到\n");
			}
			else {
				printNode(findNodeByquery(list, tempData.num));
			}
			break;
		case 0:saveInfoToFile("student.txt", list); exit(0); break;
		default:printf("输入有误，请重新输入\n"); break;
		
		}
		system("pause");
		system("cls");
	} while (input);

	return 0;
}