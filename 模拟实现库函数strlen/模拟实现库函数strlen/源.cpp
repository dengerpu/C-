#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <cassert>
int my_strlen(char* str) {
	int count = 0;
	assert(str != NULL);  //��ָ֤�����Ч��
	while (*str) {
		count++;
		str++;
	}
	return count;
}

int main() {
	char arr[] = "abcedfg";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}