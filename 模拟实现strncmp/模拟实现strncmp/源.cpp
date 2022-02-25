#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strncmp(const char* str1, const char* str2, size_t num) {
	assert(str1 && str2);
	while (num-- && *str1 && *str2) {
		if (*str1 > *str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			str1++;
			str2++;
		}
	}
	return 0;
}
int main() {
	char arr[] = "abcdefgh";
	char arr2[] = "abcedef";
	int ret = my_strncmp(arr, arr2,4);
	printf("%d\n", ret);
	return 0;
}