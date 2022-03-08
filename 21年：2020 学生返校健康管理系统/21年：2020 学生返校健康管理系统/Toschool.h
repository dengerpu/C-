#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student {
	char stu_num[8];//学号
	char name[15];  //姓名
	char college[20];//学院
	char temperate[4];//温度
	char isCough;     ///是否咳嗽
	char status;      //健康状态
	char time[5];     //时间
	char date[8];    //日期
		
}Student;

typedef struct students {
	Student data[10];
	int size;
}Students;

enum option {
	EXIT,
	ADD,
	MODIFY,
	DELETE,
	SEARCH,
	ABNORMAL
};
enum college {
	通信学院 = 1,    //01	
	计算机学院,  //02
	光电学院,	 //03
	自动化学院, //04
	经管学院,    //05
	研究生院,    //06
	外语学院,    //07
	安法学院,     //08
	体育学院,     //09
	传媒学院,     //10
	先进制造学院, //11
	马克思主义学院,//12
}enum_college;


//初始化学生信息
void InitStudent(Students* p);


//添加学生信息
void addStudent(Students* p);

//打印学生信息
void printStudent(Students* p);



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
