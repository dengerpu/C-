#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2) {
	assert(str1 && str2);
	//比较
	while (*str1 == *str2) {
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2) {
		return 1;  //大于
	}
	else if (*str1 < *str2) {
		return -1;  //小于
	}

}
int main() {
	char arr[] = "abcdefg";
	char arr2[] = "abcefg";
	int ret = my_strcmp(arr, arr2);
	if (ret > 0) {
		printf(">\n");
	}
	else if (ret < 0) {
		printf("<\n");
	}
	else {
		printf("=\n");
	}
	return 0;
}