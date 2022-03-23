#pragma once
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define WIN_WIDTH 160 // 窗口宽度
#define WIN_HEIGHT 60 // 窗口高度
#define TABLE_WIDTH 158 //表格宽度
#define MENU_WIDTH  40 //菜单宽度
#define COL_LEN_MAX 64 //最大列数

#define DEFAULT_SZ 10 //默认数组大小
#define DEFAULT_PAGE_NUM 10  //默认每页显示多少条数据

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
//打印表头（适用于打印菜单 ┌──────────┐）
void printMenuHead(int tableWidth);
//打印表格中间的信息（│ 菜单内容│）（适用于输出数据）
void printMenuMidInfo(int tableWidth, const char* str);
//打印表尾（适用于打印菜单 └──────────┘）
void printMenuTail(int tableWidth);

//打印表格标题格式（ ┌───┬───┬───┐标题栏）（适用于输出数据）
void printTableHead(int tableWidth, int cols);
//打印表头数据     （│ 标题1│ 标题2│ 标题3│标题或内容）（适用于输出数据）
void printTableRow(int tableWidth, char cols[][COL_LEN_MAX], int n);
//打印表格中间分割线（├───┼─ ─┼───┤）（适用于输出数据）
void printTableMidLine(int tableWidth, int cols);
//打印表格表尾（      └───┴───┴───┘）（适用于打印数据）
void printTableTail(int tableWidth, int cols);


//居中打印
void printMidInfo(const char* str);

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

//获取日期的年份
int getYear(char* date);
//获取日期的月份
int getMonth(char* date);
//获取日期的日
int getDay(char* date);



