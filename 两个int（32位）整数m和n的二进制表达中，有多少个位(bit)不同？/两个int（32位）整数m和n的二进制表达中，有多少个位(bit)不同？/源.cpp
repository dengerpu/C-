#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int find_diffrent(int m, int n) {
	int value = m ^ n;  //��� ����ͬΪ0����Ϊ1
	int count = 0;
	while (value) {
		value = value & (value-1);  //��λ��  ����ȥ�����ұߵ�1
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