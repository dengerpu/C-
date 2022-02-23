#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src) {
	assert(dest && src);
	char* str = dest;
	//拷贝src指向的字符串到dest指向的空间，包含‘\0’
	while (*dest++ = *src++) {
		;
	}
	return str;
}
int main() {
	char arr[] = "abcde";
	char arr2[] = "fg";
	my_strcpy(arr, arr2);
	printf("%s\n",arr );
	return 0;
}