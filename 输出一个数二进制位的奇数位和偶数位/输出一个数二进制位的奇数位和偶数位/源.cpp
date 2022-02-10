#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n,i;
	scanf("%d", &n);
	printf("偶数位\n");
	for (i = 31; i >= 1; i -= 2) {
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("奇数位\n");
	for (i = 30; i >= 0; i -= 2) {
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");

	return 0;
}