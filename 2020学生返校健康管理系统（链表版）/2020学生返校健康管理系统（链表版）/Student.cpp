#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "utils.h"



//菜单
void menu() {
	printf("----------------学生管理系统----------------\n");
	printf("\t\t0.退出管理系统\n");
	printf("\t\t1.添加学生信息\n");
	printf("\t\t2.修改学生信息\n");
	printf("\t\t3.查找学生信息\n");
	printf("\t\t4.统计学生信息\n");
	printf("\t\t5.异常状态预警\n");
	printf("\t\t6.打印学生信息\n");
	printf("--------------------------------------------\n");
	printf("请选择操作:>");
}

//创建链表
struct Node* createList() {
	//申请空间
	struct Node* listHead = (struct Node*)malloc(sizeof(struct Node));
	listHead->next = NULL;
	return listHead;
}

//创建结点
struct Node* createNode(struct student data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//申请一个新结点
	newNode->next = listHeadNode->next;
	listHeadNode->next = newNode;
}

//尾插法，插入节点
void insertNodeByTail(struct Node* listHeadNode, struct student data) {
	struct Node* newNode = createNode(data);//申请一个新结点
	listHeadNode->next = newNode;
	listHeadNode = newNode;
}

//删除链表
void deleteNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* posFrontNode = listHeadNode;  //要删除结点的前一个结点
	struct Node* posNode = listHeadNode->next; //要删除的结点
	if (posNode == NULL) {
		printf("表为空，无法删除\n");
		return;
	}
	else {
		/*while (不满足查询条件) {
			posFrontNode->next = posNode;
			posNode = posNode->next;
			if (posNode == NULL) {
				printf("查找不到,无法删除\n");
				return;
			}
		}
		查找到，进行删除
		posFrontNode->next = posNode->next;*/
	}
}
//查找结点
struct Node* findNodeByquery(struct Node* listHeadNode, char* query) {
	struct Node* searchNode = listHeadNode->next;
	if (searchNode == NULL) {
		return NULL;
	}
	else {
		/*while (不满足条件) {
			searchNode = searchNode->next;
			if (searchNode == NULL) {
				return NULL;
			}
		}
		return searchNode;*/
	}
}
//计算链表长度
int getLenth(struct Node* listHeadNode) {
	int length = 0;
	struct Node* node = listHeadNode->next;
	if (node == NULL) {
		return 0;
	}
	else {
		while (node != NULL) {
			node = node->next;
			length++;
		}
		return length;
	}
}

//打印链表
void printList(struct Node* listHeadNode) {
	struct Node* pMove = listHeadNode->next;
	//char stu_id[10];	//学号
	//char name[20];		//姓名
	//char colleage[20];	//学院
	//char temperate[5];	//体温
	//char isCough;		//是否咳嗽
	//char status;		//健康状态
	//char time[10];			//统计时间
	//char date[10];			//日期
	printf("%-10s\t%s\t%-10s\t%-5s\t%s\t%s\t%s\t%s\t\n","学号","姓名","学院","体温","是否咳嗽","健康状态","统计时间","日期");
	while (pMove != NULL) {
		printf("%-10s\t%s\t%-10s\t%-5s\t%c\t\t%c\t\t%s\t\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.temperate, pMove->data.isCough, pMove->data.status, pMove->data.time, pMove->data.date);
		pMove = pMove->next;
	}
}
//打印结点
void printNode(struct Node* node) {
	printf("打印结点信息\n");
}
//读取文件信息
void readInfoFromFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w");  //如果文件不存在，就创建文件
	}
	struct student tempData;
	while (fscanf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", tempData.stu_id, tempData.name, tempData.colleage, tempData.temperate, &(tempData.isCough), &(tempData.status), tempData.time, tempData.date) != EOF) {
		insertNodeNyHead(listHeadNode, tempData);
		memset(&tempData, 0, sizeof(tempData));
	}
	fclose(fp);
	fp = NULL;
}

//保存信息到文件
void saveInfoToFile(const char* filename, struct Node* listHeadNode) {
	FILE* fp = fopen(filename, "w");
	struct Node* pMove = listHeadNode->next;
	while (pMove) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%c\t%c\t%s\t%s\t\n", pMove->data.stu_id, pMove->data.name, pMove->data.colleage, pMove->data.temperate, pMove->data.isCough, pMove->data.status, pMove->data.time, pMove->data.date);
		pMove = pMove->next;
	}
	fclose(fp);
	fp = NULL;
}