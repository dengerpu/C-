#pragma once
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
struct Node* createNode(struct student  data);
//头插法，插入结点
void insertNoByHead(struct Node* listHeadNode, struct student data);
//打印链表
void printList(struct Node* listHeadNode);
//删除链表
void deleteNodeByStudent_Name(struct Node* listHeadNode, char* name);
//根据学号查找学生信息
struct Node* searchNodeBynum(struct Node* listHeadNode, char* num);
//打印结点
void printNode(struct Node* newNode);
//根据学号修改学生信息
void modifyNodeBynum(struct Node* listHeadNode, char* num);
//读取文件中的信息
void readInfofromfile(const char* filename, struct Node* listHeadNode);
//保存到文件中
void saveInfoToFile(const char* filename, struct Node* listHeadNode);