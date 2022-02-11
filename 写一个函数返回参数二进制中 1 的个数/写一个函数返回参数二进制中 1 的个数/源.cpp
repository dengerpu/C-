#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int  count_one_bits(unsigned int n)
{
	int count = 0;
	while (n) {
		if (n % 2 == 1) count++;
		n = n / 2;
	}
	return count;
	// 返回 1的位数
}

int  count_one_bits2(unsigned int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++) {
		if ((n >> i) & 1 == 1) count++;
	}
	return count;
	// 返回 1的位数
}
int  count_one_bits3(unsigned int n)
{
	int count = 0;
	while (n) {
		n = n &(n - 1);
		count++;
	}
	return count;
	// 返回 1的位数
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", count_one_bits(n));
	printf("%d\n", count_one_bits2(n));
	printf("%d\n", count_one_bits3(n));


	return 0;
}