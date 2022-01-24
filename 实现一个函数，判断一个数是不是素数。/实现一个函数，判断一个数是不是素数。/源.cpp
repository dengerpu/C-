#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void isSushu(int n) {
	int i;
	for (i = 2; i < sqrt(n); i++) {
		if (n % i == 0) {
			break;
		}
	}
	if (i >= sqrt(n)) {
		printf("是素数\n");
	}
	else {
		printf("不是素数\n");
	}
}
int main() {
	int n;
	scanf("%d", &n);
	isSushu(n);
	return 0;
}