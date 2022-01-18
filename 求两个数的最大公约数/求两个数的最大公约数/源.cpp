#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a, b,t,c;
	scanf("%d%d", &a, &b);
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	for (int i = a; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) {
			c = i;
			break;
		}
	}

	printf("%d和%d的最大公约数为：%d\n", a, b, c);
	return 0;
}