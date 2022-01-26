#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int n) {
	if (n < 10) return n;
	else return n % 10 + fun(n / 10);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d ", fun(n));
	return 0;
}