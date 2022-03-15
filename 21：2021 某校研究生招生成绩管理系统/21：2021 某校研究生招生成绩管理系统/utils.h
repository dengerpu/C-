#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum COLLEGE {
	通信学院 = 1,		//01
	计算机学院,		//02
	光电学院,		//03
	自动化学院,		//04
	经管学院,		//05
	研究生院,		//06
	外语学院,		//07
	安法学院,		//08
	体育学院,		//09
	传媒学院,		//10
	先进制造学院,	//11
	马克思主义学院	//12
};


//截取字符串
int my_substr(char* res, int pos, int len, char* substr);

//获取学院
void getCollege(int num, char* college);
//获取学号年份
int getSidYear(char* id);
//获取学号学院代号
int getSidCollege(char* id);
//获取学号随机数
int getSidNum(char* id);

//获取年份
int getYear(char* date);
//获取月
int getMonth(char* date);
//获取日
int getDay(char* date);

