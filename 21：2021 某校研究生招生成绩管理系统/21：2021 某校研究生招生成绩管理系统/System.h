#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum adminOption {
	EXIT,
	ADDUSER,
	MODIFYUSER,
	DELETEUSER,
	QUERYUSER,
	ADDSTUDENT,
	MODIFYSTUDENT,
	DELETESTUDENT,
	QUERYSTUDENT,
	PRINTUSER,
	PRINTSTUDENT,
	SORT
};


struct Account {
	char account[10];  //账号
	char password[10]; //密码
	int type;         //用户类型：1.管理员 2.系统操作员 3.学生用户
};

struct Accounts {
	struct Account account;
	struct Accounts* next;
};

struct student {
	char stu_id[10];	//复试学号
	char name[20];		//姓名
	char colleage[20];	//报考学院
	char type[10];      //报考类别
	char course1[6];	//基础课1
	char course2[6];	//基础课2
	char course3[6];	//专业课1
	char course4[6];	//专业课2
	char ptest[10];		//初试成绩
	char retest[10];		//复试成绩
	char olanguage[6];  //口语成绩
	char comprehensive[10];//综合成绩
};

struct Node {
	struct student data;
	struct Node* next;
};

//登陆
int login(struct Accounts* userList,char* user);
//管理员菜单
void adminMenu();
//系统操作员菜单
 void SystemoptionMenu();
//学生菜单
void StudentMenu();
//读取文件中用户信息
void readUserInfoFromFile(const char* filename, struct Accounts* listHeadNode);
//保存用户信息到文件
void saveUserInfoToFile(const char* filename, struct Accounts* listHeadNode);
//创建用户链表
struct Accounts* createUserList();
//创建用户结点
struct Accounts* createUserNode(struct Account account);
//用户 头插法，插入节点
void insertUserNodeNyHead(struct Accounts* listHeadNode, struct Account account);
//查找用户,返回结果为用户类型，如果找不到或为空，返回为0
int findUser(struct Accounts* listHeadNode,char* user, char* pwd);
//计算链表长度
int getUserLenth(struct Accounts* listHeadNode);
//建议用户修改密码
void AdviceModifyPwd(struct Accounts* userList, char* user, char* pwd);

//创建学生成绩链表
struct Node* createList();
//创建学生成绩结点
struct Node* createNode(struct Node data);
//学生成绩 头插法，插入节点
void insertNodeNyHead(struct Node* listHeadNode, struct student data);
//计算学生成绩链表长度
int getStudentLenth(struct Node* listHeadNode);
//读取文件中学生成绩信息
void readStudentInfoFromFile(const char* filename, struct Node* listHeadNode);
//保存学生信息到文件
void saveStudentInfoToFile(const char* filename, struct Node* listHeadNode);
//保存排序后的学生信息到文件
void saveSortStudentInfoToFile(const char* filename, struct Node* listHeadNode);
