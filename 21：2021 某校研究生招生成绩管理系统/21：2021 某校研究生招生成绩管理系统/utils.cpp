#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
//截取字符串
int my_substr(char* res, int pos, int len, char* substr) {//从pos开始取len个字符到substr
	char* p = res;
	int i = 0;
	if (pos > strlen(res)) {
		return 0;
	}
	pos--;
	while (i < len) {
		substr[i++] = res[pos++];
		if (pos > strlen(res)) {
			substr[i] = '\0';
		}
	}
	substr[i] = '\0';
	return 1;
}


//获取学号年份
int getSidYear(char* id) {
	char year[5] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 1, 4, year);
		return atoi(year);
	}
}
//获取学号学院代号
int getSidCollege(char* id) {
	char college[3] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 5, 2, college);
		return atoi(college);
	}
}
//获取学号随机数
int getSidNum(char* id) {
	char random_num[4] = { 0 };
	if (id == NULL) {
		return 0;
	}
	else {
		my_substr(id, 7, 3, random_num);
		return atoi(random_num);
	}

}


//获取年份
int getYear(char* date) {
	char year[5] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 1, 4, year);
		return atoi(year);
	}
}
//获取月
int getMonth(char* date) {
	char month[3] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 5, 2, month);
		return atoi(month);
	}
}
//获取日
int getDay(char* date) {
	char day[3] = { 0 };
	if (date == NULL) {
		return 0;
	}
	else {
		my_substr(date, 7, 2, day);
		return atoi(day);
	}
}

//获取学院
void getCollege(int num, char* college) {
	switch (num) {
	case 通信学院:strcpy(college, "通信学院"); break;
	case 计算机学院:strcpy(college, "计算机学院"); break;
	case 光电学院:strcpy(college, "光电学院"); break;
	case 自动化学院:strcpy(college, "自动化学院"); break;
	case 经管学院:strcpy(college, "经管学院"); break;
	case 研究生院:strcpy(college, "研究生院"); break;
	case 外语学院:strcpy(college, "外语学院"); break;
	case 安法学院:strcpy(college, "安法学院"); break;
	case 体育学院:strcpy(college, "体育学院"); break;
	case 传媒学院:strcpy(college, "传媒学院"); break;
	case 先进制造学院:strcpy(college, "先进制造学院"); break;
	case 马克思主义学院:strcpy(college, "马克思主义学院"); break;
	default:strcpy(college, "无"); break;
	};
}
