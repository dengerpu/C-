#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void  isYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		printf("%d������\n", year);
	}
	else {
		printf("%d��������\n", year);
	}
}
int main() {
	int year;
	scanf("%d", &year);
	isYear(year);
	return 0;
}