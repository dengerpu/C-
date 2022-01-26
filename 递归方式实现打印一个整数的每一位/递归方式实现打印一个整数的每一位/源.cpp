#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int n) {
	if (n < 10) printf("%d ", n);
	else {
		fun(n / 10);
		printf("%d ", n%10);
	}
}
void print(int n) {
	if (n > 9) {
		fun(n / 10);
	}
	printf("%d ", n%10);
}
int main() {

	int n;
	scanf("%d", &n);
	fun(n);
	print(n);
	return 0;
}