#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

enum option {
	EXIT,
	ADD,
	MODIFY,
	QUERY,
	STATISTICS,
	ADVICE,
	PRINT
};

struct student {
	char stu_id[10];	//学号
	char name[20];		//姓名
	char colleage[20];	//学院
	char temperate[5];	//体温
	char isCough;		//是否咳嗽
	char status;		//健康状态
	char time[10];			//统计时间
	char date[10];			//日期
};

struct Node {
	struct student data;
	struct Node* next;
};

//菜单
void menu();
//创建链表
struct Node* createList();
//创建结点
struct Node* createNode(struct Node data);
//头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct student data);
//尾插法，插入节点
void insertNodeByTail(struct Node* listHeadNode, struct student data);
//删除链表
void deleteNodeByquery(struct Node* listHeadNode, char* query);
//查找结点
struct Node* findNodeByquery(struct Node* listHeadNode, char* query);
//计算链表长度
int getLenth(struct Node* listHeadNode);
//打印链表
void printList(struct Node* listHeadNode);
//打印结点
void printNode(struct Node* node);
//读取文件信息
void readInfoFromFile(const char* filename, struct Node* listHeadNode);
//保存信息到文件
void saveInfoToFile(const char* filename, struct Node* listHeadNode);