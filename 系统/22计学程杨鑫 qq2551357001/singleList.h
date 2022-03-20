#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
定义学生基本信息数据结构
*/
typedef struct student {
	char name[20];
	char stuID[20];
	char academy[20];
	float temperature;
	int cough;
	int state;
	char time[10];
	char date[20];
	int day;
}student;

/***********定义学生类型结点*************/
typedef struct Node {
	student data;
	struct Node* next;
}Node;

/*
函数功能：创建含头结点的单链表
参数：无
返回值：链表头指针
*/
Node* createList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}


/*
函数功能：插入结点
参数：链表头指针，学生信息
返回值：插入后的链表头指针
*/
insertNode(Node* list, student data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = list->next;
	list->next = newNode;
	newNode->data = data;
}

/*
函数功能：通过学号和日期查找结点结点
参数：链表头指针，学生姓名，日期
返回值：查找到的结点
*/
Node* searchNode(Node* list, char* stuID,char* date) {
	Node* node = list->next;
	while (node != NULL && strcmp(node->data.stuID, stuID) != 0 && strcmp(node->data.stuID, date) != 0) {
		node = node->next;
	}
	return node;
}


/*
函数功能：通过姓名查找结点结点
参数：链表头指针，学生姓名
返回值：查找到的结点
*/
Node* searchNodeByName(Node* list,char* name) {
	Node* node = list->next;
	while (node != NULL && strcmp(node->data.name, name) != 0) {
		node = node->next;
	}
	return node;
}

/*
 函数功能：通过学号查找结点结点
 参数：链表头指针，学生学号
 返回值：查找到的结点
*/
Node* searchNodeByID(Node* list, char* stuID) {
	Node* node = list->next;
	while (node != NULL && strcmp(node->data.stuID, stuID) != 0 ) {
		node = node->next;
	}
	return node;
}

/*
函数功能：删除结点
参数：链表头指针，学生学号
返回值：无
*/
void deleteNode(Node* list, char* stuID) {
	Node* pre = list;//需要删除结点的前驱
	Node* p = list->next;//需要删除的结点
	if (p == NULL) {
		printf("没有相关信息！\n");
		return;
	}
	else {
		while (strcmp(p->data.stuID, stuID)) {
			pre = p;
			p = p->next;
			if (p == NULL) {
				printf("没有相关信息!\n");
				return;
			}
		}
		pre->next = p->next;//删除结点
		free(p);
	}
}

/*
函数功能：输出链表信息
参数：链表头指针
返回值：无
*/
printList(Node* list) {
	if (list->next == NULL) {
		printf("无可查询信息！\n");
		return;
	}
	Node* p = list->next;
	printf("|------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-10s|\n", "学号", "姓名", "学院", "体温",
		"是否咳嗽", "健康状态", "时间", "日期");
	printf("|----------+----------+---------------+--------+--------+--------+--------+----------|\n");
	while (p != NULL) {
		printf("|%-10s|%-10s|%-15s|%-8.1f|%-8d|%-8d|%-8s|%-10s|\n", p->data.stuID, p->data.name, p->data.academy, p->data.temperature,
			p->data.cough, p->data.state,p->data.time, p->data.date);

		p = p->next;
		if (p)
		{
			printf("|----------+----------+---------------+--------+--------+--------+--------+----------|\n");
		}
		else
		{
			printf("|------------------------------------------------------------------------------------|\n");
		}
	}
}

/*
函数功能：输出当前结点包含的学生信息
参数：结点指针
返回值：无
*/
void printCurNode(Node* node) {
	Node* newNode = node;
	printf("|------------------------------------------------------------------------------------|\n");
	printf("|%-10s|%-10s|%-15s|%-8s|%-8s|%-8s|%-8s|%-10s|\n", "学号", "姓名", "学院", "体温",
		"是否咳嗽", "健康状态", "时间", "日期");
	printf("|----------+----------+---------------+--------+--------+--------+--------+----------|\n");
	printf("|%-10s|%-10s|%-15s|%-8.1f|%-8d|%-8d|%-8s|%-10s|\n", newNode->data.stuID, newNode->data.name, newNode->data.academy, 
		newNode->data.temperature,newNode->data.cough, newNode->data.state, newNode->data.time, newNode->data.date);
	printf("|------------------------------------------------------------------------------------|\n");
}

/*
函数功能：从文本中读取信息到链表中
参数：文件名，链表
返回值：无
*/
void readFile(char* fileName, Node* list) {
	student stu;
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {//文件不存在，则创建文件
		fp = fopen(fileName, "w");
	}
	while ((fscanf(fp, "%s\t%s\t%s\t%f\t%d\t%d\t%s\t%s\n", stu.stuID, stu.name, stu.academy, &stu.temperature,
		&stu.cough, &stu.state, stu.time, stu.date)) != EOF) {
		insertNode(list, stu);
	}
	fclose(fp);
}

/*
函数功能：将链表数据写入文件中
参数：文件名，链表
返回值：无
*/
void writeFile(char* fileName, Node* list) {
	Node* p = list->next;//遍历指针
	FILE* fp = fopen(fileName, "w");
	while (p) {
		fprintf(fp, "%s\t%s\t%s\t%.1f\t%d\t%d\t%s\t%s\n", p->data.stuID, p->data.name, p->data.academy, p->data.temperature,
			p->data.cough, p->data.state, p->data.time, p->data.date);
		p = p->next;
	}
	fclose(fp);
}

void swap(char* cur, char* curN) {
	char* temp[20] = { "" };
	strcpy(temp, cur);
	strcpy(cur, curN);
	strcpy(curN, temp);
}

/*
函数功能：通过日期按先后进行排序
参数：待排序链表
返回值：无
*/
void sortByDate(Node* list) {
	if (list->next == NULL) {
		return;
	}
	if (list->next->next == NULL) {
		return;
	}
	Node* tail = NULL;
	Node* cur = list->next;
	while (cur->next != tail) {
		int flag = 0;
		while (cur->next != tail) {
			if (strcmp(cur->data.date, cur->next->data.date) > 0) {
				swap(cur->data.date, cur->next->data.date);
				flag = 1;
			}
			cur = cur->next;
		}
		if (!flag) {
			break;
		}
		tail = cur;
		cur = list->next;
	}
}