#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//问题描述换汽水，1块钱可以买一瓶汽水，两个空瓶可以换一瓶汽水，
//问：花20最多能喝多少瓶汽水
int main() {
	int money = 0, total = 0, empty = 0;
	scanf("%d", &money);
	total = money/1;
	empty = total;
	while (empty >= 2) {
		total += empty / 2;
		empty = empty / 2+empty%2;
	} 
	printf("%d \n", total);
	
}