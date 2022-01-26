#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fac(int n) {
	int i, ret=1;
	for (int i = 1; i <= n; i++) {
		ret *= i;
	}
	return ret;
}
int fac1(int n) {
	if (n == 1) return 1;
	else return n * fac1(n - 1);
}

int main() {

	int n;
	scanf("%d", &n);

	printf("%d\n", fac(n));
	printf("%d\n", fac1(n));

	return 0;
}