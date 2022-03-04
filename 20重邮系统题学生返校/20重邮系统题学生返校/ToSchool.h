#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SZ 10  //定义默认的储存量，如果不够动态申请同样大小个
#define MALLOC(type,num) (type*)malloc(num*sizeof(type))  //定义一个宏

enum OPTION {
	EXIT,
	ADD,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

typedef struct studentInfo {   //学生信息
	char stu_num[15];      //学号
	char name[15];         //姓名
	char stu_id[20];       //身份证号
	char college[50];      //学院
	char stu_type;         //学生类型
	char major[50];        //专业
	char route[100];       //返校路线
	char trafficTools[100];//交通工具
	char isCloseContact;   //近14天是否有密切接触确诊人员
	char temperature[10];  //入校时温度
	char isFever;		   //是否发烧
	char isCough;		   //是否咳嗽
	char time[20];		  //进校时间


}Student;
struct students {
	Student* data;
	int size;
	int capicty;
};
//登陆
void Login();
//菜单
void menu();
//加载学生信息
void LoadStudent(students* p);
//初始化
void Init(students* p);
//检查容量是否够用
void CheckCapacity(students* p);
//添加学生信息
void AddStudent(students* p);
//展示学生信息
void ShowStudent(const students* p);
//搜索信息
void SearchStudent(const students* p);
//修改信息
void MOdifyStudent(students* p);
//排序
void SortStudent(students* p);

