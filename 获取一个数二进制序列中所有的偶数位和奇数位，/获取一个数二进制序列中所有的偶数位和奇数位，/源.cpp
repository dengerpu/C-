#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n;
	int i = 0;
	scanf("%d", &n);
	printf("ż��λ\n");
	for(i = 31; i >= 1; i -= 2) {
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("����\n");
	for (i = 30; i >= 0; i -= 2) {
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");

	return 0;
}