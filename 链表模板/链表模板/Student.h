#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
	char name[20];  //姓名
	char num[10];	//学号
	int age;		//年龄
	char tel[20];	//电话
	char addr[20];	//地址
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
//打印链表
void printList(struct Node* listHeadNode);
//打印结点
void printNode(struct Node* node);
//读取文件信息
void readInfoFromFile(const char* filename, struct Node* listHeadNode);
//保存信息到文件
void saveInfoToFile(const char* filename, struct Node* listHeadNode);