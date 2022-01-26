#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int n) {
	int a = 1, b = 1, c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	printf("%d ", c);
	
}

int fun1(int n) {
	if (n == 1 || n == 2) return 1;
	else return fun1(n - 1) + fun1(n - 2);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		fun(i);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", fun1(i));
	}
	return 0;
}