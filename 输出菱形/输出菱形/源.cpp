#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n, i, j,k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = n - i; j >= 1; j--) {
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = n-1; i >= 1; i--) {
		for (j = n - i; j >= 1; j--) {
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++) {
			printf("*");
		}
		
		printf("\n");
	}
	
}