#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void  isYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		printf("%d是润年\n", year);
	}
	else {
		printf("%d不是润年\n", year);
	}
}
int main() {
	int year;
	scanf("%d", &year);
	isYear(year);
	return 0;
}