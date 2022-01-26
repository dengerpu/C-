#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int n,int k) {
	if (k == 1) {
		return n;
	}
	else {
		return n * fun(n, k - 1);
	}
}
int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	printf("%d", fun(n, k));
	return 0;
}