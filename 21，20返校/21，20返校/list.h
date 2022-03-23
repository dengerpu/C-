#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
struct student {
	char stu_id[10];	//学号
	char name[20];		//姓名
	char colleage[20];	//学院
	char temperate[5];  //温度
	char isCough;       //是否咳嗽
	char status;        //健康状态
	char time[10];      //统计时间
	char date[10];      //日期
};

struct students {
	struct student* data;   //存储学生数据的数组
	int size;				//数组长度
	int capicity;			//当前容量
};

struct Node {
	struct student data;
	struct Node* next;
};

//创建学生成绩链表
struct Node* createList();
//创建学生成绩结点
struct Node* createNode(struct student data);
//学生成绩 头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct student data);
//计算学生成绩链表长度
int getStudentLenth(struct Node* listHeadNode);
//读取文件中学生成绩信息
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode);
//保存学生信息到文件
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode);

//初始化students
void InitStudents(struct students* stu);
//检查容量是否够用
void CheckCapacity(struct students* stu);
//解决bug，去除  .
void removedot(char* arr, int length);
