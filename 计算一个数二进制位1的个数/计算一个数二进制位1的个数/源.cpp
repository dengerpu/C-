#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int count_bit1(unsigned int n) {
	int count = 0;
	while(n){
		if (n % 2 == 1)count++;
		n = n / 2;
	}
	return count;
}

int count_bit2(int n) {
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++) {
		if ((n >> i) & 1) {
			count++;
		}
	}
	return count;
}

//n = n&(n-1)
//n
//13
//1101 n
//1100 n-1
//1100 n
//1011 n-1
//1000 n
//0111 n-1
//0000 n

//一个数和自己-1得数按位与可以去掉二进制中最右边的1

int count_bit3(int n) {
	int count = 0;
	while (n) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", count_bit1(n));
	printf("%d\n", count_bit2(n));
	printf("%d\n", count_bit3(n));
	return 0;
}