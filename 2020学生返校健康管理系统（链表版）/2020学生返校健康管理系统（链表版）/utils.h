#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//截取字符串
int my_substr(char* res, int pos, int len, char* substr);

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
