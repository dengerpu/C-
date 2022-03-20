#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DEFAULT_SZ 10

struct student {
	char stu_id[12];//学号
	char name[20];	//姓名
	char sid[20];	//身份证号
	char college[20];//学院
	char type[20];	//学生类型
	char major[20];	//专业
	char route[20];	//返校路线
	char traffic[20];//交通工具
	char isClose[10];//密切接触
	char temperate[10];//温度
	char history[20]; //过去14天病史
	char isCough[5];//是否发烧
	char time[20];  //进校时间
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
void saveStudentInfoToFile(struct Node* listHeadNode);
//保存所有学生信息到文件
void saveALLStudentInfoToFile(const char* filename, struct Node* listHeadNode);
//保存排序后的数组信息到文件中
void saveStudentArrInfoToFile(const char* filename, struct student* arr, int length);

//初始化students
void InitStudents(struct students* stu);
//检查容量是否够用
void CheckCapacity(struct students* stu);
