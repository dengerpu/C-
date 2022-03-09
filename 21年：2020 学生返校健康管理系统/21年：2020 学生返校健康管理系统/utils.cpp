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
