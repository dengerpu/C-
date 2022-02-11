#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int find_diffrent(int m, int n) {
	int value = m ^ n;  //异或 ，相同为0相异为1
	int count = 0;
	while (value) {
		value = value & (value-1);  //按位与  可以去掉最右边的1
		count++;
	}
	return count;
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d\n", find_diffrent(m, n));
	return 0;
}