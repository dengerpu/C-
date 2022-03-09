#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student {
	char stu_num[10];//学号
	char name[15];  //姓名
	char college[20];//学院
	char temperate[5];//温度
	char isCough;     ///是否咳嗽
	char status;      //健康状态
	char time[8];     //时间
	char date[10];    //日期
		
}Student;

typedef struct students {
	Student data[20];
	int size;
}Students;

enum option {
	EXIT,
	ADD,
	MODIFY,
	DELETE,
	SEARCH,
	ABNORMAL,
	PRINT
};


//初始化学生信息
void InitStudent(Students* p);


//添加学生信息
void addStudent(Students* p);

//打印学生信息
void printStudent(const Students* p);

//保存数据到文件
void saveStudent(const char* filename,const Students* p);

//修改学生信息
void modifyStudent(Students* p);

//查询学生信息模块
void searchStudent(Students* p);



//C语言提供了几个标准库函数，可以将任意类型(整型、长整型、浮点型等)的数字转换为字符串，下面列举了各函数的方法及其说明。
//● itoa()：将整型值转换为字符串。
//● ltoa()：将长整型值转换为字符串。
//●ultoa()：将无符号长整型值转换为字符串。
//● gcvt()：将浮点型数转换为字符串，取四舍五入。
//● ecvt()：将双精度浮点型值转换为字符串，转换结果中不包含十进制小数点。
//● fcvt()：指定位数为转换精度，其余同ecvt()。
//————————————————
//● atof()：将字符串转换为双精度浮点型值。
//● atoi()：将字符串转换为整型值。
//● atol()：将字符串转换为长整型值。
//● strtod()：将字符串转换为双精度浮点型值，并报告不能被转换的所有剩余数字。
//● strtol()：将字符串转换为长整值，并报告不能被转换的所有剩余数字。
//● strtoul()：将字符串转换为无符号长整型值，并报告不能被转换的所有剩余数字。
//————————————————
