#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
//��ȡ�ַ���
int my_substr(char* res, int pos, int len, char* substr) {//��pos��ʼȡlen���ַ���substr
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
//��ȡѧ�����
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
//��ȡѧ��ѧԺ����
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
//��ȡѧ�������
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


//��ȡ���
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
//��ȡ��
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
//��ȡ��
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
