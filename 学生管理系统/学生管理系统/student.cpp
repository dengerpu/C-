#define _CRT_SECURE_NO_WARNINGS
#include "student.h"

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

//创建链表
struct Node* createList() {
	//申请空间
	struct Node* listHeadNode = (struct Node*)malloc(sizeof(struct Node));
	//listHeadNode->data = NULL;
	listHeadNode->next = NULL;
	return listHeadNode;

}
//创建结点
struct Node* createNode(struct student data) {
	//申请空间
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//头插法插入链表
void insertNoByHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);
	//采用头插法插入节点
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}
//删除链表
void deleteNodeByStudent_Name(struct Node* listHeadNode, char *name) {
	struct Node* posFrontNode = listHeadNode;  //要删除结点的额前一个结点
	struct Node* posNode = listHeadNode->next;	//要删除的节点
	if (posNode == NULL) {
		printf("表为空，无法删除\n");
		return;
	}
	else {
		while (strcmp(name,posNode->data.name)) {
			posFrontNode = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("查找不到，无法删除\n");
				return;
			}
		}
		//查找到,进行删除
		posFrontNode->next = posNode->next;
	}
}
//根据学号查找学生的信息
struct Node* searchNodeBynum(struct Node* listHeadNode, char* num) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		while (strcmp(num, searchNode->data.num)) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;
	}

}
//打印结点
void printNode(struct Node* newNode) {
	printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n", "姓名", "学号", "年龄", "电话", "地址");
	printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", newNode->data.name, newNode->data.num, newNode->data.age, newNode->data.tel, newNode->data.addr);
}
//根据学号修改学生信息
//void modifyNodeBynum(struct Node* listHeadNode, char* num) {
//	struct Node* newNode = searchNodeBynum(listHeadNode, num);
//	
//}

//打印链表
void printList(struct Node* listHeadNode) {
	///因为第一个链表没有存储信息
	//char name[20];  //姓名
	//char num[10];	//学号
	//int age;		//年龄
	//char tel[20];	//电话
	//char addr[20];	//地址
	struct Node* pMove = listHeadNode->next;
	printf("%-20s\t%-10s\t%s\t%-20s\t%-20s\t\n","姓名","学号","年龄","电话","地址");
	while (pMove) {
		printf("%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}
}

//读取文件信息
void readInfofromfile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");//如果没有就创建
	}
	struct student tempData;
	while (fscanf(fp, "%s%s%d%s%s", tempData.name, tempData.num, &tempData.age, tempData.tel, tempData.addr) != EOF) {
		insertNoByHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
}
//保存到文件中
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	
	while (pMove) {
		fprintf(fp,"%-20s\t%-10s\t%d\t%-20s\t%-20s\t\n", pMove->data.name, pMove->data.num, pMove->data.age, pMove->data.tel, pMove->data.addr);
		pMove = pMove->next;
	}
}