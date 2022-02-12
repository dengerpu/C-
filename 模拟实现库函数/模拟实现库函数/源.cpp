#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <cassert>
char* strcpy(char* dst,const char* src) {
	char* str = dst;
	assert(dst && src);
	while (*dst++ = *src++);
	return str;
}

int main() {
	char dst[] = "#######";
	char src[] = "bit";
	 strcpy(dst, src);
	printf("%s\n", dst);
	return 0;
}