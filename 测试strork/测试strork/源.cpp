#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char date[20] = { 0 };
	char *day;
	char *month;
	char *year;
	scanf("%s", date);
	day = strtok(date,"/");
	month = strtok(NULL, "/");
	year = strtok(NULL, "/");
	printf("%s\n", day);
	printf("%s\n", month);
	printf("%s\n", year);
	if (atoi(year) < 21 || atoi(year) > 22) {
		printf("��ݴ���\n");
	}
	if (atoi(month) < 0 || atoi(month) > 12) {
		printf("�·ݴ���\n");
	}
	if (atoi(day) < 0 || atoi(day) > 31) {
		printf("���ڴ���\n");
	}
	return 0;
}