#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10
struct country {
	char country_name[20];	//国家
	char continent[20];  	//洲
	int total_peoples;	     //人口总数
	double country_area;     //国土面积
	double builder_area;	//建成区面积
	double people_density;  //密度
	int add;	//新增确诊
	int total ;	//累计确诊
	int death;	//累计死亡
	int cure;		//累计治愈
	double mortality;		//死亡率
	double cure_rate;  //治愈率
	char severity_index;//严重指数
};

struct courties {
	struct country* data;   //存储学生数据的数组
	int size;				//数组长度
	int capicity;			//当前容量
};

struct Node {
	struct country data;
	struct Node* next;
};

//创建学生成绩链表
struct Node* createList();
//创建学生成绩结点
struct Node* createNode(struct country data);
//学生成绩 头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct country data);
//计算学生成绩链表长度
int getStudentLenth(struct Node* listHeadNode);
//读取文件中学生成绩信息
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode);
//保存学生信息到文件
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode);

//初始化students
void InitStudents(struct countrys* stu);
//检查容量是否够用
void CheckCapacity(struct countrys* stu);
//解决bug，去除  .
void removedot(char* arr, int length);
