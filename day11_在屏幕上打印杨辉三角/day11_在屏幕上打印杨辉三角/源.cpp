#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int i = 0, j = 0, k = 0,n=0;
	int a[100][100] ;
	printf("«Î ‰»Î–– ˝:\n");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		a[i][1] = 1;
		for (j = 2; j <= i; j++) {
			if (j == i) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (k = 0; k <= n-i; k++) {
			printf("  ");
		}
		for (j = 1; j <= i; j++) {
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}



	return 0;
}